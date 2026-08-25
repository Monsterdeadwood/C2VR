# Crysis 2 VR — NEXT

## CURRENT GATE
**VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT.**

This replaces the old P6/cadence-K next step.

Read first:
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/LATEST_OVERRIDE_20260825_T1_K0_HARD_RED.md`
3. `docs/FALSIFIED.md`

## WHY THE OLD NEXT IS CANCELLED

Two recent descendants are user HARD RED:

- `C2VR_RC33_V1721_RESULT_20260825_063149.zip`
  - transport/pairs alive;
  - catastrophic camera/world instability and moving/sliding light/shadows in headset.

- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`
  - SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`;
  - user reports it visually even worse;
  - no fresh RESULT ZIP is bound yet.

Therefore:
- NO K=1/K=2 child;
- NO HEAD child;
- NO WEAPON/NEAR child;
- NO temporal/shadow child;
- NO further watchdog tuning as a visual fix.

## NEXT WORK

Recover exact physical package + runner for the nearest user-positive/near-normal Crysis camera checkpoint.

Priority recovery candidates:

### 1. A1 native-repair camera checkpoint
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user verdict:
- head left/right drove the real in-game camera/world;
- remaining major problem was flicker/two-screen behavior;
- state was described as very close.

Target use:
`CAMERA_OWNERSHIP_REFERENCE_ONLY`.

### 2. Single-source upstream camera owner
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Target use:
- preserve HMD x1 at `Crysis2.exe+0x0057AC76`;
- downstream SetCamera pass-through;
- compare against all-SetCamera feedback-loop failure.

This is an ownership topology reference, not visual GOLD.

### 3. Historical controls/components
- `191909`: low-divergence orientation/native-stereo control only;
- `203734/204156`: 6DoF/IPD/FOV propagation component proof only;
- `021239`: weapon/muzzle component donor only;
- x86 game + x64 OpenXR host: infrastructure GOLD;
- `CUSTOM_DUAL_T1 v1.0.1`: true-L/R renderer technical proof only.

## NEXT LIVE RULE

Do not build a new visual child until the exact chosen ancestor and runner are recovered.

Then:

`EXACT HISTORICAL PACKAGE -> UNCHANGED REPRO -> USER HEADSET VERDICT -> FREEZE -> ONE CAUSAL MUTATION`

No multi-policy integration.

## PASS FOR RECOVERED BASELINE

A baseline is eligible to become a visual parent only if the user confirms in headset:
- stationary head -> stationary world;
- slow yaw does not make camera/world fall, jump or shear;
- fast yaw/reversal does not explode eye coherence;
- lighting and shadows remain spatially stable enough to judge the world;
- no severe two-screen/monitor-panel behavior;
- L/R remain non-duplicate where true stereo is expected;
- restore and retail hashes pass.

Counters are supporting evidence only.

## FAIL

Any user report equivalent to catastrophic camera motion, severe flicker, sliding shadows/lights, wrong two-screen stereo, extreme lateral separation or unusable blur marks the package `USER_VISUAL_HARD_RED` and immediately forbids it as a direct future visual parent.

## PARKED

Until a visual baseline is recovered:
- cadence K;
- final HEAD composition;
- weapon/NEAR integration;
- temporal isolation;
- second-eye shadow policy;
- coordinate-sign LIVE experiments.

Do not reopen these merely because their code already exists.
