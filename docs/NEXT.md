# Crysis 2 VR — NEXT

## CURRENT GATE

`VISIBLE PRIVATE L/R / STEREO CAUSAL MATRIX`

This supersedes the stale R1-next text in this file.

Read first:
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `experiments/R2_V102_VALIDATOR_SYNC_PREPARED_20260825.md`
6. `experiments/NEXT_EXPERIMENT.md`

## R1 STATUS

R1 hidden replay has already been executed:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
SHA256 `E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`.

Mechanical result:
- 824 hidden private L/R pairs;
- L/R 824/824;
- temporal snapshot/restore 824/824;
- temporal leak 0;
- pose mismatch 0;
- private publication/shared copy/OpenXR submit 0/0/0.

Classification:
`LIVE / MECHANICAL PASS / VISIBLE TRUE STEREO NOT TESTED`.

Do not repeat R1.

## R2 v1.0.0

Result `20260825_194014` is `NOT_LIVE`.
It stopped before game launch on a stale PowerShell source-sanity string. No stereo conclusion.

## R2 v1.0.1

Guardfix was isolated and validated `43/43`, but its inherited generic validator still reported `66/67 FAIL` because it expected the obsolete pre-guardfix PowerShell SHA.

Do not run v1.0.1 now.

## CURRENT NEXT RUNTIME

`R2 PRIVATE L/R PHASE MATRIX v1.0.2 VALIDATOR_SYNC`

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.2_VALIDATOR_SYNC_ONECLICK.zip`

Bytes:
`205935`

SHA256:
`2F751F869FC4B4AB8110FA6C893A77EA5B849457BEC21451E1C313D342852242`

Status:
`PREPARED / UNRUN`.

Validation:
- R2 static `67/67 PASS`;
- inherited v1.0.1 guardfix `43/43 PASS`;
- package manifest hashes `81/81 PASS`;
- ZIP CRC PASS.

Compared with v1.0.1:
- runtime sources unchanged byte-for-byte;
- BAT unchanged;
- PowerShell runner unchanged;
- recovery unchanged;
- analyzer unchanged;
- IPC v5 / 636 bytes unchanged;
- phase matrix unchanged;
- only generic validator + package metadata/hash records synchronized.

## PHASE MATRIX

```text
0–10 s   MONO_A
10–22 s  PRIVATE_ZERO
22–36 s  PRIVATE_IPD
36–52 s  PRIVATE_FULL
52–64 s  PRIVATE_SWAP
64–74 s  MONO_B
>74 s    DONE
```

Interpretation:
- MONO_A bad -> baseline invalid; stop interpreting later phases.
- ZERO bad while MONO_A good -> private replay/publication/state path is enough to break visible output.
- ZERO good, IPD bad -> eye translation / camera geometry.
- IPD good, FULL bad -> asymmetric per-eye projection/FOV.
- FULL bad, SWAP materially better -> eye order/sign mapping.
- FULL stable/fused/nonduplicate -> true private stereo path is a viable visual parent candidate, pending explicit user verdict.
- MONO_B returning stable after private failure is a strong causal recovery control.

## RUN

Use only:
`20_RUN_C2VR_FULL_VR.bat`.

No F-keys and no settings changes during the matrix.

After DONE, exit normally and send the resulting `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_*.zip` plus phase-by-phase headset verdict.

## PARKED

Still parked until R2 closes:
- PosePair/K;
- final HEAD rewrite;
- A1 camera merge;
- weapon/NEAR integration;
- new temporal/shadow policy;
- release optimization.