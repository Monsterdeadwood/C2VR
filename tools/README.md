# Tools

Project-authored corpus harvesters, extractors, builders, analyzers and diagnostic packagers belong here. Prefer tools that move a concrete target to the next evidence lane. Avoid duplicate harvesters after a target/corpus index already exists.

## Repository tools
- `extract_verified_custom_dual_t1_v1_0_1.py` — reconstructs/verifies the exact `CUSTOM_DUAL_T1 v1.0.1` parent source authority from the canonical corpus.
- `extract_verified_v17_2_1.py` — deterministic compact recovery of the v17.2.1 donor textual source layer.
- `extract_verified_v17_2_1_original.py` — verifies/reconstructs the original v17.2.1 donor package authority; use for exact donor provenance before transplant work.

## Existing external/local C2VR artifact families
Do not regenerate these classes blindly; check Library/local research root first.

### Current PosePair line
- `CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip` — current untested P6 finalist; only bounded exact wait ceiling 45->120 ms. SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`.
- v17.2.5 WAIT45 result — latest completed timing causal result; 269 exact / 269 submits / 53 misses, exact 83.5404%, wait max 47 ms.
- `runtime/donors/v17.2.1/` — verified donor source authority and PosePair transplant reference.

### Main renderer authority
- `runtime/main/CUSTOM_DUAL_T1_v1.0.1/` — exact proven true-L/R parent.
- canonical T1 result `CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

### HEAD / camera research already performed
- HEAD convergence/state packs around `+0x0057AC76`, `SetupCamera +0x0057A730`, real CCamera bounded mutation/restore, frustum semantics, basis/order controls.
- Do not create another generic camera analyzer while PosePair is current gate.

### Weapon / NEAR research already performed
- v17.2.x controller/NEAR source and one-click builds
- historical STABLE CAMERA / FULL VR donors
- RenderDoc/320-byte camera carrier analyses
- source/PDB weapon topology work
- focused state is in `research/WEAPON_NEAR.md`

### Static/runtime analysis ecosystem already used
- Ghidra/headless source-to-retail mapping
- beta PDB/symbol census
- RenderDoc/GPU matrix/resource inspection
- TTD targeted writer/reader traces
- x64dbg/loaded-memory disassembly
- ReClass for concrete field tests
- x86 D3D11 proxy + x64 OpenXR host
- keyed mutex transport / shared-texture capture

## Important local roots
- Retail: `C:\GOG Games\Crysis 2`
- Beta 5620/source/PDB: `C:\GOG Games\Crysis 2\crysis2(5620)\_r\crysis2(5620)\_01_13`
- Shared research tools: `C:\GOG Games\VR Research Tools`

## Rule
Once an analyzer produces a concrete target, pass that target to the next specialized lane. Do not build another analyzer of the same class unless new evidence falsifies the first result.
