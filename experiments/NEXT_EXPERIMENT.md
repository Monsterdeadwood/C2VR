# Crysis 2 VR — NEXT EXPERIMENT

## CURRENT GATE

`VISIBLE PRIVATE L/R / STEREO CAUSAL MATRIX`

## R1 CLOSED MECHANICALLY

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
SHA256 `E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`.

R1 reached DONE with 824 hidden private L/R pairs, balanced 824/824 eye execution, 824/824 temporal restore, temporal_leak=0, pose_mismatch=0, and no hidden publication/shared copy/OpenXR submit.

Classification:
`LIVE / MECHANICAL PASS / VISIBLE TRUE STEREO NOT TESTED`.

## R2 v1.0.0 RESULT 194014

`NOT_LIVE`.

Stopped at Stage 3 before x86 compile and before game launch:
`v6 game client guard failed: custom_vr_transport=MONO_BACKBUFFER_TO_TWO_OPENXR_EYES`

No stereo conclusion is allowed.

## SUPERSEDED PACKAGES

`R2 v1.0.1 GUARDFIX` and `R2 v1.0.2 VALIDATOR_SYNC` are no longer valid next parents.

Reason: the proven R1/v6 build runner should not have been modified to weaken/change its source guard merely because the R2 source removed an inherited marker.

## NEXT RUNTIME

`R2 PRIVATE L/R PHASE MATRIX v1.0.3 CLEAN REBASE`

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.3_CLEAN_REBASE_ONECLICK.zip`

Bytes:
`205897`

SHA256:
`AD9C28F175E7F300B89334F31F2AB921D24597B415A30C5E8B385A86CFE0DD0C`

Status:
`PREPARED / UNRUN`.

Validation:
- clean-rebase static `53/53 PASS`;
- exact inherited client/host/IPC source guards simulated PASS;
- analyzer Python compile PASS;
- ZIP CRC PASS.

Full record:
`experiments/R2_V103_CLEAN_REBASE_PREPARED_20260825.md`.

## PREFLIGHT — exactly 5 lines

MISSING FACT = where visible true-private L/R first becomes wrong: replay/state, eye translation, asymmetric projection, or eye order.
WHY THIS PARENT = exact proven R1 is the parent again; no guardfix/validator-sync descendant is reused as architecture.
ONE MUTATION CATEGORY = visible XR source/projection phase mux plus diagnostics only; build/launch/restore/world-owner/IPC remain exact R1.
PASS = matrix localizes the first bad transition, or PRIVATE_FULL is stable/nonduplicate and user-fused while MONO controls remain stable.
FAIL = baseline invalid, private publication fails, restore/hash fails, or no phase yields interpretable mechanical/visual evidence.

## LINEAGE

BASE_PACKAGE = `CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`
BASE_SCRIPT = `20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`
KNOWN_GOOD_RESULT = `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
WHAT IS REUSED = exact R1 BAT/PS1/recovery, v6 world owner, porous proxy, IPC v5/636, retail guards, backup/restore and result packaging.
ONLY DELTA = R2 phased private-eye render/publication/composition plus analyzer.
UNCHANGED LAUNCH PATH = YES, byte-identical to R1.
UNCHANGED BUILD PATH = YES, byte-identical to R1.
UNCHANGED RESTORE PATH = YES, byte-identical to R1.
EXPECTED NEW RESULT = `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_*.zip` containing R2 phase status, captures and analyzer.

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

No keys.

After DONE, exit normally so the inherited runner restores retail and packs the RESULT.

Observe per phase:
- world/camera stability;
- binocular fusion/doubling;
- shadows/light;
- geometry/object integrity;
- FULL versus SWAP;
- MONO_B recovery.

## FORBIDDEN

No K/PosePair/final HEAD/weapon/NEAR/native Nvidia/Cry stereo/new temporal-shadow policy in this LIVE.