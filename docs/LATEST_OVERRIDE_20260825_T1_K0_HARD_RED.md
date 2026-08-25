# C2VR latest override — 2026-08-25 — T1 PosePair K0 USER HARD RED

## PRECEDENCE

This file supersedes earlier NEXT/STATE text where it conflicts, including the prior `063149` proposal to continue from a clean T1 PosePair K0 control.

For the current audited state also read:
- `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
- `docs/FALSIFIED.md`
- `docs/GATES.md`
- `docs/NEXT.md`

## NEW USER VERDICT

Package:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`

The user ran this package and reported that it is visually even worse than the already-rejected previous build.

Classification:
`USER_VISUAL_HARD_RED / RESULT_ZIP_NOT_BOUND`.

No fresh RESULT ZIP has been bound to this verdict. Do not invent runtime counters or infer a result filename.

## IMMEDIATE CONSEQUENCE

STOP all direct descendants of this package:
- no K=1;
- no K=2;
- no HEAD descendant;
- no WEAPON/NEAR descendant;
- no temporal/shadow descendant.

The strategy “return to clean T1 + PosePair and then continue cadence K” is visually falsified as the next-parent strategy.

This does NOT falsify the mechanical fact that `CUSTOM_DUAL_T1 v1.0.1` renders true private L/R. It falsifies promotion of the PosePair K0 child to visual parent.

## WHY THE PROJECT MUST REWIND BY PROPERTY

Historical audit shows repeated over-promotion of technical successes:
- all-SetCamera HMD injection caused cumulative camera feedback and eye collapse;
- native/NVIDIA monitor stereo was explicitly rejected as final VR;
- real Quest IPD/FOV on native stereo produced flicker and per-eye light/shadow disagreement;
- STABLE_CAMERA still flickered;
- `063149` had live pair transport but catastrophic camera/world and light/shadow motion;
- T1 PosePair K0 was visually even worse;
- multiple old packages named GOLD/GREEN/CLEAN/NO_BINOCULAR/ONE_WINDOW were only component proofs or had no visual submit at all.

Therefore recovery must be property-based, not version-number-based.

## CURRENT GATE

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

Not cadence K.
Not final HEAD.
Not weapon work.
Not temporal/shadow tuning.

## FIRST EXACT PHYSICAL RECOVERY ANCHOR

A physical user-positive world-stability package has now been recovered exactly:

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Size:
`164221 bytes`.

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact runner lineage inside the archive:

`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

This is the first exact unchanged reproduction target.
It is NOT final stereo and must not be labelled whole-build GOLD.

## CAMERA OWNERSHIP RECOVERY AXIS

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user-positive property:
head left/right drove the real in-game camera/world; remaining dominant failure was flicker/two-screen behavior.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

Single-source topology reference:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

HMD x1 at `Crysis2.exe+0x0057AC76`; downstream SetCamera pass-through.

Do not inherit its old final native/NVIDIA stereo.

## TRUE-L/R RECOVERY AXIS

`CUSTOM_DUAL_T1 v1.0.1 / CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Classification:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

Use only the proven private-eye render transaction/restoration mechanics after baseline recovery.

## OTHER HISTORICAL COMPONENTS

- `191909` — low-divergence orientation/native-stereo control only.
- `203734/204156` — pose/IPD/FOV math only; surrounding visual renderer rejected.
- `021239/175934` — weapon firing-direction donor only.
- v7.0.2 `001036` — technical source-size transport; user visual status UNBOUND.
- v10 `034749` — structural/mechanical green; primary visual verdict not directly recovered.
- v10.2 `020117` — genuine LIVE, visual verdict UNBOUND.
- v13/v13.1 — genuine LIVE, visual verdict UNBOUND.
- v15.1 `NO_BINOCULAR` — mechanical dual-scene proof; zero visual projection-layer submits.

## HISTORICAL SINGLE-WINDOW PROFILE

The 18–19 Aug user oracle records:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- only hand/weapon visibly wrong.

Exact physical package/hash remains OPEN.

Continue archival recovery, but do not guess the identity and do not project later independent wins backward into this unknown package.

## NEXT ACTION

1. Reproduce exact physical v6.0.1 unchanged with its recovered runner.
2. Verify that the historical no-flicker/stable-world property is reproduced.
3. Bind fresh RESULT + explicit headset verdict.
4. Freeze that property baseline.
5. Treat camera ownership and true private L/R as separate axes.
6. Add exactly one visual mutation per child only after unchanged reproduction.

## ABSOLUTE RULE

A package marked `USER_VISUAL_HARD_RED` may never become canonical visual parent merely because counters, hashes, static validation, source lineage, or package naming are green.

An unresolved historical binding must stay `OPEN/UNBOUND`; never fill it by guess.
