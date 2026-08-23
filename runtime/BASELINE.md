# Crysis 2 VR — RUNTIME BASELINE

## Main build
`CUSTOM_DUAL_T1 v1.0.1`

This remains the main build. It already proves genuine private LEFT/RIGHT rendering in retail Crysis 2. Do not replace it wholesale with v17.2.

## Proven main-build measurements
- center HMD inject/restore: 2296 / 2296
- private LEFT passes: 2295
- private RIGHT passes: 2295
- direct eye copies: 2229
- OpenXR submits: 2624
- median sampled L/R MAE: 35.9781

Interpretation: two distinct eye images are real. Stereo discovery is closed.

## Exact retail guards
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## Immutable render architecture
One prepared render-list executes twice:
`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`.

Canonical eye transaction:
`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 snapshot -> render-thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`.

Current RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Forbidden in the baseline:
- second top-level RenderWorld / EF_StartEf
- second EF_StartEf3D
- mono RGB+depth reprojection final renderer
- native Cry SBS/DisplayStereo/CopyToStereo final transport
- HMD transform applied on every Renderer::SetCamera

## Current authorized mutation surface
**PosePairContract only.**

Allowed donor from v17.2:
- immutable XR frame ticket/contract
- host ticket publication
- exact ticket carriage through LEFT+RIGHT
- completed pair publication after RIGHT RT completion
- bounded host wait
- exact identity validation
- mismatch => zero layers

Not allowed in the same mutation:
- HEAD/culling rewrite
- RIGHT Touch NEAR/weapon mutation
- temporal-history mutation
- second-eye shadow suppression

## Donor baselines
- v17.2/v17.2.1: implementation donor only, not main build
- v2.2.0 STABLE CAMERA: weapon/input behavior donor only

## Acceptance invariant
Every accepted change must preserve true private L/R execution. If the PosePair fix damages the proven renderer primitive, rollback rather than rebuilding around the failure.
