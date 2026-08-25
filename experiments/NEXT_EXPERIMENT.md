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

The run stopped at Stage 3 before x86 client compile and before game launch because an inherited PowerShell source-sanity guard still expected the obsolete v6 mono transport status string.

Exact failure:
`v6 game client guard failed: custom_vr_transport=MONO_BACKBUFFER_TO_TWO_OPENXR_EYES`

No R2 phase executed and no stereo/headset conclusion is allowed.

Record:
`experiments/R2_NOT_LIVE_20260825_194014.md`.

## NEXT RUNTIME

`R2 PRIVATE L/R PHASE MATRIX v1.0.1 GUARDFIX`

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.1_GUARDFIX_ONECLICK.zip`

SHA256:
`42B7CF4E23C794F52912961631BC402E1B9273DA41AA23A32FF11AE2293422EB`.

Guardfix validation:
`PASS 43/43`.

R2 runtime sources and phase matrix are byte-identical to v1.0.0.

ONLY DELTA:
one source-sanity needle in `tools/Build-Run-EngineTap.ps1` changes from the obsolete
`custom_vr_transport=MONO_BACKBUFFER_TO_TWO_OPENXR_EYES`
to the actual R2 identity
`custom_vr_transport=R2_PHASED_MONO_OR_PRIVATE_LR`.

All other known source-guard needles were prevalidated against the actual R2 sources.

## PREFLIGHT — exactly 5 lines

MISSING FACT = where visible true-private L/R first becomes wrong: replay/state, eye translation, asymmetric projection, or eye order.
WHY THIS PARENT = R1 proved hidden private L/R can execute mechanically under the stable v6 world owner without temporal leak; R2 preserves that lineage.
ONE MUTATION CATEGORY = change only visible XR source/projection mux; v1.0.1 additionally fixes one non-runtime pre-build sanity string.
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

No K/PosePair/final HEAD/weapon/NEAR/new temporal-shadow policy is added.