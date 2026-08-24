# C2VR — SOURCE / MOD / BETA / DONOR CORPUS REGISTRY

Updated: 2026-08-25

Purpose: one canonical registry for every important external or internal source family used by C2VR. This file answers four separate questions for every corpus item:

1. what exactly is it;
2. where/under what identity it was observed;
3. what C2VR knowledge came from it;
4. whether the physical bytes, exact identity, and derived knowledge are preserved in Git.

Do not confuse `KNOWLEDGE IN GIT` with `FULL BYTES IN GIT`. Large proprietary/beta/PDB/capture/result corpora normally remain external; Git stores identity/provenance and extracted engineering truth.

## Status vocabulary

- `RETAIL AUTHORITY` — current retail binary/runtime truth.
- `EXACT LOCAL CORPUS` — exact local source/binary corpus previously indexed/used.
- `DIRECT LIBRARY` — physical carrier is surfaced in persistent ChatGPT Library.
- `INDEXED` — existence/path/identity is proven by retained evidence, but bytes are not necessarily mounted now.
- `PARTIAL` — only part of the source/package is directly preserved in repo/library.
- `PUBLIC PINNED` — public repository with a recorded commit used as a donor/reference.
- `KNOWLEDGE IN GIT` — gate-relevant findings are preserved in C2VR GitHub.
- `EXTERNAL CARRIER` — physical source remains outside ordinary Git history.
- `NOT PROVEN PRESENT` — never silently upgrade this to available.

## Evidence precedence

1. retail Crysis 2 1.9 causal/runtime proof;
2. retail Crysis 2 1.9 static proof;
3. exact Crysis-2-specific source / SDK / beta/PDB lineage;
4. CryEngine 3.3.8 lineage where version mapping supports it;
5. Crysis 2 ModSDK/public C2 donor runtime/source;
6. older CryEngine/Crysis donor mods;
7. generic engine/OpenXR reference.

`FALSIFIED`, `STOPPED`, `SUPERSEDED`, and `DO NOT REPEAT` always outrank older donor similarity.

---

# A. RETAIL C2 AUTHORITY

## A1. GOG Crysis 2 retail 1.9 — x86 game
- Class: `RETAIL AUTHORITY`
- Path: `C:\GOG Games\Crysis 2\Bin32\Crysis2.exe`
- Recorded size: `29,289,472 B` in artifact inventory.
- Canonical SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- Knowledge in Git: YES.
- Full binary in Git: NO.
- Role: absolute game/runtime truth for camera ownership, RenderWorld, GameDLL integration and final regression.

## A2. Retail DX11 renderer
- Class: `RETAIL AUTHORITY`
- Path: `C:\GOG Games\Crysis 2\Bin32\CryRenderD3D11.dll`
- Recorded size: `4,888,360 B`.
- Canonical SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
- Knowledge in Git: YES, including concrete renderer offsets and proven RC/RT transaction topology.
- Full binary in Git: NO.

## A3. Retail DX9 reference renderer
- Class: `INDEXED / REFERENCE`
- File: `CryRenderD3D9.dll`
- Recorded size: `4,316,968 B`.
- Role: comparison/reference only; current final path is retail DX11.

## A4. Retail x64 binaries from Crysis 2 installation / SDK lineage
- Class: `INDEXED / CROSS-ARCHITECTURE REFERENCE`
- Evidence corpus contains `Bin64\CryRenderD3D11.dll` and `Bin64\CryRenderD3D9.dll` string/source-lineage mappings.
- Role: easier cross-architecture/static comparison where exact module identity is established first.
- Not retail x86 proof by itself.

---

# B. C2 BETA / PROTOTYPE / DEBUG CORPUS

## B1. Jan 13 2011 PC prototype / build 5620
- Class: `EXACT LOCAL CORPUS / INDEXED-PARTIAL`
- Local path used by project: `C:\GOG Games\Crysis 2\crysis2(5620)_r\crysis2(5620)_01_13`
- Build label: `crysis2(5620)_r`, build `5620`.
- Public metadata lineage: Hidden Palace Jan 13 2011 PC prototype page/category.
- Project-side use: exact beta binary/source/PDB bridge, source-path archaeology, ABI/version triangulation.
- Knowledge in Git: YES.
- Full prototype in Git: NO.
- Policy: do not redownload when local exact corpus already exists; do not publish proprietary build bytes into ordinary Git history.

### B1 modules explicitly swept in prior autopsy
- `Bin32\Crysis2.exe`
- `Bin32\CryRenderD3D11.dll`
- `Bin32\CrySystem.dll`
- `Bin32\CryAction.dll`
- `Bin32\Cry3DEngine.dll`
- `Bin32\CryGameCrysis2.dll`

## B2. Beta/debug PDB family
- Class: `EXACT LOCAL CORPUS / INDEXED`
- Known module families: `CryGameCrysis2`, `CryAction`, `CrySystem`, `CryRenderD3D11`, `Cry3DEngine`, `CryEntitySystem`.
- Recorded range: roughly `7.7–82.0 MB` each in inventory.
- Observed `CryGameCrysis2.pdb`: `82,045,952 B`.
- Role: symbol identity, class/function names, source paths, beta RVA/size/call topology.
- Knowledge in Git: YES, selected mappings/provenance.
- Full PDBs in Git: NO.

## B3. Retail PDB status
- Class: `NOT PROVEN PRESENT`
- Retail `CryRenderD3D11.dll` contains a CodeView path, but the actual matching retail PDB file has NOT been proven present.
- Never describe a CodeView path as retail-PDB availability.

## B4. Independent public 5620 runtime map
- Class: `THIRD-PARTY CROSS-CHECK / KNOWLEDGE IN GIT`
- Public repo: `Esyottil/Crysis2Hack5620`.
- Explicit target comment: `Crysis 2 5620 DX9`.
- Recorded public candidates: `CSystem::Update +0x4B290`, `gEnv +0x6BC520`, `CGame +0x6C4D08`, plus partial `SSystemGlobalEnvironment` layout.
- Git note: `research/BETA_5620_PUBLIC_CROSSCHECK_20260824.md`.
- Use only to cross-check exact local 5620; never as retail offset authority.

---

# C. C2-SPECIFIC SOURCE / SDK CORPUS

## C1. Crysis 2 SDK / platform source family
- Class: `EXACT LOCAL CORPUS / PARTIAL`
- Recorded local path family: `C:\GOG Games\Crysis 2\Beta 2\crysis2_src_pc_ps3_x360\...`
- Includes C2/CryCommon source/header semantics used by source-first mapping.
- Role: Crysis-2-specific game and engine semantics before generic later CryEngine donors.
- Knowledge in Git: YES, gate-relevant mappings/conclusions.
- Full tree in Git: NO.

## C2. Crysis-2-specific CryEngine source tree
- Class: `EXACT LOCAL CORPUS / PARTIAL`
- Recorded family: `...\cryengine\Code`.
- Role: closest known C2-specific renderer/system source lineage where available.
- Trust: below retail truth, above generic CE3.3.8 donor.
- Knowledge in Git: YES.

## C3. CryEngine 3.3.8 source lineage
- Class: `EXACT LOCAL CORPUS / PARTIAL`
- Recorded roots: `...\cryengine\CE_3_3_8\Code` and `...\cryengine\CryEngine_3.3.8\Code`.
- Version study concluded these two are effectively duplicate renderer-family copies for current research.
- Recorded normalized similarity anchors vs C2 source:
  - `EF_ProcessRenderLists ~95.5%`
  - `EF_RenderScene ~89.9%`
  - `EF_Scene3D ~88.3%`
  - `RT_SetCameraInfo ~76.4%`
  - `EF_EndEf3D ~68.8%`
  - `RT_RenderScene ~31.5%`
- Consequence: thin submit/render-list wrappers are excellent mapping anchors; `RT_RenderScene` requires retail proof.
- Knowledge in Git: YES.

## C4. Crysis 2 Mod SDK 1.1 package
- Class: `INDEXED / PUBLIC SDK PACKAGE`
- Historical installer name used by collector: `Crysis_2_ModSDK_1.1_1107.exe`.
- Collector source: Archive.org Crysis 2 files mirror plus ModDB/PCGamingWiki reference pages.
- Previous collector was designed to compute SHA256 after successful local download; no canonical package SHA is promoted here unless exact retained output is recovered.
- Role: official C2 SDK/runtime source of bin64 donor modules and CryCommon/Game startup interfaces.
- Full installer in Git: NO.

## C5. Crysis 2 ModSDK 64-bit donor runtime / c2-launcher
- Class: `PUBLIC PINNED / C2-SPECIFIC DONOR`
- Repo: `https://github.com/mvoolt/c2-launcher.git`
- Recorded pinned commit: `74cb408e5ee63038ae69d16e7dfb03c432f0d606`.
- Purpose: run the 64-bit build found in Crysis 2 Mod SDK as a game client.
- Loads: `CryGameCrysis2.dll`, `CryAction.dll`, `CryNetwork.dll`, `CrySystem.dll` and resolves `CreateGameStartup2`.
- Git note: `research/CRYSIS2_MODSDK64_DONOR_20260824.md`.
- Role: cross-architecture function fingerprinting and donor-runtime semantics, especially future weapon mapping.
- Not retail x86 proof.

---

# D. C2 MOD / GAME-SPECIFIC DONORS

## D1. Crysis2Coop source release
- Class: `ALREADY POSSESSED / PREVIOUSLY PROCESSED C2 MODSDK-LINEAGE DONOR`
- Public identity: `Crysis2Coop_SOURCE_20120418.rar` / `Crysis2Coop.rar`.
- Published: `2012-04-18`.
- Recorded size: `11,133,614 B`.
- MD5: `dc640394f1534084baf4ac7c7e04c34c`.
- Important correction: this is NOT a new acquisition target. The project already had Crysis2Coop source/config material in its source corpus.
- Next use: targeted re-harvest only for current missing GameDLL facts, especially `PostUpdateView`, `UpdateFPPosition`, `UpdateFPCharacter`, firing-locator and muzzle/helper lineage.
- Knowledge in Git: YES.
- Full RAR in Git: NO.

## D2. Crysis2Coop later package
- Class: `INDEXED PUBLIC MOD PACKAGE`
- Collector filename: `Crysis2Coop_LATEST_20130706.rar`.
- Recorded MD5: `b5c0b2b83a450f5afc57fa54243845e6`.
- Role: later scripts/config/mod reference; keep separate from 2012 source release.
- Do not treat as source-equivalent without inspecting exact contents.

## D3. Crysis 2 DX11 Ultra Upgrade technical paper
- Class: `PUBLIC DOCUMENT / INDEXED`
- Collector filename: `c2_dx11_ultra_upgrade.pdf`.
- Recorded MD5: `56e73d6fae883ffd24f1c8b92b875faa`.
- Role: renderer/stereo/shadow technical context, not source proof.

## D4. Crysis 2 XML/config/stereo mod material
- Class: `INDEXED / DONOR REFERENCE`
- Existing canonical knowledge base explicitly records `Crysis2Coop and stereo-related XML/config/mod material` as donor/reference data.
- Preserve exact file identities on targeted reuse; do not rerun broad scans without a gate-specific missing fact.

---

# E. DIRECT CRYENGINE VR / STEREO DONORS

## E1. fholger Crysis VR
- Class: `PUBLIC PINNED / HIGH-VALUE VR DONOR`
- Repo: `https://github.com/fholger/crysis_vrmod.git`
- Recorded pinned commit: `2e8045947cf3bcee78b5740eb9ce04efcee05c70`.
- Persistent archive: `02_CRYENGINE_VR_AND_STEREO_DONORS.zip`.
- Archive SHA256 recorded by 2026-08-24 harvest: `8134EAA87951232FD50AD68960E970DD58634E959DC6841E26CD6D3677E7F823`.
- High-value donor findings already in Git:
  - immutable original/center camera -> per-eye cameras;
  - eye render ordering / OpenXR timing donor;
  - `CItem::UpdateFPPosition -> CItem::UpdateFPCharacter` topology;
  - controller/weapon rigid-bind architecture;
  - `SetFiringLocator` / firing-pos / firing-dir family;
  - first-eye-only shadow-generation precedent while rendering full second eye.
- Git note: `research/CRYSIS_VR_DONOR_MAPPING_20260824.md`.
- Donor only; its second high-level render call is not admissible as final C2VR architecture.

## E2. c1-launcher
- Class: `PUBLIC PINNED / CRYENGINE STARTUP DONOR`
- Repo: `https://github.com/ccomrade/c1-launcher.git`
- Recorded pinned commit: `32d447e126654698c5cab59c08ea91e767b4f70d`.
- Role: startup/engine loader lineage.

## E3. c1-mod-sdk
- Class: `PUBLIC DONOR`
- Repo: `https://github.com/ccomrade/c1-mod-sdk.git`.
- No canonical pin promoted in retained fetcher snapshot.
- Role: older CryEngine/GameDLL reference.

## E4. 3Dmigoto DX11
- Class: `PUBLIC PINNED / STEREO-SHADER ARCHAEOLOGY DONOR`
- Repo: `https://github.com/bo3b/3Dmigoto.git`
- Recorded pinned commit: `4ce5f2f72b2777223d2e809dcdafec514ac98295`.
- Role: shader/stereo interception reference for later temporal/shadow/weapon archaeology, not C2 runtime proof.

## E5. DarkStarSword 3d-fixes
- Class: `PUBLIC PINNED / STEREO FIX DONOR`
- Repo: `https://github.com/DarkStarSword/3d-fixes.git`
- Recorded pinned commit: `dd9a3555e33d746113dbcb77d19afa4abeb9b388`.
- Historical collector also tracked a `crysis3` branch / Crysis 3 subtree.
- Role: CryEngine/Crysis stereo-fix archaeology.

## E6. Perception
- Class: `PUBLIC DONOR`
- Repo: `https://github.com/cybereality/Perception.git`.
- Role: historical VR injection/stereo architecture reference.

## E7. Revive
- Class: `PUBLIC DONOR`
- Repo: `https://github.com/LibreVR/Revive.git`.
- Role: VR/runtime compatibility reference only.

## E8. CRYTEK GameSDK
- Class: `PUBLIC DONOR / LATER GAMEPLAY API LINEAGE`
- Repo: `https://github.com/CRYTEK/GameSDK.git`.
- Role: later weapon/view/aim API and implementation topology; use only for candidate generation unless C2-specific mapping closes.

---

# F. ENGINE DESCENDANT / PUBLIC LINEAGE

## F1. Lumberyard CryEngine lineage
- Class: `PUBLIC SPARSE DONOR`
- Upstream: `https://github.com/aws/lumberyard.git`.
- Sparse corpus intentionally limits to:
  - `dev/Code/CryEngine/CryCommon`
  - `dev/Code/CryEngine/RenderDll`
  - `dev/Code/CryEngine/Cry3DEngine`
  - `dev/Code/CryEngine/CrySystem`
- Role: later descendant renderer/thread/scene-command lineage.
- Never retail proof.

## F2. Public CRYENGINE fork
- Class: `OPTIONAL HEAVY PUBLIC LINEAGE`
- Upstream used by fetcher: `https://github.com/ValtoGameEngines/CryEngine.git`.
- Fetched only with heavy-lineage option.
- Role: generic CryEngine source triangulation after closer C2/CE3.3.8 sources are exhausted.

## F3. Official CryENGINE documentation / Crytek presentations
- Class: `PUBLIC DOCUMENTATION / KNOWLEDGE IN GIT`
- Git note: `research/PUBLIC_LINEAGE_ENRICHMENT_20260824.md`.
- Preserved subjects include CCamera Matrix34 semantics, engine axes, native dual-render stereo, renderer/culling camera ownership, later async HMD camera injection, weapon firing API, first-person weapon lineage, Crytek Crysis 2 stereo/shadow presentation references.
- Documentation is lineage/candidate evidence unless retail independently closes it.

---

# G. OPENXR / HOOK / TRANSPORT REFERENCE CORPUS

## G1. OpenXR-SDK-Source
- Class: `PUBLIC PINNED / SPEC-RUNTIME REFERENCE`
- Repo: `https://github.com/KhronosGroup/OpenXR-SDK-Source.git`
- Recorded pin: `c610211f38f4e1e4ac811ced6135e144eedc7cf2`.
- Priority areas: loader, common, `hello_xr`, `xrWaitFrame`, `xrLocateViews`, `xrBeginFrame`, `xrEndFrame`.

## G2. OpenXR-SDK / OpenXR-Docs
- Class: `PUBLIC REFERENCE`
- Repos: Khronos `OpenXR-SDK`, `OpenXR-Docs`.
- Role: headers/spec semantics.

## G3. MinHook
- Class: `PUBLIC PINNED`
- Pin: `d94c64d32ea37bc4f5ee47d580709f70c6fb6080`.

## G4. kiero2
- Class: `PUBLIC PINNED`
- Pin: `8f57dd9da568b8f22a59d96eec60cd3837175459`.

## G5. ReShade-Core
- Class: `PUBLIC PINNED`
- Pin: `aae2b7ecc18096ccddca2c073b50727541220292`.

## G6. DxWrapper
- Class: `PUBLIC PINNED`
- Pin: `488cc03ea44695d5930c8aea1023a197395f2859`.

These are infrastructure donors only. They do not establish C2 camera/render ownership.

---

# H. ASSET / FORMAT / ARCHAEOLOGY UTILITIES

## H1. CryEngine-Converter
- Repo: `https://github.com/Markemp/Cryengine-Converter.git`
- Recorded pin: `7b951dbb254ab99f560e8ffbf64a771c70ccef74`.
- Role: CryEngine asset/format analysis.

## H2. CryEngine 010 Templates
- Repo: `https://github.com/Markemp/010-Templates.git`
- Recorded pin: `fcb4253a7677ebce3f51a6b4315c24604193857f`.
- Role: binary format templates.

## H3. CryBlend
- Repo: `https://github.com/Tzeentchnet/CryBlend.git`.
- Role: asset pipeline reference.

## H4. CryLevelConvert
- Repo: `https://github.com/prophetl33t/CryLevelConvert.git`.
- Role: level/format conversion reference.

---

# I. LIVE / STATIC EVIDENCE CORPUS

## I1. RenderDoc
- Class: `RETAIL PASSIVE LIVE EVIDENCE / PARTIAL-DIRECT`
- Canonical capture lineage: `RDC_20260819_195145` / `c2vr_frame_frame8588.rdc`.
- Library also surfaced additional RDCs including `праа.rdc`, `4554.rdc`, `555666.rdc`.
- Recorded surfaced sizes include `269,167,025`, `306,256,951`, `288,668,138 B`.
- Role: GPU draw/resource/constant/projection provenance.
- Raw large captures stay outside normal Git; findings/identities go in Git.

## I2. TTD
- Class: `RETAIL CAUSAL/PROVENANCE EVIDENCE / PARTIAL`
- Canonical lineage: `TTD_20260819_195118` plus `CRYSIS2VR_TTD_CAMERA_STEREO` / temporal-matrix-writer results.
- Historical full trace noted around `152.8 MB`.
- Role: writer/reader/call-stack/object provenance for concrete questions.
- Do not repeat broad TTD after target closure.

## I3. Ghidra/static binary atlas
- Class: `RETAIL/BETA STATIC EVIDENCE`
- Used across retail and beta renderer/game modules with source-to-binary/version fingerprints.
- Knowledge in Git: concrete offsets, callsites, mappings and STOP rules.

## I4. Blackbox / Engine Tap / projection-CB census / late 320-byte carrier
- Class: `PASSIVE LIVE / STATIC HYBRID EVIDENCE`
- Canonical knowledge base records these families as already used.
- Important preserved conclusion: late carrier separates WORLD and NEAR semantic families but is a passive raster witness, not a gameplay owner detector.

## I5. RESULT archive families
- Class: `DIRECT LIBRARY + INDEXED HISTORY`
- Examples surfaced in inventory:
  - `C2VR_GAMEPLAY_VIEW_ORACLE_RESULT_20260821_034531.zip` — `49,308,191 B`
  - `...040927.zip` — `14,928,673 B`
  - `CRYSIS2VR_CADENCE_FASTPATH_RESULT_20260818_133603.zip` — `24,183,954 B`
  - `C2VR_TOTAL_COLD_ATLAS_RESULT_20260821_174756.zip` — `4,375,168 B`
- Many prior result archives exist; do not blindly import all bytes. Promote exact result identity and scientific verdict.

---

# J. PROJECT BUILD / RUNTIME SOURCE CARRIERS

## J1. CUSTOM_DUAL_T1 v1.0.1
- Class: `MAIN PROVEN PARENT / EXTERNAL CARRIER DEPENDENT`
- Repo path: `runtime/main/CUSTOM_DUAL_T1_v1.0.1/`.
- Exact carrier required by extractor: `CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`.
- Status: scientific knowledge in Git; full exact source carrier still an archival survivability gap until exact carrier/source promotion is completed.
- See `research/ARCHIVE_COMPLETENESS_20260824.md`.

## J2. v17.2.1 donor
- Class: `PARTIAL SOURCE PRESERVED + PACKAGE IDENTITY PRESERVED`
- Repo path: `runtime/donors/v17.2.1/`.
- Small source subset in Git; do not silently treat subset as full donor package.

## J3. P6 v17.2.6 EXACT_BLOCK120
- Class: `CURRENT PREPARED FINALIST / PHYSICAL CARRIER VERIFIED`
- Package: `CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- Bytes: `85,852`.
- SHA256: `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`.
- Persistent Library carrier re-located and SHA-verified.
- Git has package manifest and gate state; source promotion can occur without changing runtime behavior.
- Still `PREPARED / UNRUN` until actual P6 LIVE result exists.

---

# K. LARGE CANONICAL HANDOFF / KNOWLEDGE CORPUS

## K1. START_HERE
- `CRYSIS2VR_CLAUDE_START_HERE_20260823.md`
- `24,058 B`
- SHA256 `1E60216AFB430DB413ABF1A38A0BE12CE12DA34E1DF9712FE607ABFCC65C2903`

## K2. MAIN_CORPUS
- `CRYSIS2VR_CLAUDE_MAIN_CORPUS_20260823.md`
- `100,249,910 B` / `95.606 MiB`
- SHA256 `BDF73215DAEE53C396460F601806D36803713E08CC42EE5F73ECF07E6264A683`

## K3. LEGACY_EVIDENCE
- `CRYSIS2VR_CLAUDE_LEGACY_EVIDENCE_20260823.md`
- `17,942,281 B` / `17.111 MiB`
- SHA256 `E8ED6882C6938224435D2D0AFFD90E4314BF9AA452EF2EE25FE49FB26A341384`

Policy: do not dump huge handoff corpora into ordinary Git as giant blobs. Compact canonical `docs/` state outranks stale chronology.

---

# L. PERSISTENT RESEARCH PACKAGE GROUPS

Previously surfaced persistent packages:
- `01_OPENXR_AND_HOOKS.zip`
- `02_CRYENGINE_VR_AND_STEREO_DONORS.zip`
- `04_CRYSIS2_PUBLIC_MOD_MATERIAL.zip`
- `05_DOCS_AND_WEB_SNAPSHOTS.zip`

Policy:
- do not redownload similar corpora unless identity/version changed and the change matters;
- mine existing corpus SOURCE-FIRST;
- promote exact repo commit/file hash, symbol/function name, mapping and gate-relevant conclusion;
- keep broad copyrighted/proprietary source and giant binaries outside ordinary Git.

---

# M. CROSS-PROJECT ARCHITECTURE DONORS

These are not Crysis 2 source and should never outrank C2-specific evidence, but they contributed architecture:

## M1. FEAR2VR
- Historical lesson: x86 game + separate x64 XR helper is a proven workable ownership pattern.
- Use: transport architecture only.

## M2. BF3VR
- Historical lesson: x86 present/capture side plus x64 Meta/OpenXR owner and shared frame/pose transport.
- Use: x86/x64 split architecture only, not CryEngine owner semantics.

---

# N. CANONICAL KNOWLEDGE ALREADY PROMOTED TO GIT

Key research notes now tied to this registry:
- `research/CORPUS_MANIFEST.md`
- `research/ARCHIVE_COMPLETENESS_20260824.md`
- `research/PUBLIC_LINEAGE_ENRICHMENT_20260824.md`
- `research/CRYSIS_VR_DONOR_MAPPING_20260824.md`
- `research/BETA_5620_PUBLIC_CROSSCHECK_20260824.md`
- `research/CRYSIS2_MODSDK64_DONOR_20260824.md`
- `research/COORDINATE_BASIS_CONFLICT_20260824.md`
- `research/WEAPON_NEAR.md`
- `research/RESULT_INDEX.md`
- canonical `docs/STATE.md`, `docs/SYNC.md`, `docs/PROVEN.md`, `docs/FALSIFIED.md`, `docs/GATES.md`, `docs/NEXT.md`.

---

# O. CURRENT GAPS / NEXT ARCHIVAL ACTIONS

1. **T1 exact carrier survivability** — locate/verify exact `CUSTOM_DUAL_T1 v1.0.1 HOSTFIX` carrier and promote safe small source/build/recovery files.
2. **P6 source survivability** — physical carrier is verified; promote exact small text source/runner/recovery while preserving original file hashes/EOL identity. Do not change behavior before first LIVE.
3. **C2 beta/PDB carrier identities** — recover exact hashes/sizes for the specific beta modules/PDBs that matter most and add them here as immutable identities.
4. **Crysis2Coop targeted re-harvest** — no redownload; extract only weapon/GameDLL/current-gate-relevant facts from already-held corpus.
5. **ModSDK x64 module identity** — hash exact `CryGameCrysis2.dll`, `CryAction.dll`, `CrySystem.dll`, renderer modules and associate them with c2-launcher/SDK build identity.
6. **Large capture/result registry** — continue indexing only scientifically important RDC/TTD/RESULT carriers, not every intermediate scratch archive.
7. **Public donor commit refresh** — update only when a newer upstream revision materially affects an open gate; preserve old pinned commit used for prior conclusions.

---

# P. ACTIVE GATE DISCIPLINE

This registry is archival/COLD state only. It does not authorize a new LIVE.

Current runtime serial order remains:

`P6 PosePair -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW -> REGRESSION -> RELEASE`

Before any expensive LIVE, perform normal cross-branch STATE SYNC and the exact 5-line PREFLIGHT. Do not repeat broad source/corpus scans when this registry or canonical handoff already contains the answer.
