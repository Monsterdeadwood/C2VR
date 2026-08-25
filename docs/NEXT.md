# Crysis 2 VR — NEXT

## CURRENT GATE

**VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT.**

This replaces the old P6/PosePair/cadence-K next step.

Read first:
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `docs/GATES.md`

## WHY THE OLD NEXT IS CANCELLED

Two recent descendants are user HARD RED:

- `C2VR_RC33_V1721_RESULT_20260825_063149.zip`
  - pair transport alive;
  - catastrophic camera/world instability and moving/sliding light/shadows in headset.

- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`
  - SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`;
  - user reported it visually even worse;
  - no fresh RESULT ZIP is bound to that user verdict.

Therefore:
- NO K=1/K=2 child;
- NO HEAD child;
- NO WEAPON/NEAR child;
- NO temporal/shadow child;
- NO watchdog tuning as visual fix.

## FIRST EXACT RECOVERY ACTION

The strongest physically recovered, user-positive visual property baseline is now exact:

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Historical user verdict:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

Exact historical runner is recovered inside the physical package:

`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

**The first reproduction should be this exact package unchanged, using this exact runner lineage.**

Purpose:
re-establish the known stable-world/no-flicker property before mixing in a different camera or eye renderer.

This is NOT a claim that v6.0.1 has correct stereo fusion.

## SECOND RECOVERY AXIS — CAMERA OWNERSHIP

### A1 native-repair camera checkpoint

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user-positive property:
- head left/right drove the real in-game camera/world;
- remaining major problem was flicker/two-screen behavior;
- state was described as very close.

Use as:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

### Single-source upstream camera owner

`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Use as ownership topology reference:
- HMD x1 at `Crysis2.exe+0x0057AC76`;
- downstream SetCamera pass-through.

Do not inherit old native/NVIDIA final stereo.

## THIRD RECOVERY AXIS — TRUE PRIVATE L/R

`CUSTOM_DUAL_T1 v1.0.1 / CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Use as:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

Do not use later T1 PosePair K0 as parent.

## HISTORICAL SINGLE-WINDOW TARGET

The 18–19 Aug user oracle records a useful behavior profile:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- only hand/weapon visibly wrong.

Exact physical package/hash remains OPEN.

Continue archival recovery, but **do not block the exact v6.0.1 unchanged reproduction on guessing this package identity**.

Do not infer that this unknown old build already contained every later independent win.

## HISTORICAL COMPONENTS THAT ARE NOT PARENTS

- `191909`: low-divergence/native-stereo control only.
- `203734/204156`: pose/IPD/FOV math only; surrounding renderer visually rejected.
- `021239/175934`: weapon firing-direction donor only.
- `v7.0.2 / 001036`: technical source-size transport, user visual status UNBOUND.
- `v10 034749`: structural/mechanical green; direct primary user verdict not recovered, whole-build visual status not GREEN.
- `v10.2 020117`: genuine LIVE, visual verdict UNBOUND.
- `v13/13.1`: genuine LIVE, visual verdict UNBOUND.
- `v15.1 NO_BINOCULAR`: mechanical dual-scene proof only; host submitted zero visual projection layers.

## NEXT LIVE RULE

No new visual child before exact chosen baseline reproduction.

Sequence:

`EXACT HISTORICAL PACKAGE -> UNCHANGED REPRO -> USER HEADSET VERDICT -> FREEZE PROPERTY -> ONE CAUSAL MUTATION`

No multi-policy integration.

## PASS FOR v6.0.1 REPRO

The reproduction succeeds only if the historically accepted property returns:
- no periodic blank/flicker behavior;
- textures/objects stable;
- shadows/light stable enough to judge;
- byte-exact restore and retail hashes PASS.

Stereo fusion is expected to remain unresolved and must be recorded as such, not silently promoted.

## PASS FOR A FUTURE WHOLE-BUILD PARENT

Only explicit headset acceptance can classify `FULL_USER_VISUAL_GREEN`:
- stationary head -> stationary world;
- slow yaw no fall/jump/shear;
- fast yaw/reversal no catastrophic eye split;
- stable light/shadows;
- credible world scale;
- no severe monitor-panel/two-screen behavior;
- coherent non-duplicate L/R;
- restore/hashes PASS.

## FAIL

Catastrophic camera motion, severe flicker, sliding shadows/lights, wrong two-screen stereo, extreme lateral separation or unusable blur => exact package becomes `VISUAL_RED` and cannot be the direct future visual parent.

## PARKED

Until visual baseline recovery succeeds:
- cadence K;
- final HEAD composition;
- weapon/NEAR integration;
- temporal isolation;
- second-eye shadow policy;
- coordinate-sign LIVE experiments.
