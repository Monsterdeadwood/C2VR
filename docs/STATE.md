# Crysis 2 VR State

## Status
ACTIVE. WORKING BUILD FIRST.

## Main build
`CUSTOM_DUAL_T1 v1.0.1`

This build already proved genuine retail two-eye rendering:
- LEFT private passes 2295
- RIGHT private passes 2295
- direct eye copies 2229
- OpenXR submits 2624
- median sampled L/R MAE 35.9781, therefore non-duplicate eye pixels

Do not rebuild stereo.

## Current gate
**PosePairContract.** The existing true-L/R renderer primitive must carry exactly one immutable current-frame OpenXR ticket through both eyes and submission. Mismatched/stale pairs are dropped, never relabeled.

## Finish order
`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

## Current architecture
One prepared render-list executes twice inside the canonical eye transaction. Do not add a second top-level RenderWorld/EF_StartEf.

Current master RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Key retail anchors:
- `CSystem::m_ViewCamera +0x3F0`
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- `Renderer::SetCamera +0x00148340`
- `EF_Scene3D +0x00101370`
- `EF_EndEf3D +0x001019A0`
- `RC_RenderScene +0x001C48D0`
- `RT_RenderScene +0x00107370`
- `FOB_NEAREST SetCamera return +0x000FF456`

## Next mutation
Transplant only the PosePair rendezvous contract from the v17.2 donor lineage into T1:
- one immutable XR frame ticket
- exact LEFT/RIGHT ticket identity
- publish completed pair only after RIGHT RT completion
- bounded host wait
- exact identity acceptance
- mismatch => zero layers

Do not mix HEAD/culling, weapon/NEAR, temporal or shadow mutations into this build.

## Later blocker already known
Fast-head-turn temporal tearing / eye-state corruption is a real later finish blocker, but it is not authorized until PosePair, HEAD and weapon/NEAR reach their visual gates.

See `docs/SYNC.md` for the complete canonical state.
