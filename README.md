# Crysis 2 VR

Native VR integration research for **Crysis 2 retail 1.9 / CryEngine DX11**.

## CURRENT STATUS - VISUAL BASELINE RECOVERY

**WORKING BUILD FIRST. USER VISUAL VERDICT FIRST.**

Current gate:

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

The project is NOT currently in cadence K, final HEAD, weapon/NEAR, temporal or shadow integration.

Read first:
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `docs/STATE.md`
6. `docs/NEXT.md`
7. `docs/GATES.md`

## EVIDENCE LAW

For visual/playability acceptance:

`USER_HEADSET_VERDICT > XR/LR captures > raw LIVE RESULT > counters > static validation > design intent`

Permanent guards:
- `RESULT ZIP != LIVE`;
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

Therefore:
- no K1/K2 descendant;
- no final HEAD descendant;
- no weapon/NEAR descendant;
- no temporal/shadow descendant;
- no more watchdog tuning as a visual fix.

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

This is the first exact unchanged reproduction target.
It is not final stereo.

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

1. Reproduce exact physical v6.0.1 unchanged with its recovered runner.
2. Bind a fresh RESULT and explicit headset verdict for the no-flicker/stable-world property.
3. Freeze that property baseline.
4. Treat A1/single-source camera ownership as a separate axis.
5. Treat T1 true-private-L/R mechanics as a separate axis.
6. Add only one causal visual mutation per child after unchanged reproduction.

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
- `experiments/` - reproducible causal experiments
- `runtime/` - technical source authorities and selective donors
- `tools/` - deterministic extraction/build/analysis tooling

## EXACT RETAIL BASELINE

- Game path: `C:\GOG Games\Crysis 2`
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)_r\crysis2(5620)_01_13`
- Shared tools: `C:\GOG Games\VR Research Tools`
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
