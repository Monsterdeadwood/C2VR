# Crysis 2 VR — STATE SYNC

Snapshot imported: 2026-08-23

## LATEST RESULT
- Runtime research has progressed beyond corpus-only archaeology.
- RenderDoc/framegraph analysis observed a retail frame with ~1886 draws and a camera/per-view constant-buffer candidate identified as resource `20500` (320 bytes), updated about 98 times per frame in the measured run.
- CPU ownership work established a `GetViewCamera` / `CSystem::Render` ownership chain.
- `RC_SetCamera` as the sole final raster owner is rejected; a later `RT_RenderScene` overwrite/apply stage remains the supported direction.

## PROVEN
- Retail and beta/dev lineages are both useful, but retail runtime proof remains authoritative.
- `GetViewCamera` / `CSystem::Render` ownership chain is established strongly enough to keep as project truth.
- `RC_SetCamera` is not sufficient as the sole final raster camera owner.
- RenderDoc/framegraph work found a concrete high-value camera/per-view CB candidate: resource `20500`, size 320 bytes, ~98 updates/frame in the captured run.
- The measured frame contained ~1886 draws, providing a concrete render workload baseline for provenance work.

## FALSIFIED / CLOSED
- Broad LIVE fishing without a concrete retail target: closed by policy.
- Treating `RC_SetCamera` as the final/sole raster camera owner: rejected.
- Beta/dev symbol similarity alone as proof of retail ownership: rejected.

## CURRENT FINALISTS
1. Late camera/application path around `RT_RenderScene`.
2. Retail camera/per-view constant-buffer candidate resource `20500`.

## CONCRETE TARGETS
- CPU ownership lineage: `GetViewCamera` -> `CSystem::Render`.
- Late-stage application candidate: `RT_RenderScene`.
- GPU resource candidate: `20500`, 320 bytes, ~98 updates/frame in the measured capture.
- Exact retail writer/consumer instruction connecting CPU camera state to resource `20500`: OPEN.

## CURRENT GATE
Resolve the exact retail writer/consumer provenance that connects the authoritative camera/view state to resource `20500` and the late `RT_RenderScene` application stage.

## NEXT
1. Use the existing candidate resource and late-stage owner to avoid another broad census.
2. Find the exact CPU write/copy/update instruction feeding resource `20500`.
3. Tie that instruction to `RT_RenderScene` call context and one render pass/frame schedule.
4. Only after provenance is concrete, perform one causal perturbation to a single matrix/field with a written prediction.
5. Preserve flat known-good rendering as the baseline.

## METHOD ALREADY USED
- Beta/dev/source/static archaeology.
- Ghidra/static mapping followed by retail LIVE confirmation.
- RenderDoc frame/resource analysis.
- TTD CPU provenance attempts and runtime call-chain work.
- Framegraph/resource archaeology.
- Matrix/constant-buffer candidate analysis.
- Targeted causal interventions only after candidate identification.
- Depth/resource/OpenXR telemetry in supporting lanes.

## HARD CONSTRAINTS
- SOURCE-FIRST remains mandatory when new lineage material appears, but G0 corpus harvest is no longer the visible blocker.
- Do not restart a broad analyzer while resource `20500` and `RT_RenderScene` remain concrete unresolved targets.
- Retail proof outranks beta/dev resemblance.
