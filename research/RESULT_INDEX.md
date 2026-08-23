# Crysis 2 VR — RESULT INDEX

Current rule: WORKING BUILD FIRST, reverse only blockers.

## 2026-08-23/24 — latest cross-branch timing state
### v17.2.5 WAIT45
**Class:** latest completed causal PosePair timing result

Measurements:
- exact pair consumes `269`
- host submits `269`
- misses `53`
- exact ratio `83.5404%`
- `pair_wait_ms_max = 47`
- completed/copies `354/354`
- flashes/dropouts remained visible

Earlier line was roughly `92 exact / 776 miss` (~10.6%). WAIT45 increased exact acceptance about 7.9x. Interpretation: bounded wait/deadline is a proven contributor to projection-layer misses, but timely prediction and final visual stability are not yet proven.

### v17.2.6 EXACT_BLOCK120 P6
**Class:** CURRENT UNTESTED FINALIST

Package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

SHA256:
`8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

Only intended change vs P5:
`exact wait watchdog ceiling 45 ms -> 120 ms`.

Not a fixed sleep; exit occurs when exact pair arrives.

Recorded checks:
- static `130/130 PASS`
- independent `98/98 PASS`
- game-side C++ unchanged in camera/FOV/weapon/shadow/temporal/RC33 policy

No recorded P6 LIVE result found at sync time.

## CUSTOM_DUAL_T1 v1.0.1
**Class:** PROVEN MAIN RENDERER PARENT

Canonical result:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`
- bytes `68,872,488`
- SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAe1EDDB3596144D341CD53367`

Measurements:
- center HMD inject/restore `2296/2296`
- private LEFT `2295`
- private RIGHT `2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- sampled L/R median MAE `35.9781`
- FramePairContract desync `0/0`
- PosePair acceptance failed

Interpretation: genuine non-duplicate two-eye retail rendering is proven. Do not rebuild stereo.

## Weapon / NEAR historical visual results
### 20260817_010329
**Class:** PROVEN controller->visual-viewmodel behavior, unstable global image

User-observed:
- right controller could move weapon/viewmodel
- firing still followed monitor/game-center aim
- image still flickered/changed violently

Interpretation: Touch pose data and visual weapon movement existed; the missing piece was not basic controller tracking.

### historical 021239 GOLD
**Class:** PROVEN gameplay-aim fallback behavior

Preserved behavior:
- right controller drove gameplay aim through a closed-loop retail input/mouse-response servo
- trigger drove retail fire
- user confirmed firing followed weapon/muzzle direction

Interpretation: working gameplay-aim/firing donor exists. It is not direct proof of `CWeapon::SetFiringLocator` ownership and remains parked until ballistics gate.

### 20260818_034749 v10
**Class:** PROVEN projection/weapon visual coupling

Visual observation preserved in later state: weapon stopped moving right when head looked left after WORLD/FOB_NEAREST projection was made coherent.

Interpretation: apparent weapon counter-motion can be caused by NEAR projection mismatch, not only bad controller pose math.

## v7 weapon-object transform lineage
**Class:** informative but not final

Historical policy transformed the actual `FOB_NEAREST` render-object Matrix34 temporarily and restored it after draw. This was a better ownership seam than mutating WORLD, but its math used head position as rotation pivot and treated late NEAR object state too much like ordinary world space. Do not reuse that formula unchanged.

## Current MASTER3 weapon finalist prepared for later gate
**Class:** COLD/PARKED

Primary rigid calibration:
`GripBind = inverse(C_bind) * W_bind`
`W_now = C_now * GripBind`

Requirements:
- fixed baseline; no automatic squeeze/grip rebind
- one controller contract for both eyes
- weapon pose and NEAR per-eye projection remain separate responsibilities
- first clean upstream target, if renderer shim is insufficient: real weapon entity between `CItem::UpdateFPPosition` and `CItem::UpdateFPCharacter`

See `research/WEAPON_NEAR.md`.

## v17.2 / v17.2.1 donor source authority
**Class:** DONOR CORPUS, NOT WHOLESALE MAIN BUILD

Physical donor package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.1_ARGV_FIX_ONECLICK.zip`
- bytes `91,521`
- SHA256 `53688524B59E9C8F7B768BFA78BB80DEDC0981EB7FF699204E496887668D38A2`
- original manifest `27/27 PASS`

Contains PosePair, HEAD/culling, weapon/NEAR and temporal/shadow candidates. Import policies serially only.

Repository authority:
- `runtime/donors/v17.2.1/`
- `tools/extract_verified_v17_2_1.py`
- `tools/extract_verified_v17_2_1_original.py`

## Canonical eye transaction
`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 snapshot -> render-thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`.

One prepared render-list executes twice. No second top-level RenderWorld/EF_StartEf.

## Historical RenderDoc / resource 20500 lineage
**Class:** SUPPORTING ARCHAEOLOGY

- retail capture ~1886 draws
- resource `20500`, 320 bytes, ~98 updates/frame in measured capture
- later carrier evidence distinguished WORLD and NEAR families

Useful provenance history, not the current gate.

## v15 late-sink / mono reprojection
**Class:** FALSIFIED AS FINAL ARCHITECTURE

Mono RGB+depth/Z reprojection is rejected as shipping renderer.

## Retail identity
- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
