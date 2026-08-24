# C2VR — exact source lineage: CUSTOM_DUAL_T1 v1.0.1 -> P6 v17.2.6 — 2026-08-25

Purpose: prove which working-parent subsystems survived into the current P6 finalist and which subsystems materially evolved. This is exact-package COLD comparison, not a new LIVE result.

## Exact source authorities compared
### T1 parent
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`
- bytes `83,442`
- SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- internal package manifest `20/20 PASS`

### P6 finalist
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- bytes `85,852`
- SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`
- exact physical carrier previously re-located and verified

Both comparisons were made directly from the package bytes, not from reconstructed snippets.

## Shared first-party source topology
The two packages share these first-party source paths:
- `src/exports.def`
- `src/t1_camera.cpp`
- `src/t1_dual_render.cpp`
- `src/t1_game_api.h`
- `src/t1_host_x64.cpp`
- `src/t1_ipc.h`
- `src/t1_proxy.cpp`

T1 also vendors three OpenXR headers under `src/third_party/openxr/...`; P6 does not carry separate additional first-party source files.

## Mechanical line-similarity snapshot
This is a navigation metric only, not semantic proof by itself.

| File | T1 bytes | P6 bytes | SequenceMatcher line ratio | Meaning |
|---|---:|---:|---:|---|
| `src/exports.def` | 138 | 138 | `1.000` | byte-identical export surface |
| `src/t1_camera.cpp` | 7,969 | 8,111 | `0.995` | camera/RenderWorld/cull core essentially preserved |
| `src/t1_game_api.h` | 847 | 1,014 | `0.931` | game/renderer API contract strongly preserved |
| `src/t1_dual_render.cpp` | 12,765 | 20,540 | `0.583` | eye transaction/temporal/NEAR logic substantially evolved |
| `src/t1_host_x64.cpp` | 22,617 | 36,380 | `0.314` | OpenXR host contract/timing/input substantially evolved |
| `src/t1_ipc.h` | 2,618 | 2,824 | `0.315` | IPC ABI reworked around exact immutable contracts |
| `src/t1_proxy.cpp` | 11,365 | 23,074 | `0.190` | publication/shared-texture/semantic instrumentation substantially evolved |

Do not interpret the numeric ratio as correctness. Its value here is identifying where reverse/review effort belongs.

## 1. Camera/RenderWorld authority survived
`src/t1_camera.cpp` is almost unchanged between exact T1 and exact P6 packages.

Therefore the project should treat the T1/P6 camera layer as one continuous source lineage rather than two unrelated attempts.

Practical consequence for future G2 HEAD:
- do not restart broad camera-owner archaeology;
- validate/converge the existing upstream center-camera owner already proven mechanically in T1;
- resolve the separate XR<->Cry coordinate-sign conflict before final positional math;
- preserve immutable game/body camera composition and culling coherence.

This source continuity is additional COLD support for the existing `STOP broad HEAD reverse` rule. Retail visual/causal proof still decides G2 PASS.

## 2. Game API seam is also strongly preserved
`t1_game_api.h` remains close to T1. This supports treating the known CSystem/RenderWorld/renderer ABI bridge as inherited infrastructure rather than a newly invented P6 dependency.

Exact retail hash guards and current concrete RVAs remain the authority.

## 3. Dual-render layer is where major engine-side evolution occurred
`src/t1_dual_render.cpp` changed materially while keeping the same basic two-eye RC33 design family.

Important P6 additions/evolution visible in exact source include:
- per-eye `EyeTicket` ownership rather than only a thread-local clone id;
- immutable `T1FrameContract` carried into the eye ticket;
- completed-pair serial/contract publication;
- exact contract/eye ownership checks;
- explicit SetCamera interception at the known renderer owner;
- `FOB_NEAREST` callsite handling;
- exact per-eye near asymmetric frustum application;
- right-controller/head-relative NEAR transform support;
- stronger frame/pose desync accounting.

### Shadow policy changed from early T1
Early T1's clone path suppressed depth/shadow preparation for clone eyes broadly. P6's current source instead makes LEFT the shadow-preparation owner and skips repeated shadow preparation only on RIGHT.

Conceptually:
`LEFT prepares shadow state -> RIGHT reuses -> both scenes render`.

This is consistent with the later donor/shadow policy direction. It is **not** a new P6-vs-P5 delta; P6 must still be run unchanged for the current gate.

### Temporal policy changed from early T1
Early T1 wrapped each eye with local temporal snapshot/restore.

P6 introduces a stronger ownership scheme:
- LEFT is once-per-XR-frame global temporal owner;
- LEFT post-state is preserved;
- RIGHT uses isolated right-eye history when available;
- after RIGHT, shared global state returns to LEFT post-state;
- completed pair publication occurs only after coherent LEFT/RIGHT completion for the same serial.

This explains why future G4 should inspect existing P6 temporal behavior before inventing another temporal layer.

## 4. IPC evolved from pose-id bookkeeping to immutable pair contract
T1 IPC used the older map/version identity and pair-pose id fields.

P6 changes the shared contract family to include:
- exact `predicted_display_time`;
- exact per-eye orientation/position/FOV;
- immutable `pair_contract` protected by a sequence counter;
- right-controller pose/trigger/grip fields;
- exact-frame hit/miss/wait telemetry;
- semantic WORLD/NEAR eye telemetry;
- completed-contract and pair-contract mismatch telemetry.

This is a large ABI evolution, so old T1 shared-memory offsets must never be mixed with P6 IPC offsets by name alone.

## 5. Proxy evolved into atomic pixel+contract publication
Exact P6 proxy source publishes a completed pair by:
1. reading the completed immutable frame contract;
2. acquiring both keyed mutexes;
3. copying LEFT and RIGHT engine eye textures;
4. flushing the transport context;
5. publishing `pair_contract` under a sequence counter;
6. incrementing pair publication state;
7. releasing both keyed mutexes.

This is the mature form of the project's packet-atomicity rule: pixels and the pose/FOV/display-time contract that produced them are one publication unit.

## 6. Host evolved into exact requested-contract rendezvous
P6 host source contains:
- `xrWaitFrame` / `predictedDisplayTime` ownership;
- exact contract publication to the x86 game;
- exact-pair consume/wait logic;
- stale-pair draining rather than relabeling;
- pair wait telemetry buckets;
- right Touch action setup;
- exact pair contract used for XR submit pose/FOV.

The P6-specific bounded watchdog is visibly host-side:
`budget = 120 ms`.

This is important scope control: the current P6 experiment is fundamentally a host-side deadline/watchdog test, not a rewrite of the preserved T1 camera core.

## 7. Architecture inheritance map

```text
T1 proven parent
|
|-- camera / RenderWorld / cull core ----------> almost unchanged in P6
|-- renderer/game ABI -------------------------> strongly preserved
|-- RC33 two-eye transaction -----------------> preserved family, stronger tickets/contracts
|-- temporal handling ------------------------> evolved to LEFT-owner + RIGHT-isolated history
|-- shadow handling --------------------------> evolved to LEFT prepare / RIGHT reuse
|-- pixel transport --------------------------> evolved to atomic pair+contract publication
|-- shared IPC -------------------------------> substantially redesigned
|-- x64 OpenXR host --------------------------> substantially redesigned around exact rendezvous
`-- RIGHT Touch / NEAR ------------------------> added into later lineage
```

## 8. Gate consequences
### Current G1 PosePair
No change. Run P6 unchanged. The 120 ms watchdog is a narrow host policy test on top of a largely preserved camera foundation.

### Future G2 HEAD
This lineage strengthens the instruction to converge existing T1/P6 camera ownership rather than start over.

### Future G3 WEAPON/NEAR
P6 already contains NEAR/right-controller machinery. Before adding more code, compare its existing behavior against the now-mapped donor/GameDLL rigid-bind path and decide KEEP/ADAPT/STOP.

### Future G4 TEMPORAL/SHADOW
Do not assume these are blank-slate problems. Exact P6 source already has explicit LEFT/RIGHT temporal ownership and first-eye shadow ownership. G4 should first measure whether those policies are sufficient or specifically where they fail.

## Classification
- T1->P6 camera-source continuity: **EXACT PACKAGE COLD PROVEN**
- T1->P6 renderer/game API continuity: **EXACT PACKAGE COLD SUPPORTED STRONGLY**
- P6 host/IPC/proxy as major evolution: **EXACT PACKAGE COLD PROVEN**
- visual adequacy of P6 temporal/shadow/NEAR policies: **UNPROVEN UNTIL THEIR SERIAL GATES**
- P6 watchdog result: **PREPARED / UNRUN**

No LIVE or mutation was performed for this lineage comparison.
