# Crysis 2 VR — PROVEN

Canonical current sources: `C2VR_STATE_SYNC_20260823.md`, `C2VR_MAIN_INTEGRATOR_BLUEPRINT_20260823.md`, retail runtime evidence.

## True two-eye retail renderer
Main working build: `CUSTOM_DUAL_T1 v1.0.1`.

Canonical RESULT:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

- bytes `68,872,488`
- SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAe1EDDB3596144D341CD53367`

Historical result:
- center HMD inject/restore 2296/2296
- private LEFT passes 2295
- private RIGHT passes 2295
- direct eye copies 2229
- OpenXR submits 2624
- sampled L/R median MAE 35.9781
- FramePairContract desync 0/0
- PosePairContract desync game/host 1/1

The two eyes are genuinely different. **True private L/R execution is PROVEN. Do not rebuild stereo.**

## Exact main-source authority recovered
Physical source package:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`

- bytes `83,442`
- SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- internal manifest `20/20 PASS`

Exact main source identities include:
- `t1_camera.cpp` `03D87C773DEA4FBA9D9C4828DCCB8BC50AD518E12B4E490B8C624CC26509F8BE`
- `t1_dual_render.cpp` `64F3B8FC3DEBB9976894DD1494406E4166B626BAF6B9AEB2F3D2CF846900C9F2`
- `t1_host_x64.cpp` `C88F9147D5C204B2D6E4C39FC271A34FDD5C3F9664431A2059306AE7C2468819`
- `t1_ipc.h` `4C98391543122FE9B3A9FFBBDAE76415568D51F7186D61DF1955A7BECBD2C90A`
- `t1_proxy.cpp` `4505003BE7574E0DFE7766FED603F41C7BC98FF882ED50E996A735A42C7F05CD`

Canonical RESULT build identity:
- x64 host binary `2F79B1D4C2233444E75BC895929FABEF41EF44734854E8448D158D151A87B028`
- x86 proxy binary `A11FC3E91669FBD472013E4882CEE721F09CB0A9C25FBD981AF222E87F92B279`

Repository authority:
- `runtime/main/CUSTOM_DUAL_T1_v1.0.1/README.md`
- `runtime/main/CUSTOM_DUAL_T1_v1.0.1/PACKAGE_SHA256.txt`
- `tools/extract_verified_custom_dual_t1_v1_0_1.py`

This exact T1 source package is the parent for the next integration child.

## v17.2.1 donor authority recovered
Physical donor package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.1_ARGV_FIX_ONECLICK.zip`

- bytes `91,521`
- SHA256 `53688524B59E9C8F7B768BFA78BB80DEDC0981EB7FF699204E496887668D38A2`
- original manifest `27/27 PASS`

This independently supersedes the earlier text-corpus-only source provenance. The corpus reconstruction remains a cross-check.

The donor contains multiple later-gate policies. Only its PosePair rendezvous transaction is currently authorized for transplant.

Repository authority:
- `runtime/donors/v17.2.1/README.md`
- `runtime/donors/v17.2.1/ORIGINAL_PACKAGE_SHA256.txt`
- `runtime/donors/v17.2.1/POSEPAIR_TRANSPLANT.md`
- `tools/extract_verified_v17_2_1_original.py`

## Canonical render transaction
- One prepared render-list can execute twice as separate eyes.
- `RC_RenderScene` packages camera/thread snapshot plus render-list snapshot.
- Render-item storage survives first eye; logical reset happens at the next top-level `EF_StartEf`.
- `RT_RenderScene` is not draw-only: shadows, HDR/deferred, ordered lists, temporal state and postprocess live there.
- Current master render-target transaction is `RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

## Corrected retail anchors
- `CSystem::m_ViewCamera = +0x3F0`
- `C3DEngine::RenderWorld = +0x005E2360`
- `RenderInternal = +0x005DEF10`
- `Renderer::SetCamera = CryRenderD3D11+0x00148340`
- `EF_Scene3D = +0x00101370`
- `EF_EndEf3D = +0x001019A0`
- `RC_RenderScene = +0x001C48D0`
- `RT_RenderScene = +0x00107370`
- `PrepareDepthMaps = +0x0011D390`
- `FOB_NEAREST SetCamera return = +0x000FF456`

Retail hashes used by the successful forensic line:
- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## Camera ownership constraints
- Applying HMD transform at every `Renderer::SetCamera` creates the proven feedback loop `G -> G*HMD -> G*HMD^2 -> ...`; this is forbidden.
- Standalone `RC_SetCamera` mutation is not final eye ownership because later RT-side state can supersede it.
- `+0x0057AC76` is a proven useful HEAD propagation anchor from earlier work.
- `+0x005E2476` is a concrete gameplay RenderWorld-call seam used by v17.2; it is not the canonical RenderWorld function start.

## Build lineage worth preserving
- `CUSTOM_DUAL_T1 v1.0.1`: real private L/R render; PosePairContract failed.
- v17.1: host-driven reconstruction of the successful two-pass primitive.
- v17.2/v17.2.1: donor corpus containing immutable pair ticket, HEAD/culling, NEAR/weapon and temporal/shadow candidates. Do not install wholesale.
- v2.2.0 STABLE CAMERA: useful last-known-good weapon/input behavior donor, not replacement for the main T1 stereo build.

## Current integration equation

```text
exact CUSTOM_DUAL_T1 v1.0.1 parent
+ only verified v17.2.1 PosePair rendezvous
= next PosePair child
```

Do not import HEAD/culling, weapon/NEAR, temporal or shadow mutations into that child.

## Source/runtime trust
Retail Crysis 2 1.9 runtime/binary truth outranks source/SDK, CE 3.3.8, beta/PDB and donor inference.

## Historical GPU provenance
The resource `20500` / 320-byte camera-per-view CB work remains useful research evidence, but it is historical support rather than the current finish blocker.
