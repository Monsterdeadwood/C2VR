# C2VR — SOURCE CORPUS CURRENT STATUS OVERLAY — 2026-08-25

Purpose: compact authoritative status overlay for `research/SOURCE_CORPUS_REGISTRY.md`. Read this file **before** interpreting preservation gaps or acquisition TODOs in the larger registry.

The detailed registry remains the inventory. This overlay records newer closures so future branches do not repeat already-completed archival work.

## Precedence
For source/corpus availability questions:
1. this current-status overlay;
2. newer focused research notes named below;
3. `SOURCE_CORPUS_REGISTRY.md` detailed inventory;
4. older handoff chronology.

This overlay does not alter retail evidence precedence or runtime gate ordering.

---

## CLOSED: T1 source carrier
Previous registry state: external carrier dependency / exact carrier location unresolved.

Current state:
**RECOVERED + SHA VERIFIED + ZIP CRC PASS + INTERNAL MANIFEST 20/20 PASS.**

Carrier:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`
- bytes `83,442`
- SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`

Scientific RESULT carrier also recovered:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`
- bytes `68,872,488`
- SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAE1EDDB3596144D341CD53367`

See `research/T1_CARRIER_RECOVERY_20260825.md`.

## CLOSED: T1 -> P6 source genealogy
Exact package comparison proves:
- T1 camera core -> P6 `t1_camera.cpp` line similarity ~0.995;
- game API bridge strongly preserved ~0.931;
- export surface byte-identical;
- substantial later evolution is concentrated in dual-render/host/IPC/proxy transaction layers.

Implication: do not restart broad HEAD owner archaeology after G1; converge the inherited upstream camera core first.

See `research/T1_TO_P6_SOURCE_LINEAGE_20260825.md`.

## CLOSED: P5 exact carrier and P5 -> P6 causal delta
Exact P5 carrier recovered:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
- bytes `82,867`
- SHA256 `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`
- ZIP CRC PASS
- package manifest `39/39 PASS`

Exact P6 carrier remains:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- bytes `85,852`
- SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`
- package manifest `42/42 PASS`

Exact delta:
- 32/40 common files byte-identical;
- 0 P5 files removed;
- all game/in-process runtime source byte-identical;
- only changed first-party runtime file is x64 host;
- one causal policy mutation: wait watchdog `45 -> 120 ms`;
- P6 also adds passive host timeout/latency histogram telemetry.

Correct wording: **one causal timing-policy mutation plus passive host telemetry**, not literally one changed source line.

See `research/P5_TO_P6_EXACT_DELTA_20260825.md`.

## CLOSED: beta 5620 PDB identity conflict
Previous apparent conflict between PDB sizes is resolved.

Same exact `crysis2(5620)_r\crysis2(5620)_01_13` tree contains separate:
- `BETA5620_BIN32`
- `BETA5620_BIN64`
- `BETA5620_BIN32_NO_PROTECT`

The smaller historical PDB set was Bin64, not an unknown revision.

Exact path/size/SHA identities for high-value modules and PDBs are preserved in:
`research/BETA_PDB_IDENTITY_CONFLICT_20260825.md`

That note is now `RESOLVED COLD` despite its historical filename.

## CLOSED: x64 C2/SDK donor module identity
Exact local x64 donor identities recovered from retained PDB Atlas:

| Module | Bytes | SHA256 |
|---|---:|---|
| `Bin64\CryGameCrysis2.dll` | 11,156,264 | `4E51AEA15E679066BC8CB3BE2D29BC61156DFF99AC78977036F313BD568F7331` |
| `Bin64\CryAction.dll` | 5,119,272 | `EDECB754B78AFFF731F3E597077363EBB1040AE21DA7E497C71204B9C7548F1D` |
| `Bin64\CrySystem.dll` | 5,225,768 | `BACC02298962E54B5051516B0DF00B02F168079A2B27FB7AAFB754E7D8A80694` |
| `Bin64\CryRenderD3D11.dll` | 3,493,160 | `9460DC78D2806A0438B9B669E8D4EC8C3F62810F63A8479DA5B003B96AA93692` |

See `research/CRYSIS2_MODSDK64_IDENTITY_20260825.md` and `research/CRYSIS2_MODSDK64_DONOR_20260824.md`.

## CONFIRMED: Crysis2Coop is already possessed/processed
Do not reacquire it as a new dependency.

2012 source identity retained:
- `Crysis2Coop_SOURCE_20120418.rar` / `Crysis2Coop.rar`
- bytes `11,133,614`
- MD5 `dc640394f1534084baf4ac7c7e04c34c`

Future action is targeted re-harvest only for GameDLL/weapon seams when G3 requires it.

## CONFIRMED: persistent public/donor corpora
Existing persistent groups include:
- `01_OPENXR_AND_HOOKS.zip`
- `02_CRYENGINE_VR_AND_STEREO_DONORS.zip`
- `04_CRYSIS2_PUBLIC_MOD_MATERIAL.zip`
- `05_DOCS_AND_WEB_SNAPSHOTS.zip`
- asset/format tooling corpus

Do not redownload equivalent public corpora unless a changed upstream revision matters to an open gate.

## STILL OPEN
These are legitimate remaining archival/research TODOs, not already-closed gaps:
1. optional promotion strategy for exact small T1/P5/P6 source trees into Git while preserving original ZIP as byte authority;
2. PDB GUID/age/CodeView association for especially important beta mapping targets where SHA/path alone is insufficient for a future question;
3. targeted Crysis2Coop GameDLL re-harvest when G3 opens;
4. targeted Crytek stereo/shadow/temporal presentation mining before G4;
5. compact indexing of only scientifically important RDC/TTD/RESULT carriers as they become gate-relevant;
6. P6 LIVE result itself.

## Current runtime gate
Nothing in this overlay changes the serial runtime gate:

`P6 PosePair -> HEAD 1:1 -> WEAPON/NEAR -> TEMPORAL/SHADOW -> REGRESSION -> RELEASE`

Current P6 remains **PREPARED / UNRUN**.
