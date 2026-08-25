# C2VR R2 — PRIVATE L/R PHASE MATRIX — PREPARED / UNRUN — 2026-08-25

## STATUS

`PREPARED / UNRUN`

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.0_ONECLICK.zip`

Bytes:
`199164`

SHA256:
`CFC430BDC6B916ACCB87F382924C718F5A60710C0BEFE837282F6C133877E856`

Static validation:
`R2_STATIC=PASS (67/67)`.

No Windows/Zig compile or Quest LIVE is claimed before user execution.

## LINEAGE

BASE_PACKAGE:
`CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`
SHA256 `330382153381C01CDE23FA15D777A6F54796F761D8DEC3F0A2BC2D07AC78EC79`.

KNOWN_GOOD_RESULT:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
SHA256 `E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`.

Exact launch/build/restore chain remains unchanged:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

IPC ABI remains v5 / 636 bytes; only existing reserved slots gain R2 phase semantics.

## ONE MUTATION CATEGORY

The v6 world/camera owner, T1 RC/RT replay seams, temporal restore, retail guards, scripts and transport stack remain inherited.

R2 changes only the visible XR source/projection mux so the already-rendered private L/R can be exposed under controlled phases.

## AUTOMATIC PHASE MATRIX

```text
0–10 s   MONO_A
10–22 s  PRIVATE_ZERO
22–36 s  PRIVATE_IPD
36–52 s  PRIVATE_FULL
52–64 s  PRIVATE_SWAP
64–74 s  MONO_B
>74 s    DONE
```

- MONO_A: exact v6 fusion-lock baseline.
- PRIVATE_ZERO: two private passes, zero eye translation, common left XR FOV, common center submit pose.
- PRIVATE_IPD: real Quest eye translation, common left XR FOV.
- PRIVATE_FULL: real Quest eye translation + exact per-eye XR FOV.
- PRIVATE_SWAP: same render/projection as FULL, only visible L/R mapping swapped.
- MONO_B: exact v6 fusion-lock recovery control.

No F keys.

## AUTOMATIC EVIDENCE

Each phase records tagged XR captures and runtime identity. Analyzer computes per phase:
- L/R pixel MAE;
- changed-pixel ratio;
- luma MAE;
- capture coverage;
- mono duplicate control;
- PRIVATE_ZERO determinism;
- private stereo separation;
- FULL vs SWAP MAE consistency.

Runtime records:
- private replay/stage/Present-publication counts;
- LEFT/RIGHT eye builds and RT scenes;
- temporal snapshot/restore/leak;
- center restore commands;
- pose match/miss;
- packet/render/present identity;
- OpenXR copies/submits and empty-layer firewall;
- phase max replay command-issue microseconds;
- retail restore/hash evidence.

Analyzer ends with:
`VISUAL_RESULT=NOT_AUTOMATED__USER_HEADSET_VERDICT_REQUIRED`.

## CAUSAL VERDICT TREE

- PRIVATE_ZERO bad: second-pass replay/state transaction is the blocker, independent of IPD/FOV.
- ZERO good, PRIVATE_IPD bad: eye translation/camera geometry is the blocker.
- IPD good, PRIVATE_FULL bad: asymmetric per-eye projection/FOV is the blocker.
- FULL and SWAP differ strongly in headset fusion: eye order/sign is localized.
- Private phases bad but MONO_B returns to baseline: private path is causally implicated without contaminating the parent.
- FULL stable, nonduplicate and user-fused: R2 becomes a strong visible true-stereo candidate; still no automatic whole-build GREEN.

## FORBIDDEN

No PosePair/K lead, no final HEAD rewrite, no weapon/NEAR mutation, no new temporal/shadow policy, no native Nvidia/Cry final stereo, no new x86↔x64 transport stack.