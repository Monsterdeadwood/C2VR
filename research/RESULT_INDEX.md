# Crysis 2 VR — RESULT INDEX

Current governing rule: WORKING BUILD FIRST, reverse only blockers.

## CUSTOM_DUAL_T1 v1.0.1
**Class:** PROVEN MAIN BUILD / acceptance failed only on PosePairContract

Historical measurements:
- center HMD inject/restore: 2296/2296
- private LEFT passes: 2295
- private RIGHT passes: 2295
- direct eye copies: 2229
- OpenXR submits: 2624
- L/R median sampled MAE: 35.9781

Interpretation: genuine non-duplicate retail L/R rendering is proven. Do not rebuild stereo.

## Current integration handoff: PosePairContract
**Class:** CURRENT BLOCKER

Finalist:
- one host-owned immutable current-XR-frame ticket
- same ticket travels through LEFT + RIGHT
- completed pair publishes ticket only after RIGHT RT completion
- bounded host wait
- exact ticket identity required
- mismatch/stale pair => zero layers, never relabel

v17.2 already contains donor implementation material for this contract. Import only the rendezvous pieces into T1 first.

## Canonical eye transaction
**Class:** PROVEN / IMMUTABLE ARCHITECTURE

`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 snapshot -> render-thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`

One prepared render-list executes twice. No second top-level RenderWorld/EF_StartEf.

## v17.2 / v17.2.1
**Class:** DONOR IMPLEMENTATION CORPUS, NOT MAIN BUILD

Contains candidates for multiple later gates:
- immutable PosePair ticket/rendezvous
- HEAD/culling union
- FOB_NEAREST / RIGHT Touch weapon transaction
- temporal-history isolation
- second-eye shadow gating

Do not install wholesale because it destroys causal attribution.

## v2.2.0 STABLE CAMERA
**Class:** BEHAVIOR DONOR / LAST-KNOWN-GOOD REFERENCE

Preserves useful right-controller weapon/viewmodel motion and right-trigger firing behavior. Do not replace T1 main stereo build with it.

## Historical RenderDoc / resource 20500 lineage
**Class:** SUPPORTING ARCHAEOLOGY, NOT CURRENT FRONTIER

- analyzed retail frame ~1886 draws
- resource `20500`, 320 bytes, ~98 updates/frame in measured capture
- useful camera/per-view CB provenance history

This is no longer the finish blocker. Do not restart broad resource archaeology unless a serial working-build gate produces a concrete need.

## v15 late-sink / mono reprojection
**Class:** FALSIFIED AS FINAL ARCHITECTURE

Mono RGB+depth/Z reprojection is visually and architecturally rejected as the shipping renderer.

## Retail identity
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## Canonical handoff corpus
- `C2VR_STATE_SYNC_20260823.md`
- `C2VR_MAIN_INTEGRATOR_BLUEPRINT_20260823.md`
- `CRYSIS2VR_CLAUDE_START_HERE_20260823.md`
- `CRYSIS2VR_CLAUDE_MAIN_CORPUS_20260823.md`
- manifest SHA identities recorded separately in `research/CORPUS_MANIFEST.md`.
