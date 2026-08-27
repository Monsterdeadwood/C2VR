# Crysis 2 VR — NEXT EXPERIMENT

## CURRENT GATE

`220427 PARTIAL VISUAL BASELINE -> SCALE-ONLY DEPTH PROJECTION TRUTH`

This supersedes the older quality-first plan. COLD evidence found a stronger causal scale defect in the exact fresh result itself.

## PREFLIGHT — exactly 5 lines

MISSING FACT = whether feeding the final downstream WORLD Renderer::SetCamera projection into the existing depth packer restores natural static world scale in the working 220427 Quest path.
WHY NOT COLD = COLD has already proven the mismatch (`downstream near=0.12` versus `packed near=0.24`) and its ~2x Z effect, but only a headset LIVE can determine the visual scale consequence.
PASS = downstream WORLD projection equals packed-depth projection, Quest transport/220427 behavior remains intact, and stationary WORLD scale is natural or materially corrected.
FAIL = downstream and packed projection still differ, XR/bridge/world behavior regresses, scale does not materially improve, or restore fails.
BASELINE MUST HOLD = exact 220427 private-RTV XR bridge, camera/HMD path, source size, quality config, eye basis, temporal policy, shader, weapon/NEAR behavior and union-FOV algorithm remain unchanged.

## BASE

```text
BASE_RESULT = CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip
SHA256      = 483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4
VISUAL      = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE = FAIL
XR_SUBMITS  = 4691
```

## PRIMARY FACT ALREADY PROVEN COLD

Fresh `ENGINE_TAP_CAMERA.tsv`:

```text
WORLD downstream Renderer::SetCamera:
  vfov  1.991177
  ratio 0.963753
  near  0.12
  far   ~2000
```

Fresh packer:

```text
near 0.24
far  2000
```

The same-run active depth source is stable MAIN_DSV `1600x1200 fmt=45`.

Exact v6.0.1 source publishes the upstream RenderWorld tuple before the original RenderWorld executes. The existing downstream Renderer::SetCamera hook then observes the final WORLD projection inside that same render call. Present packs depth afterward.

No new owner discovery is needed.

## ONLY RUNTIME DELTA

At the already-existing `hkRendererSetCamera`:

1. recognize proven primary game-camera caller lineage `0x0057AC76`;
2. require readable/sane CCamera;
3. require actual FOV within ~0.08 rad of latest WORLD union FOV;
4. read actual live:

```text
+0x30 vfov
+0x3C ratio
+0x48 near
+0x60 far
```

5. call the existing mono-camera/projection publish path so this downstream WORLD tuple overwrites the earlier upstream tuple before Present depth packing.

Do not hardcode `0.12` as the architecture.

Keep upstream publication as bootstrap/fallback.

## REQUIRED REGRESSION ASSERTIONS

The old project once used projection-GREEN labels that did not guarantee the later downstream depth-truth property. This experiment must validate actual values, not names.

Result must contain:

```text
upstream_world_vfov/ratio/near/far
downstream_world_vfov/ratio/near/far
packed_depth_vfov/ratio/near/far
renderer_depth_publish_count
renderer_depth_reject_count
depth_projection_owner=RENDERER_SETCAMERA_PRIMARY_WORLD
```

Mechanical PASS:

```text
renderer_depth_publish_count > 0
DOWNSTREAM_WORLD == PACKED_DEPTH within tolerance
expected fresh near approximately 0.12, but measured value is authoritative
XR submits > 0
private RTV bridge active
restore OK
```

A static validator must also fail the build if the downstream publisher/filter is absent from source. Do not allow an architecture label such as `PROJECTION_GREEN` to substitute for this assertion.

## VISUAL TEST ORDER

First, stand still and judge WORLD only:

```text
walls / doors / rooms
human-sized objects / people
near world geometry excluding weapon
medium distance geometry
distant world
```

Primary answer:
`WORLD_SCALE = natural / better-but-wrong / unchanged / worse`.

Only after that, move head slowly and then quickly as a regression check.

Do NOT use weapon/viewmodel as the primary scale oracle. Fresh evidence proves FOB_NEAREST is a separate ~55-degree / near~0.03 projection family.

## FORBIDDEN IN THIS LIVE

- no eye-basis correction;
- no packed-frame pose/FOV tagging change;
- no depth sampler change;
- no MotionBlur/PostMSAA change;
- no 2032x1968 source change;
- no IPD/worldScale/convergence sweep;
- no union-FOV algorithm change;
- no weapon/FOB_NEAREST mutation;
- no temporal/cadence optimization;
- no true-L/R merge;
- no new launcher/build architecture.

## ALREADY-KNOWN FOLLOW-UPS, NOT PART OF THIS LIVE

See `docs/Z_V601_GEOMETRY_DEFECT_MAP_20260827.md`.

After scale verdict, independent known defects can be tested one at a time:

```text
B eye basis: fixed recenter -> current/render-head-local
C frame contract: old pixels cannot use newer pose/FOV
D inverse-Z sampling: linear -> POINT
E deterministic quality CVars
F source angular ray density / resolution
```

## STOP RULE

If downstream WORLD == packed depth is mechanically proven and static WORLD scale does not materially change in the headset, mark this causal hypothesis VISUAL_RED for scale and do not start arbitrary IPD/worldScale tuning. Return to the defect map and re-rank the next independent cause.

If scale materially improves, freeze this exact property before any B/C/D/E/F child.
