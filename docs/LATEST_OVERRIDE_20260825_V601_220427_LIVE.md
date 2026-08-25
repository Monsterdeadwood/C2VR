# C2VR LATEST OVERRIDE — V6.0.1 PRIVATE RTV LIVE 220427

Date: 2026-08-25

This file supersedes older NEXT/STATE text that calls 220427 user verdict UNBOUND or treats the v6.0.1 runtime as merely PREPARED/UNRUN.

Read together with:
- `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
- `docs/MONO_QUALITY_ANCHOR_20260818.md`
- `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
- `docs/FALSIFIED.md`

## FRESH LIVE

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Raw runtime proves:
- XR session created and began;
- `submit_count=4691`;
- `ever_submitted=1`;
- private eye staging ready for both eyes;
- `eye_stage_copies=9382`;
- `reproject_draws=9382`;
- 33 XR stereo pair captures;
- raw restore PASS.

The historical v6.0.0 direct-XR-RTV blocker is mechanically closed.

## DIRECT USER HEADSET VERDICT — NOW BOUND

Fresh user verdict after 220427:
- scale is wrong/problematic;
- otherwise the result is broadly normal/promising;
- user considers it worth finishing rather than discarding.

Classification:

```text
USER_HEADSET_VERDICT          = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE                   = FAIL
WHOLE_BUILD_VISUAL_RED        = NO
FULL_USER_VISUAL_GREEN        = NO
```

Do not invent PASS/FAIL for binocular fusion, shadows/light or RIGHT-eye quality from this sentence alone. Those axes remain UNBOUND unless separately stated.

220427 is therefore a valid iterative control parent for narrow scale/quality work, but not a final renderer.

## ARCHITECTURE FACT

220427 headset source is still:

```text
center color + inverse depth
 -> x64 depth reprojection
 -> synthetic LEFT / RIGHT
 -> private typed eye RTs
 -> CopyResource to XR swapchains
 -> Quest
```

It is NOT true independent native/private LEFT+RIGHT scene rendering.

Classification:

```text
PRIVATE_RTV_XR_BRIDGE          = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER   = NO
```

Mono RGB+depth/Z reprojection remains a control/current-working path, not the assumed final renderer architecture.

## RECOVERED CLEAN-MONO QUALITY ANCHOR

Historical result family:
`CRYSIS2VR_FULL_POSE_WORLD_NEAR_RESULT_20260818_030228.zip`
SHA256 `8EFAE73A7B6E30230D56FC3E66DC6BAE3D78E9118425C79F246748F0FBD26D72`.

The historical council explicitly recorded that:

```text
r_MotionBlur=0
r_PostMSAA=0
```

were retained and corresponded to the cleaner image reported by the user.

This is now a permanent component visual-quality donor:
`COMPONENT_VISUAL_GREEN: CLEAN_MONO_IMAGE_QUALITY_SETTINGS`.

Important limitation:
separate stock native-SBS tests showed MotionBlur OFF alone and SSAO OFF alone did not cure stock RIGHT-eye softness. Do not overgeneralize the mono quality observation into a universal stereo-blur fix.

Fresh 220427 RESULT does not prove whether `r_MotionBlur=0` and `r_PostMSAA=0` were active, so:
`220427 CLEAN_MONO_QUALITY_PAIR = UNKNOWN`.

## CURRENT SCALE / SOURCE FACTS

Fresh 220427:

```text
XR capture source_eye = 1600x1200
host game_texture     = 1600x1200
union_fov_deg         = 114.086
union_ratio           = 0.963753
```

Historical 030228 already proved a similar class of mismatch:

```text
calculated source target ~= 2032x1968
actual producer          = 1400x1050
WORLD union projection   = 110.747 deg / 1.02737
FOB_NEAREST              = 55 deg / 1.33333
```

Therefore the current scale defect must first be treated as a projection/source-resolution/reprojection-contract problem, not arbitrary worldScale/IPD/convergence tuning.

## ANALYZER OVERRIDE

The generated `Z_REPROJECTION_VERDICT.txt` is contradicted by raw evidence for XR transport, eye-stage copies and restore.

Classification:
`ANALYZER_FALSE_NEGATIVE / SUMMARY_PARSER_BUG`.

Do not repeat the LIVE or redesign transport to satisfy the broken summary parser.

## CURRENT GATE

`220427 PARTIAL VISUAL BASELINE -> SCALE / SOURCE-PROJECTION CONTRACT`

Preserve the working bridge and current broadly usable visual behavior.

Next causal work is limited to:
1. establish exact producer/projection/reprojection rectangle contract;
2. restore/verify historical clean-mono quality settings as a separate minimal delta;
3. correct scale without touching unrelated renderer ownership.

## FORBIDDEN IN NEXT CHILD

- no GOODLINE/R2/T1/v17 whole-build resurrection;
- no K/PosePair;
- no true-L/R architecture rewrite in the same scale test;
- no weapon/NEAR merge;
- no temporal/shadow rewrite;
- no controller rig work;
- no arbitrary convergence/IPD grid;
- no broad reverse.

One scale/quality fact at a time while 220427 remains the working control.

## EVIDENCE LAW

`USER_HEADSET_VERDICT > deterministic captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > package intent`.
