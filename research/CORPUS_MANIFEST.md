# Crysis 2 VR — CORPUS MANIFEST

Large handoff/evidence corpora stay outside ordinary Git history. This manifest records exact identities and read order.

## Canonical handoff read order
1. `CRYSIS2VR_CLAUDE_START_HERE_20260823.md`
2. `CRYSIS2VR_CLAUDE_MAIN_CORPUS_20260823.md`
3. `CRYSIS2VR_CLAUDE_LEGACY_EVIDENCE_20260823.md` only for older chronology/raw evidence
4. `CRYSIS2VR_CLAUDE_MANIFEST_20260823.txt` for identity verification

## Exact identities
### START_HERE
File: `CRYSIS2VR_CLAUDE_START_HERE_20260823.md`
- bytes: 24,058
- MiB: 0.023
- SHA256: `1E60216AFB430DB413ABF1A38A0BE12CE12DA34E1DF9712FE607ABFCC65C2903`

### MAIN_CORPUS
File: `CRYSIS2VR_CLAUDE_MAIN_CORPUS_20260823.md`
- bytes: 100,249,910
- MiB: 95.606
- SHA256: `BDF73215DAEE53C396460F601806D36803713E08CC42EE5F73ECF07E6264A683`

### LEGACY_EVIDENCE
File: `CRYSIS2VR_CLAUDE_LEGACY_EVIDENCE_20260823.md`
- bytes: 17,942,281
- MiB: 17.111
- SHA256: `E8ED6882C6938224435D2D0AFFD90E4314BF9AA452EF2EE25FE49FB26A341384`

## Current compact canonical handoffs
- `C2VR_STATE_SYNC_20260823.md` — current working-build-first state
- `C2VR_MAIN_INTEGRATOR_BLUEPRINT_20260823.md` — serial integration blueprint and PosePair finalist

These compact files outrank an older broad research frontier when they describe the current finish blocker.

## Evidence precedence
1. latest retail runtime proof
2. latest retail static/cold proof
3. older retail runtime proof
4. beta/PDB/source triangulation
5. donor/mod architecture
6. hypothesis

Explicit `FALSIFIED`, `SUPERSEDED`, `STOP`, or `DO NOT REPEAT` statements are not silently revived.

## Exact retail guards
- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## Current working-build rule
Do not dump the 95.6 MiB MAIN_CORPUS into the repository as a single Git blob. Promote only facts needed by the active serial ladder into `docs/` and exact result identities into `research/RESULT_INDEX.md`.
