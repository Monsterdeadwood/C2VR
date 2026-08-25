# Crysis 2 VR State

## CURRENT GATE — 2026-08-25

`220427 V6.0.1 LIVE -> BIND USER HEADSET VERDICT -> VISUAL BASELINE DECISION`

The exact historical Z-reprojection v6.0.1 PRIVATE_RTV recovery is no longer merely PREPARED/UNRUN. It has now executed in the target environment.

Read first:
1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
3. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
4. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
5. `docs/FALSIFIED.md`
6. `docs/NEXT.md`
7. `experiments/NEXT_EXPERIMENT.md`

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

Historical v6.0.0 blocker `XR_RTV_CREATE_FAIL eye=0 image=0 hr=0x80070057` is mechanically closed by private typed eye staging + CopyResource to XR swapchains.

## ARCHITECTURE CLASSIFICATION

Actual headset source in 220427:

`ONE CENTER RGB + inverse depth -> x64 depth reprojection -> synthetic LEFT/RIGHT -> private eye RTs -> XR swapchains`.

Therefore:

```text
LIVE_STATUS                         = LIVE
PRIVATE_RTV_XR_BRIDGE               = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT      = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER        = NO
USER_HEADSET_VERDICT                = UNBOUND
FULL_USER_VISUAL_GREEN              = NO
```

Mono RGB+depth/Z reprojection remains forbidden as the assumed final renderer. It may be retained as a narrow transport/control component.

## ANALYZER CORRECTION

Fresh generated `Z_REPROJECTION_VERDICT.txt` incorrectly reports:
- `OpenXRTransport=FAIL` despite 4691 submits and `ever_submitted=1`;
- `eyeStageCopies=0` despite raw `eye_stage_copies=9382`;
- `Restore=FAIL` despite raw `RESTORE_OK=True`.

Classification:
`ANALYZER_FALSE_NEGATIVE / SUMMARY_PARSER_BUG`.

Do not downgrade the executed runtime to PIPELINE_INCOMPLETE based on those contradicted summary fields.

## CURRENT NEXT

No new build yet.

First bind the user's direct headset verdict for 220427:
- world/head stability;
- binocular/fusion quality;
- shadows/light;
- RIGHT-eye quality;
- scale/geometry;
- general usability.

Then:

### If ACCEPT
Freeze 220427 as a component visual/control baseline, preserve its XR bridge, and isolate the next question to true-L/R/source geometry.

### If RED
Hard-stop v6.0.1 as a whole visual parent, salvage only the PRIVATE_RTV_XR_BRIDGE, and continue recovery of the exact historical user-accepted single-window profile.

## EXISTING HARD REDS REMAIN HARD RED

No direct visual descendants from:
- `C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage;
- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`;
- `CRYSIS2VR_GOODLINE_NATIVE_SINGLE_WINDOW_v1.0.0_ONECLICK.zip`;
- R2 `201208` binocular/telescope path;
- native/NVIDIA monitor-stereo final-renderer paths;
- black-headset DualWorld family.

## PRESERVED COMPONENT AUTHORITIES

- `CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip` = `COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`, fusion still failed.
- `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` = camera ownership reference.
- `CUSTOM_DUAL_T1 v1.0.1 / 212003` = `MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`, not a whole visual parent.
- controller-directed firing evidence remains a weapon-direction donor only.
- historical one-window / good-scale / stable-head / headset-visible behavior profile remains valuable, exact package identity still OPEN.

## PARKED

Until 220427 receives a direct headset verdict:
- PosePair/K;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- later Z v6.1+ descendants;
- arbitrary IPD/FOV/convergence tuning;
- release optimization.

## RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
