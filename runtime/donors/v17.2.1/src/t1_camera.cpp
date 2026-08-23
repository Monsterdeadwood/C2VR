#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include "t1_game_api.h"

static const uintptr_t RVA_RENDERWORLD_CALL=0x005E2476u;
static const uintptr_t RVA_RENDERWORLD_FUNC=0x005DEF10u;
static const size_t CAMERA_BYTES=0x230u;
static const size_t OFF_FOV=0x30u, OFF_RATIO=0x3Cu, OFF_NEAR=0x48u, OFF_ASYM=0x68u;

typedef uintptr_t (__thiscall *PFN_RENDER_WORLD)(void*,uintptr_t,void*,uintptr_t,uintptr_t,uintptr_t);
static PFN_RENDER_WORLD g_orig=NULL;
static uint8_t* g_callsite=NULL; static uint8_t g_saved[5]={};
static volatile LONG g_shutdown=0;
static volatile LONG g_snapSeq=0; static uint8_t g_center[CAMERA_BYTES]={}; static T1FrameContract g_fc={}; static uint64_t g_contractId=0;

static int finitef(float v){return v==v && fabsf(v)<1000000.0f;}
static int camera_sane(const void* p){
    if(!p||IsBadReadPtr(p,0x78))return 0;const float* m=(const float*)p;
    for(int i=0;i<12;i++)if(!finitef(m[i]))return 0;
    float f=*(const float*)((const uint8_t*)p+OFF_FOV),r=*(const float*)((const uint8_t*)p+OFF_RATIO),n=*(const float*)((const uint8_t*)p+OFF_NEAR);
    return f>0.20f&&f<2.8f&&r>0.2f&&r<5.0f&&n>0.001f&&n<5.0f;
}
static void quat_to_mat3(const float q_[4],float r[9]){
    float x=q_[0],y=q_[1],z=q_[2],w=q_[3];float n=sqrtf(x*x+y*y+z*z+w*w);if(n<1e-6f){x=y=z=0;w=1;}else{x/=n;y/=n;z/=n;w/=n;}
    r[0]=1-2*y*y-2*z*z;r[1]=2*x*y-2*z*w;r[2]=2*x*z+2*y*w;
    r[3]=2*x*y+2*z*w;r[4]=1-2*x*x-2*z*z;r[5]=2*y*z-2*x*w;
    r[6]=2*x*z-2*y*w;r[7]=2*y*z+2*x*w;r[8]=1-2*x*x-2*y*y;
}
static int apply_center_6dof(void* camera,const T1FrameContract& c){
    if(!camera_sane(camera)||IsBadWritePtr(camera,48))return 0;float* m=(float*)camera;
    float B[9]={m[0],m[1],m[2],m[4],m[5],m[6],m[8],m[9],m[10]},r[9];quat_to_mat3(c.head_q,r);
    /* Proven Crysis retail coordinate bridge. */
    float cr[9]={r[0],-r[2],r[1], -r[6],r[8],-r[7], r[3],-r[5],r[4]},o[9]={};
    for(int a=0;a<3;a++)for(int b=0;b<3;b++)for(int k=0;k<3;k++)o[a*3+b]+=B[a*3+k]*cr[k*3+b];
    m[0]=o[0];m[1]=o[1];m[2]=o[2];m[4]=o[3];m[5]=o[4];m[6]=o[5];m[8]=o[6];m[9]=o[7];m[10]=o[8];
    float local[3]={c.center_pos_m[0],-c.center_pos_m[2],c.center_pos_m[1]};
    float wd[3]={B[0]*local[0]+B[1]*local[1]+B[2]*local[2],B[3]*local[0]+B[4]*local[1]+B[5]*local[2],B[6]*local[0]+B[7]*local[1]+B[8]*local[2]};
    m[3]+=wd[0];m[7]+=wd[1];m[11]+=wd[2];return 1;
}
static int fov_sane(const float f[4]){return f[0]<-0.05f&&f[1]>0.05f&&f[2]>0.05f&&f[3]<-0.05f&&fabsf(f[0])<1.7f&&fabsf(f[1])<1.7f&&fabsf(f[2])<1.7f&&fabsf(f[3])<1.7f;}
/* CCamera asymmetry is not a culling input in this renderer lineage. Build a
   center-only symmetric envelope for list preparation, but publish the eye
   snapshot BEFORE this change so LEFT/RIGHT raster cameras remain exact XrView. */
static int apply_center_cull_union(void* camera,const T1FrameContract& c,float* outFov){
    if(!camera_sane(camera)||!fov_sane(c.fov[0])||!fov_sane(c.fov[1]))return 0;uint8_t* p=(uint8_t*)camera;
    float ratio=*(float*)(p+OFF_RATIO),nearZ=*(float*)(p+OFF_NEAR),orig=*(float*)(p+OFF_FOV);if(ratio<0.2f||nearZ<0.001f)return 0;
    float maxH=0,maxV=0;for(int e=0;e<2;e++){float ex=c.eye_pos_head_m[e][0]/nearZ,ez=c.eye_pos_head_m[e][1]/nearZ;
        float h[2]={ex+tanf(c.fov[e][0]),ex+tanf(c.fov[e][1])};float v[2]={ez+tanf(c.fov[e][3]),ez+tanf(c.fov[e][2])};
        for(int k=0;k<2;k++){if(fabsf(h[k])>maxH)maxH=fabsf(h[k]);if(fabsf(v[k])>maxV)maxV=fabsf(v[k]);}}
    float halfTan=fmaxf(maxV,maxH/ratio)*1.02f;float cover=2.0f*atanf(halfTan);if(!finitef(cover)||cover<0.2f||cover>2.7f)return 0;
    if(cover>orig)memcpy(p+OFF_FOV,&cover,4);else cover=orig;if(outFov)*outFov=cover;return 1;
}
static int apply_exact_asym(void* camera,const float f[4]){
    if(!camera_sane(camera)||!fov_sane(f)||IsBadWritePtr((uint8_t*)camera+OFF_ASYM,16))return 0;
    uint8_t* c=(uint8_t*)camera;float vf=*(float*)(c+OFF_FOV),ratio=*(float*)(c+OFF_RATIO),nearZ=*(float*)(c+OFF_NEAR);
    float hh=nearZ*tanf(vf*0.5f),hw=hh*ratio;
    float a[4]={nearZ*tanf(f[0])+hw,nearZ*tanf(f[1])-hw,nearZ*tanf(f[3])+hh,nearZ*tanf(f[2])-hh};
    for(int i=0;i<4;i++)if(!finitef(a[i]))return 0;memcpy(c+OFF_ASYM,a,16);return 1;
}
static void publish_snapshot(const void* camera,const T1FrameContract& fc){
    InterlockedIncrement(&g_snapSeq);MemoryBarrier();memcpy(g_center,camera,CAMERA_BYTES);g_fc=fc;g_contractId=fc.contract_id;MemoryBarrier();InterlockedIncrement(&g_snapSeq);
}
static int read_snapshot(uint8_t* cam,T1FrameContract* fc,uint64_t* id){
    for(int t=0;t<12;t++){LONG a=g_snapSeq;if(a&1)continue;MemoryBarrier();memcpy(cam,g_center,CAMERA_BYTES);*fc=g_fc;uint64_t x=g_contractId;MemoryBarrier();LONG b=g_snapSeq;if(a==b&&!(b&1)&&x){if(id)*id=x;return 1;}}return 0;
}

static uintptr_t __fastcall hkRenderWorld(void* self,void*,uintptr_t a1,void* camera,uintptr_t a3,uintptr_t a4,uintptr_t a5){
    T1Shared* ipc=T1_IPC();if(ipc)InterlockedIncrement(&ipc->renderworld_calls);
    if(!g_orig)return 0;if(!camera_sane(camera)||IsBadWritePtr(camera,CAMERA_BYTES))return g_orig(self,a1,camera,a3,a4,a5);
    T1FrameContract fc={};int have=T1_HostRunning()&&T1_ReadContract(&fc);uint8_t save[CAMERA_BYTES];memcpy(save,camera,CAMERA_BYTES);int patched=0;
    if(have&&apply_center_6dof(camera,fc)){patched=1;publish_snapshot(camera,fc);if(ipc)InterlockedIncrement(&ipc->center_inject_ok);float cf=0;if(apply_center_cull_union(camera,fc,&cf)&&ipc){ipc->last_cull_fov=cf;InterlockedIncrement(&ipc->cull_union_ok);}}
    uintptr_t r=g_orig(self,a1,camera,a3,a4,a5);
    if(patched){memcpy(camera,save,CAMERA_BYTES);if(ipc)InterlockedIncrement(&ipc->center_restore_ok);}return r;
}

int T1_GetCenterCamera(void* out,size_t bytes,uint64_t* id){if(!out||bytes<CAMERA_BYTES)return 0;T1FrameContract fc={};return read_snapshot((uint8_t*)out,&fc,id);}
int T1_GetSnapshotContract(T1FrameContract* out){if(!out)return 0;uint8_t cam[CAMERA_BYTES];uint64_t id=0;return read_snapshot(cam,out,&id);}
int T1_BuildEyeCamera(int eye,void* out,size_t bytes,uint64_t* id,float* axisDot){
    if(eye<0||eye>1||!out||bytes<CAMERA_BYTES)return 0;uint8_t cam[CAMERA_BYTES];T1FrameContract fc={};uint64_t cid=0;if(!read_snapshot(cam,&fc,&cid)||!fov_sane(fc.fov[eye]))return 0;
    float* m=(float*)cam;const float* ep=fc.eye_pos_head_m[eye];
    /* Exact proven eye-local bridge from the successful retail camera path:
       OpenXR (+X right,+Y up,-Z forward) -> Cry (+X right,+Y forward,+Z up). */
    float local[3]={ep[0],-ep[2],ep[1]};
    float dx=m[0]*local[0]+m[1]*local[1]+m[2]*local[2],dy=m[4]*local[0]+m[5]*local[1]+m[6]*local[2],dz=m[8]*local[0]+m[9]*local[1]+m[10]*local[2];
    m[3]+=dx;m[7]+=dy;m[11]+=dz;if(!apply_exact_asym(cam,fc.fov[eye]))return 0;
    float axisLen=sqrtf(m[0]*m[0]+m[4]*m[4]+m[8]*m[8]);float dLen=sqrtf(dx*dx+dy*dy+dz*dz);float dot=0;
    if(axisLen>0.5f&&dLen>1e-6f){float p=(dx*m[0]+dy*m[4]+dz*m[8])/(axisLen*dLen);dot=(eye==0)?-p:p;}
    if(axisDot)*axisDot=dot;if(id)*id=cid;memcpy(out,cam,CAMERA_BYTES);return dot>0.70f;
}

static int install(){
    uint8_t* base=(uint8_t*)GetModuleHandleW(NULL);if(!base)return 0;uint8_t* cs=base+RVA_RENDERWORLD_CALL;if(cs[0]!=0xE8){T1_Fault("RENDERWORLD_CALL_OPCODE_MISMATCH");return 0;}int32_t rel=*(int32_t*)(cs+1);if(cs+5+rel!=base+RVA_RENDERWORLD_FUNC){T1_Fault("RENDERWORLD_CALL_TARGET_MISMATCH");return 0;}
    g_orig=(PFN_RENDER_WORLD)(base+RVA_RENDERWORLD_FUNC);memcpy(g_saved,cs,5);DWORD old=0;if(!VirtualProtect(cs,5,PAGE_EXECUTE_READWRITE,&old)){T1_Fault("RENDERWORLD_PROTECT_FAIL");return 0;}cs[0]=0xE8;*(int32_t*)(cs+1)=(int32_t)((uint8_t*)&hkRenderWorld-(cs+5));DWORD x;VirtualProtect(cs,5,old,&x);FlushInstructionCache(GetCurrentProcess(),cs,5);g_callsite=cs;T1_Log("CENTER_CAMERA_HOOK_READY call=+005E2476 target=+005DEF10");return 1;
}
void T1_CameraBootstrap(){install();}
void T1_CameraShutdown(){g_shutdown=1;if(g_callsite){DWORD old=0;if(VirtualProtect(g_callsite,5,PAGE_EXECUTE_READWRITE,&old)){memcpy(g_callsite,g_saved,5);DWORD x;VirtualProtect(g_callsite,5,old,&x);FlushInstructionCache(GetCurrentProcess(),g_callsite,5);}g_callsite=NULL;}}
