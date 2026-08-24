# C2VR — Crysis 2 build 5620 public cross-check — 2026-08-24

Purpose: preserve independent public runtime evidence for the same `5620` Crysis 2 lineage as the project's local Jan-13-2011 beta/source bridge. This is THIRD-PARTY COLD evidence only; local beta/PDB and retail mapping remain authoritative.

## Project-side beta identity
C2VR already uses the local beta lineage:
`crysis2(5620)\_r\crysis2(5620)\_01_13`

The project's beta/PDB corpus is the preferred source for exact symbol/RVA work.

## Public independent 5620 runtime map
Public GitHub repository:
`Esyottil/Crysis2Hack5620`

The source explicitly identifies its target as:
`Crysis 2 5620 DX9`

At the inspected repository revision, it records:
- `CSystem::Update` candidate offset `+0x0004B290` from the System module;
- global `SSystemGlobalEnvironment*` pointer location `GameModule +0x006BC520`;
- `CGame*` pointer location `GameModule +0x006C4D08`.

Its local `SSystemGlobalEnvironment` layout uses:
- `IRenderer*` at `+0x0C`;
- `I3DEngine*` at `+0x20`;
- `IPhysicalWorld*` at `+0x2C`;
- `IEntitySystem*` at `+0x38`.

It also models common CryEngine interfaces and uses `IRenderer::ProjectToScreen`, entity/skeleton access, actor/game-framework access and view rotation successfully enough for a public runtime tool.

## Evidence quality
Classification:
**THIRD-PARTY RUNTIME MAP / SAME BUILD NUMBER / NOT SYMBOL AUTHORITY.**

Reasons not to promote blindly:
- repository is a modern reverse-engineered tool, not Crytek source;
- it targets DX9 and may use a different executable/module split from the project's exact local beta workflow;
- offsets may be hard-coded for one binary variant carrying the same 5620 label;
- class/vtable layouts are partial and purpose-built.

## C2VR value
This is still useful because it gives independent coordinates to cross-check against the project's exact beta binaries/PDB:
1. test whether local build 5620 resolves `gEnv` near `+0x6BC520`;
2. test whether `CGame` resolves near `+0x6C4D08`;
3. identify the function at/near System `+0x4B290` and compare PDB symbol to `CSystem::Update`;
4. compare `SSystemGlobalEnvironment` field offsets against beta SDK/PDB/type information;
5. if all four agree, use the public map as an additional anchor for independent version identity, not as a retail offset source.

A mismatch is also informative: it may distinguish the public DX9 5620 executable from the project's exact Jan-13 beta variant or reveal differing module bases/patch lineage.

## Why this matters for future GameDLL mapping
The highest-value parked symbols remain:
- `CPlayer::PostUpdateView`;
- `CItem::UpdateFPPosition`;
- `CItem::UpdateFPCharacter`;
- `CWeapon::SetFiringLocator`;
- `GetProbableHit`;
- `GetFiringPos`;
- `GetFiringDir`.

The new Crysis VR donor harvest gives source-level topology for those families. A verified 5620 module/base map gives another independent coordinate system for triangulating those functions inside the local beta before matching fingerprints to retail.

## Pinned public references
- repository: `https://github.com/Esyottil/Crysis2Hack5620`
- inspected `dllmain.cpp`: source comment `Crysis 2 5620 DX9`, SystemUpdate offset `0x4B290`
- inspected `CryClass.h`: `gEnv +0x6BC520`, `CGame +0x6C4D08`, environment field offsets above

## Gate discipline
No LIVE authorization and no active-gate change.

Use this only as COLD cross-check when beta version mapping resumes. Current runtime order remains:
`P6 PosePair -> HEAD -> WEAPON/NEAR -> TEMPORAL/SHADOW -> REGRESSION -> RELEASE`.
