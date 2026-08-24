# C2VR — PosePair exact-wait causal ladder P4 -> P5 -> P6 — 2026-08-25

Purpose: consolidate exact-package proof and runtime outcomes for the three-step PosePair timing ladder so the active G1 claim rests on reproducible source deltas rather than package naming or historical shorthand.

## Summary

```text
P4: adaptive wait = predicted period * 1.65, clamped 12..28 ms
    -> ~10.599% exact acceptance

P5: exact wait = 45 ms
    -> 83.5404% exact acceptance
    -> ~7.88x exact-rate improvement
    -> flashes/dropouts still remain

P6: exact wait watchdog = 120 ms
    + passive timeout/latency histogram telemetry
    -> PREPARED / UNRUN
```

The exact physical packages prove that P4->P5 and P5->P6 preserve the game-side runtime source byte-for-byte. Both timing steps are confined to the x64 host, apart from validation/metadata and passive logging/telemetry additions.

---

# P4 exact package

`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.4_EXACT_STALE_DRAIN_SYNC_ONECLICK.zip`
- bytes `80,644`
- SHA256 `E048DE17A86A74370179E0C8A9F3771F40A9FBA1622C8778411BF2E280EC2AB4`
- ZIP CRC PASS
- package manifest `36/36 PASS`

P4 host wait policy:
```cpp
double periodMs=(double)fs.predictedDisplayPeriod/1000000.0;
uint32_t budget=(uint32_t)(periodMs*1.65);
if(budget<12)budget=12;
if(budget>28)budget=28;
```

Therefore the exact-pair rendezvous could wait at most `28 ms`, regardless of a slower observed RC33 pair cadence.

Canonical P4 result retained by the project:
- exact consumes `92`
- misses `776`
- stale drains `386`
- exact acceptance = `92 / (92+776) = 10.599078%`

---

# P4 -> P5 exact delta

P5 package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
- bytes `82,867`
- SHA256 `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`
- ZIP CRC PASS
- package manifest `39/39 PASS`

Package comparison:
- P4 total files `37`
- P5 total files `40`
- common relative paths `37`
- byte-identical common files `29`
- changed common files `8`
- P5-only files `3`
- removed files `0`

P5-only files are gate documentation/preflight:
- `CROSS_BRANCH_STATE_SYNC_P5.txt`
- `PREFLIGHT_V1725.txt`
- `V1725_README.txt`

Changed common files:
- `src/t1_host_x64.cpp`
- validation scripts/results
- package manifest/checksum metadata

**Only changed first-party runtime source file: `src/t1_host_x64.cpp`.**

All game/in-process source remains byte-identical:
- `src/exports.def`
- `src/t1_camera.cpp`
- `src/t1_dual_render.cpp`
- `src/t1_game_api.h`
- `src/t1_ipc.h`
- `src/t1_proxy.cpp`

## Exact P4 -> P5 host source change

P4:
```cpp
uint32_t budget=(uint32_t)(periodMs*1.65);
if(budget<12)budget=12;
if(budget>28)budget=28;
```

P5:
```cpp
uint32_t budget=45;
```

P5 also adds an observational log line:
```cpp
EXACT_WAIT_POLICY budget_ms=45 display_period_ms=...
```

No wait algorithm, exact identity test, stale-drain behavior or submit fallback was changed.

## P5 runtime result
- exact consumes `269`
- host submits `269`
- misses `53`
- stale drains `31`
- exact acceptance `83.5404%`
- `pair_wait_ms_last=31`
- `pair_wait_ms_max=47`
- completed/copies `354/354`
- flashes/dropouts still visually remained

Exact-rate improvement over P4:
`83.5404 / 10.599078 = ~7.88x`.

Misses fell by `723` in the compared canonical counters (`776 -> 53`).

### Causal conclusion from P4 -> P5
Because the game-side source, IPC, proxy, exact-only semantics and stale-drain architecture are byte-identical, and the changed runtime source is confined to the x64 wait budget, the runtime improvement is strong causal evidence that the previous bounded deadline was expiring before many valid pairs became host-visible.

This does **not** prove every remaining flash is a timeout. It proves the wait budget is a major contributor.

---

# P5 -> P6 exact delta

P6 package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- bytes `85,852`
- SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`
- ZIP CRC PASS
- package manifest `42/42 PASS`

See full exact comparison:
`research/P5_TO_P6_EXACT_DELTA_20260825.md`.

Package comparison proves:
- all game/in-process runtime source byte-identical;
- only changed first-party runtime source is `src/t1_host_x64.cpp`;
- causal policy mutation `45 -> 120 ms`;
- passive additions: timeout counter and wait-latency histogram/status logging;
- exact-only submission and stale-drain remain unchanged.

P6:
```cpp
uint32_t budget=120;
exact=wait_exact_pair(requested,budget);
```

The function still returns immediately on exact-pair arrival. `120 ms` is only a fail-closed watchdog ceiling.

## Why P6 has better observability
P6 adds:
- `exact_wait_timeouts`
- wait bins `<20`, `<30`, `<40`, `<60`, `>=60 ms`

This allows the next LIVE to distinguish:
1. pairs normally arriving in the 30-60 ms region;
2. genuine >60 ms tails;
3. full 120 ms watchdog expirations;
4. visual flashes that survive even after timeout starvation closes.

---

# Current G1 decision tree

## Case A: timeouts near zero AND flashes/dropouts materially collapse
Classification:
`P6 PASS for watchdog-starvation hypothesis`.

Action:
- KEEP exact identity architecture;
- STOP increasing watchdog;
- next timing experiment = pipeline lead / earlier requested target, candidate:
  `targetDisplayTime = predictedDisplayTime + K*predictedDisplayPeriod`, minimal successful `K=0..3`.

## Case B: timeouts near zero BUT flashes remain
Classification:
`WATCHDOG PATH CLOSED, VISUAL PROBLEM REMAINS`.

Action:
- STOP timeout tuning;
- inspect Present publication seam / host-visible timeliness / projection-layer submit continuity;
- do not mutate HEAD/weapon/shadow/temporal yet.

## Case C: material timeouts remain even at 120 ms
Classification:
`LONG-TAIL / PHASE STARVATION NOT CLOSED`.

Action:
add passive timestamps before any further mutation:
`contract -> RenderWorld -> RT LEFT -> RT RIGHT -> Present publish -> host consume`.

## Regression failure
Any loss of true L/R, black eye, renderer instability, contract corruption or stale relabel is a P6 failure regardless of exact-rate improvement.

---

# Scientific scope

This ladder proves/targets **host exact-pair timing availability**, not:
- final HEAD 1:1 ownership;
- controller weapon binding;
- final NEAR correctness;
- temporal release quality;
- shadow release quality.

Those remain later serial gates.

## Classification
- P4 exact package identity/integrity: **PROVEN**
- P4 -> P5 game-side byte identity: **PROVEN**
- P4 -> P5 x64 wait-budget-only causal mutation + policy logging: **PROVEN**
- P5 runtime improvement after wait widening: **PROVEN RESULT**
- wait deadline as major contributor to missing projection layers: **CAUSALLY SUPPORTED STRONGLY**
- P5 -> P6 game-side byte identity: **PROVEN**
- P6 45 -> 120 watchdog mutation + passive telemetry: **PROVEN COLD**
- P6 runtime/headset result: **UNRUN**

No LIVE or mutation was performed during this audit.
