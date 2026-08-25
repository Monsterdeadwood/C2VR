# C2VR — CLEAN MONO QUALITY / SCALE ANCHOR

Recovered 2026-08-25 from historical corpus.

## WHY THIS MATTERS NOW

Fresh `CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip` is now directly user-classified as promising/mostly normal apart from a scale problem.

The historical mono/reprojection lineage contains an important quality fact that must not be lost when iterating from 220427.

## EXACT HISTORICAL QUALITY FACT

Result family:
`CRYSIS2VR_FULL_POSE_WORLD_NEAR_RESULT_20260818_030228.zip`

Result SHA256:
`8EFAE73A7B6E30230D56FC3E66DC6BAE3D78E9118425C79F246748F0FBD26D72`

Historical launch/config retained:

```text
r_MotionBlur=0
r_PostMSAA=0
```

The contemporary council record explicitly states:

```text
r_MotionBlur=0 and r_PostMSAA=0 were retained and correspond to the cleaner image reported by the user.
```

Classification:
`COMPONENT_VISUAL_GREEN: CLEAN_MONO_IMAGE_QUALITY_SETTINGS`

This is a property/donor fact, not a whole-build visual-GOLD claim.

## IMPORTANT DISTINCTION

Separate stock-native-SBS RenderDoc bisection showed:
- stock 65 mm RIGHT eye was already softer than LEFT;
- `r_MotionBlur=0` alone did NOT cure stock stereo eye asymmetry;
- `r_SSAO=0` alone also did NOT cure it.

Therefore do not generalize:
`MotionBlur OFF fixes all Crysis stereo blur`.

The supported claim is narrower:
within the clean mono/reprojection lineage, the pair

```text
r_MotionBlur=0
r_PostMSAA=0
```

was retained and historically corresponded to a cleaner image reported by the user.

That property is relevant to 220427 because 220427 is also a mono-center + depth-reprojection lineage.

## HISTORICAL SCALE / RESOLUTION FACT FROM 030228

The same council result proved:

```text
calculated source target  ~= 2032x1968
actual shared producer    = 1400x1050
WORLD union projection    = 110.747 deg / ratio 1.02737
FOB_NEAREST               = 55 deg / ratio 1.33333
```

It explicitly selected the next surgical direction as:
- unify projection ownership where required;
- force/verify actual DXGI source dimensions rather than assuming launch CVars changed the producer.

The old launch attempts using `+r_Width/+r_Height/+r_Fullscreen/+r_Driver` were rejected as unknown commands in that result and must not be reused blindly.

## FRESH 220427 OBSERVATION

Fresh result inspection shows:

```text
XR capture source_eye     = 1600x1200
host game_texture         = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
mono_camera near/far      = 0.24 / 2000
native eye records L/R    = 0 / 0
```

Direct fresh user verdict:
- scale is wrong / problematic;
- otherwise the result is broadly normal/promising and worth finishing;
- this is NOT a whole-build reject.

Classification:

```text
USER_HEADSET_VERDICT_220427 = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE                 = FAIL
WHOLE_BUILD_VISUAL_RED      = NO
FULL_USER_VISUAL_GREEN      = NO
```

Other visual axes not explicitly stated by the user in this verdict remain UNBOUND rather than being guessed.

## NEXT CAUSAL POLICY

Do not rewrite the renderer.

Preserve:
- 220427 private-RTV XR bridge;
- 220427 working Quest submit path;
- current usable world/head behavior unless a direct regression is observed.

Recover separately:
- clean mono quality pair `r_MotionBlur=0 + r_PostMSAA=0`;
- scale/projection/source-resolution contract.

The next child should NOT also change:
- true-L/R architecture;
- weapon/NEAR ownership;
- temporal/shadow policy;
- cadence K;
- controller rig.

## FIRST TECHNICAL QUESTION

Before changing scale numerically, establish the exact 220427 relationship among:

```text
actual producer dimensions
center render projection/FOV/ratio
packed depth projection
XR per-eye FOV
reprojection sampling rectangle
submitted swapchain rectangle
```

The scale defect should be treated as a projection/source-contract problem first, not as arbitrary worldScale/IPD/convergence tuning.

## QUALITY QUESTION

Verify whether 220427 already forces:

```text
r_MotionBlur=0
r_PostMSAA=0
```

The fresh RESULT does not contain enough config/launch evidence to prove those two settings were active.

Therefore current status:
`220427 CLEAN_MONO_QUALITY_PAIR = UNKNOWN`.

Do not assume they were active and do not assume adding them alone will solve scale.
