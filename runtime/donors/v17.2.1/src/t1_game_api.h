#pragma once
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include "t1_ipc.h"

T1Shared* T1_IPC();
void T1_Fault(const char* s);
void T1_Log(const char* fmt,...);
void T1_OnSwapchain(ID3D11Device* d,ID3D11DeviceContext* c,IDXGISwapChain* s);
void T1_OnPresent(IDXGISwapChain* s);
int  T1_ReadContract(T1FrameContract* out);
int  T1_HostRunning();

void T1_CameraBootstrap();
void T1_CameraShutdown();
int  T1_BuildEyeCamera(int eye,void* outCamera,size_t bytes,uint64_t* contractId,float* axisDot);
int  T1_GetCenterCamera(void* outCamera,size_t bytes,uint64_t* contractId);
int  T1_GetSnapshotContract(T1FrameContract* out);

void T1_DualBootstrap();
void T1_DualShutdown();
void T1_DualOnPresent(IDXGISwapChain* s);
ID3D11Texture2D* T1_DualEyeTexture(int eye);
uint64_t T1_DualQueuedPairPoseId();
LONG T1_DualQueuedPairSerial();
LONG T1_DualCompletedPairSerial();
int T1_DualCompletedPairContract(T1FrameContract* out);
int T1_DualCurrentEye();
int T1_DualTargetsReady();
void T1_DualWriteStatus();
