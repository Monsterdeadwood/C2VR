# Crysis 2 VR — FALSIFIED / STOPPED PATHS

Do not repeat these without new independent evidence.

See:
- `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
- `docs/HISTORICAL_VISUAL_ORACLES_20260815_19.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`

## ABSOLUTE EVIDENCE GUARDS

- **`RESULT ZIP == LIVE` assumption** — FALSIFIED. A result archive may contain only build/preflight failure. It is not runtime/visual evidence unless the claimed target code actually executed.
- **`CRYSIS2VR_C2_NATIVE_RESULT_20260816_010051.zip` as WORLDLOCK evidence** — FALSIFIED. Exact physical result contains only build failure: Zig self-test failed, `GameFilesTouched=False`. No Crysis/OpenXR world-lock test occurred.
- **`CRYSIS2VR_C2_NATIVE_RESULT_20260816_011323.zip` as cleanroom visual evidence** — FALSIFIED. Exact physical result is an OpenXR-loader/preflight failure with `GameFilesTouched=False`. No visual conclusion is permitted.
- **Old `EVIDENCE/GOLD` / `MAIN_PROVEN_XR` classification for `194212` as visual GOLD** — FALSIFIED. `194212` is strong XR transport evidence, but recorded `CameraLock=False`, `CameraInject=False`, `HORIZON_WORLD_LOCK=No`, user sees flat image.
- **Package intent as PASS** — FALSIFIED. `v1.0.5 WORLDLOCK_DIRECT_CAMERA` physically exists, but its first result never executed the experiment; v1.0.5.1 only fixed Zig/toolchain discovery; v1.0.6 was observability. Do not remember this family as a user-accepted world-lock checkpoint without a real bound LIVE.
- **`GOLD`, `CLEAN`, `MAIN`, `NO_BINOCULAR`, `GREEN`, or source-authority naming as evidence** — rejected. User headset verdict + captures + raw LIVE evidence outrank names.
- **Counters alone as visual proof** — rejected.
- **Guessing an old package/result binding from timestamp adjacency** — STOP. Mark `UNBOUND` or family-bound until exact identity is recovered.

## USER VISUAL HARD-RED GUARD

- **`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip` as visual parent** — HARD STOP. SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`. User reported it visually worse than the already rejected predecessor. No K1/K2/HEAD/weapon/temporal/shadow descendants.
- **`C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage as visual parent** — HARD STOP. Pair transport alive, but catastrophic camera/world instability and moving/sliding light/shadow state in headset.
- **Native/NVIDIA/monitor stereo as final renderer** — HARD STOP. Explicitly rejected by user after repeated flicker/two-image behavior.
- **Native stereo + real Quest IPD/XrView FOV as final shortcut** — HARD STOP. `205430` produced wrong stereo, flicker, disappearing/changing shadows and per-eye render-state disagreement.
- **STABLE_CAMERA v2.2.0 as proof that one world-camera owner solves renderer** — FALSIFIED visually. `010329` still flickered and weapon motion did not establish correct firing ownership.
- **All-SetCamera HMD injection** — HARD STOP. `171947` proved recursive feedback `G -> G*HMD -> G*HMD^2...`, eye collapse and camera accumulation.
- **`CRYSIS2VR_REWRITE_v4.0.0_EXACT_XR_STEREO_GOLD_WEAPON_PORTABLE.zip` as visual GOLD** — HARD STOP. `023510` received immediate user rejection for both image and hand behavior.
- **`A1_HISTORY_FIX_RESULT_20260817_175934` surrounding renderer as parent** — HARD STOP. Preserve only controller-to-fire-direction behavior; the two-image flickering Nvidia/Cry renderer was explicitly rejected.
- **v11/v12 telescope/binocular family as baseline** — HARD STOP. Severe binocular/telescope geometry and misalignment were explicitly rejected.
- **`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip` as visual parent** — HARD STOP. SHA256 `A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`; headset completely black.
- **`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.3_LAZY_GATE_HOTFIX.zip` as visual parent** — HARD STOP. Headset still completely black.

## EARLY / SEMANTIC FAILURES

- **Mouse-look / SendInput as final VR HEAD camera** — FALSIFIED. No true roll/6DoF and it mixes head/body/aim ownership.
- **Black headset + alive monitor/game as VR proof** — FALSIFIED. Early MVP brought up session/input while headset was black.
- **Two eye textures/two different images as VR acceptance** — FALSIFIED. “Two screens in two eyes” with no world-lock is not VR.
- **Submitting current HMD pose for pixels not rendered from current HMD pose** — HARD STOP. This creates invalid compositor semantics / screen-glued behavior. Pixels + render pose + FOV + ticket are atomic.
- **Old pixels relabelled with newer/current pose** — HARD STOP generally. Last-good reuse must retain original render metadata.
- **One fresh eye + one stale eye** — invalid stereo submission.
- **Eye-axis dot + asymmetric-FOV numeric match as binocular-fusion proof** — rejected. Headset fusion is mandatory.
- **Exact IPD/FOV/pose math as renderer visual PASS** — rejected. `203734/204156` proved excellent math while saved captures showed exact-eye projection/NEAR/culling policy visually broken.

## `203734/204156` SPECIFIC CORRECTION

KEEP only:
- HMD pose propagation;
- IPD/FOV math;
- within-run control showing `camera_locked=0` normal versus `camera_locked=1` broken.

STOP inheriting:
- world-eye asymmetric projection unchanged into `FOB_NEAREST` near plane;
- old narrow center-frustum visibility before wide Quest eye views;
- surrounding exact-eye visual renderer.

Recovered mechanism:
- ordinary world near roughly `0.12`;
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
- **Treat raw Present as logical game frame** — falsified by historical cadence evidence.
- **P3 latest-pair stale submit/relabel** — falsified by pose/contract mismatches and severe jitter/blur/one-eye asymmetry.
- **SHDF_ZPASS_ONLY as normal RIGHT-eye shadow policy** — falsified because it suppresses normal scene body too.
- **Wholesale v17.2 integration** — STOP; mixes too many policies to preserve causality.

## CAMERA / WEAPON / REVERSE STOPS

- **Fake/partial CCamera as authoritative camera object** — unsafe; use real full CCamera or fully verified lifetime/layout.
- **GPU constant-buffer hits as gameplay detector** — rejected.
- **Downstream GPU/CB camera mutation as final gameplay-camera ownership** — STOP. Useful as diagnostic/verifier only; CPU culling/shadows/sky/NEAR/gameplay may already have consumed a different camera.
- **`camera-0x3E8 == CSystem`** — falsified.
- **Universal XR +X -> Cry -X as settled global truth** — STOP; evidence conflict remains.
- **Universal XR +X -> Cry +X as settled global truth** — also STOP until conflict closes.
- **Random weapon XYZ/muzzle grids before rigid-transform closure** — STOP.
- **Head position as final weapon rotation pivot** — STOP.
- **Independent position/rotation correction as assumed final weapon SE(3)** — STOP; prefer one rigid bind transform.
- **Automatic grip-edge rebaseline as default weapon policy** — STOP; can create snaps.
- **AIM-vs-GRIP pose-family hunt** — STOP unless new evidence appears.
- **Gameplay ballistics work before visual camera/stereo baseline** — STOP. Preserve historical controller-directed firing only as a donor fact.
- **Broad weapon reverse now** — STOP.
- **Broad HEAD archaeology now** — STOP while visual baseline recovery is active.
- **Temporal/shadow mutation now** — STOP until stable visual baseline exists.
- **Broad symbol/corpus census for weapon functions** — STOP; later use narrow source/PDB->retail bridge only.
- **Cadence K work now** — STOP after current user HARD REDs; timing cannot repair a visually wrong parent.
- **Increasing wait beyond P6 as a visual fix** — STOP.
- **Full GPU fence/synchronous wait as first overwrite fix** — STOP absent direct evidence.
- **Double/triple/ring-buffering engine eye RTs before publication ownership closure** — STOP.

## IMPORTANT PARTIAL GREENS — DO NOT LOSE THEM

### Exact physical v6.0.1 world-stability baseline

Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact runner lineage exists inside the recovered archive:

`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user state:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`WORLD_STABILITY_NO_FLICKER_REFERENCE = GREEN`
`BINOCULAR_STEREO = FAIL`.

Do not invent a new runner when reproducing it.

### Historical last-good native single-window behavior profile

Recorded desired recovery properties:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- visible headset image;
- only hand/weapon visibly wrong.

Exact package/hash remains OPEN. Do not guess.

## STOCK NATIVE STEREO CAVEAT

Clean stock Crysis 2 native 65mm SBS itself showed strong RIGHT-eye softness in RenderDoc:
- `555666.rdc`;
- approximate LEFT sharpness `328`, RIGHT `162`;
- no OpenXR/C2VR/camera injection.

`r_MotionBlur=0` did not remove it.
`r_SSAO=0` did not remove it.

Therefore:
- later right-eye blur can still be a user visual failure;
- but do not automatically assign its entire cause to XR transport without stock-control comparison.

Historical provenance lives in:
- `docs/HISTORICAL_VISUAL_ORACLES_20260815_19.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
- `research/COORDINATE_BASIS_CONFLICT_20260824.md`
- `research/POSEPAIR_PUBLICATION_OWNERSHIP_20260824.md`
