# C2VR R2 v1.0.3 — CLEAN REBASE — PREPARED / UNRUN

## PACKAGE

`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.3_CLEAN_REBASE_ONECLICK.zip`

Bytes: `205897`

SHA256: `AD9C28F175E7F300B89334F31F2AB921D24597B415A30C5E8B385A86CFE0DD0C`

Validation: `R2_CLEAN_REBASE_STATIC=PASS (53/53)`, analyzer Python compile PASS, ZIP CRC PASS.

## WHY v1.0.1 / v1.0.2 ARE SUPERSEDED

The failed R2 v1.0.0 LIVE result `194014` proved the inherited R1/v6 runner stopped at its game-client source guard because R2 had removed the exact v6 transport token that the unchanged runner intentionally checks.

Changing that proven runner to accept the new token was the wrong lineage direction. v1.0.1 GUARDFIX and v1.0.2 VALIDATOR_SYNC are therefore superseded and must not be the next parent.

## CLEAN REBASE RULE

Start again from exact:
`CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`
SHA256 `330382153381C01CDE23FA15D777A6F54796F761D8DEC3F0A2BC2D07AC78EC79`.

Known-good R1 result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
SHA256 `E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`.

Exact immutable R1 hashes are preserved for:
- `20_RUN_C2VR_FULL_VR.bat`
- `19_RECOVER_C2VR_ENGINE_TAP.bat`
- nested `RUN_FULL_VR.bat`
- `tools/Build-Run-EngineTap.ps1`
- `tools/Recover.ps1`
- `engine_tap.cpp/.h`
- `porous_proxy.cpp`
- `c2vr_shared.h` IPC v5 / 636 bytes.

Only the R2 scientific delta is reapplied:
- `hidden_t1_replay.cpp`
- `c2vr_host_client.cpp/.h`
- `c2vr_openxr_host.cpp`
- `analysis/analyze_result.py`.

The inherited v6 source-guard token is preserved explicitly inside `c2vr_host_client.cpp`, while runtime status separately reports the actual active mode `R2_PHASED_MONO_OR_PRIVATE_LR`. No runner guard is weakened or rewritten.

## R2 MATRIX

`MONO_A -> PRIVATE_ZERO -> PRIVATE_IPD -> PRIVATE_FULL -> PRIVATE_SWAP -> MONO_B -> DONE`

Same causal questions as prepared R2. No PosePair/K/final HEAD/weapon/NEAR/native Nvidia/Cry stereo/new temporal-shadow policy.

## STATUS

`PREPARED / UNRUN`.

No LIVE stereo or visual PASS is claimed until the user runs this exact package and returns its RESULT ZIP plus headset verdict.