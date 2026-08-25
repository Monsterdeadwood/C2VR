# Crysis 2 VR

Native VR integration research for **Crysis 2 retail 1.9 / CryEngine DX11**.

## CURRENT STATUS — PROMISING 220427 CONTROL / SCALE + QUALITY CLOSURE

**WORKING BUILD FIRST. USER VISUAL VERDICT FIRST.**

Current gate:

`220427 PARTIAL VISUAL BASELINE -> CLEAN MONO QUALITY CONTROL -> SCALE / SOURCE-PROJECTION CONTRACT`

Fresh direct user verdict:
- scale is wrong/problematic;
- otherwise the result is broadly normal/promising and worth finishing;
- 220427 is not a whole-build visual HARD RED;
- it is not yet FULL_USER_VISUAL_GREEN either.

Read first:
1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `docs/MONO_QUALITY_ANCHOR_20260818.md`
3. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
4. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
5. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
6. `docs/FALSIFIED.md`
7. `docs/STATE.md`
8. `docs/NEXT.md`
9. `docs/SYNC.md`
10. `experiments/NEXT_EXPERIMENT.md`

## LATEST LIVE — Z-REPROJECTION v6.0.1 / 220427

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Raw result proves:

```text
XR session ran            = YES
submit_count              = 4691
ever_submitted            = 1
eye_stage_ready           = 1,1
eye_stage_copies          = 9382
reproject_draws            = 9382
xr_capture_count          = 33
raw restore               = PASS
```

The old `XR_RTV_CREATE_FAIL` blocker is mechanically closed.

Actual headset source remains:

`CENTER RGB + inverse depth -> synthetic LEFT/RIGHT depth reprojection -> private eye RT -> XR swapchains`.

So:

```text
PRIVATE_RTV_XR_BRIDGE          = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER   = NO
USER_HEADSET_VERDICT           = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE                    = FAIL
FULL_USER_VISUAL_GREEN         = NO
```

Mono RGB+depth/Z reprojection is the current working/control path, not the assumed final renderer.

## RECOVERED CLEAN-MONO QUALITY FACT

Historical result:
`CRYSIS2VR_FULL_POSE_WORLD_NEAR_RESULT_20260818_030228.zip`
SHA256 `8EFAE73A7B6E30230D56FC3E66DC6BAE3D78E9118425C79F246748F0FBD26D72`.

Its contemporary council record explicitly says:

```text
r_MotionBlur=0
r_PostMSAA=0
```

were retained and corresponded to the cleaner image reported by the user.

Classification:
`COMPONENT_VISUAL_GREEN: CLEAN_MONO_IMAGE_QUALITY_SETTINGS`.

Fresh 220427 RESULT does not prove whether these two settings were active. Recover the exact current config before changing anything.

Important distinction: separate stock native-SBS tests showed MotionBlur OFF alone and SSAO OFF alone did not cure the stock RIGHT-eye softness. Do not turn the mono quality observation into a universal stereo-blur claim.

## CURRENT SCALE EVIDENCE

Fresh 220427:

```text
source_eye / game_texture = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
```

Historical 030228 already exposed a related contract mismatch:

```text
calculated source target ~= 2032x1968
actual producer          = 1400x1050
WORLD union projection   = 110.747 deg / 1.02737
FOB_NEAREST              = 55 deg / 1.33333
```

The current scale problem is therefore treated first as a **projection/source-resolution/reprojection-rectangle contract** problem.

Do not start with arbitrary `worldScale`, IPD or convergence grids.

## NEXT

1. Recover authoritative 220427 values for `r_MotionBlur` and `r_PostMSAA` from the exact package/config lineage.
2. If already `0/0`, skip redundant quality mutation.
3. If not, run one quality-only child changing only those two known historical settings.
4. Freeze the cleaner state.
5. Map actual producer size, center projection, packed-depth projection, XR eye FOV, reprojection sample rect, XR swapchain and submitted subImage rect.
6. Correct the first proven scale mismatch only.
7. Get direct headset verdict after every LIVE.

Do not merge true-L/R, HEAD, weapon, NEAR, temporal, shadow or cadence work into this closure.

## EVIDENCE LAW

For visual/playability acceptance:

`USER_HEADSET_VERDICT > XR/LR captures > raw LIVE RESULT/status > counters > generated analyzer summary > static validation > design intent`.

Permanent guards:
- `RESULT ZIP != LIVE`;
- a broken analyzer summary does not erase a proven LIVE;
- package names such as GOLD/GREEN/CLEAN/NO_BINOCULAR/ONE_WINDOW are not acceptance evidence;
- bare `GREEN` is forbidden, qualify the exact property;
- `VACUOUS_PASS` with missing/zero/None prerequisites is invalid;
- unresolved historical bindings remain OPEN/UNBOUND rather than guessed.

## CURRENT USER VISUAL HARD REDS

Do not use as direct visual parents:
- `C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage: catastrophic camera/world + moving/sliding light/shadow state;
- T1 PosePair K0: visually worse;
- R2 `201208`: binocular/telescope catastrophe;
- GOODLINE v1.0.0: broken shadows + blurred RIGHT eye;
- native/NVIDIA/monitor stereo as final VR renderer;
- DualWorld black-headset family.

## PARTIAL AUTHORITIES TO KEEP SEPARATE

- **World stability / no flicker:** exact `CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`.
- **Camera ownership:** `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` + single-source topology around `Crysis2.exe+0x0057AC76`.
- **Quest/private-RTV bridge:** fresh 220427.
- **Clean mono image quality:** `r_MotionBlur=0 + r_PostMSAA=0` from 030228 lineage.
- **True private L/R mechanics:** `CUSTOM_DUAL_T1 v1.0.1 / 212003`, mechanical donor only.
- **Weapon direction:** controller-directed firing donor only.
- **Historical accepted one-window/good-scale/stable-head behavior:** useful profile, exact package identity still OPEN.

## CANONICAL RENDERER FACTS THAT REMAIN USEFUL

One prepared render-list may execute twice for two eyes. Do not add a second high-level `RenderWorld` / `EF_StartEf` merely to obtain stereo.

`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`

RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Pixels and the render pose/FOV/contract metadata that produced them are one atomic publication unit. Never relabel stale pixels with a newer pose.

## WORKING MODEL

`SYNC -> EXACT CURRENT CONTROL -> ONE MISSING FACT -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP / ADAPT / STOP`

**PARALLELIZE EVIDENCE - SERIALIZE MUTATION.**

## REPOSITORY MAP

- `docs/` — canonical state, visual ledger, historical audit, quality/scale anchors, proven/falsified facts
- `research/` — source/beta/mod/donor evidence and focused blocker research
- `experiments/` — reproducible causal experiments and executed result records
- `runtime/` — technical source authorities and selective donors
- `tools/` — deterministic extraction/build/analysis tooling

## EXACT RETAIL BASELINE

- Game path: `C:\GOG Games\Crysis 2`
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
