# Crysis 2 VR — NEXT EXPERIMENT

## CURRENT GATE

`NO NEW MUTATION YET — BIND 220427 USER HEADSET VERDICT`

The previously planned exact v6.0.1 PRIVATE_RTV reproduction has executed.

Fresh result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Detailed result record:
`experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`.

## PREFLIGHT — exactly 5 lines

MISSING FACT = whether the already executed 220427 output is an acceptable visual/control baseline in the Quest headset.
WHY NO NEW BUILD = XR/private-RTV transport already executed successfully; another mutation before binding the user's visual verdict would destroy causal attribution.
ONE MUTATION CATEGORY = NONE until verdict; observation/classification only.
PASS = user explicitly accepts the relevant world/head/fusion/shadow/right-eye properties sufficiently to freeze 220427 as a component visual/control baseline.
FAIL = user reports binocular/telescope, unstable world/head, broken/moving shadows, pathological RIGHT-eye quality, unusable geometry, black output, or overall rejection.

## CLOSED MECHANICAL FACT

The old v6.0.0 direct-XR-RTV failure is no longer the first missing edge.

Fresh raw runtime:

```text
XR session ran              = YES
submit_count                = 4691
ever_submitted              = 1
eye_stage_ready             = 1,1
eye_stage_copies            = 9382
reproject_draws              = 9382
xr_capture_count             = 33
raw restore                 = PASS
```

Keep the private-RTV-to-XR bridge unless direct new evidence falsifies it.

## IMPORTANT ARCHITECTURE LIMIT

This result uses:

`CENTER RGB + inverse depth -> synthetic LEFT/RIGHT reprojection -> private RT -> XR`.

It does not prove true private/native L/R scene rendering.

Project rule remains:
mono RGB+depth/Z reprojection is not assumed to be the final renderer.

## OBSERVE / BIND

Record the user's direct headset verdict for the completed 220427 LIVE:

```text
WORLD_STABILITY       = PASS / FAIL
CAMERA_WORLD_LOCK     = PASS / FAIL
BINOCULAR_FUSION      = PASS / FAIL
WORLD_SCALE           = PASS / FAIL
SHADOW_LIGHT_STABLE   = PASS / FAIL
RIGHT_EYE_QUALITY     = PASS / FAIL
WEAPON_VISIBLE_STATE  = PASS / FAIL / NOT_RELEVANT
USER_HEADSET_VERDICT  = ACCEPT / RED
```

Do not infer these from counters or desktop captures.

## AFTER ACCEPT

Only after ACCEPT, prepare one child with one missing fact:

`CAN TRUE L/R SOURCE GEOMETRY REPLACE SYNTHETIC DEPTH EYES WITHOUT LOSING THE ACCEPTED WORLD/CAMERA/XR BASELINE?`

Constraints for that future child:
- preserve proven private-RTV XR bridge;
- preserve accepted world/camera behavior byte/logically where possible;
- do not simultaneously change HEAD, weapon, NEAR, temporal, shadow, cadence;
- recover a proven true-L/R mechanical donor rather than rewrite stereo from scratch;
- require new explicit headset verdict.

## AFTER RED

Do not make v6.0.2/v6.0.3 by visual tuning.

Classify v6.0.1 whole-build path `VISUAL_RED` and salvage only:
`PRIVATE_RTV_XR_BRIDGE`.

Next evidence task becomes:
`RECOVER EXACT HISTORICAL USER-ACCEPTED SINGLE-WINDOW PACKAGE IDENTITY`.

No guessed package names. No neighboring-timestamp promotion.

## ANALYZER TASK — SEPARATE, NOT CURRENT VISUAL MUTATION

The fresh verdict generator has false-negative fields:
- transport FAIL despite real submits;
- eye-stage copies 0 despite raw 9382;
- restore FAIL despite raw PASS.

Later make a deterministic analyzer-only patch that reads authoritative raw fields and includes prerequisite evidence counts.

Do not mix that tooling repair into the next renderer LIVE.

## FORBIDDEN NOW

- no K/PosePair;
- no GOODLINE/R2/T1/v17 whole-build descendant;
- no later Z jump;
- no arbitrary convergence/IPD/FOV matrix;
- no weapon/NEAR work;
- no temporal/shadow work;
- no broad reverse;
- no new launcher architecture.
