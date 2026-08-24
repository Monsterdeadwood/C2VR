# Crysis 2 VR — NEXT

## CURRENT GATE
**POSEPAIR / PROJECTION-LAYER EXACT-PAIR CADENCE GATING.**

Do not move to HEAD, weapon/NEAR, temporal or shadow work before this gate is closed.

## NEXT LIVE
Run unchanged:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

SHA256:
`8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

Exact P4->P5->P6 package comparison is now closed COLD in:
`research/POSEPAIR_CAUSAL_LADDER_P4_P5_P6_20260825.md`.

Precise P5->P6 scope:
- all game/in-process runtime source is byte-identical;
- only changed first-party runtime file is `src/t1_host_x64.cpp`;
- one causal timing-policy mutation: exact-pair watchdog `45 ms -> 120 ms`;
- passive P6 additions: exact-wait timeout counter and latency histogram/status logging;
- exact-only submit, stale drain, IPC, proxy publication, camera/FOV, RC33 eye code, weapon/NEAR game-side code, temporal and shadow policy are unchanged.

`120 ms` is not a forced sleep. `wait_exact_pair()` returns immediately when the requested exact pair is available.

Recorded pre-LIVE validation:
- P5 physical package SHA/manifest verified `39/39 PASS`;
- P6 physical package SHA/manifest verified `42/42 PASS`;
- static `130/130 PASS`;
- independent `98/98 PASS`.

## PREFLIGHT — exactly 5 lines
**MISSING FACT:** do the remaining flashes/dropouts come from the 45 ms watchdog expiring before a slow-but-valid exact RC33 pair becomes host-visible?
**WHY NOT COLD:** P4->P5 exact-package identity plus the ~7.88x exact-rate gain already establishes wait-budget causality; only LIVE can show whether the 120 ms watchdog collapses the remaining timeouts/misses and whether visual flashes collapse with them.
**PASS:** exact wait timeouts approach zero, exact ratio rises toward 1, host submits become continuous, flashes/dropouts materially reduce, true L/R remains fused/alive.
**FAIL:** misses/timeouts remain material despite 120 ms, or flashes remain while timeouts are near zero, or the true-L/R baseline regresses.
**BASELINE MUST HOLD:** exact-only submit, stale-pair drain, keyed transport, two RC33 eye passes, camera/FOV, temporal/shadow, weapon/NEAR game-side policy and byte-exact restore remain unchanged.

## REQUIRED P6 TELEMETRY
At minimum preserve:
- `exact_pair_consumes`
- `exact_wait_timeouts`
- wait histogram `<20`, `<30`, `<40`, `<60`, `>=60 ms`
- `pair_wait_ms_last`
- `pair_wait_ms_max`
- `host_submits`
- pair misses / zero-layer frames
- completed pair / copy counts
- contract/ticket mismatch counters
- layerCount submit counts where available.

The histogram is important because it distinguishes ordinary 30-60 ms arrivals from genuine 120 ms watchdog expiry.

## WHAT TO REPORT FROM HEADSET
- flashes/dropouts: gone / reduced / unchanged
- stereo fusion/depth: stable / unstable
- head-motion latency/judder: acceptable / obvious
- shadows: still running / unexpectedly improved

Unchanged running shadows are **not** P6 failure.

## POST-P6 DECISION
- **timeouts near zero + flashes gone/materially collapsed:** KEEP exact architecture. STOP increasing wait. Next timing experiment is pipeline lead `target = predictedDisplayTime + K*predictedDisplayPeriod`, `K=0..3`, choose the smallest sustainable K.
- **timeouts near zero + flashes remain:** STOP timeout path. Do not immediately tune another wait. Inspect presentation/timeliness seam and the already-recorded publication-owner risk in `research/POSEPAIR_PUBLICATION_OWNERSHIP_20260824.md`.
- **many timeouts remain:** add passive phase timestamps `contract -> RenderWorld -> RT L -> RT R -> Present publish -> host consume` before any mutation.

Reserve only if post-P6 evidence demands it:
- coherent last-good **complete** stereo pair;
- keep the exact pose/FOV/metadata that rendered those pixels;
- never relabel cached pixels as the new/current XR contract.

Historical packet-atomicity and continuity evidence is preserved in:
`research/POSEPAIR_PACKET_ATOMICITY_PACING_20260824.md`.

## PARKED AFTER POSEPAIR
1. HEAD 1:1 rotation-first + coherent visibility envelope.
2. WEAPON / FOB_NEAREST rigid bind or upstream FP entity owner.
3. TEMPORAL / SHADOW stability.
4. Regression.
5. Release candidate.

### First HEAD action after PosePair
Do **not** restart broad HEAD reverse first. Exact T1->P6 source lineage proves the upstream camera core is preserved. `CUSTOM_DUAL_T1 v1.0.1` already has:
- center HMD inject/restore `2296/2296`;
- union cull `2296/2296`;
- upstream RenderWorld call seam `Crysis2.exe +0x005E2476`.

First validate/converge that existing upstream center-HMD owner in headset. Only reverse a new owner if that visual proof falsifies it.

See:
- `research/T1_TO_P6_SOURCE_LINEAGE_20260825.md`
- `research/T1_CARRIER_RECOVERY_20260825.md`

Before final HEAD/eye-position math, resolve the explicit local-X sign conflict in `research/COORDINATE_BASIS_CONFLICT_20260824.md`. That question is COLD-only and is not authorization to delay P6.
