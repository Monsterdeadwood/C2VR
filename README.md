# Crysis 2 VR

Native VR integration research for **Crysis 2 retail 1.9 / CryEngine DX11**.

## CURRENT STATUS - 220427 LIVE / VISUAL VERDICT GATE

**WORKING BUILD FIRST. USER VISUAL VERDICT FIRST.**

Current gate:

`220427 V6.0.1 LIVE -> BIND USER HEADSET VERDICT -> VISUAL BASELINE DECISION`

The recovered historical Z-reprojection v6.0.1 PRIVATE_RTV path is no longer PREPARED/UNRUN. It executed on 2026-08-25 and produced real Quest submissions.

Read first:
1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
3. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
4. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
5. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
6. `docs/FALSIFIED.md`
7. `docs/STATE.md`
8. `docs/NEXT.md`
9. `docs/SYNC.md`

The project is NOT currently in cadence K, final HEAD, weapon/NEAR, temporal or shadow integration.

## LATEST LIVE — Z-REPROJECTION v6.0.1 / 220427

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Raw result proves:
- XR session ran;
- `submit_count=4691`;
- `ever_submitted=1`;
- both private eye staging targets became ready;
- `eye_stage_copies=9382`;
- `reproject_draws=9382`;
- 33 XR stereo pair captures were recorded;
- raw restore says PASS.

The old v6.0.0 `XR_RTV_CREATE_FAIL eye=0 image=0 hr=0x80070057` blocker is therefore mechanically closed.

Actual headset source was still:

`CENTER RGB + inverse depth -> synthetic LEFT/RIGHT depth reprojection -> private eye RT -> XR swapchains`.

So this is:

```text
MECHANICAL_GREEN: PRIVATE_RTV_XR_BRIDGE
MECHANICAL_GREEN: MONO_DEPTH_SYNTHETIC_LR_OUTPUT
TRUE_PRIVATE_LR_SCENE_RENDER = NO
USER_HEADSET_VERDICT = UNBOUND
FULL_USER_VISUAL_GREEN = NO
```

Mono RGB+depth/Z reprojection remains a control/transport path, not the assumed final renderer.

The generated verdict file contains false-negative summary fields (`OpenXRTransport=FAIL`, `eyeStageCopies=0`, `Restore=FAIL`) contradicted by raw logs/status. Do not use `PRIMARY_RESULT=PIPELINE_INCOMPLETE` to erase the executed runtime facts.

## EVIDENCE LAW

For visual/playability acceptance:

`USER_HEADSET_VERDICT > XR/LR captures > raw LIVE RESULT/status > counters > generated analyzer summary > static validation > design intent`

Permanent guards:
- `RESULT ZIP != LIVE`;
- a broken analyzer summary also does not erase a proven LIVE;
- package names such as GOLD/GREEN/CLEAN/NO_BINOCULAR/ONE_WINDOW are not acceptance evidence;
- bare `GREEN` is forbidden, qualify the exact property;
- `VACUOUS_PASS` with missing/zero/None prerequisites is invalid;
- an unresolved historical binding stays OPEN/UNBOUND rather than being guessed.

## CURRENT USER VISUAL HARD REDS

### `063149`
`C2VR_RC33_V1721_RESULT_20260825_063149.zip`

Pair transport was alive, but user reported catastrophic camera/world instability and moving/sliding light/shadow state.

`VISUAL_RED`.

### T1 PosePair K0
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`.

User reported it visually even worse.

`VISUAL_RED / RESULT_ZIP_NOT_BOUND`.

### R2 visible matrix `201208`
Fresh user verdict was binocular/telescope catastrophe despite strong counters.

`VISUAL_RED`.

### GOODLINE v1.0.0
`CRYSIS2VR_GOODLINE_NATIVE_SINGLE_WINDOW_v1.0.0_ONECLICK.zip`

SHA256:
`566BBBA4C9889DDD5B1F4974DF32330845EEE2F772B7EFD0469A9AF3DEFD07DA`.

User reported broken/unstable shadows and a blurred RIGHT eye.

`USER_VISUAL_HARD_RED`.

Therefore:
- no K1/K2 descendant;
- no final HEAD descendant from rejected visual parents;
- no weapon/NEAR descendant from rejected visual parents;
- no temporal/shadow descendant from rejected visual parents;
- no more watchdog/IPD/FOV tuning as a substitute for a good visual parent.

## CORRECTED P6 STATUS

P6 is not an untested finalist.

Package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`.

It was executed as:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`.

Observed:
- host contract publication alive;
- zero exact hits/consumes/submits;
- zero eye pairs queued/completed;
- game RenderWorld/scene activity alive;
- fault `NO_LATCHED_RENDER_CONTRACT`;
- restore/hash PASS.

Classification:
`LIVE_RUNTIME_RED_BEFORE_PAIR_PRODUCTION`.

## EXACT RECOVERED WORLD-STABILITY BASELINE

Physical package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

- bytes `164221`
- SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`

Exact historical runner:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did NOT fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

This is not final stereo.

## CAMERA OWNERSHIP REFERENCE

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user-positive property:
head left/right drove the real in-game camera/world; main remaining issue was flicker/two-screen behavior.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

Single-source topology:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

HMD x1 at `Crysis2.exe+0x0057AC76`; downstream SetCamera pass-through.

## TRUE PRIVATE L/R TECHNICAL AUTHORITY

`CUSTOM_DUAL_T1 v1.0.1`
Canonical result:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

Proves genuine private LEFT/RIGHT retail render execution.

Classification:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

Do not rebuild stereo, but do not call T1 a whole-build visual parent either.

## IMPORTANT HISTORICAL CORRECTIONS

- `194212`: real XR transport, but flat/non-world-locked image. Technical only.
- `010051`: NOT_LIVE Zig build failure.
- `011323`: NOT_LIVE OpenXR-loader preflight failure.
- v6.1 A/FUSION: compositor 2D control only.
- v6.1 Z `201832`: direct user VISUAL RED with blur and weapon counter-motion.
- Z v6.2/v6.3/v6.4: real LIVE, user verdicts currently UNBOUND.
- v7.0.2 `001036`: real technical source-size transport, visual verdict UNBOUND.
- v10 `034749`: strong structural/mechanical result; whole-build visual GREEN not primary-proven.
- v10.2 `020117`: genuine LIVE, visual verdict UNBOUND.
- v11 CADENCE_FASTPATH: own arbiter says REJECT_DO_NOT_CALL_FIXED.
- v13/v13.1: genuine LIVE, visual verdicts UNBOUND.
- v14 DualWorld: package/family black-headset VISUAL RED.
- v15.1 `NO_BINOCULAR`: dual-scene mechanics ran, but visual projection layers/submitted frames were zero. Visual result was not tested.

## HISTORICAL SINGLE-WINDOW TARGET

18-19 Aug user oracle records a useful behavior profile:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- only hand/weapon visibly wrong.

Exact package/hash remains OPEN.

Do not guess it from v7/v10 names and do not invent an old mythical build containing every later independent success.

## NEXT

**No new renderer build before the direct user headset verdict for 220427 is bound.**

If 220427 is visually accepted enough to serve as a control:
1. freeze its exact private-RTV XR bridge;
2. freeze the accepted world/camera properties;
3. next isolate true-L/R/source geometry as one mutation category;
4. do not simultaneously touch HEAD, weapon, NEAR, temporal, shadow or cadence.

If 220427 is visually rejected:
1. mark v6.0.1 whole visual path `VISUAL_RED`;
2. salvage only `PRIVATE_RTV_XR_BRIDGE`;
3. continue exact recovery of the historical accepted single-window package identity;
4. do not jump automatically to later Z versions or rejected GOODLINE/R2/T1/v17 parents.

Do not resume cadence K until a whole visual candidate is explicitly accepted again in headset.

## CANONICAL RENDERER FACTS THAT REMAIN USEFUL

One prepared render-list may execute twice for the two eyes. Do not add a second high-level `RenderWorld` / `EF_StartEf`.

`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`

RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Pixel data and the render pose/FOV/contract metadata that produced it are one atomic publication unit. Stale pixels must never be relabelled as a newer XR contract.

## WORKING MODEL

`SYNC -> AUDIT STATUS -> EXACT PARENT -> UNCHANGED REPRO -> USER VERDICT -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP/ADAPT/STOP`

**PARALLELIZE EVIDENCE - SERIALIZE MUTATION.**

## REPOSITORY MAP

- `docs/` - canonical state, visual ledger, historical audit, proven/falsified facts, gates and policy
- `research/` - evidence indexes, source/beta/mod/donor registry and focused blocker research
- `experiments/` - reproducible causal experiments and executed result records
- `runtime/` - technical source authorities and selective donors
- `tools/` - deterministic extraction/build/analysis tooling

## EXACT RETAIL BASELINE

- Game path: `C:\GOG Games\Crysis 2`
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)_r\crysis2(5620)_01_13`
- Shared tools: `C:\GOG Games\VR Research Tools`
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
