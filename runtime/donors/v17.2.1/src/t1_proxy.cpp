#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <d3d11.h>
#include <dxgi.h>
#include "t1_game_api.h"

static HMODULE g_real=NULL,g_self=NULL;static HANDLE g_map=NULL;static T1Shared* g_ipc=NULL;static FILE* g_log=NULL;static WCHAR g_out[MAX_PATH]={};static volatile LONG g_shutdown=0;
static ID3D11Device* g_dev=NULL;static ID3D11DeviceContext* g_ctx=NULL;static IDXGISwapChain* g_swap=NULL;static ID3D11Texture2D* g_shared[2]={};static IDXGIKeyedMutex* g_mutex[2]={};static HANDLE g_handle[2]={};static LONG g_lastCopiedSerial=0;
static HRESULT (STDMETHODCALLTYPE *oPresent)(IDXGISwapChain*,UINT,UINT)=NULL;static HRESULT (STDMETHODCALLTYPE *oCreateSwapChain)(IDXGIFactory*,IUnknown*,DXGI_SWAP_CHAIN_DESC*,IDXGISwapChain**)=NULL;
static HRESULT (STDMETHODCALLTYPE *oMap)(ID3D11DeviceContext*,ID3D11Resource*,UINT,D3D11_MAP,UINT,D3D11_MAPPED_SUBRESOURCE*)=NULL;static void (STDMETHODCALLTYPE *oUnmap)(ID3D11DeviceContext*,ID3D11Resource*,UINT)=NULL;
struct MapRec{ID3D11Resource* r;void* p;UINT size;int eye;};static MapRec g_maps[512]={};static CRITICAL_SECTION g_mapLock;static LONG g_lockReady=0;

T1Shared* T1_IPC(){if(g_ipc)return g_ipc;if(!g_map)g_map=OpenFileMappingW(FILE_MAP_ALL_ACCESS,FALSE,C2VR_T1_MAP_NAME);if(!g_map)return NULL;g_ipc=(T1Shared*)MapViewOfFile(g_map,FILE_MAP_ALL_ACCESS,0,0,sizeof(T1Shared));if(!g_ipc)return NULL;if(g_ipc->magic!=C2VR_T1_MAGIC||g_ipc->version!=C2VR_T1_VERSION){UnmapViewOfFile(g_ipc);g_ipc=NULL;CloseHandle(g_map);g_map=NULL;return NULL;}g_ipc->game_alive=1;return g_ipc;}
static void openlog(){if(g_log)return;if(!g_out[0]){DWORD n=GetEnvironmentVariableW(L"C2VR17_OUT",g_out,MAX_PATH);if(!n||n>=MAX_PATH){GetModuleFileNameW(g_self,g_out,MAX_PATH);WCHAR* p=wcsrchr(g_out,L'\\');if(p)*p=0;}}CreateDirectoryW(g_out,NULL);WCHAR p[MAX_PATH];wsprintfW(p,L"%s\\C2VR17_GAME.log",g_out);_wfopen_s(&g_log,p,L"wb");}
void T1_Log(const char* fmt,...){openlog();if(!g_log)return;SYSTEMTIME st;GetLocalTime(&st);fprintf(g_log,"[%02u:%02u:%02u.%03u] ",st.wHour,st.wMinute,st.wSecond,st.wMilliseconds);va_list a;va_start(a,fmt);vfprintf(g_log,fmt,a);va_end(a);fputc('\n',g_log);fflush(g_log);}
void T1_Fault(const char* s){T1Shared* p=T1_IPC();if(p){p->faulted=1;lstrcpynA(p->fault_text,s,sizeof(p->fault_text));}T1_Log("FAULT %s",s?s:"UNKNOWN");}
int T1_HostRunning(){T1Shared* p=T1_IPC();return p&&p->host_alive&&p->session_running&&p->views_valid&&!p->faulted;}
int T1_ReadContract(T1FrameContract* out){T1Shared* p=T1_IPC();if(!p||!out||!p->views_valid)return 0;for(int i=0;i<16;i++){LONG a=p->contract_seq;if(a&1)continue;MemoryBarrier();*out=p->contract;MemoryBarrier();LONG b=p->contract_seq;if(a==b&&!(b&1)&&out->contract_id)return 1;}return 0;}
static bool patch_vslot(void* obj,size_t slot,void* h,void** orig){if(!obj)return false;void** vt=*(void***)obj;if(!vt)return false;void** cell=&vt[slot];if(*cell==h)return true;DWORD old=0;if(!VirtualProtect(cell,sizeof(void*),PAGE_EXECUTE_READWRITE,&old))return false;if(orig&&!*orig)*orig=*cell;*cell=h;MemoryBarrier();DWORD x;VirtualProtect(cell,sizeof(void*),old,&x);FlushInstructionCache(GetCurrentProcess(),cell,sizeof(void*));return true;}
static float f32(const uint8_t* p,UINT off){float v=0;memcpy(&v,p+off,4);return _finite(v)?v:0;}
static int semantic_family(const uint8_t* p,UINT n){if(!p||n<224)return 0;float a=f32(p,144),b=f32(p,148),z=f32(p,204);if(fabsf(a-0.12f)<0.0012f&&fabsf(b-2000.0f)<0.6f&&fabsf(z+0.1200072f)<0.0025f)return 1;if(fabsf(a-0.03f)<0.0012f&&fabsf(b-40.0f)<0.15f&&fabsf(z+0.0300225f)<0.0025f)return 2;return 3;}
static uint64_t semantic_hash64(const uint8_t* p,UINT n){uint64_t h=1469598103934665603ull;if(!p)return 0;UINT lim=n<64?n:64;for(UINT i=0;i<lim;i++){h^=p[i];h*=1099511628211ull;}return h;}
static void map_put(ID3D11Resource* r,void* p,UINT size,int eye){if(!r||!p||!g_lockReady)return;EnterCriticalSection(&g_mapLock);for(int i=0;i<512;i++)if(!g_maps[i].r||g_maps[i].r==r){g_maps[i].r=r;g_maps[i].p=p;g_maps[i].size=size;g_maps[i].eye=eye;break;}LeaveCriticalSection(&g_mapLock);}
static MapRec map_take(ID3D11Resource* r){MapRec x={};if(!r||!g_lockReady)return x;EnterCriticalSection(&g_mapLock);for(int i=0;i<512;i++)if(g_maps[i].r==r){x=g_maps[i];ZeroMemory(&g_maps[i],sizeof(g_maps[i]));break;}LeaveCriticalSection(&g_mapLock);return x;}
static HRESULT STDMETHODCALLTYPE hkMap(ID3D11DeviceContext* c,ID3D11Resource* r,UINT sub,D3D11_MAP mt,UINT fl,D3D11_MAPPED_SUBRESOURCE* m){HRESULT hr=oMap?oMap(c,r,sub,mt,fl,m):E_FAIL;if(SUCCEEDED(hr)&&r&&m&&m->pData){ID3D11Buffer* b=NULL;if(SUCCEEDED(r->QueryInterface(__uuidof(ID3D11Buffer),(void**)&b))&&b){D3D11_BUFFER_DESC d={};b->GetDesc(&d);if(d.ByteWidth==320)map_put(r,m->pData,d.ByteWidth,T1_DualCurrentEye());b->Release();}}return hr;}
static void STDMETHODCALLTYPE hkUnmap(ID3D11DeviceContext* c,ID3D11Resource* r,UINT sub){MapRec m=map_take(r);if(m.r&&m.p&&m.size==320){int fam=semantic_family((const uint8_t*)m.p,m.size);T1Shared* s=T1_IPC();if(s){if(m.eye>=0&&m.eye<2){uint64_t h=semantic_hash64((const uint8_t*)m.p,m.size);if(fam==1){s->semantic_world_hash[m.eye]=h;InterlockedIncrement(&s->semantic_world_eye[m.eye]);}else if(fam==2){s->semantic_near_hash[m.eye]=h;InterlockedIncrement(&s->semantic_near_eye[m.eye]);}else InterlockedIncrement(&s->semantic_other_eye[m.eye]);}else InterlockedIncrement(&s->semantic_unknown_eye);}}if(oUnmap)oUnmap(c,r,sub);}
static void install_context_hooks(ID3D11DeviceContext* c){if(!c)return;patch_vslot(c,14,(void*)&hkMap,(void**)&oMap);patch_vslot(c,15,(void*)&hkUnmap,(void**)&oUnmap);}
static void release_shared(){for(int e=0;e<2;e++){if(g_mutex[e]){g_mutex[e]->Release();g_mutex[e]=NULL;}if(g_shared[e]){g_shared[e]->Release();g_shared[e]=NULL;}g_handle[e]=NULL;if(g_ipc)g_ipc->shared_handle[e]=0;}}
static int make_shared(){if(g_shared[0]&&g_shared[1])return 1;if(!g_dev||!T1_DualTargetsReady())return 0;ID3D11Texture2D* s0=T1_DualEyeTexture(0),*s1=T1_DualEyeTexture(1);if(!s0||!s1)return 0;D3D11_TEXTURE2D_DESC a={},b={};s0->GetDesc(&a);s1->GetDesc(&b);if(a.Width!=b.Width||a.Height!=b.Height||a.Format!=b.Format||a.SampleDesc.Count!=1||b.SampleDesc.Count!=1){T1_Fault("PRIVATE_EYE_DESC_MISMATCH");return 0;}D3D11_TEXTURE2D_DESC d=a;d.Usage=D3D11_USAGE_DEFAULT;d.BindFlags=D3D11_BIND_SHADER_RESOURCE|D3D11_BIND_RENDER_TARGET;d.CPUAccessFlags=0;d.MiscFlags=D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX;d.MipLevels=1;d.ArraySize=1;for(int e=0;e<2;e++){if(FAILED(g_dev->CreateTexture2D(&d,NULL,&g_shared[e]))||!g_shared[e]){T1_Fault("CREATE_DIRECT_EYE_SHARED_FAILED");return 0;}if(FAILED(g_shared[e]->QueryInterface(__uuidof(IDXGIKeyedMutex),(void**)&g_mutex[e]))||!g_mutex[e]){T1_Fault("DIRECT_EYE_MUTEX_FAILED");return 0;}IDXGIResource* r=NULL;if(FAILED(g_shared[e]->QueryInterface(__uuidof(IDXGIResource),(void**)&r))||!r)return 0;HRESULT hr=r->GetSharedHandle(&g_handle[e]);r->Release();if(FAILED(hr)||!g_handle[e])return 0;}T1Shared* p=T1_IPC();if(p){p->game_w=d.Width;p->game_h=d.Height;p->game_format=(uint32_t)d.Format;p->shared_handle[0]=(uint64_t)(uintptr_t)g_handle[0];p->shared_handle[1]=(uint64_t)(uintptr_t)g_handle[1];MemoryBarrier();InterlockedExchange(&p->eye_ready_mask,3);}T1_Log("V17_SHARED_EYES_READY %ux%u fmt=%u",d.Width,d.Height,(unsigned)d.Format);return 1;}
static int read_completed(T1FrameContract* fc,LONG* serial){if(!fc||!serial)return 0;LONG s=T1_DualCompletedPairSerial();if(s<=0)return 0;if(!T1_DualCompletedPairContract(fc))return 0;*serial=s;return 1;}
static int publish_pair(){if(!g_ctx||!make_shared())return 0;T1FrameContract fc={};LONG serial=0;if(!read_completed(&fc,&serial)||serial==g_lastCopiedSerial)return 0;if(g_mutex[0]->AcquireSync(0,0)!=S_OK)return 0;if(g_mutex[1]->AcquireSync(0,0)!=S_OK){g_mutex[0]->ReleaseSync(0);return 0;}ID3D11Texture2D* L=T1_DualEyeTexture(0),*R=T1_DualEyeTexture(1);if(!L||!R){g_mutex[1]->ReleaseSync(0);g_mutex[0]->ReleaseSync(0);return 0;}g_ctx->CopyResource(g_shared[0],L);g_ctx->CopyResource(g_shared[1],R);g_ctx->Flush();T1Shared* p=T1_IPC();if(p){InterlockedIncrement(&p->pair_contract_seq);MemoryBarrier();p->pair_contract=fc;MemoryBarrier();InterlockedIncrement(&p->pair_contract_seq);MemoryBarrier();InterlockedIncrement(&p->pair_seq);InterlockedIncrement(&p->direct_pair_copies);InterlockedExchange(&p->activation_beep_ready,1);}g_mutex[0]->ReleaseSync(1);g_mutex[1]->ReleaseSync(1);g_lastCopiedSerial=serial;return 1;}
static void mirror_left(IDXGISwapChain* sc){T1Shared* p=T1_IPC();if(!sc||!g_ctx||!T1_DualTargetsReady())return;ID3D11Texture2D* L=T1_DualEyeTexture(0),*bb=NULL;if(!L||FAILED(sc->GetBuffer(0,__uuidof(ID3D11Texture2D),(void**)&bb))||!bb)return;D3D11_TEXTURE2D_DESC a={},b={};L->GetDesc(&a);bb->GetDesc(&b);if(a.Width==b.Width&&a.Height==b.Height&&a.Format==b.Format&&a.SampleDesc.Count==b.SampleDesc.Count){g_ctx->CopyResource(bb,L);if(p)InterlockedIncrement(&p->mirror_left_ok);}else if(p)InterlockedIncrement(&p->mirror_left_fail);bb->Release();}
static void status(){
    if(!g_out[0])return;WCHAR q[MAX_PATH];wsprintfW(q,L"%s\\C2VR17_GAME_STATUS.txt",g_out);
    FILE* f=NULL;_wfopen_s(&f,q,L"wb");if(!f)return;T1Shared* p=T1_IPC();
    fprintf(f,"architecture=RC33_TWO_PASS_TRUE_LR\nmono_reprojection=ABSENT\nnative_stereo=ABSENT\nsecond_renderworld=ABSENT\nsilent_mono_fallback=ABSENT\n");
    if(p)fprintf(f,
      "host_alive=%ld\nsession_running=%ld\nviews_valid=%ld\nfaulted=%ld\n"
      "renderworld_calls=%ld\ncenter_inject_ok=%ld\ncenter_restore_ok=%ld\ncull_union_ok=%ld\nlast_cull_fov=%.7f\n"
      "scene_packets=%ld\ncustom_pairs_queued=%ld\npairs_completed=%ld\n"
      "eye_camera_left_ok=%ld\neye_camera_right_ok=%ld\neye_camera_left_fail=%ld\neye_camera_right_fail=%ld\nlast_axis_dot=%.6f\n"
      "rt_push_left=%ld\nrt_push_right=%ld\nrt_scene_left=%ld\nrt_scene_right=%ld\n"
      "temporal_snap_left=%ld\ntemporal_snap_right=%ld\ntemporal_restore_left=%ld\ntemporal_restore_right=%ld\nshadow_skip_right=%ld\n"
      "direct_pair_copies=%ld\ndirect_pair_copy_fail=%ld\npair_seq=%ld\nlast_completed_contract=%llu\n"
      "pose_desync=%ld\nframe_desync=%ld\npair_contract_mismatch=%ld\n"
      "near_left=%ld\nnear_right=%ld\nhand_near_left=%ld\nhand_near_right=%ld\nhand_baseline_resets=%ld\n"
      "semantic_world_left=%ld\nsemantic_world_right=%ld\nsemantic_near_left=%ld\nsemantic_near_right=%ld\nsemantic_unknown=%ld\n"
      "semantic_world_hash_left=%016llX\nsemantic_world_hash_right=%016llX\nsemantic_near_hash_left=%016llX\nsemantic_near_hash_right=%016llX\n"
      "two_pass_active=%ld\ncenter_scene_suppressed=%ld\nhost_frame_gate_skips=%ld\nmirror_left_ok=%ld\nmirror_left_fail=%ld\n"
      "hand_delta_m=%.6f,%.6f,%.6f\nhand_angle_deg=%.4f\nfault=%s\n",
      p->host_alive,p->session_running,p->views_valid,p->faulted,
      p->renderworld_calls,p->center_inject_ok,p->center_restore_ok,p->cull_union_ok,p->last_cull_fov,
      p->scene_packets,p->custom_pairs_queued,p->pairs_completed,
      p->eye_camera_ok[0],p->eye_camera_ok[1],p->eye_camera_fail[0],p->eye_camera_fail[1],p->last_axis_dot,
      p->rt_push_eye[0],p->rt_push_eye[1],p->rt_scene_eye[0],p->rt_scene_eye[1],
      p->temporal_snap[0],p->temporal_snap[1],p->temporal_restore[0],p->temporal_restore[1],p->shadow_skip[1],
      p->direct_pair_copies,p->direct_pair_copy_fail,p->pair_seq,(unsigned long long)p->last_completed_contract,
      p->pose_desync,p->frame_desync,p->pair_contract_mismatch,
      p->near_events[0],p->near_events[1],p->hand_near_eye[0],p->hand_near_eye[1],p->hand_baseline_resets,
      p->semantic_world_eye[0],p->semantic_world_eye[1],p->semantic_near_eye[0],p->semantic_near_eye[1],p->semantic_unknown_eye,
      (unsigned long long)p->semantic_world_hash[0],(unsigned long long)p->semantic_world_hash[1],
      (unsigned long long)p->semantic_near_hash[0],(unsigned long long)p->semantic_near_hash[1],
      p->two_pass_active,p->center_scene_suppressed,p->host_frame_gate_skips,p->mirror_left_ok,p->mirror_left_fail,
      p->last_hand_delta_m[0],p->last_hand_delta_m[1],p->last_hand_delta_m[2],p->last_hand_angle_deg,p->fault_text);
    fclose(f);
}
static HRESULT STDMETHODCALLTYPE hkPresent(IDXGISwapChain* s,UINT sync,UINT flags){T1_IPC();T1_DualOnPresent(s);int pub=publish_pair();if(pub)mirror_left(s);static LONG n=0;if((++n%90)==1){status();T1_DualWriteStatus();}return oPresent?oPresent(s,sync,flags):E_FAIL;}
static void install_present(IDXGISwapChain* s){if(s)patch_vslot(s,8,(void*)&hkPresent,(void**)&oPresent);}
static void force_desc(DXGI_SWAP_CHAIN_DESC* d){if(!d)return;WCHAR b[32];DWORD n=GetEnvironmentVariableW(L"C2VR17_FORCE_W",b,32);UINT w=n?(UINT)_wtoi(b):0;n=GetEnvironmentVariableW(L"C2VR17_FORCE_H",b,32);UINT h=n?(UINT)_wtoi(b):0;if(w>=800&&h>=600&&w<=4096&&h<=4096){d->BufferDesc.Width=w;d->BufferDesc.Height=h;T1_Log("FORCE_SWAPCHAIN %ux%u",w,h);}}
static HRESULT STDMETHODCALLTYPE hkCreateSwapChain(IDXGIFactory* f,IUnknown* dev,DXGI_SWAP_CHAIN_DESC* desc,IDXGISwapChain** out){DXGI_SWAP_CHAIN_DESC tmp={};DXGI_SWAP_CHAIN_DESC* use=desc;if(desc){tmp=*desc;force_desc(&tmp);use=&tmp;}HRESULT hr=oCreateSwapChain?oCreateSwapChain(f,dev,use,out):E_FAIL;if(SUCCEEDED(hr)&&out&&*out){adopt_device(dev);if(!g_swap){g_swap=*out;g_swap->AddRef();}install_present(*out);}return hr;}
static void install_factory(ID3D11Device* d){if(!d)return;IDXGIDevice* xd=NULL;if(FAILED(d->QueryInterface(__uuidof(IDXGIDevice),(void**)&xd))||!xd)return;IDXGIAdapter* ad=NULL;if(SUCCEEDED(xd->GetAdapter(&ad))&&ad){IDXGIFactory* f=NULL;if(SUCCEEDED(ad->GetParent(__uuidof(IDXGIFactory),(void**)&f))&&f){patch_vslot(f,10,(void*)&hkCreateSwapChain,(void**)&oCreateSwapChain);f->Release();}ad->Release();}xd->Release();}
void T1_OnSwapchain(ID3D11Device* d,ID3D11DeviceContext* c,IDXGISwapChain* s){if(d&&!g_dev){g_dev=d;g_dev->AddRef();install_factory(g_dev);}if(c&&!g_ctx){g_ctx=c;g_ctx->AddRef();install_context_hooks(g_ctx);}else if(g_dev&&!g_ctx){g_dev->GetImmediateContext(&g_ctx);install_context_hooks(g_ctx);}if(s&&!g_swap){g_swap=s;g_swap->AddRef();install_present(g_swap);}}
void T1_OnPresent(IDXGISwapChain* s){hkPresent(s,0,0);}
static FARPROC realproc(const char* n){if(!g_real){WCHAR sys[MAX_PATH];GetSystemDirectoryW(sys,MAX_PATH);lstrcatW(sys,L"\\d3d11.dll");g_real=LoadLibraryW(sys);}return g_real?GetProcAddress(g_real,n):NULL;}
extern "C" HRESULT WINAPI T1_D3D11CreateDevice(IDXGIAdapter* a,D3D_DRIVER_TYPE dt,HMODULE sw,UINT fl,const D3D_FEATURE_LEVEL* lv,UINT nl,UINT sdk,ID3D11Device** dev,D3D_FEATURE_LEVEL* out,ID3D11DeviceContext** ctx){typedef HRESULT(WINAPI*F)(IDXGIAdapter*,D3D_DRIVER_TYPE,HMODULE,UINT,const D3D_FEATURE_LEVEL*,UINT,UINT,ID3D11Device**,D3D_FEATURE_LEVEL*,ID3D11DeviceContext**);F f=(F)realproc("D3D11CreateDevice");if(!f)return E_FAIL;HRESULT hr=f(a,dt,sw,fl,lv,nl,sdk,dev,out,ctx);if(SUCCEEDED(hr))T1_OnSwapchain(dev?*dev:NULL,ctx?*ctx:NULL,NULL);return hr;}
extern "C" HRESULT WINAPI T1_D3D11CreateDeviceAndSwapChain(IDXGIAdapter* a,D3D_DRIVER_TYPE dt,HMODULE sw,UINT fl,const D3D_FEATURE_LEVEL* lv,UINT nl,UINT sdk,const DXGI_SWAP_CHAIN_DESC* sd,IDXGISwapChain** sc,ID3D11Device** dev,D3D_FEATURE_LEVEL* out,ID3D11DeviceContext** ctx){typedef HRESULT(WINAPI*F)(IDXGIAdapter*,D3D_DRIVER_TYPE,HMODULE,UINT,const D3D_FEATURE_LEVEL*,UINT,UINT,const DXGI_SWAP_CHAIN_DESC*,IDXGISwapChain**,ID3D11Device**,D3D_FEATURE_LEVEL*,ID3D11DeviceContext**);F f=(F)realproc("D3D11CreateDeviceAndSwapChain");if(!f)return E_FAIL;DXGI_SWAP_CHAIN_DESC tmp={};const DXGI_SWAP_CHAIN_DESC* use=sd;if(sd){tmp=*sd;force_desc(&tmp);use=&tmp;}HRESULT hr=f(a,dt,sw,fl,lv,nl,sdk,use,sc,dev,out,ctx);if(SUCCEEDED(hr))T1_OnSwapchain(dev?*dev:NULL,ctx?*ctx:NULL,sc?*sc:NULL);return hr;}
static DWORD WINAPI worker(void*){openlog();T1_Log("V172_BOOT RC33_TRUE_LR mono=0 reprojection=0 native_stereo=0");for(int i=0;i<240&&!T1_IPC();i++)Sleep(250);T1_CameraBootstrap();T1_DualBootstrap();while(!g_shutdown){T1_IPC();Sleep(500);}return 0;}
BOOL WINAPI DllMain(HINSTANCE h,DWORD reason,LPVOID){if(reason==DLL_PROCESS_ATTACH){g_self=h;DisableThreadLibraryCalls(h);InitializeCriticalSection(&g_mapLock);g_lockReady=1;CreateThread(NULL,0,worker,NULL,0,NULL);}else if(reason==DLL_PROCESS_DETACH){g_shutdown=1;status();T1_DualShutdown();T1_CameraShutdown();if(g_ipc)g_ipc->game_alive=0;release_shared();if(g_swap)g_swap->Release();if(g_ctx)g_ctx->Release();if(g_dev)g_dev->Release();if(g_ipc)UnmapViewOfFile(g_ipc);if(g_map)CloseHandle(g_map);if(g_log)fclose(g_log);if(g_lockReady){DeleteCriticalSection(&g_mapLock);g_lockReady=0;}}return TRUE;}
