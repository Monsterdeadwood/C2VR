# Crysis 2 VR — GATES

## G0 — Source/beta corpus harvest
**PASS:** camera, view, projection, render-context, frame and stereo-adjacent symbols/classes/functions are indexed and cross-linked across available lineage material.

## G1 — Retail target map
**PASS:** at least one retail D3D11 view/projection target is mapped from the corpus and verified passively at runtime with call/resource/context evidence.

## G2 — Coherent stereo insertion
**PASS:** both eyes render from one simulation frame/pose with distinct eye offsets and asymmetric projection, without breaking the flat baseline.

## G3 — Independent HMD camera
**PASS:** HMD orientation/translation are applied at one authoritative camera point and do not double-apply body/camera transforms.

## G4 — Stereo-safe culling and post path
**PASS:** geometry, shadows and post effects remain valid for both eyes or have documented stereo-safe fallbacks.

## G5 — Weapon / hands
**PASS:** viewmodel/controller pose can be separated from the HMD camera after rendering gates remain green.

## Current gate
**G0**, with G1 candidate generation happening as part of the same corpus harvest.
