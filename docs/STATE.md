# Crysis 2 VR State

## LATEST RESULT
Latest cross-branch causal result is `v17.2.5 WAIT45` on the PosePair/projection-layer cadence line:
- `269 exact_pair_consumes`
- `269 host_submits`
- `53 misses`
- exact ratio `83.5404%`
- `pair_wait_ms_max = 47`
- `354/354` completed/copies
- visual flashes/dropouts still remained

Compared with the earlier ~`92 exact / 776 miss` (~10.6%), increasing the bounded exact wait to 45 ms improved exact acceptance by about 7.9x. This strongly implicates deadline/watchdog timing in the projection-layer misses.

The next build already exists but has no recorded LIVE result:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`.
Against P5 it changes only the bounded exact-pair watchdog `45 ms -> 120 ms`; game-side camera/FOV/weapon/shadow/temporal/RC33 code is unchanged. Recorded static checks: `130/130 PASS`; independent verification `98/98 PASS`.

## BEST WORKING / MAIN PARENT
`CUSTOM_DUAL_T1 v1.0.1`

True retail two-eye rendering is already PROVEN:
- center HMD inject/restore `2296/2296`
- private LEFT passes `2295`
- private RIGHT passes `2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- median sampled L/R MAE `35.9781`
- FramePairContract desync `0/0`
- acceptance failure was PosePairContract, not lack of stereo

## CURRENT GATE
**POSEPAIR / PROJECTION-LAYER EXACT-PAIR CADENCE GATING.**

The immediate question is whether flashes/dropouts are primarily caused by the bounded exact-pair watchdog expiring before the complete pair reaches the host.

## NEXT
Run **P6 (`v17.2.6 EXACT_BLOCK120`) unchanged** and record headset behavior plus exact/miss/wait telemetry.

Interpretation:
- If exact ratio approaches 100% and flashes/dropouts disappear or materially collapse: KEEP exact identity; do **not** increase timeout again. ADAPT to pipeline lead using `targetDisplayTime = predictedDisplayTime + K*predictedDisplayPeriod` with minimal successful K.
- If misses remain materially high: investigate the existing rendezvous timing chain only; no HEAD/weapon mutation.
- If exact ratio is high but flashes remain: distinguish exact identity from timely prediction; test pipeline lead / coherent last-good pair policy before later gates.

## FINISH ORDER
`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

## PROVEN ARCHITECTURE
Canonical eye transaction:
`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 snapshots same-eye SThreadInfo -> render-thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`.

One prepared render-list executes twice:
`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`.

Current RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

## CONCRETE RETAIL TARGETS / OFFSETS
Crysis2.exe:
- `CSystem::m_ViewCamera = +0x3F0`
- `C3DEngine::RenderWorld = +0x005E2360`
- `RenderInternal = +0x005DEF10`
- direct gameplay RenderWorld call seam `+0x005E2476`
- `C3DEngine::SetupCamera candidate = +0x0057A730`
- once-per-frame camera landmark `+0x0057AC76`

CryRenderD3D11.dll:
- NEAR owner region `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- NEAR restore `+0x000FF4A3`
- object-owner landmark `+0x00102100`
- `Renderer::SetCamera = +0x00148340`
- `EF_RenderScene = +0x00101270` high confidence
- `EF_Scene3D = +0x00101370`
- `EF_EndEf3D = +0x001019A0`
- `RT_RenderScene = +0x00107370`
- `PrepareDepthMaps = +0x0011D390`
- `RC_SetCamera = +0x001C38F0`
- `RC_PushRT = +0x001C4190`
- `RC_PopRT = +0x001C4200`
- `RC_RenderScene = +0x001C48D0`

## CURRENT FINALISTS
### Active gate
1. `P6 EXACT_BLOCK120`: same exact immutable PosePair contract, only 120 ms bounded watchdog ceiling.
2. If P6 proves identity but exposes latency: pipeline lead batch `K=0..3` using `predictedDisplayTime + K*predictedDisplayPeriod`.
3. Reserve only: last-good complete stereo pair **with its own original pose/FOV**, never old pixels relabelled with new pose.

### Parked HEAD gate
After PosePair only:
- PRIMARY basis: OpenXR `(x,y,z) -> Cry (+x,-z,+y)`.
- old universal `-X` reflection is not authoritative.
- HEAD candidates: immutable `G * HMDrelative`, then `yawOnly(G) * HMDrelative` if gameplay pitch/body contamination appears; `HMDrelative * G` only as multiplication-order control.
- Use a real center `CCamera` with coherent frustum semantics before visibility; no all-SetCamera injection.
- Future refinement: use `XR_REFERENCE_SPACE_TYPE_VIEW` located at the same target display time for true center-head pose.

### Parked MASTER3 WEAPON / NEAR gate
WORLD remains immutable in this branch.
- historical controller->visual weapon motion is proven
- final controller/weapon ownership should be upstream real weapon pose if the renderer shim is not perfect
- primary rigid candidate: `G = inverse(C_bind) * W_bind`; `W_now = C_now * G`
- no automatic squeeze/grip rebind
- one controller pose/contract for both eyes
- keep per-eye NEAR projection separate from weapon pose
- exact retail RVAs still missing for `CPlayer::PostUpdateView`, `CItem::UpdateFPPosition`, `CItem::UpdateFPCharacter`; beta PDB/source bridge is the preferred cold closure when this gate becomes active

## METHOD ALREADY USED
- source/SDK/PDB/RTTI/donor corpus harvest
- RenderDoc/GPU projection and constant-buffer provenance
- Ghidra/source-to-retail mapping
- runtime loaded-memory disassembly and raw stack propagation
- x86 proxy / x64 OpenXR host split
- keyed mutex shared textures
- immutable frame contract and exact pair identity
- serial causal timing changes (notably WAIT45)
- historical controller->NEAR and controller->gameplay-aim bridges
- TTD/ReClass only where a concrete writer/field question existed

Do not build another broad analyzer after a concrete target exists.

## IMPORTANT PATHS / VERSIONS / DEPENDENCIES
- Retail: `C:\GOG Games\Crysis 2`, retail 1.9, 32-bit game
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)\_r\crysis2(5620)\_01_13`
- Shared tools: `C:\GOG Games\VR Research Tools`
- Beta `CryGameCrysis2.pdb` observed size `82,045,952` bytes; an older broad symbol census stopped at `80,000` hits, so missing weapon symbols in that census are not negative evidence
- Architecture: x86 in-process game/proxy + x64 OpenXR host
- Quest/OpenXR transport through current Oculus/Meta OpenXR runtime used by the project

Retail hashes:
- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## UNRESOLVED QUESTIONS
1. Does P6 eliminate/strongly reduce exact-pair misses and flashes?
2. Once identity is closed, how many display periods of pipeline lead are required for timely prediction?
3. After PosePair, which HEAD composition gives visual 1:1 without double rotation: `G*HMDrelative` or `yawOnly(G)*HMDrelative`?
4. At WEAPON gate, can the fixed-bind full SE(3) controller transform pass visually at the existing NEAR seam, or must ownership move upstream to the real FP weapon entity?
5. Exact retail mapping remains open for `CPlayer::PostUpdateView`, `CItem::UpdateFPPosition`, `CItem::UpdateFPCharacter`, `CWeapon::SetFiringLocator`, and fire-mode hit/firing position/direction functions.
6. Temporal-history and second-eye shadow policies remain later gates only.
