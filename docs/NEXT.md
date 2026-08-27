# Crysis 2 VR — NEXT

## CURRENT GATE

`220427 PARTIAL VISUAL BASELINE -> SCALE-ONLY DEPTH PROJECTION TRUTH`

Fresh direct user verdict:
- scale is wrong/problematic;
- otherwise the branch is broadly normal/promising and worth finishing;
- 220427 is not a whole-build visual HARD RED.

Read first:
1. `docs/Z_V601_GEOMETRY_DEFECT_MAP_20260827.md`
2. `docs/Z_V601_OFFLINE_SCALE_QUALITY_AUDIT_20260827.md`
3. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
4. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
5. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
6. `docs/FALSIFIED.md`

## KEEP FROM 220427

```text
XR session / Quest output             KEEP
private typed eye RTV bridge          KEEP
CopyResource to XR swapchain          KEEP
4691 submits                          PROVEN
9382 reprojection draws               PROVEN
current broadly usable visual control KEEP
```

Do not rebuild transport.

## FIRST ROOT — WORLD SCALE

Fresh same-run evidence:

```text
DOWNSTREAM WORLD Renderer::SetCamera:
  vfov  = 1.991177 rad
  ratio = 0.963753
  near  = 0.12
  far   = ~2000

DEPTH PACKER:
  near  = 0.24
  far   = 2000
```

Exact v6.0.1 publishes projection metadata upstream before the final renderer projection exists. Present later linearizes MAIN_DSV with stale upstream `near=0.24`.

At ordinary gameplay distances this reconstructs WORLD Z almost 2x too far and roughly halves synthetic stereo disparity.

Classification:
`SCALE_ROOT_CAUSE = STRONGLY PROVEN: DEPTH_PROJECTION_OWNER_MISMATCH`.

## NEXT CHILD — ONE MUTATION ONLY

Use exact 220427 lineage.

Only mutation category:
`DEPTH_PROJECTION_METADATA_OWNER`.

At the existing proven primary downstream `Renderer::SetCamera` observation (`0x0057AC76` lineage), publish live:

```text
+0x30 vfov
+0x3C ratio
+0x48 near
+0x60 far
```

into the existing pack-depth contract before Present.

Safety gate:
- primarySite only;
- readable valid camera;
- actual FOV within ~0.08 rad of current WORLD union FOV;
- sane ratio/near/far;
- reject FOB_NEAREST and other camera families.

Do not hardcode `0.12` as architecture.

Log and require:

```text
UPSTREAM_RENDERWORLD_PROJECTION
DOWNSTREAM_WORLD_RENDERER_PROJECTION
PACKED_DEPTH_PROJECTION
DOWNSTREAM_WORLD == PACKED_DEPTH
```

Keep upstream publish as startup/fallback. The downstream primary WORLD camera becomes the authoritative final overwrite before pack.

## USER PASS TARGET FOR SCALE CHILD

Judge stationary WORLD first, not weapon:

```text
WORLD_SCALE          = natural / materially corrected
WALLS_ROOMS_PEOPLE   = believable size/depth
DISTANT_WORLD        = believable scale
WORLD_HEAD_BEHAVIOR  = no regression
XR_OUTPUT             = stable
```

Then move head slowly/quickly only as a regression check.

Weapon/FOB_NEAREST is explicitly outside this primary verdict.

## DO NOT CHANGE IN SCALE CHILD

- no eye-basis correction yet;
- no packed-frame temporal rewrite;
- no depth sampler change;
- no source-resolution change;
- no MotionBlur/PostMSAA change;
- no union-FOV change;
- no IPD/worldScale/convergence tuning;
- no weapon/FOB_NEAREST handling;
- no true-L/R merge;
- no XR bridge change.

## COLD-KNOWN DEFECTS AFTER SCALE

These are already proven enough that no broad archaeology is needed later, but they remain parked until the scale verdict:

```text
B EYE BASIS
  v6.0.1 rotates eye offsets by fixed recenter orientation.
  Current/render-head-local basis is required.
  Fresh logged eye X half-baseline collapses from ~31 mm to ~3.8 mm under head motion while physical IPD stays ~62.85 mm.

C FRAME CONTRACT
  4691 XR submits vs 4109 fresh packed frames means >=582 reused XR submits (~12.4%).
  v6.0.1 can reuse old pixels/depth with newer current pose/FOV metadata.

D DEPTH SAMPLING
  v6.0.1 linearly filters packed inverse-Z alpha across silhouettes.
  Later line split color filtering from POINT depth.

E QUALITY CONFIG
  exact v6.0.1 does not deterministically set MotionBlur/PostMSAA.

F SOURCE RAY DENSITY
  1600x1200 is too sparse for ~114-degree union FOV; later live-XR-derived target was about 2032x1968.
```

## CORRECTED BRANCH HISTORY

Do not call v11 a descendant regression from v10.1 depth-truth.

Actual evidence is sibling-like:

```text
v10 visual line 034749
  WORLD + FOB_NEAREST projection alignment improved
  2032x1968 source active
  user-recorded weapon counter-motion improvement
  depth contract still from old near=0.24 family

v11 133603
  working XR submit
  cadence/ray-density/frame-contract work
  runtime mono_camera still near=0.24

v10.1 134133
  downstream renderer near=0.12 == packed near=0.12 numerically
  XR shader compile failed
  submit=0
```

Therefore:

`WORKING_XR + CORRECT_DOWNSTREAM_DEPTH_TRUTH HAS NOT YET BEEN PROVEN TOGETHER IN ONE LIVE.`

That is exactly why the next scale-only child has high information value.

## POST-SCALE LADDER

If scale improves without regression, freeze it and proceed one mutation category at a time:

1. `EYE_BASIS_ONLY` - current/render-head-local eye vector;
2. `ATOMIC_PACKED_FRAME_CONTRACT_ONLY` - pixels+depth+render pose+FOV+display time as one transaction;
3. `DEPTH_SAMPLER_ONLY` - POINT inverse-Z, filtered color;
4. `QUALITY_CVARS_ONLY` - deterministic `r_MotionBlur=0 + r_PostMSAA=0`;
5. `SOURCE_RAY_DENSITY_ONLY` - raise actual producer toward XR-derived ~2032x1968 target;
6. only then decide how accepted properties migrate into final true/private L/R architecture.

Each LIVE gets its own direct headset verdict.

## PARKED

- true private/native L/R merge;
- K/PosePair;
- final HEAD rewrite;
- weapon/NEAR/controller work;
- temporal/shadow mutation beyond the explicitly ordered contract test;
- arbitrary worldScale/IPD/convergence sweeps;
- broad reverse;
- release optimization.

Current goal remains deliberately narrow:
**make the working 220427 Quest path use the projection that actually generated its WORLD depth, then ask the headset one question: did static world scale become natural?**
