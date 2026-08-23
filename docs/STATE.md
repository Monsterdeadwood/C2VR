# Crysis 2 VR State

## Status
ACTIVE.

## Current gate
Resolve the exact retail CPU writer/consumer provenance that connects authoritative camera/view state to GPU resource `20500` (320 bytes, ~98 updates/frame in the measured capture) and the late `RT_RenderScene` application stage.

## Current known state
- Retail path: `C:\GOG Games\Crysis 2`.
- Beta/dev lineage remains valuable for static candidate generation, but the visible blocker is now a concrete retail provenance problem, not a broad corpus census.
- RenderDoc/framegraph analysis observed ~1886 draws in the measured retail frame.
- Resource `20500` is a high-value camera/per-view constant-buffer candidate: 320 bytes, ~98 updates/frame in that measured run.
- `GetViewCamera` / `CSystem::Render` ownership chain is established strongly enough to preserve as project truth.
- `RC_SetCamera` is not sufficient as the sole final raster camera owner.
- A later `RT_RenderScene` overwrite/apply stage is the supported current direction.
- Exact instruction tying CPU camera state to resource `20500` remains OPEN.

## Operating protocol
- Do not restart broad LIVE fishing while concrete resource `20500` and `RT_RenderScene` targets remain unresolved.
- Retail runtime evidence outranks beta/dev resemblance.
- PARALLELIZE EVIDENCE, SERIALIZE MUTATION.
- One causal field/matrix perturbation only after exact writer/consumer provenance is concrete.
- Preserve the flat known-good baseline.

## Next
1. Trace the CPU update/copy/write that feeds resource `20500`.
2. Bind that instruction to `RT_RenderScene` call context and render-pass schedule.
3. Confirm which bytes/matrix fields are view/projection relevant.
4. Perform one targeted causal mutation with a written prediction.
5. Only then proceed to coherent stereo insertion.

See `docs/SYNC.md` for the canonical cross-branch snapshot.
