# Crysis 2 VR — NEXT

## CURRENT GATE

`220427 PARTIAL VISUAL BASELINE -> SCALE / SOURCE-PROJECTION CONTRACT`

The direct headset verdict is now bound:
- scale is wrong/problematic;
- otherwise the branch is broadly normal/promising and worth finishing;
- do not discard 220427 as a visual HARD RED.

Read first:
1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `docs/MONO_QUALITY_ANCHOR_20260818.md`
3. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
4. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
5. `docs/FALSIFIED.md`

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

## CURRENT ARCHITECTURE LIMIT

220427 still uses one center color+depth image to synthesize LEFT/RIGHT.

It is not final true-L/R scene rendering.

That question is parked until scale and image-quality controls are closed.

## RECOVERED QUALITY FACT

Historical mono/reprojection result `20260818_030228` retained:

```text
r_MotionBlur=0
r_PostMSAA=0
```

and the contemporary council explicitly says those settings corresponded to the cleaner image reported by the user.

Treat this as:
`COMPONENT_VISUAL_GREEN: CLEAN_MONO_IMAGE_QUALITY_SETTINGS`.

Fresh 220427 RESULT does not prove those settings were active.

## CURRENT SCALE FACTS

220427:

```text
source_eye / game_texture = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
```

Historical 030228 already showed a related source/projection mismatch:

```text
calculated target ~= 2032x1968
actual producer   = 1400x1050
```

So the next problem is not "guess a scale number".

It is:
`which projection + source rectangle does each synthesized eye actually represent?`

## NEXT EXPERIMENT ORDER

1. **QUALITY CONTROL**: on the exact 220427 lineage verify current `r_MotionBlur` and `r_PostMSAA` values. If not already `0/0`, make a child whose only runtime delta is those two known historical clean-mono quality settings. Do not change scale in the same child.
2. **SCALE CONTRACT**: preserve the accepted quality control and record/compare actual producer size, center projection/FOV/ratio, packed-depth projection, XR eye FOV, reprojection sampling rectangle and submitted XR rectangle.
3. Only after the mismatch is identified, make one scale/projection correction. No arbitrary IPD/convergence sweep.

Each child gets a fresh explicit headset verdict.

## PASS TARGET FOR QUALITY CONTROL

```text
same world/head behavior
same scale defect, not worse
image at least as clean as 220427
no new blur introduced
XR bridge unchanged
```

The quality control is not allowed to claim scale fixed.

## PASS TARGET FOR SCALE CHILD

```text
world scale natural
world/head remains stable
image quality preserved
no binocular/telescope catastrophe
XR bridge unchanged
```

## DO NOT DO NOW

- no true-L/R renderer merge yet;
- no GOODLINE/R2/T1/v17 whole-build descendant;
- no K/PosePair;
- no weapon/NEAR merge;
- no temporal/shadow mutation;
- no controller work;
- no arbitrary worldScale/IPD/convergence matrix;
- no broad reverse;
- no new launcher architecture.

Current goal is deliberately small:
**make the already-promising 220427 image clean and correctly scaled before changing the renderer family again.**
