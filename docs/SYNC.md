# Crysis 2 VR — STATE SYNC

## GLOBAL OVERRIDE — 2026-08-25 / 220427 PARTIAL ACCEPT

Every C2VR branch must read these before choosing a parent, planning a LIVE, writing a BAT/PS1, or changing renderer policy:

1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `docs/MONO_QUALITY_ANCHOR_20260818.md`
3. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
4. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
5. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
6. `docs/FALSIFIED.md`
7. `docs/STATE.md`
8. `docs/NEXT.md`
9. `experiments/NEXT_EXPERIMENT.md`

Evidence law:
`USER_HEADSET_VERDICT > deterministic captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > package intent`.

## CURRENT GATE

`220427 PARTIAL VISUAL BASELINE -> CLEAN MONO QUALITY CONTROL -> SCALE / SOURCE-PROJECTION CONTRACT`

Fresh direct user verdict:

```text
USER_HEADSET_VERDICT = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE          = FAIL
WHOLE_BUILD_RED      = NO
FULL_USER_VISUAL_GREEN = NO
```

User says scale is problematic, but otherwise the branch is broadly normal/promising and worth finishing.

Do not demote it to HARD RED.
Do not promote it to final visual GREEN.

## FRESH RESULT

`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`
SHA256 `483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`.

Raw runtime facts:

```text
TARGET_RUNTIME_EXECUTED   = YES
XR_SESSION_RAN            = YES
XR_SUBMITS                = 4691
ever_submitted            = 1
eye_stage_ready           = 1,1
eye_stage_copies          = 9382
reproject_draws            = 9382
xr_capture_count           = 33
raw RESTORE_OK            = True
```

The old direct-XR-RTV blocker is mechanically closed.

## CURRENT ARCHITECTURE

Fresh headset source:

```text
CENTER scene color + inverse depth
 -> x64 host depth reprojection
 -> synthetic LEFT / RIGHT
 -> private typed eye RTs
 -> CopyResource to XR swapchain images
 -> Quest
```

Native/private independent scene-eye rendering was not the source:

```text
native_eye_left_records  = 0
native_eye_right_records = 0
```

Keep:
`PRIVATE_RTV_XR_BRIDGE = MECHANICAL_GREEN`.

Do not call mono+depth reprojection the final renderer.

## RECOVERED CLEAN-MONO QUALITY ANCHOR

Historical result:
`CRYSIS2VR_FULL_POSE_WORLD_NEAR_RESULT_20260818_030228.zip`
SHA256 `8EFAE73A7B6E30230D56FC3E66DC6BAE3D78E9118425C79F246748F0FBD26D72`.

Contemporary council record explicitly states:

```text
r_MotionBlur=0
r_PostMSAA=0
```

were retained and corresponded to the cleaner image reported by the user.

Classification:
`COMPONENT_VISUAL_GREEN: CLEAN_MONO_IMAGE_QUALITY_SETTINGS`.

Fresh 220427 RESULT does not prove whether these two settings were active.

Separate stock native-SBS bisection proved MotionBlur OFF alone and SSAO OFF alone did not cure stock RIGHT-eye softness. Do not confuse the two claims.

## SCALE / SOURCE FACTS

Fresh 220427:

```text
source_eye / game_texture = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
```

Historical 030228:

```text
calculated target ~= 2032x1968
actual producer   = 1400x1050
WORLD union       = 110.747 deg / 1.02737
FOB_NEAREST       = 55 deg / 1.33333
```

This makes scale a projection/source-resolution/reprojection-rectangle contract question first.

Do not run arbitrary worldScale/IPD/convergence grids.

## NEXT ORDER

1. Recover authoritative 220427 values of `r_MotionBlur` and `r_PostMSAA` from the exact package/config lineage.
2. If already `0/0`, do not create a redundant quality child.
3. If not `0/0`, make one minimal quality-only child changing only these two values.
4. Freeze best quality state.
5. Instrument exact source/projection/reprojection/XR-rectangle contract.
6. Correct the first proven scale mismatch only.
7. Get direct headset verdict after each LIVE.

## HARD REDS THAT MUST NOT REAPPEAR AS PARENTS

- `063149` catastrophic camera/world + moving/sliding light/shadow state;
- T1 PosePair K0 visually worse;
- R2 `201208` binocular/telescope catastrophe;
- GOODLINE v1.0.0 broken shadows + blurred RIGHT eye;
- native/NVIDIA/monitor-stereo final renderer;
- DualWorld black-headset family.

## PARTIAL AUTHORITIES TO KEEP SEPARATE

- world stability/no-flicker donor: exact `CUSTOM_VR_OWNER v6.0.1`;
- camera ownership: `A1_NATIVE_REPAIR 173053` + single-source topology;
- private-RTV XR bridge: fresh 220427;
- clean mono image quality: `r_MotionBlur=0 + r_PostMSAA=0` from 030228 lineage;
- true private L/R mechanics: T1 v1.0.1 / 212003 mechanical donor only;
- weapon direction: narrow donor only;
- historical accepted one-window/good-scale/stable-head profile: exact package identity OPEN.

## ANALYZER FALSE NEGATIVE

Fresh generated verdict incorrectly reports transport/copy/restore failures despite raw successful evidence.

Do not repeat the LIVE to satisfy the broken summary parser.
Analyzer repair remains a separate tooling task.

## PARKED

Until clean quality and scale are closed:
- true-L/R renderer merge;
- K/PosePair;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- controller rig;
- release optimization;
- broad reverse archaeology.

## CROSS-BRANCH RULE

`SYNC -> EXACT CURRENT CONTROL -> ONE MISSING FACT -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP / ADAPT / STOP`.

Current control is 220427. Preserve it while fixing quality and scale surgically.
