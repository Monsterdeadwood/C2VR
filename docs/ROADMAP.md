# Crysis 2 VR — ROADMAP

## CURRENT CONTROL

`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`
SHA256 `483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`.

Direct headset verdict:
```text
USER_HEADSET_VERDICT = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE          = FAIL
WHOLE_BUILD_RED      = NO
FULL_USER_VISUAL_GREEN = NO
```

The current control is worth finishing surgically. Do not reset renderer architecture while quality and scale remain the active blockers.

Current source path:
`CENTER RGB + inverse depth -> depth reprojection -> synthetic LEFT/RIGHT -> private eye RTs -> XR swapchains`.

`CUSTOM_DUAL_T1 v1.0.1` remains a proven true-private-L/R mechanical donor, not the current visual parent.

---

## BUILD Q — CLEAN MONO QUALITY CONTROL — CURRENT

First recover exact current values of:
```text
r_MotionBlur
r_PostMSAA
```

Historical 030228 accepted quality property:
```text
r_MotionBlur=0
r_PostMSAA=0
```

If 220427 already uses `0/0`, do not create a redundant child.
If not, create one quality-only child with those values and no scale/projection/renderer mutation.

PASS:
- current world/head behavior preserved;
- same known scale defect, not worse;
- image at least as clean as 220427;
- no new blur or binocular regression;
- Quest/private-RTV bridge unchanged;
- restore/hash baseline holds.

Then FREEZE the best quality state.

---

## BUILD S — SCALE / SOURCE-PROJECTION CONTRACT — NEXT

Known fresh facts:
```text
source_eye / game_texture = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
```

Before changing scale, map the complete contract:
- producer dimensions;
- center RenderWorld projection/FOV/ratio;
- packed-depth projection;
- XR LEFT/RIGHT FOV;
- reprojection sampling rectangle;
- XR swapchain dimensions;
- submitted XR `subImage` rectangle.

Historical 030228 already showed a related mismatch:
```text
calculated source target ~= 2032x1968
actual producer          = 1400x1050
```

Change only the first proven mismatch.

Do not run arbitrary worldScale/IPD/convergence matrices.

PASS:
- natural world scale;
- head/world stability preserved;
- image quality preserved;
- no telescope/binocular catastrophe;
- bridge unchanged.

Then FREEZE.

---

## BUILD L — TRUE PRIVATE L/R INTEGRATION

Only after Q + S are visually acceptable.

Use `CUSTOM_DUAL_T1 v1.0.1 / 212003` only as the mechanical donor for genuine non-duplicate private LEFT/RIGHT scene rendering.

Do not resurrect whole-build descendants already rejected visually:
- RC33/v17.2 lineage;
- PosePair K0;
- R2 binocular/telescope branch;
- GOODLINE whole build;
- native/NVIDIA/monitor-stereo final renderer;
- DualWorld black-headset family.

Integration rule:
start from the accepted post-S control and import only the minimum L/R renderer mechanism.

PASS:
- true non-duplicate LEFT/RIGHT alive;
- stable fused world;
- natural scale retained;
- current image quality retained;
- no camera/light/shadow regression.

Then FREEZE.

---

## BUILD H — POSE/PIXEL CONTRACT + HEAD 1:1

After L passes.

Architecture:
- pixels + render pose + FOV + ticket are one atomic publication contract;
- no stale relabel;
- HEAD applied once upstream of visibility/list selection;
- EYES applied only in per-eye raster transaction;
- conservative visibility envelope only where needed.

PASS:
- yaw/pitch 1:1;
- no doubled rotation/drift;
- head stop -> world stops;
- fast reversal -> no eye-time split;
- no culling pop;
- lighting/shadows spatially stable.

Old PosePair/P5/P6 evidence remains useful timing evidence only. It is not the active parent or current gate.

Then FREEZE.

---

## BUILD W — WEAPON / NEAR

Use preserved retail anchors without broad weapon reverse:
- FOB_NEAREST `+0x000FF340`;
- NEAR SetCamera return `+0x000FF456`;
- restore return `+0x000FF4A3`;
- object owner `+0x00102100`;
- `Renderer::SetCamera +0x00148340`.

Controller-directed firing remains a donor component only.

PASS:
- head still -> weapon still;
- controller only -> weapon moves, WORLD does not;
- head only -> no weapon counter-motion;
- both eyes coherent;
- firing direction follows intended weapon/controller authority;
- no flicker.

Then FREEZE.

---

## BUILD T — TEMPORAL / SHADOW STABILITY

Only after Q/S/L/H/W pass visually.

Do not use temporal/shadow work to mask quality or scale errors.
Never use `SHDF_ZPASS_ONLY` as normal RIGHT-eye scene policy.

Serial mutation only when directly justified by remaining visual evidence.

Then FREEZE.

---

## BUILD R — REGRESSION

Required:
- normal mono launch;
- Quest output;
- coherent stereo;
- natural scale;
- HEAD 1:1;
- weapon correct;
- shadows/light coherent;
- HUD both eyes;
- save/load;
- menu -> gameplay;
- cutscene transitions;
- no accumulating drift;
- no state corruption;
- byte-exact D3D11 restore;
- retail hashes unchanged.

Any failure -> rollback to last accepted frozen stage.

---

## RELEASE CANDIDATE

At least 10 minutes actual gameplay with head motion, movement, weapon use and traversal with no tearing, drift, eye divergence, black eye, crash or state corruption.

PASS -> STOP FORENSICS -> RELEASE CANDIDATE.

---

## CANONICAL ORDER

`220427 CONTROL -> Q QUALITY -> S SCALE -> L TRUE L/R -> H HEAD/POSE -> W WEAPON/NEAR -> T TEMPORAL/SHADOW -> R REGRESSION -> RELEASE`

Working law:
`SYNC -> EXACT CURRENT CONTROL -> ONE MISSING FACT -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP / ADAPT / STOP`.
