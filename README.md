# Crysis 2 VR

Native VR integration research for **Crysis 2 retail 1.9 / CryEngine DX11**.

## Current status
**ACTIVE — WORKING BUILD FIRST.**

Main renderer parent: `CUSTOM_DUAL_T1 v1.0.1`.

True private LEFT/RIGHT retail rendering is PROVEN. The active project gate is now **PosePair / projection-layer exact-pair cadence**, not stereo discovery and not weapon reverse.

Latest causal timing result: `v17.2.5 WAIT45` reached `269 exact_pair_consumes / 269 host_submits`, `53 misses`, exact ratio `83.5404%`, `pair_wait_ms_max=47`, with flashes/dropouts still visible. The next untested finalist is `v17.2.6 EXACT_BLOCK120 P6`, changing only the bounded exact-pair watchdog `45 ms -> 120 ms`.

Current finish ladder:

`POSEPAIR -> HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`

Do not restart broad renderer/stereo/camera/weapon archaeology unless the serial gate requires it.

## Start here
1. `docs/SYNC.md` — canonical cross-branch snapshot
2. `docs/STATE.md` — concise active state and concrete targets
3. `experiments/NEXT_EXPERIMENT.md` — the one authorized next LIVE
4. `docs/GATES.md` — serial acceptance ladder
5. `docs/PROVEN.md` — facts that must not be re-researched
6. `docs/FALSIFIED.md` — dead paths / do-not-repeat list
7. `research/RESULT_INDEX.md` — result/build lineage
8. `research/WEAPON_NEAR.md` — parked MASTER3 weapon/NEAR state prepared for its later gate

## Canonical renderer architecture
One prepared render-list executes twice for the two eyes. Do not add a second high-level `RenderWorld` / `EF_StartEf`.

`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`

Current RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

## Working model
`SYNC -> THINK -> KEEP/ADAPT/STOP -> BATCH HARVEST -> CONVERGE -> PROVEN/FALSIFIED -> NEXT GATE -> SYNC`

**PARALLELIZE EVIDENCE — SERIALIZE MUTATION.**

## Repository map
- `docs/` — canonical state, proven/falsified facts, gates, workflow and policy
- `research/` — evidence indexes and focused blocker research
- `experiments/` — reproducible causal experiments
- `runtime/` — accepted main/donor source authority
- `tools/` — deterministic extraction/build/analysis tooling

## Exact retail baseline
- Game path: `C:\GOG Games\Crysis 2`
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)\_r\crysis2(5620)\_01_13`
- Shared research tools: `C:\GOG Games\VR Research Tools`
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
