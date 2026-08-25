# Crysis 2 VR — NEXT EXPERIMENT

## CURRENT GATE

`VISIBLE PRIVATE L/R / STEREO CAUSAL MATRIX`

Old PosePair/cadence-K/final-HEAD direction remains parked.

## R1 CLOSED MECHANICALLY

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
SHA256 `E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`.

R1 reached DONE with 824 hidden private L/R pairs, balanced 824/824 eye execution, 824/824 temporal restore, temporal_leak=0, pose_mismatch=0, no hidden publication/shared copy/OpenXR submit.

Classification:
`LIVE / MECHANICAL PASS / VISIBLE TRUE STEREO NOT TESTED`.

Record:
`experiments/R1_HIDDEN_T1_REPLAY_RESULT_20260825_175757.md`.

## NEXT RUNTIME

`R2 PRIVATE L/R PHASE MATRIX`

Status:
`PREPARED / UNRUN`.

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.0_ONECLICK.zip`

Bytes:
`199164`

SHA256:
`CFC430BDC6B916ACCB87F382924C718F5A60710C0BEFE837282F6C133877E856`.

Static validation:
`R2_STATIC=PASS (67/67)`.

Record:
`experiments/R2_PRIVATE_LR_PHASE_MATRIX_PREPARED_20260825.md`.

## PREFLIGHT — exactly 5 lines

MISSING FACT = where visible true-private L/R first becomes wrong: replay/state, eye translation, asymmetric projection, or eye order.
WHY THIS PARENT = R1 proved hidden private L/R can execute mechanically under the stable v6 world owner without temporal leak; R2 preserves that lineage.
ONE MUTATION CATEGORY = change only visible XR source/projection mux; no new world owner, renderer seam, launcher, transport stack, HEAD, K, weapon or temporal policy.
PASS = phase matrix localizes the first bad transition, or PRIVATE_FULL is stable/nonduplicate and user-fused while MONO controls remain stable.
FAIL = baseline is invalid, private publication fails, restore/hash fails, or no phase yields interpretable mechanical/visual evidence.

## LINEAGE

BASE_PACKAGE = `CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`
BASE_SCRIPT = `20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`
KNOWN_GOOD_RESULT = `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
WHAT IS REUSED = exact v6 world owner, R1 T1 RC/RT replay, temporal restore, IPC v5/636, host startup, Zig discovery, retail guards, backup/restore, logging and RESULT packaging.
ONLY DELTA = phased mono/private direct/private swap XR source plus phase-specific pose/FOV controls and richer analyzer.
UNCHANGED LAUNCH PATH = YES
UNCHANGED BUILD PATH = YES
UNCHANGED RESTORE PATH = YES
EXPECTED NEW RESULT = `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_*.zip` with R2_PRIVATE_STEREO_STATUS, phase-tagged XR captures and R2_ANALYSIS.

## RUN

Use only:
`20_RUN_C2VR_FULL_VR.bat`

Automatic phases:
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
- PRIVATE_ZERO bad -> replay/state blocker.
- ZERO good, IPD bad -> eye translation/camera geometry blocker.
- IPD good, FULL bad -> asymmetric FOV/projection blocker.
- FULL vs SWAP visually different -> eye mapping/order localized.
- private bad, MONO_B recovers -> private path causally implicated.
- PRIVATE_FULL stable + nonduplicate + user-fused -> strong visible stereo candidate, not automatic whole-build GREEN.

## AUTOMATIC DATA

Per-phase XR captures plus L/R MAE, changed-pixel ratio, luma MAE, capture coverage, FULL/SWAP comparison, packet/render/present identity, replay/stage/publish counts, temporal restore/leak, pose match/miss, copies/submits/empty-layer firewall, replay command-issue timing, restore and retail hash evidence.

`VISUAL_RESULT=NOT_AUTOMATED__USER_HEADSET_VERDICT_REQUIRED`.

## FORBIDDEN

No K=1/K=2, PosePair child, final HEAD, weapon/NEAR, native Nvidia/Cry final stereo, new temporal/shadow policy or new transport stack in this LIVE.