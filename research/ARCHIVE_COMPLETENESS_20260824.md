# C2VR — archive completeness / source survivability audit — 2026-08-24

Purpose: distinguish what is actually preserved inside Git from what is only referenced by identity and still depends on an external carrier. The goal is long-term project survivability without old chat tabs.

## Rule
Do not confuse:
- knowledge preserved in Git;
- exact source preserved in Git;
- package identity preserved in Git;
- physical package still available outside Git.

Large proprietary/beta/PDB/capture corpora should normally remain outside ordinary Git history. Preserve exact identity, provenance, extracted symbols/mappings and gate-relevant conclusions instead.

## 1. CUSTOM_DUAL_T1 v1.0.1
Current repository directory:
`runtime/main/CUSTOM_DUAL_T1_v1.0.1/`

Exact package source is recovered by:
`tools/extract_verified_custom_dual_t1_v1_0_1.py`

The extractor declares the canonical source carrier:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`

### Recovery completed 2026-08-25
The exact HOSTFIX carrier was re-located in persistent Library and materialized.

Verified identity:
- bytes `83,442`
- SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- ZIP CRC PASS
- internal package manifest `20/20 PASS`

The exact scientific RESULT carrier was also re-located and materialized:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`
- bytes `68,872,488`
- SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAE1EDDB3596144D341CD53367`

These identities independently match the retained source/integrity history.

### Preservation status
**PHYSICAL SOURCE CARRIER RECOVERED + IDENTITY VERIFIED + PACKAGE MANIFEST 20/20 PASS + SCIENTIFIC RESULT CARRIER VERIFIED.**

T1 is no longer an unresolved/lost external dependency. The immutable ZIP remains the byte-exact authority because the original package contains mixed EOL identities and normal Git checkout rules may normalize text files.

See `research/T1_CARRIER_RECOVERY_20260825.md`.

## 2. P6 v17.2.6 EXACT_BLOCK120
Canonical package identity:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

Expected:
- bytes `85,852`
- SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`
- internal manifest `42/42 PASS`

A persistent Library carrier was re-located during this audit with the same 85,852-byte size, materialized, and verified against the canonical SHA256. The package contains the exact runtime source, analysis scripts, runner and recovery scripts described by `runtime/finalists/v17.2.6_P6/PACKAGE_FILES_SHA256.txt`.

### Preservation status
**PHYSICAL CARRIER AVAILABLE + IDENTITY VERIFIED; SOURCE NOT YET FULLY PROMOTED INTO THE FINALIST DIRECTORY.**

### Action
Promote exact small source/build/recovery files only if useful, preserving original per-file hashes and documenting Git EOL normalization. Do not mutate P6 behavior before first LIVE result.

## 3. v17.2.1 donor
Current repository authority:
`runtime/donors/v17.2.1/`

The repo already contains donor hashes, transplant notes and a small source subset including:
- `t1_camera.cpp`
- `t1_game_api.h`
- `t1_ipc.h`
- `t1_proxy.cpp`

### Preservation status
**PARTIAL SOURCE PRESERVED + ORIGINAL PACKAGE IDENTITY PRESERVED.**

This is acceptable for donor use only if every future transplant can still be traced to the original package identity. Do not silently treat the subset as the complete donor package.

## 4. Large research corpora
`research/CORPUS_MANIFEST.md` intentionally keeps giant handoff/evidence corpora outside ordinary Git history and stores exact SHA256/size/read-order identities.

This remains the correct policy for:
- huge PDBs;
- beta/dev game builds;
- RenderDoc captures;
- TTD traces;
- large raw Ghidra exports;
- large raw result archives;
- broad web/source snapshots.

### Required preservation metadata for each important external carrier
Record where known:
1. exact filename;
2. byte size;
3. SHA256;
4. origin/provenance category;
5. game/build/version identity;
6. which retail facts were derived from it;
7. whether those facts were independently proven on retail;
8. local/persistent-storage availability status;
9. superseded/falsified restrictions.

## 5. Existing persistent public/donor corpus candidates
Persistent storage also contains broad Crysis/CryENGINE research packages such as:
- `01_OPENXR_AND_HOOKS.zip`
- `02_CRYENGINE_VR_AND_STEREO_DONORS.zip`
- `04_CRYSIS2_PUBLIC_MOD_MATERIAL.zip`
- `05_DOCS_AND_WEB_SNAPSHOTS.zip`

Do not import these wholesale. Mine them SOURCE-FIRST and promote only:
- original source URL/version/date;
- exact symbol/function names;
- useful source mappings rather than bulk copied code;
- architecture facts relevant to an active/future gate;
- hashes of external carriers where preservation matters.

## 6. Public lineage enrichment added in this audit
See:
`research/PUBLIC_LINEAGE_ENRICHMENT_20260824.md`

High-value public lineage preserved there includes:
- CryENGINE CCamera coordinate/Matrix34 semantics;
- native dual-render asymmetric stereo model;
- rendering-camera/culling ownership;
- later render-thread asynchronous HMD camera composition;
- IWeapon firing locator / firing position / firing direction API lineage;
- first-person weapon ownership lineage;
- Crytek Crysis 2 stereo/shadow presentation sources.

These are candidate/lineage evidence. Retail causal proof still outranks them.

## 7. Highest-value next archival/research work
Priority order after T1 recovery:
1. close exact beta/PDB root identities with `tools/C2VR_EXTERNAL_CORPUS_IDENTITY.ps1` and `research/BETA_PDB_IDENTITY_CONFLICT_20260825.md`;
2. preserve/optionally promote P6 exact source/build/recovery files without changing P6 behavior;
3. recover exact ModSDK x64 module identities for future C2-specific weapon mapping;
4. targeted re-harvest of already-owned Crysis2Coop for GameDLL/weapon seams, no redownload;
5. mine Crytek SIGGRAPH/GDC/GPU Pro stereo material for precise weapon-depth, HUD, temporal and shadow policies;
6. continue compact identity indexing for scientifically important RDC/TTD/RESULT carriers rather than importing raw bulk evidence.

## Gate discipline
None of this changes the active runtime gate.

Current serial order remains:
`P6 PosePair -> HEAD 1:1 -> WEAPON/NEAR -> TEMPORAL/SHADOW -> REGRESSION -> RELEASE`.

Cold/source enrichment may proceed in parallel, but it must not authorize a new intrusive LIVE ahead of P6.
