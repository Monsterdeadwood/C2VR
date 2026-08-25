# Crysis 2 VR — NEXT

## CURRENT GATE

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

Old P6/PosePair/cadence-K direction remains cancelled.

Read first:
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `experiments/R1_HIDDEN_T1_REPLAY_PREPARED_20260825.md`
6. `experiments/NEXT_EXPERIMENT.md`

## CURRENT NEXT RUNTIME

`R1 HIDDEN T1 REPLAY`

Status:
`PREPARED / UNRUN`.

Package:
`CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`

Bytes `191925`.

SHA256:
`330382153381C01CDE23FA15D777A6F54796F761D8DEC3F0A2BC2D07AC78EC79`.

Static only:
`R1_STATIC=PASS (70/70)`.

No runtime/visual PASS exists yet.

## WHY R1 NOW

Exact v6.0.1 is a bounded world-stability reference:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Historical accepted property:
- no flicker;
- stable shadows/textures/objects;
- binocular fusion still failed.

Exact T1 v1.0.1 is a mechanical private-L/R donor:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`
SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`.

The key missing edge is now:

`stable v6 visible owner -> hidden T1 private replay -> does visible v6 state break?`

This is more informative than another direct v6+T1+PosePair/HEAD integration.

## BUILT-IN BASELINE CONTROL

R1 folds the unchanged-baseline check into its first and final OFF phases:

```text
0–10 s   OFF_A
10–25 s  SPARSE_1_OF_10
25–45 s  FULL
45–55 s  OFF_B
>55 s    DONE
```

OFF_A already bad -> `R1_INVALID_BASELINE`; do not interpret replay phases.

Therefore a separate R0 launch is no longer required before this prepared run.

## ISOLATION

Quest-visible output remains the inherited v6.0.1 mono Present/cache path for every phase.

Required hidden counters:
```text
private_eye_publication=0
private_eye_shared_copy=0
private_eye_openxr_submit=0
```

Exact v6 x64 host, host client, IPC ABI and BAT/PowerShell launch/build/restore chain are byte-identical.

## DECISION TREE

- OFF_A good, SPARSE/FULL bad -> `R1_REPLAY_POISONS_STATE`; bisect x86 renderer-state restore only.
- OFF_A/SPARSE good, FULL bad -> `R1_FULL_RATE_ONLY_BAD`; investigate replay scheduling/cadence/cost.
- all phases stable + hidden replay counters active -> `R1_REPLAY_VISUALLY_INERT`; authorize R2 only.
- OFF_A bad -> `R1_INVALID_BASELINE`; recover exact v6 behavior before further mutation.

## R2 IF AUTHORIZED

R2 changes only the headset image source from stable v6 center to already-rendered private T1 L/R while preserving the game-owned v6 world contract.

Still forbidden in R2 unless independently required later:
- host-driven PosePair request ownership;
- K lead;
- final HEAD rewrite;
- weapon/NEAR mutation;
- new temporal/shadow policy.

## PARKED

Until R1 closes:
- cadence K;
- final HEAD composition;
- A1 camera merge;
- weapon/NEAR integration;
- coordinate-sign LIVE experiments;
- temporal/shadow policy work.
