# C2VR — Z v6.0.1 GEOMETRY DEFECT MAP

Date: 2026-08-27

Purpose: separate the independent defects still present in the promising `220427` v6.0.1 control so future LIVE tests change only one causal category at a time.

Base:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`
SHA256 `483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`.

## DEFECT A — WORLD DEPTH PROJECTION OWNER

Status: STRONGLY PROVEN COLD from the same fresh result.

Fresh downstream WORLD Renderer::SetCamera:

```text
vfov  = 1.991177 rad
ratio = 0.963753
near  = 0.12
far   = ~2000
```

Fresh depth packer:

```text
near = 0.24
far  = 2000
```

Cause: v6.0.1 publishes projection metadata from the upstream RenderWorld camera before the renderer establishes the final GPU projection. Present later linearizes the final MAIN_DSV using the stale upstream near plane.

Effect: ordinary WORLD Z is reconstructed approximately 2x too far, inverse-Z and synthetic eye disparity approximately halve, so static perceived world scale is wrong despite correct physical IPD.

Immediate next LIVE: fix A only.

## DEFECT B — REPROJECTION EYE BASIS

Status: PROVEN BY EXACT v6.0.1 SOURCE + fresh telemetry + later v6.1 correction.

Exact v6.0.1 reprojection does:

```text
cp = current center_pos()
off = current XrView eye position - cp
invCenter = conjugate(g_centerQ)
local = rotate(invCenter, off)
```

`g_centerQ` is the fixed initial/recenter orientation.

But the center scene is rendered under the current HMD orientation. The eye offset required by the reprojection shader is therefore current/render-head-local, not initial-recenter-local.

Fresh 220427 shows the symptom directly. Physical IPD stays about 62.8501 mm, but logged reprojection X half-baseline moves through values such as:

```text
~31.3 mm
29.5 mm
19.6 mm
7.2 mm
3.8 mm
15.3 mm
... then back near 31 mm
```

A physical half-IPD is not changing by that amount. Its X component is rotating into Y/Z because it is expressed in the wrong basis.

The same exact v6.0.1 source already contains the correct model elsewhere in `publish_exact_eye_views()`: it uses current `headQ`, computes `invHead`, then rotates LEFT/RIGHT offsets into current head-local coordinates.

Physical v6.1 explicitly documents the v6.0.1 defect: INITIAL recenter orientation was wrong for depth reprojection; the correction uses current/tagged head-local eye vectors.

Expected symptom:
- little effect on a stationary forward-facing scale judgement;
- head-motion-dependent stereo strength/direction, shear or rubbery behavior during yaw/pitch.

Do NOT merge B with A in one LIVE.

## DEFECT C — PIXELS / DEPTH / XR CONTRACT ARE NOT ATOMIC ON REUSE

Status: PROVEN FROM COUNTERS + exact v6.0.1 host source.

Fresh 220427:

```text
XR submits       = 4691
new packed frames= 4109
minimum reused XR submits = 582 (~12.4%)
```

v6.0.1 can reuse the last private packed image when no new game frame is available, but reprojection and submitted projection-layer metadata are read from current XR globals rather than an immutable contract tied to the pixels that produced the pack.

Therefore an old color+depth image can be relabeled/reprojected using a newer pose/FOV contract.

Expected symptom:
- temporal rubber / drift / tearing under head motion;
- not a sufficient explanation for the stationary ~2x depth-scale error.

Physical v6.1 introduced packed-frame pose/FOV/display-time tagging specifically to close this class of error.

Do NOT merge C with A or B.

## DEFECT D — INVERSE-DEPTH ALPHA IS LINEARLY FILTERED

Status: PROVEN BY exact lineage and v6.1 correction.

v6.0.1 uses one linear sampler for packed RGB + inverse-Z alpha. Bilinear filtering mixes inverse depth across foreground/background silhouettes and creates non-physical intermediate Z.

v6.1 split the policy:
- RGB/color: filtered reconstruction;
- inverse-Z/depth: POINT sampling.

Expected symptom:
- rubbery/halo-like stereo edges near geometry boundaries;
- not global static world-scale error.

Do not change D in scale LIVE.

## DEFECT E — SOURCE ANGULAR RAY DENSITY

Status: STRONGLY SUPPORTED.

Fresh 220427 center source:

```text
1600x1200
union FOV ~= 114.086 deg
```

This source covers a very wide union frustum and has substantially less angular sample density than the Quest eye target, especially vertically.

Historical live-XR-derived plan:

```text
recommended eye = 1504x1616
source target   ~= 2032x1968
```

Later 2032x1968 branches showed near-1:1 ray density, but many of them still retained the separate depth-owner defect A (`near=0.24`). Therefore their visual outcome cannot falsify the resolution correction by itself.

Expected symptom:
- blur / loss of fine detail;
- not the proven constant WORLD scale error.

## DEFECT F — QUALITY CVARS ARE NOT DETERMINISTIC IN EXACT v6.0.1

Status: PROVEN BY exact runner audit.

Exact v6.0.1 does not force:

```text
r_MotionBlur
r_PostMSAA
r_FSAA
r_MSAA
r_SSAO
```

It appends only native-stereo-off values to the existing `system.cfg`, so the rest is inherited from whatever configuration existed before the run.

Historical cleaner mono donor:

```text
r_MotionBlur=0
r_PostMSAA=0
```

Expected symptom:
- run-to-run image quality differences / blur;
- separate from A-E.

## UNITS CHECK — NO EXTRA x100/x0.01 SCALE FOUND

Current camera chain strongly supports approximately 1 CryEngine camera world unit = 1 meter for HMD/eye translation:
- `g_headTranslationScale=1.0`;
- native-eye runtime evidence carried ~0.06677 m Quest eye separation into ~0.06677 CCamera world-unit separation.

No evidence supports another hidden mandatory metric conversion after fixing A.

## DEPTH SOURCE IDENTITY

Fresh 220427 active packed depth is stable:

```text
MONO_ACTIVE_DEPTH choice=MAIN_DSV
size=1600x1200
fmt=45
```

The discovered R32F path is fallback only in this run.

Thus defect A refers to the actual depth resource being packed, not an inactive alternate representation.

## WORLD VS FOB_NEAREST

Fresh Renderer::SetCamera census also shows a separate near family:

```text
~27,817 calls: FOV ~55 deg, near ~0.03
```

Historical owner mapping identifies this with FOB_NEAREST (`+0x000FF340`, SetCamera return `+0x000FF456`, restore `+0x000FF4A3`).

The final image can therefore contain pixels produced under more than one projection family.

The first scale child judges WORLD only. Weapon/viewmodel defects do not invalidate a successful WORLD scale correction.

## BRANCH HISTORY CORRECTION

Do not describe v11 as a descendant that regressed the later v10.1 depth-truth result.

Timeline / branch facts:

- v10 visual line `034749` proved useful WORLD/FOB_NEAREST projection alignment and actual 2032x1968 source; user feedback recorded that weapon counter-motion improved.
- v11 `133603` continued that visible v10 branch and had working XR submission, but runtime still reported `mono_camera ... near=0.24`.
- v10.1 depth-truth result `134133` separately proved downstream renderer near=0.12 == packed near=0.12 numerically, but its reprojection shader failed compilation and XR submit remained 0.

Therefore the important statement is:

```text
WORKING_XR + CORRECT_DOWNSTREAM_DEPTH_TRUTH
HAS NOT BEEN PROVEN TOGETHER IN ONE LIVE.
```

v11 and v10.1 should be treated as sibling evidence donors for different properties, not one linear parent chain.

Also note: v11's regression/static-validation policy called v10 projection GREEN but did not include a guard for the later Renderer-depth-truth owner. Future validators must test actual runtime packed projection values, not architecture labels.

## EXPERIMENT LADDER — ONE CAUSAL CATEGORY EACH

A. `DEPTH_PROJECTION_OWNER_ONLY`
- exact 220427 parent;
- downstream primary WORLD Renderer::SetCamera tuple overwrites pack-depth metadata;
- stationary WORLD scale verdict first.

B. `EYE_BASIS_ONLY`
- current/render-head-local eye offsets instead of fixed recenter basis;
- no depth/resolution/quality change;
- judge yaw/pitch stereo stability.

C. `ATOMIC_PACKED_FRAME_CONTRACT_ONLY`
- image + depth + render pose + FOV + display-time reused as one immutable transaction;
- no geometry changes.

D. `DEPTH_SAMPLER_ONLY`
- POINT inverse-Z / filtered color;
- judge silhouettes and near depth edges.

E. `QUALITY_CVARS_ONLY`
- deterministically pin `r_MotionBlur=0 + r_PostMSAA=0`;
- no resolution change.

F. `SOURCE_RAY_DENSITY_ONLY`
- raise actual producer resolution toward live-XR-derived target near 2032x1968;
- preserve accepted geometry and transport.

Only after these controls should the project decide whether to keep the synthetic Z path as a diagnostic/control or move accepted properties into the final true/private L/R renderer.

## FIRST LIVE REMAINS A

The additional defects do not change the immediate gate.

First missing live fact remains:

`DOES DOWNSTREAM WORLD DEPTH PROJECTION TRUTH RESTORE NATURAL STATIC WORLD SCALE IN THE WORKING 220427 QUEST PATH?`
