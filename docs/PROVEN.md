# Crysis 2 VR — PROVEN

Canonical current sources: `C2VR_STATE_SYNC_20260823.md`, `C2VR_MAIN_INTEGRATOR_BLUEPRINT_20260823.md`, retail runtime evidence.

## True two-eye retail renderer
Main working build: `CUSTOM_DUAL_T1 v1.0.1`.

Historical result:
- center HMD inject/restore 2296/2296
- private LEFT passes 2295
- private RIGHT passes 2295
- direct eye copies 2229
- OpenXR submits 2624
- sampled L/R median MAE 35.9781

The two eyes are genuinely different. **True private L/R execution is PROVEN. Do not rebuild stereo.**

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

## Source/runtime trust
Retail Crysis 2 1.9 runtime/binary truth outranks source/SDK, CE 3.3.8, beta/PDB and donor inference.

## Historical GPU provenance
The resource `20500` / 320-byte camera-per-view CB work remains useful research evidence, but it is historical support rather than the current finish blocker.
