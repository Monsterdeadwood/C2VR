# Crysis 2 VR — RESULT INDEX

Current governing rule: WORKING BUILD FIRST, reverse only blockers.

## CUSTOM_DUAL_T1 v1.0.1
**Class:** PROVEN MAIN BUILD / acceptance failed only on PosePairContract

Canonical result artifact:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Artifact identity:
- bytes: `68,872,488`
- SHA256: `986A1B8FBFB32908E1D11580D90005A72851FEDAe1EDDB3596144D341CD53367`

Historical measurements:
- center HMD inject/restore: 2296/2296
- private LEFT passes: 2295
- private RIGHT passes: 2295
- direct eye copies: 2229
- OpenXR submits: 2624
- L/R median sampled MAE: 35.9781
- host status recorded `pose_desync=1`
- game status recorded `frame_desync=0`, `duplicate_eye_warn=0`

Interpretation: genuine non-duplicate retail L/R rendering is proven. Do not rebuild stereo. The observed acceptance failure is PosePairContract / pose ownership, not absence of a two-eye renderer.

## Current integration handoff: PosePairContract
**Class:** CURRENT BLOCKER

Finalist:
- one host-owned immutable current-XR-frame ticket
- same ticket travels through LEFT + RIGHT
- completed pair publishes ticket only after RIGHT RT completion
- bounded host wait
- exact contract id + predictedDisplayTime identity required
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

### Byte-verified source recovery — 2026-08-23
The canonical 100MB master corpus contains embedded source from:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.1_ARGV_FIX_ONECLICK`.

A deterministic recovery pass reconstructed 25 text files and verified every recovered file against both recorded byte length and SHA-256.

Key source identities:
- `src/t1_ipc.h` — 2824 bytes — `DE00ABD099F5988BB930A6150FF16BA1A9E9AC1A55AE3EC5CC59DC7DEA54B931`
- `src/t1_host_x64.cpp` — 34560 bytes — `A349AA6BC2781C4DCD1AF20E5EF5B571656B84BF005E2193637C3591F8D21C51`
- `src/t1_dual_render.cpp` — 20540 bytes — `397D0577D3F07B776A17395733AB6500BCD05C8928A51608CE3FDD8DEA415C77`
- `src/t1_proxy.cpp` — 16526 bytes — `1CF91E61999A600C7A39E992EF610FFDF259ABD9B8D0E32373A13996DD8FC22C`
- `src/t1_camera.cpp` — 8111 bytes — `C71E6B52A6F326923A45E682392F79C96C84FFF1E1D66393769A821D9A5C42A1`
- `src/t1_game_api.h` — 1014 bytes — `642AF56F086EE9EF8E674F495C2B610E9C38088FB0A2342B55CB0F53E2E52E02`

GitHub now contains the verified compact source layer plus `tools/extract_verified_v17_2_1.py`, which reproduces the full textual donor tree from the canonical corpus and refuses any byte/hash mismatch.

Current transplant map:
`runtime/donors/v17.2.1/POSEPAIR_TRANSPLANT.md`.

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
