# Crysis 2 VR — GATES

## G0 — Source/beta corpus harvest
**STATE:** sufficient to generate concrete retail targets; no longer the visible blocker. Continue static harvest only when it directly reduces the current provenance uncertainty.

## G1 — Retail camera/resource provenance
**PASS:** identify the exact retail CPU writer/consumer that feeds the camera/per-view data used by resource `20500` and bind it to the late `RT_RenderScene` application stage and render-pass schedule.

Concrete current targets:
- `GetViewCamera` / `CSystem::Render` ownership chain
- `RT_RenderScene` late application direction
- resource `20500`, 320 bytes, ~98 updates/frame in the measured capture

**CURRENT GATE: G1**

## G2 — Causal view/projection field proof
**PASS:** one field/matrix perturbation at the proven writer produces the predicted view/projection change and restores cleanly with the flat baseline intact.

## G3 — Coherent stereo insertion
**PASS:** both eyes render from one simulation frame/pose with distinct eye offsets and asymmetric projection, without breaking the flat baseline.

## G4 — Independent HMD camera
**PASS:** HMD orientation/translation are applied at one authoritative camera point and do not double-apply body/camera transforms.

## G5 — Stereo-safe culling and post path
**PASS:** geometry, shadows and post effects remain valid for both eyes or have documented stereo-safe fallbacks.

## G6 — Weapon / hands
**PASS:** viewmodel/controller pose can be separated from the HMD camera after rendering gates remain green.
