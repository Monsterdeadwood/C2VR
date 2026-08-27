# Crysis 2 VR — NEXT

## CURRENT GATE

`220427 PARTIAL VISUAL BASELINE -> SCALE-ONLY DEPTH PROJECTION TRUTH`

Fresh direct user verdict:
- scale is wrong/problematic;
- otherwise the branch is broadly normal/promising and worth finishing;
- 220427 is not a whole-build visual HARD RED.

Read first:
1. `docs/Z_V601_OFFLINE_SCALE_QUALITY_AUDIT_20260827.md`
2. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
3. `docs/MONO_QUALITY_ANCHOR_20260818.md`
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

## COLD PROOF — SCALE ROOT FOUND

Fresh `ENGINE_TAP_CAMERA.tsv` directly proves the downstream WORLD renderer camera for the union path is:

```text
vfov  = 1.991177 rad
ratio = 0.963753
near  = 0.12
far   = ~2000
```

There are 74,347 such Renderer::SetCamera observations in 220427, including exactly 4,160 at the proven primary game-camera lineage `0x0057AC76`, matching the 4,160 successful world/union injections.

But the same run's depth packer repeatedly logs:

```text
near=0.24000
far=2000.0
```

Exact v6.0.1 source explains the mismatch: it publishes projection metadata upstream immediately after RenderWorld union-frustum mutation, then later packs the final DSV using that stale upstream near plane.

Therefore:

```text
ACTUAL DOWNSTREAM WORLD DSV near = 0.12
PACK-DEPTH LINEARIZER near        = 0.24
```

This is direct same-run evidence.

## WHY THIS FITS THE USER SCALE FAILURE

The pack shader reconstructs linear Z from raw depth using the wrong near plane and then stores `invZ=1/Z`.

With true near 0.12 but assumed near 0.24, ordinary world distances reconstruct almost exactly 2x too far:

```text
0.5 m  -> ~1.00 m
1.0 m  -> ~1.999 m
2.0 m  -> ~3.996 m
5.0 m  -> ~9.976 m
10 m   -> ~19.90 m
```

This is effectively the same for standard-Z and reversed-Z.

The reprojection shader multiplies physical eye translation by `invZ`, so disparity is approximately halved. Expected perceptual direction: world reads too large/far despite correct ~62.85 mm IPD.

Classification:

`SCALE_ROOT_CAUSE = STRONGLY PROVEN: DEPTH_PROJECTION_OWNER_MISMATCH`.

## NEXT CHILD — ONE MUTATION ONLY

Use the exact 220427 lineage.

Only mutation category:
`DEPTH PROJECTION METADATA OWNER`.

At the existing proven primary downstream `Renderer::SetCamera` observation, read and publish the live CCamera:

```text
+0x30 vfov
+0x3C ratio
+0x48 near
+0x60 far
```

into the pack-depth contract before Present packs the final DSV.

Do not hardcode `0.12`; publish the actual downstream renderer-camera tuple and log:

```text
UPSTREAM_RENDERWORLD_PROJECTION
DOWNSTREAM_RENDERER_PROJECTION
PACKED_DEPTH_PROJECTION
```

PASS mechanically requires downstream == packed for WORLD frames.

## DO NOT CHANGE IN SCALE CHILD

- no source-resolution change;
- no MotionBlur/PostMSAA change;
- no union-FOV algorithm change;
- no IPD/worldScale/convergence change;
- no reprojection shader rewrite;
- no weapon/FOB_NEAREST handling;
- no temporal/shadow/cadence change;
- no true-L/R merge;
- no XR bridge change.

## USER PASS TARGET

```text
WORLD_SCALE          = natural / materially corrected
WORLD_HEAD_BEHAVIOR  = no regression
IMAGE                = otherwise retains 220427 behavior
XR_OUTPUT             = stable
```

Weapon/FOB_NEAREST may remain imperfect; it is not part of this scale verdict.

## QUALITY COMES AFTER SCALE

Exact v6.0.1 runner does not force MotionBlur/PostMSAA. It inherits the existing user `system.cfg`.

Correct status:

`220427_QUALITY_CVARS = NONDETERMINISTIC_INHERITANCE_FROM_EXISTING_SYSTEM_CFG`.

Historical donor remains:

```text
r_MotionBlur=0
r_PostMSAA=0
```

which corresponded to the cleaner mono image reported by the user.

After scale truth is visually checked:

1. quality-CVar-only child pins `0/0`;
2. then source-ray-density-only child raises the mono producer toward the proven ~1:1 angular-density target around `2032x1968` derived from live Quest FOV.

Do not combine those with the scale fix.

## BLUR IS NOW SEPARATE FROM SCALE

Fresh 1600x1200 center source covers the ~114-degree union frustum with insufficient angular density. Relative to current 1600x1200 eye output it is effectively upsampled around 1.34x X / 1.29x Y; relative to the Quest recommended eye density the vertical source density is only about 58%.

That strongly explains blur, but it does not replace the proven depth-scale defect.

## PARKED

- true private/native L/R renderer merge;
- K/PosePair;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- controller work;
- arbitrary worldScale/IPD/convergence sweeps;
- broad reverse.

Current goal:
**fix the one proven wrong number-owner in the otherwise promising 220427 path, then ask the headset only one question: did world scale become natural?**
