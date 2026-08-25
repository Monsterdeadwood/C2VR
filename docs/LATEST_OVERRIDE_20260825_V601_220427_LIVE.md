# C2VR LATEST OVERRIDE — V6.0.1 PRIVATE RTV LIVE 220427

Date: 2026-08-25

This file supersedes any older NEXT/STATE text that still says exact Z-reprojection v6.0.1 PRIVATE_RTV is merely the next unexecuted runtime.

Detailed raw-result record:
`experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`.

## FRESH LIVE

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Bytes:
`24512034`

Runtime path is the recovered historical Z-reprojection v6.0.1 PRIVATE_RTV lineage.

The historical v6.0.0 RTV blocker is mechanically closed.

Raw runtime proves:
- XR session created and began;
- Quest submits occurred;
- `submit_count=4691`;
- `ever_submitted=1`;
- private eye staging ready for both eyes;
- `eye_stage_copies=9382`;
- `reproject_draws=9382`;
- 33 XR stereo pair captures recorded;
- raw restore record says `RESTORE_OK=True`.

## CRITICAL ARCHITECTURE FACT

This is still mono-center RGB + inverse depth Z-reprojection:

```text
center color+depth
 -> synthesize LEFT/RIGHT in x64 host
 -> private eye RTs
 -> copy into XR swapchains
 -> Quest
```

It is NOT true independent native/private LEFT+RIGHT scene rendering.

Classification:

```text
PRIVATE_RTV_XR_BRIDGE          = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER   = NO
FULL_USER_VISUAL_GREEN         = NO
```

The permanent project rule remains:
`mono RGB+depth/Z reprojection is not the final renderer architecture`.

## ANALYZER OVERRIDE

The generated `Z_REPROJECTION_VERDICT.txt` is internally contradicted by raw evidence.

It prints:
- `OpenXRTransport=FAIL` despite 4691 submits and `ever_submitted=1`;
- `eyeStageCopies=0` despite raw `eye_stage_copies=9382`;
- `Restore=FAIL` despite `RESTORE_OK=True`, `d3d11_restore=True`, `system_cfg_restore=True`.

Those summary fields are classified:
`ANALYZER_FALSE_NEGATIVE / SUMMARY_PARSER_BUG`.

Raw executed status/log evidence outranks the analyzer summary.

Do not let another branch reinterpret `PIPELINE_INCOMPLETE` as proof that XR output failed.

## CURRENT MISSING FACT

`USER_HEADSET_VERDICT FOR 220427`.

The user's direct fresh headset verdict is not yet bound in the project record.

Therefore the current gate is:

`220427 LIVE -> BIND USER HEADSET VERDICT -> VISUAL BASELINE DECISION`

No renderer mutation before that verdict.

## DECISION AFTER VERDICT

### ACCEPT / substantially good visual control

Freeze the exact 220427 path as a component visual/control baseline and keep its XR bridge unchanged.

Do NOT call Z-reprojection the final renderer.

The next isolated problem becomes source geometry / true-LR integration while preserving the proven bridge and accepted world/camera properties.

### RED

Hard-stop v6.0.1 as a whole visual parent.

Salvage only:
`PRIVATE_RTV_XR_BRIDGE`.

Then continue exact recovery of the historical user-accepted single-window behavior profile. Do not patch-number forward through later Z v6.1+ and do not fall back to GOODLINE/R2/T1/v17 whole-build parents.

## STILL PARKED

Until this fresh visual verdict is bound:
- PosePair/K;
- R2/T1 visible descendants;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- arbitrary IPD/FOV/convergence tuning;
- release optimization.

## EVIDENCE LAW

`USER_HEADSET_VERDICT > deterministic captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > package intent`

When a generated summary contradicts raw status from the same run, record the contradiction and fix the analyzer separately. Never erase the executed fact.
