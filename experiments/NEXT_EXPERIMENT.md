# Crysis 2 VR — NEXT EXPERIMENT

## CURRENT GATE

`220427 PARTIAL VISUAL BASELINE -> CLEAN MONO QUALITY CONTROL -> SCALE CONTRACT`

Fresh direct user verdict:
- scale problematic;
- otherwise broadly normal/promising and worth finishing.

Therefore no renderer-family reset.

## PREFLIGHT — exactly 5 lines

MISSING FACT = whether exact 220427 already uses the historical clean-mono quality pair `r_MotionBlur=0 + r_PostMSAA=0`, and if not, whether restoring only that pair preserves current behavior while improving/locking image clarity.
WHY THIS PARENT = 220427 has a working Quest bridge and a direct PARTIAL_ACCEPT user verdict; historical mono lineage explicitly ties these two settings to a cleaner image reported by the user.
ONE MUTATION CATEGORY = image-quality CVars only; no projection/scale change in the same LIVE.
PASS = same current world/head/scale behavior, XR bridge unchanged, image clarity preserved or improved, no new visual regression.
FAIL = world/head regression, bridge failure, worse image, new binocular/telescope behavior, or restore failure.

## LINEAGE

BASE_RESULT = `CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`
BASE_RESULT_SHA256 = `483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

BASE_VISUAL_STATUS:

```text
USER_HEADSET_VERDICT = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE          = FAIL
WHOLE_BUILD_RED      = NO
```

KEEP:
- exact private-RTV XR bridge;
- center color+depth producer;
- depth reprojection implementation;
- current camera/pose policy;
- current source size and scale behavior for the quality-control run;
- launcher/build/restore lineage.

HISTORICAL QUALITY DONOR:
`CRYSIS2VR_FULL_POSE_WORLD_NEAR_RESULT_20260818_030228.zip`
SHA256 `8EFAE73A7B6E30230D56FC3E66DC6BAE3D78E9118425C79F246748F0FBD26D72`.

Recovered accepted property:

```text
r_MotionBlur=0
r_PostMSAA=0
```

corresponded to the cleaner mono image reported by the user.

## STEP 0 — RECOVER EXACT CURRENT CONFIG

Before creating any child, inspect the exact historical/recovered 220427 package lineage and determine authoritative current values of:

```text
r_MotionBlur
r_PostMSAA
```

The RESULT ZIP itself does not contain enough config/launch evidence to prove them.

If both are already `0`, quality-control mutation is unnecessary:
`QUALITY_PAIR_ALREADY_PRESENT`.

Then skip directly to scale-contract instrumentation without changing these values.

If either is not `0`, create the minimal child below.

## QUALITY CHILD — ONLY IF NEEDED

ONLY DELTA:

```text
r_MotionBlur=0
r_PostMSAA=0
```

Everything else byte/logically unchanged where possible.

Do not change:
- union FOV;
- source dimensions;
- XR swapchain dimensions;
- IPD;
- worldScale;
- reprojection math;
- near/weapon;
- shadows;
- temporal ownership;
- cadence.

## OBSERVE

Direct headset verdict fields:

```text
IMAGE_CLARITY         = better / same / worse
WORLD_SCALE           = same_bad / changed_unexpectedly
WORLD_HEAD_BEHAVIOR   = same / regression
BINOCULAR_FEEL        = same / regression
XR_OUTPUT             = stable / regression
```

The expected scale result for this quality-only child is deliberately:
`same_bad`.

If scale changes, the experiment is confounded.

## NEXT AFTER QUALITY CONTROL

Freeze whichever quality state is better, then perform a separate instrumentation/scale child.

Fresh 220427 facts to preserve:

```text
source_eye / game_texture = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
```

Scale child must first measure/map:

```text
actual producer dimensions
center RenderWorld projection
packed depth projection
XR left/right FOV
reprojection sample rectangle
XR swapchain dimensions
submitted subImage rectangle
```

Only then change the first proven mismatch.

## FORBIDDEN

- no arbitrary worldScale/IPD/convergence sweep;
- no true-L/R merge in this experiment;
- no T1/R2/GOODLINE/v17 resurrection;
- no K/PosePair;
- no weapon/NEAR mutation;
- no temporal/shadow mutation;
- no new launcher architecture;
- no broad reverse.

The purpose is simple:
**lock the cleanest version of the already-promising 220427 image, then repair scale causally.**
