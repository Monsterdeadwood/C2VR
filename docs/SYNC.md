# Crysis 2 VR — STATE SYNC

## LATEST RESULT
`v17.2.5 WAIT45` on PosePair / projection-layer cadence:
- exact consumes `269`
- host submits `269`
- misses `53`
- exact ratio `83.5404%`
- max observed pair wait `47 ms`
- completed/copies `354/354`
- headset flashes/dropouts still remained

The single timing change increased exact acceptance from roughly `92 exact / 776 miss` (~10.6%) to 83.54%, making the bounded wait/deadline a proven contributor to layer drops.

Prepared but still untested LIVE finalist:
`v17.2.6 EXACT_BLOCK120 P6`
- only intended policy delta: bounded exact wait ceiling `45 -> 120 ms`
- no game-side camera/FOV/weapon/shadow/temporal/RC33 changes
- static validation `130/130 PASS`
- independent validation `98/98 PASS`
- package SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

## PROVEN
- Main renderer parent: `CUSTOM_DUAL_T1 v1.0.1`.
- True private retail L/R rendering: LEFT `2295`, RIGHT `2295`, direct copies `2229`, XR submits `2624`, sampled median L/R MAE `35.9781`.
- Stereo primitive is solved; PosePair timing/identity is the active problem.
- One prepared render-list may execute twice; no second top-level `RenderWorld` / `EF_StartEf`.
- Exact eye transaction and RT command marshalling are known.
- Applying HMD at every `Renderer::SetCamera` causes cumulative feedback.
- `FOB_NEAREST` is a separate near/camera-space family.
- Historical controller->visual weapon motion is real.
- Historical gameplay aim servo + trigger provided working controller-directed firing behavior.
- Projection mismatch can visually masquerade as weapon counter-motion; v10 removed that symptom without solving a new gameplay owner.
- Proper future OpenXR->Cry basis primary is `(+x,-z,+y)`; old global `-X` reflection is not authoritative.

## FALSIFIED
- rebuilding stereo
- second high-level render
- all-SetCamera HMD mutation
- native Cry SBS as final transport
- mono RGB+depth reprojection as final renderer
- stale pixels relabelled with new pose
- `camera-0x3E8 == CSystem`
- GPU CB as gameplay detector
- counters-only acceptance
- universal XR `-X` rule
- random weapon-offset search before rigid-transform closure
- broad reverse while a narrower current gate exists

## CURRENT FINALISTS
### Current gate
1. `P6 EXACT_BLOCK120` unchanged.
2. If P6 closes identity but reveals latency: pipeline lead `target = predictedDisplayTime + K*predictedDisplayPeriod`, test minimal `K=0..3`.
3. Reserve: coherent last-good complete stereo pair with its own original render pose/FOV.

### HEAD after PosePair
- `G * HMDrelative` rotation-first on immutable real center CCamera, coherent frustum, before visibility.
- `yawOnly(G) * HMDrelative` if game pitch/body contamination appears.
- `HMDrelative * G` only as order control.
- consider `XR_REFERENCE_SPACE_TYPE_VIEW` for center-head pose at same target time.

### WEAPON / NEAR after HEAD
- fixed-bind rigid transform: `GripBind = inverse(C_bind) * W_bind`; `W_now = C_now * GripBind`.
- same controller contract for both eyes.
- no automatic grip rebind.
- keep weapon pose separate from per-eye NEAR projection.
- if renderer shim cannot pass, move upstream to real FP weapon entity between `UpdateFPPosition` and `UpdateFPCharacter`.

## CONCRETE TARGETS
Crysis2.exe:
- `m_ViewCamera +0x3F0`
- `RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- RenderWorld call seam `+0x005E2476`
- SetupCamera candidate `+0x0057A730`
- once/frame camera landmark `+0x0057AC76`

CryRenderD3D11.dll:
- NEAR owner `+0x000FF340`
- NEAR enter return `+0x000FF456`
- NEAR restore `+0x000FF4A3`
- object-owner landmark `+0x00102100`
- `EF_RenderScene ~ +0x00101270`
- `EF_Scene3D +0x00101370`
- `EF_EndEf3D +0x001019A0`
- `RT_RenderScene +0x00107370`
- `PrepareDepthMaps +0x0011D390`
- `Renderer::SetCamera +0x00148340`
- `RC_SetCamera +0x001C38F0`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`
- `RC_RenderScene +0x001C48D0`

Unclosed exact retail GameDll targets:
- `CPlayer::PostUpdateView`
- `CItem::UpdateFPPosition`
- `CItem::UpdateFPCharacter`
- `CWeapon::SetFiringLocator`
- fire-mode `GetProbableHit/GetFiringPos/GetFiringDir`

## CURRENT GATE
**POSEPAIR / PROJECTION-LAYER EXACT-PAIR CADENCE GATING.**

## NEXT
Run `v17.2.6 EXACT_BLOCK120 P6` unchanged. Judge both exact/miss timing telemetry and headset flashes/dropouts. Do not add HEAD, weapon, temporal or shadow mutations to this run.

## METHOD ALREADY USED
- RenderDoc / GPU matrix and CB provenance
- source/SDK/PDB/donor corpus harvest
- Ghidra/source-to-retail mapping
- runtime stack/loaded-memory propagation
- x86 proxy + x64 OpenXR host
- keyed mutex shared texture transport
- exact immutable ticket / contract sequencing
- bounded host wait timing experiments
- historical NEAR and gameplay-aim controller bridges
- targeted TTD/ReClass only for concrete writer/field questions

## IMPORTANT PATHS / VERSION / DEPENDENCIES
- Retail 1.9: `C:\GOG Games\Crysis 2`
- Beta 5620/source/PDB bridge: `C:\GOG Games\Crysis 2\crysis2(5620)\_r\crysis2(5620)\_01_13`
- Shared tooling: `C:\GOG Games\VR Research Tools`
- x86 retail game/in-process proxy + x64 OpenXR host
- beta `CryGameCrysis2.pdb` observed size `82,045,952` bytes
- old broad symbol census capped at `80,000` hits; absence of weapon names there is not negative evidence

Retail hashes:
- Crysis2.exe `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## EXISTING REPO TOOLS / SOURCE AUTHORITY
- `runtime/main/CUSTOM_DUAL_T1_v1.0.1/` exact parent source authority
- `runtime/donors/v17.2.1/` donor source / PosePair transplant notes
- `tools/extract_verified_custom_dual_t1_v1_0_1.py`
- `tools/extract_verified_v17_2_1.py`
- `tools/extract_verified_v17_2_1_original.py`

External/local artifacts retained in project history include P6 one-click, HEAD convergence packs, C2VR source oracle, Ghidra/PDB results, RenderDoc/TTD captures and compact RESULT ZIPs. Do not regenerate an analyzer if an existing artifact already closes its evidence lane.

## UNRESOLVED
- P6 visual/telemetry verdict
- timely-prediction lead after exact identity
- HEAD visual 1:1 composition
- weapon fixed-bind SE(3) vs upstream entity seam
- exact retail weapon function mapping
- temporal history isolation
- precise second-eye shadow policy

## SERIAL ORDER
`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`
