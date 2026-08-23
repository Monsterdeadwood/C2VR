# Crysis 2 VR — STATE SYNC

Snapshot imported from `C2VR_STATE_SYNC_20260823.md` and `C2VR_MAIN_INTEGRATOR_BLUEPRINT_20260823.md`.

## GOVERNING MODE
WORKING BUILD FIRST.
REVERSE ONLY BLOCKERS.
PARALLELIZE EVIDENCE, SERIALIZE MUTATION.

## BEST WORKING / MAIN BUILD
`CUSTOM_DUAL_T1 v1.0.1`

Historical accepted facts:
- center HMD inject/restore: 2296/2296
- private LEFT passes: 2295
- private RIGHT passes: 2295
- direct eye copies: 2229
- OpenXR submits: 2624
- L/R median sampled MAE: 35.9781, therefore non-duplicate eye pixels
- acceptance failure: `PosePairContract`

**TRUE TWO-EYE RENDER IS PROVEN. DO NOT REBUILD STEREO.**

## CURRENT BLOCKER
`PosePairContract`.

## CURRENT FINISH ORDER
`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

## CANONICAL EYE TRANSACTION — IMMUTABLE
`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 snapshots full SThreadInfo of same eye -> render thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`

One prepared render-list executes twice:
`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`.

Forbidden:
- second `EF_StartEf / EF_StartEf3D`
- second high-level `RenderWorld`
- foreign-thread direct `FX_*` render-target calls
- mono RGB+depth reprojection as final renderer
- native Cry SBS / DisplayStereo / CopyToStereo as VR transport

Current master RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

## CORRECTED RETAIL ANCHORS
- `CSystem::m_ViewCamera = +0x3F0`
- `C3DEngine::RenderWorld = +0x005E2360`
- `RenderInternal = +0x005DEF10`
- `Renderer::SetCamera = CryRenderD3D11 +0x00148340`
- `EF_Scene3D = +0x00101370`
- `EF_EndEf3D = +0x001019A0`
- `RC_RenderScene = +0x001C48D0`
- `RT_RenderScene = +0x00107370`
- `PrepareDepthMaps = +0x0011D390`
- `FOB_NEAREST SetCamera return = +0x000FF456`

Retail hashes:
- Crysis2.exe `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## PROVEN / DO NOT RECHECK
- true private L/R execution is possible in retail Crysis 2
- `RC_RenderScene` packages camera/thread snapshot plus render-list snapshot
- render-item storage survives first eye; logical reset occurs at next top-level `EF_StartEf`
- `RT_RenderScene` owns more than draws: shadows, HDR/deferred, ordered lists, temporal state and postprocess
- applying HMD transform at every `Renderer::SetCamera` creates a feedback loop and is forbidden
- standalone `RC_SetCamera` mutation can be superseded by later RT-side state
- second top-level RenderWorld / EF_StartEf path is forbidden
- native Cry stereo is not final transport
- `camera-0x3E8 == CSystem` is FALSIFIED
- GPU CB hits are not a gameplay detector
- counters alone are not visual proof
- `SHDF_ZPASS_ONLY` is not a valid RIGHT-eye normal-scene policy
- v15 late-sink mono/reprojection is FALSIFIED as final architecture

## POSEPAIR FINALIST
Use a host-owned immutable current-XR-frame ticket.
Minimal first mutation imports only the v17.2 rendezvous pieces:
1. packed immutable frame contract / exact ABI equivalent
2. host publication of current XR ticket
3. pair producer carries exactly that ticket through LEFT + RIGHT
4. completed pair publishes that same ticket only after RIGHT RT completion
5. host waits in a bounded window
6. host accepts exact identity only
7. mismatch => zero layers, never stale relabel

Do NOT enable HEAD/cull rewrite, RIGHT Touch NEAR mutation, temporal-history mutation, or second-eye shadow suppression in this first build.

## NEXT
Build one T1-derived PosePair-only integration where every submitted LEFT/RIGHT pair carries exactly one immutable current-frame OpenXR contract and mismatches are dropped rather than relabeled.

## LATER SERIAL GATES
After PosePair passes:
1. HEAD 1:1 + culling envelope
2. weapon / FOB_NEAREST
3. temporal/shadow stability
4. full regression
5. release candidate

## HISTORICAL RESEARCH, NOT CURRENT BLOCKER
Resource `20500` / 320-byte per-view CB work remains useful provenance history but is no longer the visible finish gate. Do not return to broad resource archaeology unless the working-build ladder produces a concrete blocker requiring it.
