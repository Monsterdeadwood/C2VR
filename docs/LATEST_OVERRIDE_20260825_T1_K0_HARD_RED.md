# C2VR latest override — 2026-08-25 — T1 PosePair K0 USER HARD RED

## PRECEDENCE
This file supersedes earlier NEXT/STATE text where it conflicts, including the prior `063149` override's proposal to run a clean T1 PosePair K0 control.

## NEW USER VERDICT
Package:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`

The user ran this package and reported that it is visually even worse than the already-rejected previous build.

Classification:
`USER_VISUAL_HARD_RED / RESULT_ZIP_NOT_BOUND`

No fresh RESULT ZIP has been bound to this verdict yet. Do not invent runtime counters or infer a result filename.

## IMMEDIATE CONSEQUENCE
STOP all direct descendants of this package:
- no `K=1`;
- no `K=2`;
- no HEAD descendant;
- no WEAPON/NEAR descendant;
- no temporal/shadow descendant.

The hypothesis "return to clean T1 + PosePair and then continue cadence K" is visually falsified as the next-parent strategy.

This does NOT falsify the technical fact that `CUSTOM_DUAL_T1 v1.0.1` can render true private L/R. It falsifies using the new T1+PosePair K0 child as the visual baseline/parent.

## WHY THE PROJECT MUST REWIND FURTHER
Historical user verdict recovery shows the same visual failure classes repeatedly:
- all-SetCamera HMD injection caused cumulative camera feedback and eye collapse;
- native/NVIDIA monitor stereo was explicitly rejected as a final VR direction;
- real Quest IPD/FOV on the native stereo path produced flicker and per-eye light/shadow disagreement;
- STABLE_CAMERA simplification still flickered and did not fix firing ownership;
- `063149` had live pair transport but catastrophic camera/world and light/shadow motion;
- current T1 PosePair K0 is an even stronger user visual rejection.

Therefore counters and source cleanliness are not enough to choose the next parent.

## CURRENT GATE
`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

Not cadence K.
Not HEAD integration.
Not weapon work.
Not temporal/shadow tuning.

## RECOVERY ANCHORS
Use `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md` as the permanent parent-selection authority.

Priority historical salvage checkpoints:
1. `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` — user reported real head-driven camera/world behavior and described the state as close, with flicker/two-screen behavior remaining.
2. `CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip` — preserves the proven one-upstream-camera-owner topology at `Crysis2.exe+0x0057AC76`; not visual GOLD.
3. `191909` — lower-divergence orientation/native-stereo control only; not final geometry.
4. `203734/204156` — camera/pose/IPD/FOV component proof only; renderer policy is not accepted because `205430` later failed visually.
5. `021239` — weapon/muzzle component donor only; do not use its monitor-stereo as final VR.
6. x86 game + x64 OpenXR host split — infrastructure GOLD only.
7. `CUSTOM_DUAL_T1 v1.0.1` — true-L/R technical proof only, not visual parent authority.

## NEXT ACTION
Recover the exact physical package/runner corresponding to the nearest user-positive/near-normal Crysis camera checkpoint before building another visual child.

Then:
- reproduce the baseline unchanged;
- bind fresh RESULT + user headset verdict;
- freeze it;
- add exactly one visual mutation per child.

## ABSOLUTE RULE
A package marked `USER_VISUAL_HARD_RED` may never again be promoted to canonical visual parent merely because counters, hashes, static validation, or source lineage are green.
