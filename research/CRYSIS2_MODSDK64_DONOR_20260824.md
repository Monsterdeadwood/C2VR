# C2VR — Crysis 2 ModSDK 64-bit donor runtime — 2026-08-24

Purpose: preserve a newly identified Crysis 2-specific donor/runtime lineage that may reduce future x86 retail reverse-engineering. This is COLD/DONOR evidence only and does not change the active P6 gate.

## Public project
Repository:
`https://github.com/mvoolt/c2-launcher`

Project description:
- open-source replacement launcher for Crysis 2 executables;
- explicitly targets the **64-bit build found in the Crysis 2 Mod SDK**;
- goal is to make that build run as a game client rather than editor-only;
- current README reports that it can load into a map and use weapons.

### Why this matters
This is substantially closer lineage than a Crysis 1 donor:
- game: Crysis 2;
- source: official Crysis 2 Mod SDK binary set;
- architecture: x64 rather than retail x86;
- can reach live map/weapon state.

It should be treated as a **cross-architecture Crysis 2 donor**, not as retail binary equivalence.

## Launcher architecture
The public launcher loads:
- `CryGameCrysis2.dll`
- `CryAction.dll`
- `CryNetwork.dll`
- `CrySystem.dll`

It resolves `CreateGameStartup2` from `CryGameCrysis2.dll`, creates `IGameStartup`, initializes the engine via `SSystemInitParams`, enters the normal game startup run loop, and shuts it down cleanly.

This proves the ModSDK x64 `CryGameCrysis2.dll` exposes a usable game-startup contract rather than being only inert editor data.

## Existing public patch coordinates
The launcher applies several hard-coded x64 `CryAction.dll` patches to avoid crashes during level changing:
- `+0xBC7C`
- `+0xBC8A`
- `+0xBDE0`
- `+0xAF21..+0xAF26`
- `+0xB400`
- `+0xBB4A`
- `+0xBFD5`

These offsets are NOT C2VR retail targets. They are useful only as independent donor coordinates and proof that this x64 module set has already been exercised at runtime.

## Potential C2VR uses
### 1. Easier static function recovery
x64 code frequently gives cleaner decompiler output and more explicit argument/register flow than x86 retail. Once function identities are known in the x64 ModSDK donor, derive:
- constants;
- call neighborhoods;
- string/xref sets;
- vtable slot relationships;
- control-flow fingerprints;
- class/RTTI relationships;
then map those features to beta x86 and retail x86 independently.

### 2. Crysis 2-specific GameDLL mapping
Priority functions when the WEAPON gate opens:
- `CPlayer::PostUpdateView`
- `CItem::UpdateFPPosition`
- `CItem::UpdateFPCharacter`
- `CWeapon::SetFiringLocator`
- `GetProbableHit`
- `GetFiringPos`
- `GetFiringDir`

The Crysis VR donor gives source topology for these families. The ModSDK x64 donor may provide a much closer Crysis 2 binary implementation to fingerprint before retail matching.

### 3. Renderer/camera lineage
If the x64 ModSDK package contains corresponding renderer modules, use them for COLD comparison of:
- `CCamera` manipulation;
- stereo CVars and native stereo classes;
- `FOB_NEAREST` handling;
- shadow-generation ownership;
- render-command marshalling;
- temporal camera/history code.

Do not assume DX9/DX11 module parity. Establish module/version identity first.

### 4. Runtime donor experiments
Because the launcher can reach a map and weapons, a donor-only runtime can answer semantic questions cheaply before touching retail, for example:
- which GameDLL function actually writes FP weapon WorldTM;
- whether firing-locator callbacks control projectile origin/direction;
- whether native stereo framework changes NEAR geometry projection;
- which shadow work is once-per-logical-frame vs view-specific.

Any such donor result remains a candidate generator until mapped/proven in retail.

## Evidence hierarchy
For C2VR conclusions:
1. retail causal proof;
2. retail static proof;
3. exact local beta/PDB/source bridge;
4. Crysis 2 ModSDK x64 donor;
5. Crysis 2 public mod/GameDLL source;
6. Crysis 1/CryENGINE donor source;
7. generic engine documentation/hypothesis.

The ordering between 3–5 may be adjusted per symbol if exact version identity is stronger in one corpus.

## Acquisition/preservation target
Preserve, where legally/publicly available:
- exact c2-launcher commit identity;
- exact `bin64` package hashes;
- hashes/version metadata of `CryGameCrysis2.dll`, `CryAction.dll`, `CrySystem.dll`, renderer DLLs and associated ModSDK files;
- any PDB/RTTI/export data that ships publicly with the ModSDK package;
- a module-to-retail lineage table.

Do not commit large binary packages into normal Git history. Store hashes/provenance and gate-relevant extracted mappings.

## Gate discipline
No current LIVE change.

Serial runtime order remains:
`P6 PosePair -> HEAD -> WEAPON/NEAR -> TEMPORAL/SHADOW -> REGRESSION -> RELEASE`.

This donor can be harvested COLD in parallel and should be ready before the WEAPON/NEAR mapping gate opens.
