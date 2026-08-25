# Crysis 2 VR State

## CURRENT GATE — 2026-08-25

`220427 PARTIAL VISUAL BASELINE -> SCALE / SOURCE-PROJECTION CONTRACT`

Fresh direct user verdict is now bound. 220427 is not a HARD RED: scale is wrong/problematic, but the rest is broadly normal/promising enough to continue from this control.

Read first:
1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `docs/MONO_QUALITY_ANCHOR_20260818.md`
3. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
4. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
5. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
6. `docs/FALSIFIED.md`
7. `docs/NEXT.md`
8. `experiments/NEXT_EXPERIMENT.md`

Evidence law:
`USER_HEADSET_VERDICT > captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > package intent`.

## LATEST LIVE

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Raw mechanical facts:

```text
XR session creation/begin       = YES
submit_count                    = 4691
ever_submitted                  = 1
eye_stage_ready                 = 1,1
eye_stage_copies                = 9382
reproject_ready                 = 1
reproject_draws                 = 9382
xr_capture_count                = 33
raw RESTORE_OK                  = True
native eye records L/R          = 0/0
```

The historical v6.0.0 `XR_RTV_CREATE_FAIL` blocker is mechanically closed.

## DIRECT USER VISUAL VERDICT

```text
USER_HEADSET_VERDICT       = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE                = FAIL
WHOLE_BUILD_VISUAL_RED     = NO
FULL_USER_VISUAL_GREEN     = NO
```

User report: scale is problematic, otherwise this branch is broadly normal and worth finishing.

Do not infer unspoken PASS/FAIL for fusion, shadows/light or RIGHT-eye quality from this verdict alone.

## CURRENT ARCHITECTURE

220427 headset source:

`ONE CENTER RGB + inverse depth -> x64 depth reprojection -> synthetic LEFT/RIGHT -> private eye RTs -> XR swapchains`.

Therefore:

```text
PRIVATE_RTV_XR_BRIDGE               = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT      = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER        = NO
```

Mono RGB+depth/Z reprojection remains a current working/control path, not the assumed final renderer.

## RECOVERED MONO QUALITY PROPERTY

Historical `CRYSIS2VR_FULL_POSE_WORLD_NEAR_RESULT_20260818_030228.zip` retained:

```text
r_MotionBlur=0
r_PostMSAA=0
```

and its contemporary council record explicitly ties those settings to the cleaner image reported by the user.

Classification:
`COMPONENT_VISUAL_GREEN: CLEAN_MONO_IMAGE_QUALITY_SETTINGS`.

Fresh 220427 RESULT does not prove whether those settings were active:
`220427 CLEAN_MONO_QUALITY_PAIR = UNKNOWN`.

Separate stock-native-SBS bisection showed MotionBlur OFF alone and SSAO OFF alone did not cure stock RIGHT-eye softness. Keep that distinction.

## SCALE / RESOLUTION EVIDENCE

Fresh 220427:

```text
source_eye / game_texture = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
```

Historical 030228 already exposed:

```text
calculated source target ~= 2032x1968
actual producer          = 1400x1050
WORLD union projection   = 110.747 deg / 1.02737
FOB_NEAREST              = 55 deg / 1.33333
```

So scale is now treated first as a projection/source-resolution/reprojection-rectangle contract problem.

Do not jump to arbitrary worldScale/IPD/convergence tuning.

## ANALYZER CORRECTION

Fresh generated `Z_REPROJECTION_VERDICT.txt` incorrectly reports transport/copy/restore failure despite raw successful runtime evidence.

Classification:
`ANALYZER_FALSE_NEGATIVE / SUMMARY_PARSER_BUG`.

## CURRENT NEXT

Preserve the exact 220427 bridge and broadly acceptable behavior.

The next work is surgical:
1. recover/verify whether `r_MotionBlur=0` + `r_PostMSAA=0` are active in the exact 220427 lineage;
2. map actual producer dimensions to center render projection, packed depth projection, XR eye FOV, reprojection sampling rectangle and submitted swapchain rectangle;
3. change one scale/quality variable category per child;
4. require direct headset verdict after each LIVE.

## EXISTING HARD REDS REMAIN HARD RED

No direct visual descendants from:
- `C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage;
- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`;
- `CRYSIS2VR_GOODLINE_NATIVE_SINGLE_WINDOW_v1.0.0_ONECLICK.zip`;
- R2 `201208` binocular/telescope path;
- native/NVIDIA monitor-stereo final-renderer paths;
- black-headset DualWorld family.

## PRESERVED COMPONENT AUTHORITIES

- `CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip` = world stability/no flicker donor, fusion failed.
- `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` = camera ownership reference.
- `CUSTOM_DUAL_T1 v1.0.1 / 212003` = true-private-L/R mechanical donor only.
- `030228` clean mono settings = `r_MotionBlur=0 + r_PostMSAA=0` quality donor.
- controller-directed firing evidence = weapon-direction donor only.
- historical one-window/good-scale/stable-head behavior profile remains useful, exact package identity still OPEN.

## PARKED

Until scale/quality control is closed:
- true-L/R architecture merge;
- PosePair/K;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- later Z descendants;
- release optimization.

## RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
