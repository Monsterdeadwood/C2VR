# C2VR R2 v1.0.2 — VALIDATOR SYNC — PREPARED / UNRUN — 2026-08-25

## STATUS

`PREPARED / UNRUN`

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.2_VALIDATOR_SYNC_ONECLICK.zip`

Bytes:
`205935`

SHA256:
`2F751F869FC4B4AB8110FA6C893A77EA5B849457BEC21451E1C313D342852242`

ZIP CRC: PASS.
Package file-hash manifest: 81/81 PASS.
R2 static validation: `67/67 PASS`.
Inherited v1.0.1 guardfix validation: `43/43 PASS`.

No runtime or visual PASS is claimed.

## WHY v1.0.2 EXISTS

v1.0.1 correctly fixed the stale pre-build PowerShell source guard and its dedicated guardfix validator proved the delta was isolated.

However the inherited generic `R2_STATIC_VALIDATE.py` still expected the v1.0.0 PowerShell SHA and therefore printed `66/67 FAIL` on the intentionally changed guardfix runner.

This was an internal validation contradiction, not a runtime failure.

v1.0.2 resolves only that contradiction.

## LINEAGE

BASE_PACKAGE:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.1_GUARDFIX_ONECLICK.zip`

BASE_PACKAGE_SHA256:
`42B7CF4E23C794F52912961631BC402E1B9273DA41AA23A32FF11AE2293422EB`

R1 mechanical parent:
`CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`
SHA256 `330382153381C01CDE23FA15D777A6F54796F761D8DEC3F0A2BC2D07AC78EC79`.

Known R1 result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
SHA256 `E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`.

R2 v1.0.0 result `20260825_194014` is `NOT_LIVE`: it stopped before game launch on the stale source-guard needle.

## v1.0.2 ONLY DELTA

Compared with v1.0.1:
- `R2_STATIC_VALIDATE.py` now validates the already-approved guardfix `Build-Run-EngineTap.ps1` SHA256 `97596AC8381670092C595DE68E92C54C1BDAED4898A44A20B17ADDC4139C4B2B` instead of incorrectly requiring the obsolete v1.0.0 SHA.
- package manifest, lineage/readme and hash manifest synchronized to v1.0.2 identity.

Byte-identical to v1.0.1:
- all runtime sources;
- x86/x64 code;
- `20_RUN_C2VR_FULL_VR.bat`;
- `RUN_FULL_VR.bat`;
- `Build-Run-EngineTap.ps1`;
- recovery BAT/PowerShell;
- analyzer;
- IPC ABI/version/layout;
- R2 phase matrix and XR policy.

Therefore v1.0.2 changes validation/metadata only, not experiment behavior.

## R2 PHASE MATRIX

```text
0–10 s   MONO_A
10–22 s  PRIVATE_ZERO
22–36 s  PRIVATE_IPD
36–52 s  PRIVATE_FULL
52–64 s  PRIVATE_SWAP
64–74 s  MONO_B
>74 s    DONE
```

Purpose:
- MONO_A validates the inherited stable baseline in the same run;
- PRIVATE_ZERO isolates replay/state with zero eye translation and common FOV;
- PRIVATE_IPD adds only real eye translation;
- PRIVATE_FULL adds exact per-eye XR FOV and is the first complete true-L/R candidate;
- PRIVATE_SWAP changes only L/R output mapping and localizes eye-order/sign problems;
- MONO_B tests recovery to the inherited baseline.

## FORBIDDEN

No PosePair/K, final HEAD rewrite, weapon/NEAR mutation, native/NVIDIA stereo, new temporal/shadow policy or IPC ABI change is introduced.

## VISUAL VERDICT

Must come from the user after the LIVE.
Counters/static validation alone cannot promote any phase to visual GREEN.
