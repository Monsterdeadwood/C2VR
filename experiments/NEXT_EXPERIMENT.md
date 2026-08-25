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

No phase-by-phase user headset PASS is backfilled.

## R2 v1.0.0 RESULT 194014

`NOT_LIVE`.

The run stopped at Stage 3 before x86 compile and before game launch because the inherited PowerShell source-sanity guard still expected the obsolete v6 mono transport status string.

Exact failure:
`v6 game client guard failed: custom_vr_transport=MONO_BACKBUFFER_TO_TWO_OPENXR_EYES`

No R2 phase executed and no headset/stereo conclusion is allowed.

## R2 v1.0.1 GUARDFIX

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.1_GUARDFIX_ONECLICK.zip`
SHA256 `42B7CF4E23C794F52912961631BC402E1B9273DA41AA23A32FF11AE2293422EB`.

The guardfix itself is valid: dedicated validation `43/43 PASS`, runtime and phase matrix byte-identical to v1.0.0, and the only runner delta is the source-sanity needle.

But the inherited generic `R2_STATIC_VALIDATE.py` still expected the obsolete v1.0.0 PowerShell SHA and therefore printed `66/67 FAIL` on the intentionally changed runner.

Do not run v1.0.1 now; use v1.0.2 with synchronized validation.

## NEXT RUNTIME

`R2 PRIVATE L/R PHASE MATRIX v1.0.2 VALIDATOR_SYNC`

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.2_VALIDATOR_SYNC_ONECLICK.zip`

Bytes:
`205935`

SHA256:
`2F751F869FC4B4AB8110FA6C893A77EA5B849457BEC21451E1C313D342852242`

Validation:
- R2 static `67/67 PASS`;
- inherited guardfix `43/43 PASS`;
- package hash manifest `81/81 PASS`;
- ZIP CRC PASS.

Status:
`PREPARED / UNRUN`.

Compared with v1.0.1, all runtime sources, BAT, PowerShell runner, recovery, analyzer, IPC ABI and phase matrix are byte-identical. Only the generic static validator and package metadata/hash records changed.

Full record:
`experiments/R2_V102_VALIDATOR_SYNC_PREPARED_20260825.md`.

## PREFLIGHT — exactly 5 lines

MISSING FACT = where visible true-private L/R first becomes wrong: replay/state, eye translation, asymmetric projection, or eye order.
WHY THIS PARENT = R1 mechanically proved private L/R replay can execute without temporal leak; R2 preserves the stable v6 world owner and changes only visible private-eye source/projection policy.
ONE MUTATION CATEGORY = visible XR source/projection phase mux; v1.0.2 adds validation synchronization only and no runtime mutation.
PASS = phase matrix localizes the first bad transition, or PRIVATE_FULL is stable/nonduplicate and user-fused while MONO controls remain stable.
FAIL = baseline invalid, private publication fails, restore/hash fails, or no phase yields interpretable mechanical/visual evidence.

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

Observe per phase:
- whether world stays fixed under head movement;
- whether objects fuse or double;
- whether shadows/light remain coherent;
- whether geometry/weapon clips/disappears;
- whether PRIVATE_FULL or PRIVATE_SWAP fuses more naturally;
- whether MONO_B restores the initial baseline.

No K/PosePair/final HEAD/weapon/NEAR/new temporal-shadow policy is added.

## RESULT

After DONE, exit normally and preserve the produced:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_*.zip`.

User headset verdict is mandatory; static/counter PASS cannot auto-promote the build.