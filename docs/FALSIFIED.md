# Crysis 2 VR — FALSIFIED / STOPPED PATHS

Do not repeat these without new independent evidence.

Read together with:
- `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
- `docs/HISTORICAL_VISUAL_ORACLES_20260815_19.md`
- `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`

## ABSOLUTE EVIDENCE GUARDS

- **`RESULT ZIP == LIVE` assumption** — FALSIFIED. A result archive may contain only build/preflight failure. Runtime/visual evidence requires the claimed target path to execute.
- **`CRYSIS2VR_C2_NATIVE_RESULT_20260816_010051.zip` as WORLDLOCK evidence** — FALSIFIED. Zig self-test failed; `GameFilesTouched=False`; no Crysis/OpenXR world-lock LIVE occurred.
- **`CRYSIS2VR_C2_NATIVE_RESULT_20260816_011323.zip` as cleanroom visual evidence** — FALSIFIED. OpenXR-loader preflight failed; `GameFilesTouched=False`; no visual conclusion permitted.
- **Old `EVIDENCE/GOLD` / `MAIN_PROVEN_XR` classification for `194212` as visual GOLD** — FALSIFIED. XR transport was real, but `CameraLock=False`, `CameraInject=False`, `HORIZON_WORLD_LOCK=No`, user saw a flat image.
- **Package intent as PASS** — FALSIFIED. v1.0.5 WORLDLOCK physically exists, but its first result never executed the experiment; v1.0.5.1 fixed Zig discovery; v1.0.6 added observability.
- **Bare `GREEN` as a historical status** — FORBIDDEN. Qualify it as `MECHANICAL_GREEN`, `COMPONENT_VISUAL_GREEN`, or `FULL_USER_VISUAL_GREEN`.
- **Package names containing `GOLD`, `GOLDEN`, `GREEN`, `CLEAN`, `MAIN`, `PROVEN`, `WORKING`, `SAFE_VISUAL`, `NO_BINOCULAR`, `ONE_WINDOW`, `LIVE_BACKBUFFER_GREEN`, `EXACT`, or `FINAL` as acceptance evidence** — REJECTED.
- **Counters alone as visual proof** — REJECTED.
- **Guessing package/result identity from timestamp adjacency** — STOP. Use `OPEN`, `UNBOUND`, or family-bound classification.
- **`VACUOUS_PASS`** — INVALID. A PASS with missing/zero/None prerequisite evidence has no evidentiary value. If the target path did not execute or required samples are absent, the analyzer must return `NA/NOT_EXECUTED` or FAIL, never PASS.
- **Overall PASS assembled from vacuous child PASSes** — INVALID.

Known vacuous historical patterns include PASS-like output with:
- `FramePoseIntegrity` fed `None/None/None`;
- RightTouch/hand visual contract with zero observations;
- empty no-fault fields when the target path never ran.

## USER VISUAL HARD-RED GUARD

- **`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip` as visual parent** — HARD STOP. SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`. User reported it visually worse than the already rejected predecessor. No K1/K2/HEAD/weapon/temporal/shadow descendants.
- **`C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage as visual parent** — HARD STOP. Pair transport alive, but catastrophic camera/world instability and moving/sliding light/shadow state in headset.
- **Native/NVIDIA/monitor stereo as final renderer** — HARD STOP. Explicit user rejection after repeated flicker/two-image behavior.
- **Native stereo + real Quest IPD/XrView FOV as final shortcut** — HARD STOP. `205430` produced wrong stereo, flicker, disappearing/changing shadows and eye-dependent state disagreement.
- **STABLE_CAMERA v2.2.0 as proof that one world-camera owner fixes the renderer** — FALSIFIED visually. `010329` still flickered and weapon motion did not establish firing ownership.
- **All-SetCamera HMD injection** — HARD STOP. `171947` proved recursive `G -> G*HMD -> G*HMD^2...` feedback, eye collapse and camera accumulation.
- **`CRYSIS2VR_REWRITE_v4.0.0_EXACT_XR_STEREO_GOLD_WEAPON_PORTABLE.zip` as visual GOLD** — HARD STOP. `023510` received immediate user rejection for image and hand behavior.
- **`A1_HISTORY_FIX_RESULT_20260817_175934` surrounding renderer as parent** — HARD STOP. Preserve only controller-to-fire direction; flickering Nvidia/Cry renderer was explicitly rejected.
- **Z-reprojection v6.1 `201832` as a good v6.1 renderer** — HARD STOP. User reported no meaningful improvement, weapon counter-motion under head turn and severe blur. Do not confuse it with the separate v6.1 A/FUSION compositor control.
- **v11/v12 telescope/binocular family as baseline** — HARD STOP. User rejected telescope/binocular geometry and severe misalignment. Exact package binding remains OPEN; do not guess an exception.
- **`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip` as visual parent** — HARD STOP. SHA256 `A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`; user reported completely black headset.
- **`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.3_LAZY_GATE_HOTFIX.zip` as visual parent** — HARD STOP. Headset still black.

## VISUAL-NAME / STRUCTURAL-PASS CORRECTIONS

- **v6.1 A/FUSION_PROOF_QUAD as real stereo** — FALSIFIED. It is a 2D compositor/fusion control only. Later quality review rejects it as a visual-success renderer.
- **Z-reprojection v6.2/v6.3/v6.4 as accepted because they are real LIVE** — FORBIDDEN. Runtime execution is proven; direct user visual verdicts remain UNBOUND.
- **v7.0.2 `CLEAN_NATIVE_EYES / 001036` as the historical good single-window baseline** — NOT PROVEN. Technical source-size transport is KEEP; visual identity remains UNBOUND.
- **v8/v9 as whole-build stereo solution** — REJECTED. Preserve only narrow union/culling/depth/postprocess evidence.
- **v10 `034749` as whole-build GOLD** — NOT PROVEN. Structural/mechanical checks are strong; primary arbiter explicitly stopped at `READY_FOR_VISUAL_TEST`. Later user-improvement attribution is secondary-bound, not enough for `FULL_USER_VISUAL_GREEN`.
- **v10.2 `ZERO_NATIVE_ONE_WINDOW / 020117` as accepted because the package says ONE_WINDOW** — REJECTED. It is a genuine LIVE with user visual verdict currently UNBOUND.
- **v11 CADENCE_FASTPATH as visual GREEN** — REJECTED. Its own arbiter says `STRUCTURAL_ARBITER=REJECT_DO_NOT_CALL_FIXED` and `VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.
- **v13 / v13.1 as accepted visual builds** — NOT PROVEN. Both have genuine runtime evidence; direct user headset verdict remains UNBOUND.
- **v15.1 `NO_BINOCULAR` as proof binocular problem was solved** — HARD STOP. Game-side dual-scene/eye-axis/FOV mechanics ran, but host status explicitly had `visual_projection_layers=0` and `submitted_frames=0`; associated analyzer said `VISUAL_LAYER_SUBMITTED=NO`. Classification is `MECHANICAL_GREEN / VISUAL_NOT_TESTED`.
- **Eye-axis dot + tiny asymmetric-FOV error as binocular-fusion proof** — REJECTED generally.

## EARLY / SEMANTIC FAILURES

- **Mouse-look / SendInput as final VR HEAD camera** — FALSIFIED. No true roll/6DoF and mixes head/body/aim ownership.
- **Black headset + alive monitor/game as VR proof** — FALSIFIED.
- **Two eye textures/two different images as VR acceptance** — FALSIFIED. “Two screens in two eyes” with no world lock is not VR.
- **Submitting current HMD pose for pixels not rendered from current HMD pose** — HARD STOP. Pixels + render pose + FOV + ticket are atomic.
- **Old pixels relabelled with newer/current pose** — HARD STOP. Last-good reuse must retain original render metadata.
- **One fresh eye + one stale eye** — INVALID stereo submission.
- **Exact IPD/FOV/pose math as renderer visual PASS** — REJECTED. `203734/204156` proved good math while saved captures showed exact-eye/NEAR/culling policy visually broken.

## `203734/204156` SPECIFIC CORRECTION

KEEP only:
- HMD pose propagation;
- IPD/FOV math;
- within-run `camera_locked=0` normal versus `camera_locked=1` broken control.

STOP inheriting:
- world-eye asymmetric projection unchanged into `FOB_NEAREST` near plane;
- old narrow center-frustum visibility before wide Quest eye views;
- surrounding exact-eye visual renderer.

Recovered mechanism:
- world near roughly `0.12`;
- NEAR near roughly `0.03`;
- reusing world asymmetry at NEAR amplified off-axis effect roughly 4x;
- old center visibility caused culling/popping under wider eye frusta.

## RENDER / SCHEDULING DEAD ENDS

- **Rebuild stereo from scratch** — STOP. `CUSTOM_DUAL_T1 v1.0.1` proves true private retail L/R as a technical primitive.
- **Second top-level RenderWorld / second EF_StartEf** — forbidden. Use one prepared render-list with private eye executions.
- **Standalone RC_SetCamera mutation as final eye ownership** — later RT state can supersede it.
- **Native Cry SBS / DisplayStereo / CopyToStereo as final VR transport** — rejected.
- **High-level duplicate DualWorld as preferred final scheduler** — rejected by black-headset lineage and later renderer closure.
- **Mono RGB+depth/Z reprojection as final renderer** — visually/architecturally falsified.
- **Present as authoritative eye owner** — falsified. Historical logical eye scheduling did not survive Present 1:1 (`417/417` planned vs roughly `396/264` captured in one control).
- **Global/main-thread active-eye as FOB_NEAREST owner** — falsified by balanced render-thread owner truth.
- **`near_left=55 / near_right=6634` as true asymmetry** — falsified; balanced near ownership later measured around `5148/5161` at dominant `+0x000FF456`.
- **Calling FOB_NEAREST OWNER TRUTH visually successful** — forbidden. Owner evidence KEEP, visual build rejected.
- **Calling NATIVE_NEAR_PASSTHROUGH a visual baseline because reverse-control counters passed** — forbidden.
- **Unsafe CopyResource/Flush from old RC callback** — HARD STOP. `181936` reached first pair then crashed `0xC0000005` after RC copy #3 and copied near-black data.
- **Treat raw Present as logical game frame** — falsified by cadence evidence.
- **P3 latest-pair stale submit/relabel** — falsified by pose/contract mismatches and severe jitter/blur/one-eye asymmetry.
- **SHDF_ZPASS_ONLY as normal RIGHT-eye shadow policy** — falsified because it suppresses normal scene body too.
- **Wholesale v17.2 integration** — STOP; mixes too many policies for causal attribution.

## CAMERA / WEAPON / REVERSE STOPS

- **Fake/partial CCamera as authoritative camera object** — unsafe.
- **GPU constant-buffer hits as gameplay detector** — rejected.
- **Downstream GPU/CB camera mutation as final gameplay-camera ownership** — STOP. Useful as diagnostic only; CPU culling/shadows/sky/NEAR/gameplay may have consumed another camera.
- **`camera-0x3E8 == CSystem`** — falsified.
- **Universal XR +X -> Cry -X as settled global truth** — STOP; evidence conflict remains.
- **Universal XR +X -> Cry +X as settled global truth** — also STOP until conflict closes.
- **Random weapon XYZ/muzzle grids before rigid-transform closure** — STOP.
- **Head position as final weapon rotation pivot** — STOP.
- **Independent position/rotation correction as assumed final weapon SE(3)** — STOP; prefer one rigid bind transform.
- **Automatic grip-edge rebaseline as default weapon policy** — STOP; can create snaps.
- **AIM-vs-GRIP pose-family hunt** — STOP unless new evidence appears.
- **Gameplay ballistics before visual camera/stereo baseline** — STOP. Preserve controller-directed firing only as donor fact.
- **Broad weapon reverse now** — STOP.
- **Broad HEAD archaeology now** — STOP while visual baseline recovery is active.
- **Temporal/shadow mutation now** — STOP until stable visual baseline exists.
- **Broad symbol/corpus census for weapon functions** — STOP.
- **Cadence K work now** — STOP after current visual HARD REDs; timing cannot repair a broken visual parent.
- **Increasing wait beyond P6 as a visual fix** — STOP.
- **Full GPU fence/synchronous wait as first overwrite fix** — STOP absent direct evidence.
- **Double/triple/ring-buffering engine eye RTs before publication ownership closure** — STOP.

## IMPORTANT PARTIAL GREENS — DO NOT LOSE THEM

### Exact physical v6.0.1 world-stability anchor

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Runner lineage:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user state:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`
`BINOCULAR_FUSION = FAIL`.

### A1 camera checkpoint

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user-positive property:
head movement drove the in-game camera/world; old stereo still flickered/two-screen.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

### Historical last-good native single-window behavior profile

Recorded properties:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- visible headset image;
- only hand/weapon visibly wrong.

Exact package/hash remains OPEN. Do not guess.

### True private L/R technical primitive

`CUSTOM_DUAL_T1 v1.0.1 / 212003` remains `MECHANICAL_GREEN`, not visual parent authority.

## STOCK NATIVE STEREO CAVEAT

Clean stock Crysis 2 native 65mm SBS showed strong RIGHT-eye softness in RenderDoc:
- `555666.rdc`;
- approximate LEFT sharpness `328`, RIGHT `162`;
- no OpenXR/C2VR/camera injection.

`r_MotionBlur=0` did not remove it.
`r_SSAO=0` did not remove it.

Therefore later RIGHT blur remains a visual defect, but its full cause must not be assigned to XR transport without stock comparison.

## OPEN ITEMS MUST REMAIN OPEN

Do not fill by inference:
1. exact package/hash behind the 18–19 Aug last-good native single-window behavior profile;
2. direct user verdicts for Z-reprojection v6.2/v6.3/v6.4;
3. direct primary user message for v10 `034749`;
4. direct user verdict for v7.0.2 `001036`;
5. direct user verdicts for v13/v13.1;
6. exact raw result binding for v14 black-headset reports;
7. exact package binding inside v11/v12 binocular/telescope family.

An honest OPEN is safer than a false GOLD.
