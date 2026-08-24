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

At audit time it contains repository metadata/readme and package hashes, but the exact package source is recovered by:
`tools/extract_verified_custom_dual_t1_v1_0_1.py`

The extractor declares the canonical external source carrier:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`

It verifies 20 package-manifest entries before promotion.

### Preservation status
**EXTERNAL-CARRIER DEPENDENT.**

T1 is the proven main renderer parent, therefore loss of this carrier would be disproportionately expensive even though the scientific state/offsets are preserved.

### Action
Locate the exact carrier in persistent storage, verify archive/package hashes, then promote the small exact source tree and build/recovery scripts into the repository where byte identity can be preserved safely. Keep the original carrier SHA/provenance even after source promotion.

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
Promote the exact small source/build/recovery text files into `runtime/finalists/v17.2.6_P6/` after preserving original file hashes and documenting any Git EOL normalization boundary. Do not mutate P6 behavior before first LIVE result.

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
- leaked/beta/dev game builds;
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
- useful source snippets as mappings, not bulk copied copyrighted code;
- architecture facts relevant to an active/future gate;
- hashes of external carriers where preservation matters.

## 6. Public lineage enrichment added in this audit
See:
`research/PUBLIC_LINEAGE_ENRICHMENT_20260824.md`

High-value public lineage now preserved there includes:
- CryENGINE CCamera coordinate/Matrix34 semantics;
- native dual-render asymmetric stereo model;
- rendering-camera/culling ownership;
- later render-thread asynchronous HMD camera composition;
- IWeapon firing locator / firing position / firing direction API lineage;
- first-person weapon ownership lineage;
- Crytek Crysis 2 stereo/shadow presentation sources.

These are candidate/lineage evidence. Retail causal proof still outranks them.

## 7. Highest-value next archival/research work
Priority order:
1. locate and verify the exact T1 HOSTFIX source carrier;
2. promote exact P6 small source/build/recovery files without changing P6 behavior;
3. mine Crytek SIGGRAPH/GDC/GPU Pro stereo material for precise weapon-depth, HUD, temporal and shadow policies;
4. mine closest public GameSDK source lineage for `CItem::UpdateFPPosition`, `CItem::UpdateFPCharacter`, `CWeapon::SetFiringLocator`, `GetProbableHit`, `GetFiringPos`, `GetFiringDir`;
5. cross-index the existing public CryENGINE donor/doc ZIPs instead of redownloading similar corpora;
6. complete an external-carrier manifest for high-value beta/PDB/capture artifacts.

## Gate discipline
None of this changes the active runtime gate.

Current serial order remains:
`P6 PosePair -> HEAD 1:1 -> WEAPON/NEAR -> TEMPORAL/SHADOW -> REGRESSION -> RELEASE`.

Cold/source enrichment may proceed in parallel, but it must not authorize a new intrusive LIVE ahead of P6.
