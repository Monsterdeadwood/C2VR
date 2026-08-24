# C2VR — beta/PDB identity conflict — RESOLVED 2026-08-25

Purpose: prevent Crysis 2 build-5620 PDB families from being silently collapsed by filename and preserve the exact reason the historical sizes differed.

## Resolution
The two previously conflicting size sets are from the **same exact local build-5620 root but different architecture directories**:

- Set A = `crysis2(5620)_r\crysis2(5620)_01_13\Bin32`
- Set B = `crysis2(5620)_r\crysis2(5620)_01_13\Bin64`

This is now closed by already-retained COLD evidence. No new game/runtime scan was required.

The 2026-08-15 PDB Atlas contains exact `Image + PDB + ImageSHA256 + PdbSHA256` rows for Bin32. The 2026-08-21 Total Cold Atlas `01_INPUT_MANIFEST.tsv` contains exact path + size + SHA256 for both Bin32 and Bin64. The older size discrepancy was therefore architecture, not evidence of an unknown beta revision.

## Stable identity labels
Use these labels in future version mapping:

- `BETA5620_BIN32`
- `BETA5620_BIN64`
- `BETA5620_BIN32_NO_PROTECT` for the explicitly separate no-protect binaries

Never use a bare filename such as `CryGameCrysis2.pdb` as a unique identity.

## BETA5620_BIN32 high-value identities
Root:
`C:\GOG Games\Crysis 2\crysis2(5620)_r\crysis2(5620)_01_13\Bin32`

| File | Bytes | SHA256 |
|---|---:|---|
| `CryGameCrysis2.dll` | 7,523,552 | `162FC5AB4BD76AD55D8B2855BE8B05FDD5F79276607357A453E56F31B3D54BC0` |
| `CryGameCrysis2.pdb` | 82,045,952 | `B3EF76859CCE75CF92A4DBD1CCBDE67230F079175F75AE772AA7E184D824A155` |
| `CryAction.dll` | 8,522,464 | `4973E731298D617EE1DCE1B3D1A298905CF03A604D8A1617A2C7CF669C1604A5` |
| `CryAction.pdb` | 40,791,040 | `376E35C155C6C020C9AADDADCF0325CEA0DD62B4B2D59764CDF58A8CD97959EB` |
| `CrySystem.dll` | 4,777,184 | `6B44BAEA80BF3C6E7A4BACB6ABD472DB3C64AEE2EAFD7416B6644A87D9960479` |
| `CrySystem.pdb` | 18,607,104 | `2F0A3ED75D671079035DAA384D839BEBAB19AAE3DC55DC71FAAF41F30DD5F825` |
| `CryRenderD3D11.dll` | 3,438,304 | `0C368CD36A2BCA7E384DACA6F2CE3AD8C330CB40A60007053B43B7B36AEEEC08` |
| `CryRenderD3D11.pdb` | 19,467,264 | `3B679714B3C3CB7221795D093AC13868168115A78A90BE22C3266F78B2F5754C` |
| `Cry3DEngine.dll` | 2,596,576 | `B5B1FD54968E7FD6154A4CE6B18D9536F7A52112C71EFE20058EB109383DFF15` |
| `Cry3DEngine.pdb` | 14,117,888 | `9DEFEFF46C8321D4496A9775669C39449EBED1FB499F97FC78C9236770F76F3A` |
| `CryEntitySystem.dll` | 798,944 | `F21B30243B0E880E6766A26CFA963B04366090DBA61111456FFFD77D2713862B` |
| `CryEntitySystem.pdb` | 7,703,552 | `388B6BBEE48B8DE4556E83D8A9672151AF17D8168AC5F5B83FC4D65A98FC05A0` |

Additional Bin32 PDB identities are retained in the Total Cold Atlas manifest, including `CryAISystem`, `CryAnimation`, `CryNetwork`, `CryRenderD3D9`, `CryRenderNULL`, `CryScriptSystem`, `Crysis2.pdb`, editor/resource-compiler PDBs and others.

## BETA5620_BIN64 high-value identities
Root:
`C:\GOG Games\Crysis 2\crysis2(5620)_r\crysis2(5620)_01_13\Bin64`

| File | Bytes | SHA256 |
|---|---:|---|
| `CryGameCrysis2.dll` | 10,705,632 | `CB8696038776A121C7E750CB42D1D8B9C952C56BA0C9035FF74B092DAD5A063E` |
| `CryGameCrysis2.pdb` | 80,251,904 | `85A90E51EC3E5BC87EEF244DE270C1B791399CA84965381C01AA7C92610464EB` |
| `CryAction.dll` | 5,068,000 | `888124A15CDEB73F37B2C4617E08F8D9B38AA65FB347FEBF7C606B9DEBCF3438` |
| `CryAction.pdb` | 36,940,800 | `26E97242B2E96A0BA02DB7FCB9F5A211EE15E93B06B4CF9CDA17776398F31CBA` |
| `CrySystem.dll` | 5,154,528 | `8ED33EB5784B896C1D9609D8AD379F4142097A39854AD18152989DD02E537F39` |
| `CrySystem.pdb` | 16,239,616 | `938B5BC8E1F9982BE5120277F8486F78E1D5A900AE5F0F4691ABFAA49B222EF6` |
| `CryRenderD3D11.dll` | 3,386,080 | `CC1E7E9C5D43CF348E25F714040FDBA534ED67654BB6BE57E2C6436533C732E2` |
| `CryRenderD3D11.pdb` | 16,362,496 | `D1F0C0272555D08FD18FD1ECFE21EE3908E2861CEE4D584ACBAECDC731FEA747` |
| `Cry3DEngine.dll` | 3,350,752 | `B73619DD0CE44288DCE20E18A0A24E4F2B5C8EEB1324681D1E196571F9027D7C` |
| `Cry3DEngine.pdb` | 12,536,832 | `618D97053FE92236C9EA5D580A6A537B4A66753B7ACDFCB191E00121A9128887` |
| `CryEntitySystem.dll` | 976,096 | `29A265F7880B6840B73EC735497CF5D1D050FDD87B0F9475E435E89C64D7CA2E` |
| `CryEntitySystem.pdb` | 6,679,552 | `BB8445F243BB7E0EDCBC6D15B31FFCC30AE2E77E5C8572E49889D157E1BFF348` |

Additional Bin64 PDB identities retained in the same manifest include `CryAISystem`, `CryAnimation`, `CryNetwork`, `CryRenderD3D9`, `CryRenderNULL`, `CryScriptSystem`, `Crysis2.pdb`, editor/audio PDBs and others.

## BETA5620_BIN32_NO_PROTECT
Separate exact binary identities already recorded by the PDB Atlas:

| File | Bytes | SHA256 |
|---|---:|---|
| `Bin32_no_protect\CryAction.dll` | 3,605,504 | `9E0D87DC94E7B3DF74ABC5671CC839E07F10E8F7282CB928BE0FAB70256F0D3A` |
| `Bin32_no_protect\CrySystem.dll` | 3,785,216 | `8B9A8AF576E89E73FE01421420A5BA75D9229E4538951BB10707451758B873FE` |

Do not substitute no-protect RVAs for normal Bin32 without explicit mapping.

## Evidence sources
### `C2VR_PDB_SYMBOL_ATLAS_RESULT_20260815_165408.zip`
Physical Library carrier recovered during this audit:
- bytes `64,634,999`
- SHA256 `6413D3B7CD7A6FF44E38F539F5A7CEA1372C5948BEDD4E951E1258002E6AA3C2`

Its `ATLAS/PDB_SCAN_LOG.csv` explicitly pairs each Bin32 image and PDB with SHA256, and its `ATLAS/BINARY_DONORS.csv` preserves exact image identities.

### `C2VR_TOTAL_COLD_ATLAS_RESULT_20260821_195858.zip`
Physical Library carrier recovered during this audit:
- bytes `4,375,163`
- SHA256 `1B45312DAA8E438CAA14CA5FE5DAF73A4B359B671ABDB30D2F6D17DC346C78CF`

Its `01_INPUT_MANIFEST.tsv` records exact path + byte size + SHA256 across the source/beta corpus and proves that the smaller historical PDB set is `Bin64` from the same 5620 tree.

## Mapping rule
A beta-derived symbol/RVA/function-size mapping must carry at least:

`BETA5620_BIN32|BIN64 + relative path + SHA256`

For especially important functions, retain PDB GUID/age or CodeView association when obtainable, but the architecture/path/hash ambiguity that triggered this note is now resolved.

Cross-architecture convergence is useful evidence, but neither beta architecture outranks retail 1.9 proof.

## Tool status
`tools/C2VR_EXTERNAL_CORPUS_IDENTITY.ps1` remains useful as an independent future re-verifier if the user's local tree is moved/changed. It is no longer required to resolve this specific Bin32-vs-Bin64 question because the retained result manifests already closed it.

## Classification
**RESOLVED COLD.**

No LIVE, game launch, OpenXR session, hook or mutation was needed.

Current runtime gate remains P6 PosePair.
