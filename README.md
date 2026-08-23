# Crysis 2 VR

Native VR integration research for **Crysis 2 retail 1.9 / CryEngine DX11**.

## Current status
**ACTIVE — WORKING BUILD FIRST.**

Main build: `CUSTOM_DUAL_T1 v1.0.1`.

True private LEFT/RIGHT retail rendering is already PROVEN. The current blocker is **PosePairContract**, not stereo discovery.

Current finish ladder:

`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

Do not restart broad renderer/stereo archaeology unless a concrete blocker in that ladder requires it.

## Start here
1. `docs/SYNC.md` — canonical current cross-branch snapshot
2. `docs/STATE.md` — concise active state
3. `docs/GATES.md` — serial acceptance ladder
4. `docs/PROVEN.md` — facts that must not be re-researched
5. `docs/FALSIFIED.md` — dead paths / do-not-repeat list
6. `research/RESULT_INDEX.md` — artifact/result lineage
7. GitHub Issue #1 — current actionable gate

## Canonical renderer architecture
One prepared render-list executes twice for the two eyes. Do not add a second high-level RenderWorld / EF_StartEf.

Current eye transaction is preserved in `docs/SYNC.md` and must remain causally attributable while each later gate is integrated serially.

## Working model
`SYNC -> THINK -> KEEP/ADAPT/STOP -> BATCH HARVEST -> CONVERGE -> PROVEN/FALSIFIED -> NEXT GATE -> SYNC`

**PARALLELIZE EVIDENCE — SERIALIZE MUTATION.**

## Repository map
- `docs/` — canonical state, gates, workflow and policy
- `research/` — evidence indexes, canonical corpus manifests, static/runtime archaeology
- `experiments/` — reproducible causal experiments
- `runtime/` — accepted integration code
- `tools/` — project-specific tooling

## Exact retail baseline
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
