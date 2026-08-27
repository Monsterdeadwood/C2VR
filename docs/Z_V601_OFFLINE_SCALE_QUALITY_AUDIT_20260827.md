# C2VR — Z v6.0.1 / 220427 OFFLINE SCALE + QUALITY AUDIT

Date: 2026-08-27

This is a COLD/OFFLINE evidence closure. No new game run was required.

## INPUTS

Fresh control result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`
SHA256 `483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`.

Exact physical historical packages recovered from Library:

```text
CRYSIS2VR_Z_REPROJECTION_v6.0.0.zip
SHA256 875853652D3A2ACC0E684A2E9BE2118D69FB2252E4B21B677DA4CF5105922656
bytes 135564

CRYSIS2VR_Z_REPROJECTION_v6.0.1_PRIVATE_RTV_BRIDGE.zip
SHA256 E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A
bytes 137128
```

Historical depth-truth donor/reference:
`CRYSIS2VR_VIEWMODEL_MASK_DEPTH_TRUTH_v10.1.0_NOFLICKER_SCALEFIX.zip`.

## EXACT v6.0.0 -> v6.0.1 DIFF

The exact physical package diff shows v6.0.1 did not change camera, union-frustum, depth-packing, pose or reprojection geometry.

Real functional delta:
- create private typed LEFT/RIGHT eye staging textures/RTVs;
- render existing Z-reprojection into those private eye targets;
- `CopyResource` private eye target into acquired OpenXR swapchain image;
- avoid direct RTV creation on Oculus runtime swapchain textures.

Other source changes are version/stage/diagnostic text. Core shared structures and proxy architecture remain the same.

Therefore fresh 220427 is a valid visual execution of the old v6.0.0 Z geometry with the XR-output blocker removed.

## QUALITY CVAR AUDIT

Exact v6.0.1 runner does NOT force any of:

```text
r_MotionBlur
r_PostMSAA
r_FSAA
r_MSAA
r_SSAO
```

It only appends native-stereo-off controls to the existing `system.cfg`:

```text
r_StereoDevice = 0
r_StereoMode = 0
r_StereoOutput = 0
r_StereoStrength = 0
r_StereoEyeDist = 0.000
g_stereoFrameworkEnable = 0
```

The runner inherits the rest of the user's existing `system.cfg`.

Fresh 220427 RESULT does not archive enough config evidence to recover the actual runtime MotionBlur/PostMSAA values.

Correct classification:

```text
220427_QUALITY_CVARS = NONDETERMINISTIC_INHERITANCE_FROM_EXISTING_SYSTEM_CFG
```

This supersedes the weaker wording `CLEAN_MONO_QUALITY_PAIR=UNKNOWN`.

Historical quality donor remains valid:
`r_MotionBlur=0 + r_PostMSAA=0` corresponded to the cleaner image reported by the user in the mono/reprojection lineage.

Do not mix this fact with stock native-SBS eye-asymmetry tests, where MotionBlur OFF alone did not fix RIGHT-eye softness.

## FRESH 220427 PROJECTION TRUTH — DIRECT RESULT EVIDENCE

`ENGINE_TAP_CAMERA.tsv` contains 112,440 valid `Renderer::SetCamera` observations.

The exact CCamera layout used by this same engine-tap source identifies:

```text
+0x30 = FOV
+0x3C = projection ratio
+0x48 = near plane
+0x60 = far plane
```

Fresh distribution:

```text
74,347 calls: fov=1.991177 rad, ratio=0.963753, near=0.12, far~=2000
27,817 calls: fov=0.959931 rad,                 near=0.03
10,276 calls: fov=0.959931 rad,                 near=0.12
```

The union-world family is therefore directly visible downstream as:

```text
WORLD_RENDERER_CAMERA = (vfov=1.991177, ratio=0.963753, near=0.12, far~=2000)
```

The already-proven primary game camera return/caller lineage `0x0057AC76` contributes exactly 4,160 of those union-world observations, matching the 4,160 successful union-frustum/HMD world injections.

This is direct evidence from the same 220427 run, not a value imported from a later version.

## FRESH 220427 DEPTH PACKER TRUTH

The same fresh result repeatedly logs:

```text
MONO_PACK_FRAME ... size=1600x1200 ... near=0.24000 far=2000.0
```

for the packed frames.

Exact v6.0.1 source explains why:

1. The upstream RenderWorld camera receives HMD + union-frustum mutation.
2. Immediately there, `C2VR_HOST_PublishMonoCamera(...)` reads/publishes its FOV/ratio/near/far.
3. At that point the upstream near value is 0.24.
4. Later `Renderer::SetCamera` exposes the actual downstream WORLD camera used by renderer projection with near 0.12.
5. Present/depth packer reads the earlier IPC `mono_near=0.24` and uses it to linearize the final scene DSV.

Thus fresh 220427 contains a proven internal contradiction:

```text
ACTUAL DOWNSTREAM WORLD DSV PROJECTION near = 0.12
DEPTH LINEARIZER CONTRACT             near = 0.24
```

FOV/ratio are already the same union values at the downstream primary world camera; the material mismatch is the near-plane owner.

## WHY THIS BREAKS PERCEIVED WORLD SCALE

v6.0.1 pack shader reconstructs linear view depth from raw DSV depth using either:

```text
zstd(d,n,f) = n*f / (f - d*(f-n))
zrev(d,n,f) = n*f / (n + d*(f-n))
```

and stores:

```text
invZ = 1 / z
```

The OpenXR reprojection shader then uses `eye_translation * invZ` directly to synthesize eye parallax.

If the DSV was generated with `n=0.12` but is linearized with `n=0.24`, reconstructed world Z is almost doubled at ordinary gameplay distances.

Approximate exact values with far=2000:

```text
true Z   reconstructed using n=0.24
0.5 m  -> 0.9998 m
1.0 m  -> 1.9991 m
2.0 m  -> 3.9962 m
5.0 m  -> 9.9757 m
10 m   -> 19.9017 m
50 m   -> 97.5665 m
```

This result is effectively the same for standard-Z and reversed-Z.

Consequences:
- `invZ` is approximately halved for nearby/mid-distance WORLD pixels;
- synthetic LEFT/RIGHT disparity is approximately halved;
- physical IPD can still be numerically correct (`62.8501 mm`) while perceived stereo scale is wrong;
- expected perceptual direction is a world that reads approximately too large/far because depth disparity is too weak.

Classification:

```text
SCALE_ROOT_CAUSE = STRONGLY PROVEN: DEPTH_PROJECTION_OWNER_MISMATCH
SPECIFIC DEFECT   = upstream near 0.24 used to linearize downstream near 0.12 DSV
```

This is stronger than arbitrary `worldScale`, IPD or convergence hypotheses.

## LATER DONOR CONFIRMATION

The later v10.1 depth-truth branch independently documented exactly this engine behavior:
- RenderWorld metadata and downstream `Renderer::SetCamera` expose different near-plane values;
- final DSV must be linearized from the downstream renderer camera;
- its scale arbiter only passes when renderer and packed projection match;
- observed corrected tuple was renderer=(..., near=0.120000, far=2000) and packed=(..., near=0.120000, far=2000).

Therefore v10.1 is a narrow mechanism donor/reference for the current 220427 branch, NOT a whole-build visual parent.

## MINIMAL SCALE FIX DESIGN

No new owner discovery is required.

220427 already has the exact `Renderer::SetCamera` hook and already classifies the primary game-camera site at caller/return lineage `0x0057AC76`.

Minimal scale-only child:

```text
At the proven primary downstream Renderer::SetCamera observation:
  read actual CCamera vfov  +0x30
  read actual ratio         +0x3C
  read actual near          +0x48
  read actual far           +0x60
  publish these four values into the pack-depth projection contract
  before Present packs the final DSV
```

Expected fresh values:

```text
1.991177, 0.963753, 0.12, 2000
```

Do NOT hardcode 0.12 as architecture. Publish the live downstream CCamera values and log upstream-versus-downstream-versus-packed tuples.

This is one mutation category:
`DEPTH PROJECTION METADATA OWNER ONLY`.

Do not change in the same child:
- world/HMD camera transform;
- union FOV algorithm;
- XR eye FOV/IPD;
- source resolution;
- reprojection shader math;
- quality CVars;
- weapon/FOB_NEAREST handling;
- temporal/cadence policy;
- private RTV/XR bridge.

## IMPORTANT NEAR/WEAPON LIMIT

The fresh camera census also contains 27,817 `near=0.03` / 55-degree calls consistent with the FOB_NEAREST family.

A WORLD depth-truth fix does not solve viewmodel/weapon ownership automatically. Some close geometry may still require separate handling later.

Do not merge FOB_NEAREST into the scale child.

## BLUR / IMAGE QUALITY IS A SEPARATE PROBLEM

Fresh 220427:

```text
center source = 1600x1200
union centerTan ~= (1.486,1.542)
```

For the Quest FOV in this lineage, this source has substantially less angular ray density than the recommended eye target, especially vertically.

Approximate density comparison:

```text
source 1600x1200 vs current 1600x1200 output:
  source/output ray-density ratio ~= 0.745 X / 0.776 Y
  equivalent reprojection upscale ~= 1.34 X / 1.29 Y

source vs Quest recommended 1504x1616:
  source/recommended angular density ~= 0.79 X / 0.58 Y
```

Historical v6.3 already calculated a ~1:1 angular-density source target around `2032x1968` for the same Quest family and tight union-frustum logic.

Therefore:

```text
BLUR_ROOT_1 = SOURCE ANGULAR RAY DENSITY DEFICIT
BLUR_ROOT_2 = QUALITY CVARS NOT DETERMINISTIC IN v6.0.1 RUNNER
```

These are independent from the proven world-scale depth error.

## REVISED EXPERIMENT ORDER

1. **SCALE-ONLY / DEPTH TRUTH**
   - exact 220427 parent;
   - downstream renderer projection feeds pack depth;
   - no quality/resolution change;
   - direct headset verdict on world scale.

2. **QUALITY-CVAR-ONLY**
   - pin `r_MotionBlur=0 + r_PostMSAA=0` deterministically;
   - no scale/resolution change;
   - direct clarity verdict.

3. **SOURCE-RAY-DENSITY-ONLY**
   - preserve accepted scale + quality state;
   - raise actual mono producer resolution using proven DXGI create/resize path;
   - use ray-density target derived from live XR FOV, not guessed desktop resolution;
   - no renderer architecture change.

4. Only after those controls are accepted reconsider true native/private L/R integration.

## CURRENT FIRST MISSING LIVE FACT

`DOES CORRECT DOWNSTREAM DEPTH PROJECTION RESTORE NATURAL WORLD SCALE WHILE PRESERVING THE OTHERWISE PROMISING 220427 IMAGE?`

That is the next highest-information LIVE.
