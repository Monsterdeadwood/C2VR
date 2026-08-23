# Crysis 2 VR — PROVEN

## Research corpus / toolchain
- Retail and beta/dev lineages are both available for comparative research.
- The beta/dev corpus is suitable for static archaeology and symbol/lineage candidate generation, but retail runtime validation remains required.
- A POROUS ORACLE workflow has already been built and iterated to support beta archaeology plus retail DX11 runtime observation.
- Automatic runtime sensing replaced the earlier manual F8-trigger workflow in the current research direction.
- Zig 0.16.0 has been used successfully as the x86 build toolchain for the proxy/oracle path.

## Retail runtime / render provenance
- Runtime work has progressed beyond corpus-only archaeology.
- RenderDoc/framegraph analysis observed a measured retail frame with approximately 1886 draws.
- GPU resource `20500` is a concrete camera/per-view constant-buffer candidate in that capture: size 320 bytes, updated about 98 times per frame.
- A `GetViewCamera` / `CSystem::Render` ownership chain is established strongly enough to preserve as project truth.
- `RC_SetCamera` is not sufficient as the sole final raster camera owner.
- A later `RT_RenderScene` overwrite/apply stage remains the supported current ownership direction.

## Interpretation boundary
- Resource `20500` is a concrete high-value candidate, not yet a fully causally proven final camera/projection buffer.
- The exact retail CPU instruction that writes/copies the authoritative view/projection state into resource `20500` remains OPEN.
- No claim of solved stereo/camera is recorded yet.

## Process
- SOURCE-FIRST remains mandatory when a new static fact can answer the question cheaper than LIVE, but broad corpus harvest is no longer the visible blocker.
- Compact targeted provenance work is preferred over another broad analyzer while `20500` and `RT_RenderScene` remain unresolved concrete targets.
