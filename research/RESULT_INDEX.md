# Crysis 2 VR — RESULT INDEX

This ledger separates retail proof, strong candidates, static lineage, and infrastructure outcomes.

## Retail RenderDoc / framegraph camera-resource result
**Class:** SUPPORTED / current frontier

Measured retail capture facts:
- ~1886 draws in the analyzed frame.
- GPU resource `20500` identified as a high-value camera/per-view constant-buffer candidate.
- Resource size: 320 bytes.
- Update frequency in the measured run: ~98 updates/frame.

What remains OPEN:
- exact retail CPU writer/copy/update instruction feeding resource `20500`;
- exact field/matrix role;
- final causal proof that `20500` is the shipping camera/projection buffer.

## CPU ownership chain
**Class:** PROVEN/SUPPORTED ownership

- `GetViewCamera` / `CSystem::Render` ownership chain is preserved as project truth.
- `RC_SetCamera` as the sole/final raster owner is rejected.
- Later `RT_RenderScene` application/overwrite is the supported current direction.

## POROUS ORACLE lineage
**Artifact family:** `CRYSIS2VR POROUS ORACLE v0.1 -> v0.2.2 AUTO SENSE`
**Class:** TOOLING / CORPUS

- Evolved from manual-trigger variants to automatic runtime sensing.
- Supports beta archaeology plus retail DX11 porous runtime observation.
- Zig 0.16.0 used for the x86 D3D11 proxy/oracle build path.

## Beta/dev lineage
**Known research lineage:** `crysis2(5620)` tree
**Class:** STATIC CANDIDATE GENERATOR

- Used for camera/view/projection/render-context symbol and ownership candidate generation.
- Beta/dev resemblance is never retail proof by itself.

## Current handoff
Do not build another broad analyzer. Hand the concrete pair `resource 20500 + RT_RenderScene` to CPU/GPU provenance tooling until the exact retail writer/consumer is resolved.
