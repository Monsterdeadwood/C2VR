# Crysis 2 VR State

## CURRENT GATE — 2026-08-27

`220427 PARTIAL VISUAL BASELINE -> SCALE-ONLY DEPTH PROJECTION TRUTH`

Fresh direct user verdict remains:

```text
USER_HEADSET_VERDICT       = PARTIAL_ACCEPT / PROMISING
WORLD_SCALE                = FAIL
WHOLE_BUILD_VISUAL_RED     = NO
FULL_USER_VISUAL_GREEN     = NO
```

The scale root has now been substantially closed COLD from the exact 220427 result itself.

Read first:
1. `docs/Z_V601_OFFLINE_SCALE_QUALITY_AUDIT_20260827.md`
2. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
3. `docs/MONO_QUALITY_ANCHOR_20260818.md`
4. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
5. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
6. `docs/FALSIFIED.md`
7. `docs/NEXT.md`
8. `experiments/NEXT_EXPERIMENT.md`

Evidence law:
`USER_HEADSET_VERDICT > captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > package intent`.

## LATEST LIVE

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Raw mechanical facts:

```text
XR session creation/begin       = YES
submit_count                    = 4691
ever_submitted                  = 1
eye_stage_ready                 = 1,1
eye_stage_copies                = 9382
reproject_ready                 = 1
reproject_draws                 = 9382
xr_capture_count                = 33
raw RESTORE_OK                  = True
native eye records L/R          = 0/0
```

The v6.0.0 direct-XR-RTV blocker is mechanically closed.

## EXACT PACKAGE LINEAGE COLD-CLOSED

Physical historical packages were recovered and diffed:

```text
v6.0.0 SHA256 875853652D3A2ACC0E684A2E9BE2118D69FB2252E4B21B677DA4CF5105922656
v6.0.1 SHA256 E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A
```

The meaningful v6.0.1 delta is the private typed eye-RTV -> CopyResource -> XR swapchain bridge. Camera/FOV/depth/reprojection geometry remains inherited from v6.0.0.

Therefore 220427 executes the older Z geometry with the historical XR output blocker removed.

## CURRENT ARCHITECTURE

`ONE CENTER RGB + inverse depth -> x64 depth reprojection -> synthetic LEFT/RIGHT -> private eye RTs -> XR swapchains`.

```text
PRIVATE_RTV_XR_BRIDGE          = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER   = NO
```

This remains a working/control architecture, not the assumed final renderer.

## DIRECT 220427 WORLD DEPTH-PROJECTION CONTRADICTION

Fresh `ENGINE_TAP_CAMERA.tsv` contains 112,440 valid Renderer::SetCamera observations.

The same exact engine-tap source identifies CCamera fields:

```text
+0x30 FOV
+0x3C ratio
+0x48 near
+0x60 far
```

Fresh world-union downstream observations:

```text
74,347 calls: vfov=1.991177 ratio=0.963753 near=0.12 far~=2000
```

Exactly 4,160 of those are at the proven primary game-camera lineage `0x0057AC76`, matching 4,160 successful RenderWorld HMD/union injections.

But the fresh packer repeatedly logs:

```text
MONO_PACK_FRAME ... near=0.24000 far=2000.0
```

Exact v6.0.1 source shows why: projection metadata is published upstream from the RenderWorld camera before the downstream renderer changes the effective near plane.

Proven mismatch:

```text
ACTUAL DOWNSTREAM WORLD PROJECTION near = 0.12
PACKED DEPTH LINEARIZER near             = 0.24
```

Classification:

`SCALE_ROOT_CAUSE = STRONGLY PROVEN: DEPTH_PROJECTION_OWNER_MISMATCH`.

## SCALE ERROR MAGNITUDE

The pack shader reconstructs Z using the wrong near plane, then stores `invZ` used directly by eye reprojection.

With actual near 0.12 but assumed 0.24:

```text
true 0.5 m  -> packed ~1.00 m
true 1.0 m  -> packed ~1.999 m
true 2.0 m  -> packed ~3.996 m
true 5.0 m  -> packed ~9.976 m
true 10 m   -> packed ~19.90 m
```

The result is essentially the same for standard-Z and reversed-Z.

Thus WORLD disparity is roughly halved through ordinary gameplay distances even though physical IPD is correct. Expected perceptual direction is a world that reads too large/far.

Later v10.1 independently confirms the correct ownership law: final DSV projection must be described by downstream Renderer::SetCamera, not upstream RenderWorld metadata.

## NEXT SCALE-ONLY CHILD

No owner discovery is required.

At the already-existing proven primary downstream Renderer::SetCamera observation, publish actual live:

```text
vfov +0x30
ratio +0x3C
near +0x48
far +0x60
```

into the pack-depth contract before Present.

Do not hardcode `0.12`. Log and require:

```text
DOWNSTREAM_RENDERER_PROJECTION == PACKED_DEPTH_PROJECTION
```

for WORLD frames.

Only mutation category:
`DEPTH PROJECTION METADATA OWNER`.

## QUALITY / BLUR — NOW SEPARATE

Exact v6.0.1 runner does not force:

```text
r_MotionBlur
r_PostMSAA
r_FSAA
r_MSAA
r_SSAO
```

It inherits the user's existing system.cfg.

Correct classification:

`220427_QUALITY_CVARS = NONDETERMINISTIC_INHERITANCE_FROM_EXISTING_SYSTEM_CFG`.

Historical clean-mono donor remains:

```text
r_MotionBlur=0
r_PostMSAA=0
```

Fresh source quality also has a ray-density deficit:

```text
center source = 1600x1200
union FOV ~=114 deg
```

Compared with the Quest-family recommended eye density, vertical source angular density is only about 58%. Historical v6.3 already derived a near-1:1 source target around `2032x1968`.

Therefore blur is not the same problem as world scale.

## REVISED ORDER

1. scale-only downstream depth projection truth;
2. quality-CVar-only deterministic `MotionBlur=0 + PostMSAA=0`;
3. source-ray-density-only resolution increase using the proven DXGI create/resize path and live XR FOV-derived target;
4. only then reconsider true/private native L/R integration.

Each LIVE gets a direct headset verdict.

## IMPORTANT NEAR/WEAPON LIMIT

Fresh camera census also contains 27,817 `near=0.03 / FOV=55deg` observations consistent with FOB_NEAREST.

WORLD depth truth does not automatically solve weapon/viewmodel ownership. Do not merge that into the scale child.

## ANALYZER CORRECTION

Fresh generated Z verdict still contains known false negatives for transport/copies/restore. Do not repeat LIVE or redesign transport to satisfy that parser.

## EXISTING HARD REDS REMAIN HARD RED

No direct visual descendants from:
- `063149` catastrophic camera/world + moving light/shadow lineage;
- T1 PosePair K0;
- GOODLINE v1.0.0;
- R2 `201208` binocular/telescope path;
- native/NVIDIA monitor-stereo final renderer;
- DualWorld black-headset family.

## PARKED

Until scale/quality closure:
- true-L/R renderer merge;
- PosePair/K;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- later whole Z descendants;
- release optimization.

## RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
