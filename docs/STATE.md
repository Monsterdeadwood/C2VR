# Crysis 2 VR State

## CURRENT GATE — 2026-08-27

`220427 PARTIAL VISUAL BASELINE -> SCALE-ONLY DEPTH PROJECTION TRUTH`

Direct headset verdict remains:

```text
USER_HEADSET_VERDICT       = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE                = FAIL
WHOLE_BUILD_VISUAL_RED     = NO
FULL_USER_VISUAL_GREEN     = NO
```

Read first:
1. `docs/Z_V601_GEOMETRY_DEFECT_MAP_20260827.md`
2. `docs/Z_V601_OFFLINE_SCALE_QUALITY_AUDIT_20260827.md`
3. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
4. `experiments/NEXT_EXPERIMENT.md`
5. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
6. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
7. `docs/FALSIFIED.md`
8. `docs/NEXT.md`

Evidence law:
`USER_HEADSET_VERDICT > captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > package intent`.

## LATEST WORKING QUEST CONTROL

`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`
SHA256 `483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`.

```text
XR submits                    4691
eye-stage copies              9382
reprojection draws            9382
fresh packed game frames      4109
XR captures                   33
IPD                           62.8501 mm
HMD/union world injections    4160
restore                       PASS
native scene L/R records      0/0
```

Architecture:
`ONE CENTER RGB + inverse depth -> synthetic LEFT/RIGHT -> private typed eye RTVs -> CopyResource -> XR swapchains -> Quest`.

```text
PRIVATE_RTV_XR_BRIDGE          = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER   = NO
```

The v6.0.0 direct-XR-RTV blocker is closed. The Z path remains a working/control path, not the assumed final renderer.

## EXACT v6.0.0 -> v6.0.1 LINEAGE

Physical packages recovered and diffed:

```text
v6.0.0 SHA256 875853652D3A2ACC0E684A2E9BE2118D69FB2252E4B21B677DA4CF5105922656
v6.0.1 SHA256 E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A
```

Meaningful v6.0.1 change is private typed eye staging RTVs plus CopyResource into XR swapchain images. Camera/depth/reprojection geometry is inherited from v6.0.0.

## DEFECT A — CURRENT PRIMARY ROOT: WORLD DEPTH PROJECTION OWNER

Fresh 220427 contains direct same-run contradiction:

```text
DOWNSTREAM WORLD Renderer::SetCamera
  vfov  = 1.991177 rad
  ratio = 0.963753
  near  = 0.12
  far   = ~2000

DEPTH PACKER
  near  = 0.24
  far   = 2000
```

Fresh camera census:
- 112,440 valid Renderer::SetCamera observations total;
- 74,347 in union-WORLD family with `near=0.12`;
- exactly 4,160 at proven primary game-camera lineage `0x0057AC76`, matching 4,160 HMD/union injections;
- ~27,817 separate ~55-degree / `near=0.03` calls consistent with FOB_NEAREST.

Active packed depth is stable:
`MAIN_DSV 1600x1200 fmt=45`.

Exact source order:
1. upstream RenderWorld hook publishes union projection metadata with near=0.24;
2. original RenderWorld runs;
3. downstream Renderer::SetCamera establishes actual WORLD near=0.12;
4. Present later packs MAIN_DSV using still-published upstream near=0.24.

With actual near 0.12 but assumed 0.24, ordinary WORLD distances reconstruct approximately 2x too far. `invZ` and synthetic disparity are approximately halved.

Classification:
`SCALE_ROOT_CAUSE = STRONGLY PROVEN: DEPTH_PROJECTION_OWNER_MISMATCH`.

No extra mandatory x100/x0.01 unit conversion is supported. HMD/native-eye evidence strongly supports ~1 camera world unit = 1 meter in this chain.

## NEXT LIVE — A ONLY

Exact 220427 parent.

At existing primary downstream Renderer::SetCamera:
- require primary caller `0x0057AC76` lineage;
- require readable/sane CCamera;
- require FOV close to latest WORLD union FOV;
- publish live `vfov/ratio/near/far` into the existing depth-pack contract;
- keep upstream publish only as bootstrap/fallback.

Mechanical PASS requires actual downstream WORLD tuple == packed-depth tuple and XR submit remains alive.

Do not hardcode 0.12. Runtime measurement is authoritative.

User verdict first judges stationary WORLD scale. Weapon is excluded from the primary scale oracle because FOB_NEAREST is a separate projection family.

## DEFECT B — EYE BASIS

Exact v6.0.1 reprojection computes current eye offset but rotates it by the fixed recenter orientation `g_centerQ`.

The center scene is rendered under current HMD orientation, so the stereo eye vector should be current/render-head-local.

Fresh telemetry matches the defect: physical IPD remains ~62.85 mm while the logged reprojection X half-baseline moves from ~31 mm down to ~3.8 mm under head motion and later returns.

The same v6.0.1 source already uses current `headQ/invHead` correctly in its exact-eye publication path. Physical v6.1 explicitly corrected the reprojection basis from initial-recenter to current/tagged head-local.

Expected effect: head-motion-dependent stereo shear/rubber, not the primary stationary scale error.

Park until A verdict.

## DEFECT C — NON-ATOMIC PACKED FRAME REUSE

Fresh:

```text
XR submits        4691
fresh pack frames 4109
minimum reused    582 (~12.4%)
```

Exact v6.0.1 can reuse previous packed pixels/depth while reading newer current pose/FOV for reprojection/submission. Pixels + depth + render pose + FOV + display time are not one immutable transaction.

Expected effect: temporal rubber/drift/tearing under motion.

Physical v6.1 introduced frame tagging to close this class of error.

Park until A and then B are independently judged.

## DEFECT D — DEPTH EDGE SAMPLING

v6.0.1 uses a linear sampler on packed RGB + inverse-Z alpha, so silhouette filtering creates non-physical intermediate depth.

Later lineage split filtered color from POINT inverse-Z.

Expected effect: rubber/halo stereo edges, not global scale.

## DEFECT E — QUALITY CONFIG INHERITANCE

Exact v6.0.1 runner does not force `r_MotionBlur`, `r_PostMSAA`, `r_FSAA`, `r_MSAA` or `r_SSAO`; it inherits existing system.cfg.

Classification:
`220427_QUALITY_CVARS = NONDETERMINISTIC_INHERITANCE_FROM_EXISTING_SYSTEM_CFG`.

Historical cleaner mono donor:

```text
r_MotionBlur=0
r_PostMSAA=0
```

## DEFECT F — SOURCE ANGULAR RAY DENSITY

Fresh center source `1600x1200` covers ~114-degree union FOV. It is under-sampled for Quest, especially vertically.

Historical live-XR-derived target:

```text
recommended eye = 1504x1616
source target   ~= 2032x1968
```

Later 2032x1968 branches still often retained defect A near=0.24, so their whole-build visual outcomes do not falsify the resolution correction in isolation.

## CORRECTED V10 / V10.1 / V11 HISTORY

Important correction: do NOT describe v11 as a descendant regression from the later v10.1 depth-truth result.

Timeline/evidence:

```text
v10 visual line 034749
  WORLD + FOB_NEAREST projection alignment improved
  actual 2032x1968 source
  recorded user improvement: weapon no longer counter-moves in the same way
  no separate WORLD_SCALE=PASS is established from the surviving verdict text

v11 133603
  working XR transport/submission
  cadence/frame-contract/ray-density work
  runtime mono_camera still reports near=0.24

v10.1 134133
  downstream renderer tuple near=0.12
  packed tuple near=0.12
  WORLD_SCALE_ARBITER=PASS_NUMERIC_DEPTH_CONTRACT
  reprojection shader compile failure
  XR submit=0
  no headset scale verdict
```

Therefore the high-value missing combination is:

`WORKING XR + CORRECT DOWNSTREAM DEPTH TRUTH IN THE SAME LIVE`.

v10/v11 and v10.1 are component/sibling evidence donors, not a single clean linear ancestry.

Also: old static validation could preserve a `PROJECTION_GREEN` label without asserting the later Renderer-depth-truth property. New builds must validate actual downstream and packed tuples, not names.

## EXPERIMENT ORDER

One causal category per LIVE:

1. A `DEPTH_PROJECTION_OWNER_ONLY`;
2. B `EYE_BASIS_ONLY`;
3. C `ATOMIC_PACKED_FRAME_CONTRACT_ONLY`;
4. D `DEPTH_SAMPLER_ONLY`;
5. E `QUALITY_CVARS_ONLY`;
6. F `SOURCE_RAY_DENSITY_ONLY`;
7. only then decide how accepted properties migrate into final true/private L/R architecture.

This order is not permission to run all descendants automatically. Each step requires the previous direct headset verdict and baseline freeze.

## IMPORTANT WORLD / WEAPON SPLIT

FOB_NEAREST remains separate:
- owner around `+0x000FF340`;
- SetCamera return `+0x000FF456`;
- restore `+0x000FF4A3`;
- fresh family near ~0.03 / FOV ~55 degrees.

A successful WORLD depth-scale correction does not imply weapon/viewmodel is fixed.

## EXISTING HARD REDS REMAIN HARD RED

No whole-build visual descendants from:
- RC33/v17 catastrophic world/camera/light instability;
- T1 PosePair K0;
- GOODLINE v1.0.0;
- R2 `201208` binocular/telescope path;
- native/NVIDIA monitor-stereo as final renderer;
- DualWorld black-headset family.

Component donors may still be harvested narrowly when separately proven.

## PARKED

Until the ordered geometry/quality controls are closed:
- final true-L/R merge;
- PosePair/K;
- final HEAD rewrite;
- weapon/NEAR/controller work;
- shadow/temporal optimizations outside the specific C contract;
- arbitrary IPD/worldScale/convergence sweeps;
- broad reverse;
- release optimization.

## RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
