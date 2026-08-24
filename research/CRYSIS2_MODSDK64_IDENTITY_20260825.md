# C2VR — Crysis 2 ModSDK / Bin64 donor identity — 2026-08-25

Purpose: close the exact module-identity gap for the Crysis 2-specific x64 donor lineage without redownloading or launching anything.

## Source of truth
The already-retained `C2VR_PDB_SYMBOL_ATLAS_RESULT_20260815_165408.zip` contains `ATLAS/BINARY_DONORS.csv` with exact path, size and SHA256 for the local x64 Crysis 2 module set classified by that atlas as `SDK_1_1_X64`.

This means the x64 donor identity existed in the project evidence before the later `c2-launcher` research note. No new acquisition is required to establish these binary identities.

## Exact local x64 donor modules
Local root family:
`C:\GOG Games\Crysis 2\Bin64`

| Module | Bytes | SHA256 |
|---|---:|---|
| `CryGameCrysis2.dll` | 11,156,264 | `4E51AEA15E679066BC8CB3BE2D29BC61156DFF99AC78977036F313BD568F7331` |
| `CryAction.dll` | 5,119,272 | `EDECB754B78AFFF731F3E597077363EBB1040AE21DA7E497C71204B9C7548F1D` |
| `CrySystem.dll` | 5,225,768 | `BACC02298962E54B5051516B0DF00B02F168079A2B27FB7AAFB754E7D8A80694` |
| `CryRenderD3D11.dll` | 3,493,160 | `9460DC78D2806A0438B9B669E8D4EC8C3F62810F63A8479DA5B003B96AA93692` |

These are distinct from both `BETA5620_BIN64` and retail x86 modules. Never mix offsets/RVAs across these identities by filename alone.

## Relationship to c2-launcher
Public donor/runtime launcher:
`https://github.com/mvoolt/c2-launcher`

Recorded project pin:
`74cb408e5ee63038ae69d16e7dfb03c432f0d606`

The launcher is useful because it exercises Crysis 2 x64 ModSDK lineage through normal game startup and weapon/map state. The exact local module hashes above provide a stable identity key for any static/runtime donor finding made against the local x64 tree.

Do not assume the public launcher's author's module bytes are necessarily byte-identical to the local files above unless checked. The correct mapping key is the local module SHA256 plus the launcher commit and any runtime module hash observed during the donor experiment.

## Priority future mappings
When G3 WEAPON/NEAR opens, use this x64 C2-specific donor as an intermediate fingerprint layer for:
- `CPlayer::PostUpdateView`
- `CItem::UpdateFPPosition`
- `CItem::UpdateFPCharacter`
- `CWeapon::SetFiringLocator`
- fire-mode `GetProbableHit`
- `GetFiringPos`
- `GetFiringDir`

Useful features to export from the x64 donor before retail matching:
- function-size/CFG fingerprints;
- nearby constants/strings;
- vtable slot relationships;
- caller/callee neighborhoods;
- RTTI/class relationships where present;
- source/PDB path hints if available.

Then triangulate:
`Crysis VR source topology -> C2-specific source/Coop -> SDK_1_1_X64 -> BETA5620 x86/x64 -> retail x86`.

Retail causal/static proof remains final authority.

## Renderer use
The exact x64 `CryRenderD3D11.dll` identity may also help future COLD mapping of:
- native stereo CVars/classes;
- `FOB_NEAREST` family;
- shadow-generation topology;
- temporal camera/history code;
- render-command marshalling.

Do not assume the x64 renderer command ABI or DX11 implementation is identical to retail x86. Use structural fingerprints and independent retail closure.

## Classification
- local C2 x64 module identity: **COLD PROVEN**
- relation to Crysis 2 ModSDK lineage: **ATLAS/PROJECT CLASSIFICATION PRESERVED**
- byte identity to any external/public c2-launcher user's binaries: **NOT ASSUMED**
- retail mapping equivalence: **UNPROVEN UNTIL TRIANGULATED**

No new download, game launch, hook, or mutation was performed for this identity closure.
