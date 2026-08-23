# Crysis 2 VR State

## LATEST RESULT
Latest completed causal runtime result is `v17.2.5 WAIT45` on PosePair/projection-layer cadence:
- `269 exact_pair_consumes`
- `269 host_submits`
- `53 misses`
- exact ratio `83.5404%`
- stale drains `31`
- `pair_wait_ms_last = 31`
- `pair_wait_ms_max = 47`
- `354/354` completed/copies
- visual flashes/dropouts still remained

P4 immediately before it produced `92 exact`, `776 misses`, `386 stale drains`, about `10.6%` exact acceptance. WAIT45 improved the exact ratio about 7.9x. Therefore watchdog/deadline timing is a PROVEN contributor to missing projection layers.

The next build exists but still has no recorded LIVE result:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`.

P6 changes only the bounded exact-pair watchdog `45 ms -> 120 ms`; it is not a forced sleep. Recorded validation: `130/130 PASS` plus independent `98/98 PASS`. Game-side camera/FOV/weapon/shadow/temporal/RC33 policy is unchanged from P5.

## BEST WORKING / MAIN PARENT
`CUSTOM_DUAL_T1 v1.0.1`

True retail two-eye rendering is already PROVEN:
- center HMD inject/restore `2296/2296`
- private LEFT `2295`
- private RIGHT `2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- median sampled L/R MAE `35.9781`
- FramePairContract desync `0/0`
- acceptance failure was PosePairContract, not lack of stereo

Do not rebuild stereo.

## CURRENT GATE
**POSEPAIR / PROJECTION-LAYER EXACT-PAIR CADENCE GATING.**

Immediate question: are the remaining flashes/dropouts caused by the bounded exact-pair watchdog expiring before a slow-but-valid RC33 L/R pair reaches Present publication and host consumption?

## NEXT
Run **P6 (`v17.2.6 EXACT_BLOCK120`) unchanged** and return its RESULT ZIP plus headset observations.

Interpretation:
- timeouts near zero + flashes gone => KEEP exact identity, STOP increasing wait, ADAPT to future-target pipeline lead `K=0..3`;
- timeouts near zero + flashes remain => STOP timeout path, inspect presentation seam/timeliness;
- many timeouts remain => add passive phase timestamps `contract -> RenderWorld -> RT L -> RT R -> Present publish -> host consume` before any mutation.

Unchanged running shadows are not P6 failure.

## FINISH ORDER
`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

## PROVEN ARCHITECTURE
Canonical eye transaction:
`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 snapshots same-eye SThreadInfo -> render-thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`.

One prepared render-list executes twice:
`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`.

Current RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

The game-side completed pair is published cross-process from the Present gate. Exact host wait therefore includes host->RenderWorld phase, RC queue latency, RT LEFT, RT RIGHT, Present publication, shared copy/keyed-mutex rendezvous and host consume.

## CONCRETE RETAIL TARGETS / OFFSETS
Crysis2.exe:
- `CSystem::GetViewCamera +0x0006AE50`
- `CSystem::m_ViewCamera +0x3F0`
- `CSystem::Render +0x00096A40`
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- direct gameplay RenderWorld call seam `+0x005E2476`
- `C3DEngine::SetupCamera +0x0057A730`
- once/logical-frame main camera SetCamera return `+0x0057AC76`
- downstream landmarks `+0x00A0DD57`, `+0x00A8074B`

CryRenderD3D11.dll:
- `EF_RenderScene +0x00101270`
- `EF_Scene3D +0x00101370`
- `EF_EndEf3D +0x001019A0`
- `RT_RenderScene +0x00107370`
- `PrepareDepthMaps +0x0011D390`
- `ProcessScene +0x00123EA0`
- LEFT SetCamera return `+0x0012412A`
- LEFT EF_Scene3D `+0x0012413C`
- RIGHT SetCamera return `+0x00124304`
- RIGHT EF_Scene3D `+0x0012430F`
- renderer SetCamera vslot `+0xB8`
- `Renderer::SetCamera +0x00148340`
- `RC_SetCamera +0x001C38F0`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`
- `RC_RenderScene +0x001C48D0`
- NEAR owner `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- NEAR restore `+0x000FF4A3`
- near-enriched camera path `+0x0007AEB0`
- late camera CB producer `+0x0006AE2A`
- temporal/previous-matrix anchor `+0x000F95A0`
- `RT_SetCameraInfo` candidate `+0x000FB2E0`
- `mfSetCamera` candidate `+0x0008AF30`

## CURRENT FINALISTS
### Active gate
1. `P6 EXACT_BLOCK120` unchanged.
2. If P6 closes starvation: pipeline lead batch `target = predictedDisplayTime + K*predictedDisplayPeriod`, `K=0..3`, preserving exact ticket identity.
3. Reserve: coherent last-good complete stereo pair with the exact pose/FOV that produced it. Never relabel old pixels with a new pose.

### Parked HEAD gate
HEAD research is prepared but blocked behind PosePair:
- `G * HMDrelative` rotation-first on one real center CCamera, coherent frustum, upstream of visibility;
- `yawOnly(G) * HMDrelative` if body/game pitch contamination appears;
- `HMDrelative * G` only as multiplication-order control;
- future center-pose refinement: `XR_REFERENCE_SPACE_TYPE_VIEW` at the same target display time;
- translation blocked until rotation visually passes.

### Coordinate-basis conflict
Do **not** treat either local-X sign as final truth yet.

Historical `RESULT 20260817_003329` measured 1722 complete pairs and reported median dot(`stock R-L`,`exact R-L`) `-0.9999997`, leading to `XR x -> Cry -x`.

Independent later evidence points the other way: retail `ProcessScene` has exact LEFT/RIGHT return landmarks, its LEFT eye path constructs a negative local-X offset, Cry stereo source semantics are LEFT `-halfIPD` / RIGHT `+halfIPD`, and v10 frame-contract code used `XR (x,y,z) -> Cry (+x,-z,+y)`.

This is an explicit evidence conflict, not a settled PROVEN fact. Resolve COLD from the exact `003329` writer/classifier or the remaining retail eye-transform helper before final HEAD/eye position work. Do not spend a LIVE on it while P6 is current gate. See `research/COORDINATE_BASIS_CONFLICT_20260824.md`.

### Parked WEAPON / NEAR gate
- historical controller->visual weapon motion is proven;
- historical gameplay aim servo + trigger is a working fallback donor;
- primary future rigid candidate: `GripBind = inverse(C_bind) * W_bind`; `W_now = C_now * GripBind`;
- fixed bind only, no automatic grip rebind;
- same controller contract for both eyes;
- keep weapon pose separate from per-eye NEAR projection;
- if renderer shim cannot pass, move upstream to real FP weapon entity between `UpdateFPPosition` and `UpdateFPCharacter`.

Unclosed exact retail GameDll targets:
- `CPlayer::PostUpdateView`
- `CItem::UpdateFPPosition`
- `CItem::UpdateFPCharacter`
- `CWeapon::SetFiringLocator`
- fire-mode `GetProbableHit/GetFiringPos/GetFiringDir`

## METHOD ALREADY USED
- source/SDK/PDB/RTTI/donor corpus harvest
- RenderDoc/GPU projection and constant-buffer provenance
- Ghidra/source-to-retail mapping
- retail `ProcessScene` decompile / callsite closure
- runtime loaded-memory disassembly and raw stack propagation
- x86 proxy / x64 OpenXR host split
- keyed-mutex shared textures
- immutable frame contract / seqlock publication / exact pair identity
- serial causal timing P4/P5
- historical controller->NEAR and controller->gameplay-aim bridges
- targeted TTD/ReClass only for concrete writer/field questions

Do not build another broad analyzer after a concrete target exists.

## IMPORTANT PATHS / VERSIONS / DEPENDENCIES
- Retail: `C:\GOG Games\Crysis 2`, GOG retail `1.9.0.0`, 32-bit DX11
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)\_r\crysis2(5620)\_01_13`
- Shared tools: `C:\GOG Games\VR Research Tools`
- Architecture: x86 in-process game/proxy + x64 OpenXR host
- Quest/OpenXR through the project's Meta/Oculus OpenXR runtime
- Beta `CryGameCrysis2.pdb` observed size `82,045,952` bytes
- older broad symbol census stopped at `80,000` hits; missing weapon symbols there are not negative evidence

Retail hashes:
- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## UNRESOLVED QUESTIONS
1. P6 visual/telemetry verdict.
2. Pipeline lead after exact identity.
3. Exact cause of the `003329` vs retail/v10 local-X sign conflict.
4. HEAD visual 1:1 composition and true VIEW-space center pose.
5. Weapon fixed-bind SE(3) vs upstream entity seam.
6. Exact retail weapon function mapping.
7. Temporal-history isolation.
8. Precise second-eye shadow policy.
