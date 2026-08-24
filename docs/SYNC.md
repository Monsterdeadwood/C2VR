# Crysis 2 VR — STATE SYNC

## LATEST RESULT
`v17.2.5 WAIT45` on PosePair / projection-layer cadence:
- exact consumes `269`
- host submits `269`
- misses `53`
- exact ratio `83.5404%`
- stale-pair drains `31`
- last observed wait `31 ms`, max observed pair wait `47 ms`
- completed/copies `354/354`
- headset flashes/dropouts still remained

P4 baseline before WAIT45:
- exact consumes `92`
- misses `776`
- stale drains `386`
- exact ratio about `10.6%`

The single timing change from P4 to P5 raised exact acceptance to `83.5404%`, proving the bounded wait/deadline is a causal contributor to zero-layer drops.

Prepared but still untested LIVE finalist:
`v17.2.6 EXACT_BLOCK120 P6`
- only runtime policy delta vs P5: exact-pair watchdog ceiling `45 -> 120 ms`
- no game-side camera/FOV/weapon/shadow/temporal/RC33 changes
- static validation `130/130 PASS`
- independent validation `98/98 PASS`
- package: `CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

## BEST WORKING BUILD
Main renderer parent: `CUSTOM_DUAL_T1 v1.0.1`.

Historical accepted facts:
- center HMD inject/restore `2296/2296`
- private LEFT passes `2295`
- private RIGHT passes `2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- sampled median L/R MAE `35.9781`
- true private retail L/R rendering is PROVEN

Do not rebuild stereo.

## PROVEN
- Stereo primitive is solved; PosePair timing/identity is the active problem.
- One prepared render-list may execute twice; no second top-level `RenderWorld` / `EF_StartEf`.
- Exact eye transaction and RT command marshalling are known.
- `RC_RenderScene` cmd `0x33` snapshots eye-specific `SThreadInfo`; render-thread `RT_RenderScene` consumes it.
- Applying HMD at every `Renderer::SetCamera` causes cumulative feedback and is forbidden.
- `FOB_NEAREST` is a separate near/camera-space family.
- Historical controller->visual weapon motion is real.
- Historical gameplay aim servo + trigger provided working controller-directed firing behavior.
- Projection mismatch can visually masquerade as weapon counter-motion; v10 removed that symptom without solving a new gameplay owner.
- P5 proves exact-pair wait budget materially controls projection-layer availability.
- A completed game-side pair is not cross-process-visible until the Present publication gate copies/publishes it.
- `xrEndFrame` frame count is not the same thing as visible projection-layer submit count; `layerCount=0` can occur while the XR session continues.
- A fresh game render is not intrinsically required for every XR submit; a coherent cached last-good complete stereo pair with its original pose/FOV is architecturally valid as a separate fallback policy.
- Historical v6.0.0/v6.0.1 proved that pixels and render metadata must be published atomically: metadata before mutex release, barrier, then release; otherwise frame N pixels can be paired with frame N-1 pose/FOV.
- Historical v11 measured real last-good reuse (`1276` fresh, `379` reused) at 72 Hz target; reuse itself is not equivalent to pose desync, but reuse age remains a separate release metric.

## EVIDENCE CONFLICT — OPENXR↔CRY LOCAL X SIGN
**Do not promote either sign to final HEAD truth yet.** Preserve both evidence paths.

### Path A — RESULT `20260817_003329`
`XR_EYE_CAMERA.tsv` reported `1722` complete applied L/R pairs:
- median stock CryEngine L/R separation `0.02220543`
- median exact Quest L/R separation `0.06677189`
- median dot(`stock R-L`, `exact R-L`) `-0.9999997`
- historical analysis concluded stock `R-L` aligns with `-CCamera basis column 0`
- this produced the reflected mapping `XR (x,y,z) -> Cry (-x,-z,+y)`

This numeric result is real evidence and must not be erased.

### Path B — retail/static + later working lineage
- Retail `ProcessScene` eye callsites are independently identified as LEFT SetCamera return `+0x0012412A` and RIGHT SetCamera return `+0x00124304`.
- Retail decompile shows the LEFT path building a negative local-X translation before SetCamera; helper `FUN_1006ED10` is camera-copy/assignment-like, leaving `FUN_1006F790` as the main eye-transform helper still requiring exact semantic closure.
- Cry stereo source/donor semantics use LEFT `-halfIPD`, RIGHT `+halfIPD` followed by camera-matrix local-X translation.
- `CRYSIS2VR_UNIFIED_NEAR_PROJECTION_v10.0.0_COUNCIL_RESET.zip::src/c2vr_host_client.cpp` uses the proper-rotation mapping `XR (x,y,z) -> Cry (+x,-z,+y)` for frame-contract translation.
- The v10 lineage is associated with the later visually improved `CRYSIS2VR_UNIFIED_NEAR_PROJECTION_RESULT_20260818_034749.zip` path.

### Conflict status
Current hypotheses are:
1. the exact `003329` stock-eye labeling/classifier may have been reversed at that historical logger stage; or
2. the interpretation of CCamera basis column 0 / row-column semantics was wrong even though the measured dot was correct; or
3. the later `+X` lineage compensated elsewhere and therefore cannot by itself falsify `003329`.

Later code is known to use exact return-RVA eye classification, but that does not prove the exact `003329` writer used the same classifier. The sign conflict remains OPEN. Before any future HEAD/eye-basis mutation, resolve it COLD from the exact `003329` writer/source or complete retail `FUN_1006F790` eye-transform semantics. Do not spend a LIVE on this while PosePair P6 remains the active gate.

See `research/COORDINATE_BASIS_CONFLICT_20260824.md`.

## FALSIFIED / STOPPED
- rebuilding stereo
- second high-level render
- all-SetCamera HMD mutation
- native Cry SBS as final transport
- mono RGB+depth reprojection as final renderer
- stale pixels relabelled with a new pose/current contract
- one fresh eye + one stale eye
- `camera-0x3E8 == CSystem`
- GPU CB as gameplay detector
- counters-only acceptance
- treating a global XR `-X` rule as settled fact
- treating XR `+X` as settled fact before the above conflict is closed
- random weapon-offset search before rigid-transform closure
- broad reverse while a narrower current gate exists
- repeating old broad WAVE3 cadence instrumentation unless P6 demonstrates a need for phase timestamps

## CURRENT FINALISTS
### Current gate
1. `P6 EXACT_BLOCK120` unchanged.
2. If P6 closes timeout starvation: pipeline lead `target = predictedDisplayTime + K*predictedDisplayPeriod`, minimal `K=0..3`, same exact ticket semantics.
3. Reserve: coherent last-good complete stereo pair with its own original render pose/FOV; never stale-relabel it to a new pose.

### HEAD after PosePair
- first validate/converge the existing T1 upstream center-HMD owner before new broad HEAD reverse;
- T1 already executed center HMD inject/restore `2296/2296` and union cull `2296/2296` at the RenderWorld seam `+0x005E2476`;
- `G * HMDrelative` rotation-first on immutable real center CCamera, coherent frustum, before visibility remains the first composition candidate if the existing owner needs convergence;
- `yawOnly(G) * HMDrelative` if game pitch/body contamination appears;
- `HMDrelative * G` only as order control;
- consider `XR_REFERENCE_SPACE_TYPE_VIEW` for center-head pose at the same target time;
- translation remains blocked until rotation passes visually;
- coordinate-sign conflict above must be resolved before committing final eye/head position basis.

### WEAPON / NEAR after HEAD
- fixed-bind rigid transform: `GripBind = inverse(C_bind) * W_bind`; `W_now = C_now * GripBind`.
- same controller contract for both eyes.
- no automatic grip rebind.
- keep weapon pose separate from per-eye NEAR projection.
- if renderer shim cannot pass, move upstream to real FP weapon entity between `UpdateFPPosition` and `UpdateFPCharacter`.

## CONCRETE TARGETS
Crysis2.exe:
- `CSystem::GetViewCamera +0x0006AE50`
- `CSystem::m_ViewCamera +0x3F0`
- `CSystem::Render +0x00096A40`
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- RenderWorld call seam `+0x005E2476`
- `C3DEngine::SetupCamera +0x0057A730`
- once/logical-frame main-camera SetCamera return landmark `+0x0057AC76`
- downstream landmarks `+0x00A0DD57`, `+0x00A8074B`

CryRenderD3D11.dll:
- `EF_RenderScene +0x00101270`
- `EF_Scene3D +0x00101370`
- `EF_EndEf3D +0x001019A0`
- `RT_RenderScene +0x00107370`
- `PrepareDepthMaps +0x0011D390`
- `ProcessScene +0x00123EA0`
- LEFT SetCamera return `+0x0012412A`
- LEFT `EF_Scene3D` `+0x0012413C`
- RIGHT SetCamera return `+0x00124304`
- RIGHT `EF_Scene3D` `+0x0012430F`
- Renderer SetCamera vslot `+0xB8`
- `Renderer::SetCamera +0x00148340`
- `RC_SetCamera +0x001C38F0` cmd `0x36`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`
- `RC_RenderScene +0x001C48D0` cmd `0x33`
- `FOB_NEAREST` owner region `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- NEAR restore return `+0x000FF4A3`
- near-enriched shader-camera path `+0x0007AEB0`
- late camera CB producer `+0x0006AE2A`
- temporal/previous-matrix anchor `+0x000F95A0`
- `RT_SetCameraInfo` candidate `+0x000FB2E0`
- `mfSetCamera` candidate `+0x0008AF30`

Unclosed exact retail GameDll targets:
- `CPlayer::PostUpdateView`
- `CItem::UpdateFPPosition`
- `CItem::UpdateFPCharacter`
- `CWeapon::SetFiringLocator`
- fire-mode `GetProbableHit/GetFiringPos/GetFiringDir`

## CURRENT GATE
**POSEPAIR / PROJECTION-LAYER EXACT-PAIR CADENCE GATING.**

## NEXT
Run `v17.2.6 EXACT_BLOCK120 P6` unchanged.

Interpretation:
- timeouts near zero + flashes gone => STOP increasing wait; KEEP exact architecture and ADAPT to pipeline-lead K batch.
- timeouts near zero + flashes remain => STOP timeout path; inspect presentation seam and publication/timeliness evidence.
- many timeouts remain => add passive phase timestamps contract -> RenderWorld -> RT L -> RT R -> Present publish -> host consume before any mutation.

Do not add HEAD, weapon, temporal or shadow mutations to P6. Unchanged running shadows are not P6 failure.

## METHOD ALREADY USED
- RenderDoc / GPU matrix and CB provenance
- source/SDK/PDB/donor corpus harvest
- Ghidra/source-to-retail mapping
- retail `ProcessScene` decompile / callsite closure
- runtime stack/loaded-memory propagation
- x86 proxy + x64 OpenXR host
- keyed-mutex shared texture transport
- exact immutable ticket / seqlock contract sequencing
- bounded host-wait timing experiments P4/P5
- historical packet metadata/pixel atomicity fix and last-good continuity
- historical v10/v11 fresh/reuse cadence telemetry
- historical NEAR and gameplay-aim controller bridges
- targeted TTD/ReClass only for concrete writer/field questions

## IMPORTANT PATHS / VERSION / DEPENDENCIES
- Retail GOG Crysis 2 `1.9.0.0`, 32-bit DX11: `C:\GOG Games\Crysis 2`
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)\_r\crysis2(5620)\_01_13`
- Shared tooling: `C:\GOG Games\VR Research Tools`
- architecture: x86 retail game/in-process proxy + x64 OpenXR host
- Quest/OpenXR runtime via host; exact frame timing owned on x64 side
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

Important local/project artifacts already exist and should not be regenerated blindly:
- `CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`
- `CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- `C2VR_MAINLINE_SYNC_V4_20260823.zip`
- `C2VR_HEAD_CONVERGENCE_V3_20260823.zip` (HEAD research valid, gate ordering superseded)
- `C2VR_HEAD_GITHUB_ENRICHMENT_V2_20260823.zip`
- `C2VR_HEAD_CENTRAL_CAMERA_HARVEST_20260823.zip`
- source oracle / Ghidra/PDB outputs / RenderDoc/TTD captures in project corpus

## UNRESOLVED
- P6 visual/telemetry verdict
- timely-prediction lead after exact identity
- publication ownership/timeliness if exact timeouts collapse but flashes remain
- release-safe cached-pair age/reuse bounds if last-good fallback becomes necessary
- exact cause of the `003329` vs retail/v10 X-sign conflict
- HEAD visual 1:1 composition using the existing upstream T1 owner
- true VIEW-space center-head use vs left-view-derived center
- weapon fixed-bind SE(3) vs upstream entity seam
- exact retail weapon function mapping
- temporal history isolation
- precise second-eye shadow policy

## SERIAL ORDER
`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

## BRANCH DELTA IMPORTED 2026-08-24
This sync imported the branch-specific historical packet-atomicity, last-good pacing and T1 HEAD-owner evidence without changing the active P6 gate. Detailed provenance:
- `research/POSEPAIR_PACKET_ATOMICITY_PACING_20260824.md`
- `docs/EXPERIMENTS.md`
- `docs/PROVEN.md`
- `docs/NEXT.md`

No new LIVE was performed during this sync.

## COLD / DONOR ENRICHMENT IMPORTED 2026-08-24
The following research is now part of the canonical GitHub state and may be used by future branches as candidate-generating evidence without repeating broad discovery:
- `research/PUBLIC_LINEAGE_ENRICHMENT_20260824.md` — official CryENGINE camera/stereo/culling/weapon/VR lineage and future G2/G3/G4 implications.
- `research/ARCHIVE_COMPLETENESS_20260824.md` — exact distinction between Git-preserved source, package identity, and external physical carriers; T1 carrier remains an archival gap, P6 carrier is available and identity-verified.
- `research/CRYSIS_VR_DONOR_MAPPING_20260824.md` — Crysis VR source topology for `PostUpdateView -> UpdateFPPosition -> UpdateFPCharacter`, rigid controller/weapon bind, firing-locator chain, and first-eye shadow reuse precedent.
- `research/BETA_5620_PUBLIC_CROSSCHECK_20260824.md` — independent public Crysis 2 build-5620 runtime-map anchors for beta/PDB cross-check only.
- `research/CRYSIS2_MODSDK64_DONOR_20260824.md` — Crysis 2 ModSDK x64 runtime/launcher as a closer cross-architecture donor for later function fingerprinting.

Important correction: `Crysis2Coop` is **already-held / already-processed project corpus**, not a new acquisition target. Do not redownload it. When G3 opens, perform only a targeted re-harvest of the existing Crysis2Coop/GameDLL corpus for the exact weapon and firing functions above.

These imports do not promote donor facts to retail `PROVEN` and do not change the current runtime gate. No new LIVE was performed for this COLD enrichment.
