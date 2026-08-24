# C2VR — beta/PDB identity conflict — 2026-08-25

Purpose: prevent multiple Crysis 2 beta/debug PDB families from being silently collapsed into one `5620 PDB` identity. This is a COLD archival/version-mapping issue, not a runtime gate.

## Why this note exists
Retained C2VR evidence contains at least two different observed size sets for similarly named CryEngine PDBs. The discrepancy is real evidence of different roots, architectures, build variants, or package copies. Until exact path + SHA256 closes each identity, a filename alone is not an identity.

Do **not** use only `CryGameCrysis2.pdb`, `CryAction.pdb`, etc. as a unique source label.

## Observed set A — earlier PDB-rich x86 beta / SDK forensic summary
Retained `C2VR_SDK_COOP_FORENSICS_RESULT_20260815_161600.zip` / `C2VR_PDB_SYMBOL_ATLAS_RESULT_20260815_165408.zip` dossier reports a PDB-rich x86 beta family with:

| Module / PDB | Observed bytes |
|---|---:|
| `CryGameCrysis2.dll` | 7,523,552 |
| `CryGameCrysis2.pdb` | 82,045,952 |
| `CryAction.dll` | 8,522,464 |
| `CryAction.pdb` | 40,791,040 |
| `CrySystem.dll` | 4,777,184 |
| `CrySystem.pdb` | 18,607,104 |
| `CryRenderD3D11.dll` | 3,438,304 |
| `CryRenderD3D11.pdb` | 19,467,264 |
| `Cry3DEngine.pdb` | 14,117,888 |
| `CryEntitySystem.pdb` | 7,703,552 |

The same retained evidence records no-protect binaries:
- `Bin32_no_protect\CrySystem.dll` — 3,785,216 bytes
- `Bin32_no_protect\CryAction.dll` — 3,605,504 bytes

These sizes must remain associated with their exact source root/package when recovered.

## Observed set B — TOTAL COLD ATLAS 2026-08-21 census
`C2VR_TOTAL_COLD_ATLAS_v1.1.3` performed a READ-ONLY / NO GAME LAUNCH / NO OPENXR / NO HOOKS corpus pass and discovered 24,806 source files plus 213 beta artifacts across 5 roots. Its symbol census recorded:

| PDB | Observed bytes |
|---|---:|
| `Cry3DEngine.pdb` | 12,536,832 |
| `CryAction.pdb` | 36,940,800 |
| `CryEntitySystem.pdb` | 6,679,552 |
| `CryGameCrysis2.pdb` | 80,251,904 |
| `CryRenderD3D11.pdb` | 16,362,496 |
| `CryRenderD3D9.pdb` | 16,534,528 |

The same census contained many other PDBs and explicitly walked a `beta` provenance set before the symbol census.

## Conflict
Set A and Set B cannot be treated as the same exact files because sizes differ materially for every overlapping high-value PDB shown above.

Examples:
- `CryGameCrysis2.pdb`: 82,045,952 vs 80,251,904
- `CryAction.pdb`: 40,791,040 vs 36,940,800
- `CryRenderD3D11.pdb`: 19,467,264 vs 16,362,496
- `Cry3DEngine.pdb`: 14,117,888 vs 12,536,832
- `CryEntitySystem.pdb`: 7,703,552 vs 6,679,552

Possible causes include:
1. Bin32 vs Bin64/debug-tool PDB family;
2. different beta/source roots under the five-root discovery;
3. different build/package revision;
4. protected vs no-protect or SDK/prototype package lineage;
5. duplicate filenames from different directories selected by different analyzers.

Do not choose among these hypotheses by filename or size alone.

## Required identity key
Future mappings must identify a PDB/binary with at least:

`ROOT_ID + RELATIVE_PATH + SIZE + SHA256 + PE_MACHINE(if binary) + SOURCE_PACKAGE/BUILD`

For PDBs, also preserve GUID/age or CodeView association when obtainable.

## Mapping rule
A symbol/RVA/function-size result derived from a PDB must carry its identity key. A mapping from one set does not automatically validate the other set.

Evidence precedence remains:
1. retail proof;
2. exact same-package/source-path beta mapping;
3. cross-beta convergence;
4. generic symbol-name similarity.

## COLD closure plan
Use `tools/C2VR_EXTERNAL_CORPUS_IDENTITY.ps1` to hash only high-value beta/PDB candidates under the existing Crysis 2 tree. It is read-only and does not launch the game.

After the output exists:
1. cluster candidates by exact path/hash;
2. assign stable IDs such as `BETA5620_BIN32_A`, `BETA5620_BIN64_A`, `SDK11_BIN64`, etc. only when path/build evidence supports the label;
3. link every existing PDB-derived retail mapping to the exact cluster that produced it;
4. update `research/SOURCE_CORPUS_REGISTRY.md` with immutable identities;
5. if two independent clusters map the same retail function, treat that as stronger cross-version convergence.

## Gate discipline
No LIVE is authorized by this note. Current runtime gate remains P6 PosePair. This identity closure may proceed in WAVE 1 COLD in parallel.
