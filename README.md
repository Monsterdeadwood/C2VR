# Crysis 2 VR

Native VR integration research for **Crysis 2 retail 1.9 / CryEngine DX11**.

## Current status
**ACTIVE — WORKING BUILD FIRST.**

Main renderer parent: `CUSTOM_DUAL_T1 v1.0.1`.

True private LEFT/RIGHT retail rendering is PROVEN. The active project gate is **PosePair / projection-layer exact-pair cadence**, not stereo discovery, HEAD reverse, weapon reverse, temporal work or shadow work.

Latest completed causal timing result: `v17.2.5 WAIT45` reached `269 exact_pair_consumes / 269 host_submits`, `53 misses`, exact ratio `83.5404%`, `pair_wait_ms_max=47`, with flashes/dropouts still visible.

The authorized next LIVE is already built and untested:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`.

P6 changes only the bounded exact-pair watchdog `45 ms -> 120 ms`; it is not a forced sleep.

Current finish ladder:
`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

Do not restart broad renderer/stereo/camera/weapon archaeology unless the serial gate requires it.

## Start here
1. `docs/SYNC.md` — canonical cross-branch snapshot, offsets, current finalists, unresolved questions
2. `research/SOURCE_CORPUS_REGISTRY.md` — canonical registry of retail, beta/dev, ModSDK, Crysis2Coop, PDB, CryEngine source, VR/stereo donors, public pinned repos, RDC/TTD/RESULT carriers and preservation status
3. `docs/STATE.md` — active state and exact CURRENT GATE / NEXT
4. `docs/NEXT.md` — authorized P6 handoff and post-P6 decision tree
5. `experiments/NEXT_EXPERIMENT.md` — exact five-line P6 PREFLIGHT and runtime acceptance criteria
6. `docs/EXPERIMENTS.md` — compact causal experiment lineage and do-not-repeat map
7. `docs/PROVEN.md` — facts that must not be re-researched
8. `docs/FALSIFIED.md` — dead/stopped paths
9. `docs/GATES.md` — serial acceptance ladder
10. `research/RESULT_INDEX.md` — result/build lineage
11. `research/POSEPAIR_PACKET_ATOMICITY_PACING_20260824.md` — historical pixel/metadata atomicity, pacing and last-good-frame evidence
12. `research/POSEPAIR_PUBLICATION_OWNERSHIP_20260824.md` — source-proven Present publication topology and unresolved ownership risk
13. `research/COORDINATE_BASIS_CONFLICT_20260824.md` — preserved `003329` vs retail/v10 local-X evidence conflict; COLD-only, not current LIVE gate
14. `research/WEAPON_NEAR.md` — parked weapon/NEAR state for its later gate

Before downloading, rescanning, or calling a beta/mod/donor “new”, check `research/SOURCE_CORPUS_REGISTRY.md`. Existing exact/local corpora must be re-harvested narrowly when possible instead of duplicated.

## Canonical renderer architecture
One prepared render-list executes twice for the two eyes. Do not add a second high-level `RenderWorld` / `EF_StartEf`.

`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`

Current RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Pixel data and the render pose/FOV/contract metadata that produced it are one atomic publication unit. Stale pixels must never be relabelled as a newer XR contract.

## Working model
`SYNC -> THINK -> KEEP/ADAPT/STOP -> BATCH HARVEST -> CONVERGE -> PROVEN/FALSIFIED -> NEXT GATE -> SYNC`

**PARALLELIZE EVIDENCE — SERIALIZE MUTATION.**

## Repository map
- `docs/` — canonical state, proven/falsified facts, gates, workflow and policy
- `research/` — evidence indexes, source/beta/mod/donor registry and focused blocker research
- `experiments/` — reproducible causal experiments
- `runtime/` — accepted main/donor source authority
- `tools/` — deterministic extraction/build/analysis tooling

## Exact retail baseline
- Game path: `C:\GOG Games\Crysis 2`
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)\_r\crysis2(5620)\_01_13`
- Shared research tools: `C:\GOG Games\VR Research Tools`
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
