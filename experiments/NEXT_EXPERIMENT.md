# Crysis 2 VR — NEXT EXPERIMENT

## Decision
**KEEP architecture. Run the already-built PosePair timing finalist unchanged.**

Do not build a new weapon/HEAD/temporal variant before this result.

## Target build
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

SHA256:
`8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

Exact source/package audit now proves the P5->P6 scope:
- all game/in-process runtime source is byte-identical;
- only changed first-party runtime file is x64 `src/t1_host_x64.cpp`;
- the one causal timing-policy mutation is `45 ms -> 120 ms` watchdog ceiling;
- P6 additionally adds passive exact-wait timeout and latency-histogram telemetry.

It is not a fixed sleep. The wait exits as soon as the exact pair arrives.

Recorded validation before LIVE:
- P5 exact carrier SHA verified; package manifest `39/39 PASS`;
- P6 exact carrier SHA verified; package manifest `42/42 PASS`;
- static `130/130 PASS`;
- independent `98/98 PASS`;
- game-side camera/FOV/weapon/NEAR/shadow/temporal/RC33 source byte-identical from P5.

Full exact causal ladder:
`research/POSEPAIR_CAUSAL_LADDER_P4_P5_P6_20260825.md`.

## Why this is the current gate
Exact P4->P5 package comparison proves the runtime causal mutation was confined to the x64 host wait policy:

P4:
`budget = periodMs * 1.65`, clamped to `12..28 ms`.

P5:
`budget = 45 ms`.

The game-side source, exact-only submit path, stale drain, IPC/proxy publication, renderer eye code, temporal and shadow policy remained unchanged.

Canonical outcomes:
- P4: `92 exact / 776 miss` = `10.599%` exact acceptance;
- P5: `269 exact / 53 miss` = `83.5404%` exact acceptance;
- improvement: ~`7.88x`;
- P5 `pair_wait_ms_max = 47`;
- `354/354` completed/copies;
- flashes/dropouts remained.

This is strong causal evidence that the prior deadline/watchdog was expiring before many valid exact pairs became host-visible.

## PREFLIGHT — exactly 5 lines
**MISSING FACT:** whether raising only the causal exact-pair watchdog ceiling from 45 ms to 120 ms, while preserving the P5 architecture, eliminates or materially reduces remaining exact timeouts/misses and headset flashes/dropouts.
**WHY NOT COLD:** P4->P5 and P5->P6 exact-package deltas are now COLD-closed; only LIVE can measure the real 120 ms arrival/timeout distribution and whether visual flashes track those timeouts.
**PASS:** exact wait timeouts approach zero, exact ratio approaches 100%, misses collapse, flashes/dropouts disappear or materially collapse, true L/R remains alive/fused, no new black eye or renderer regression.
**FAIL:** timeouts/misses remain material despite 120 ms, or timeouts are near zero while flashes remain, or the proven true-L/R primitive regresses.
**BASELINE MUST HOLD:** `CUSTOM_DUAL_T1 v1.0.1` inherited camera/dual-eye architecture, one prepared render-list executed twice, exact retail hashes, exact-only submit/stale drain/keyed transport, no second RenderWorld/EF_StartEf, no HEAD/weapon/NEAR/temporal/shadow game-side policy changes.

## Required telemetry
Capture at minimum:
- `exact_pair_consumes`
- `exact_wait_timeouts`
- wait bins `<20`, `<30`, `<40`, `<60`, `>=60 ms`
- `pair_wait_ms_last`
- `pair_wait_ms_max`
- `host_submits`
- pair misses / zero-layer frames
- completed pair count / copy count
- contract/ticket identity mismatch counters
- layerCount submission counts where available.

Visual report must include:
- whether flashes/dropouts remain
- whether both eyes remain alive and distinct
- whether depth/fusion regresses
- stationary hold
- slow yaw
- fast yaw reversals

Counters alone are not PASS.

## Interpretation after P6
### If timeouts approach zero and flashes disappear/materially collapse
KEEP exact identity. **Do not increase timeout again.** Next experiment becomes pipeline lead:
`targetDisplayTime = predictedDisplayTime + K*predictedDisplayPeriod`
with minimal successful `K`, candidate batch `K=0,1,2,3`.

### If timeouts approach zero but flashes remain
STOP the watchdog path. Do not immediately increase/tune wait again. Inspect the existing presentation/publication/timeliness chain and `research/POSEPAIR_PUBLICATION_OWNERSHIP_20260824.md` first.

A coherent last-good complete stereo pair remains only a reserve policy and must retain its original render pose/FOV. Never relabel old pixels with a new pose.

### If timeouts remain material
Stay on PosePair rendezvous timing. Add passive timestamps before mutation along:
`xrWaitFrame -> contract N -> RenderWorld -> RC queue -> RT L -> RT R -> complete pair -> Present -> publish_pair -> host -> xrEndFrame`.

## Forbidden in P6 run
- HEAD/culling mutation
- RIGHT Touch / weapon / NEAR mutation
- temporal-history mutation
- shadow mutation
- new camera owner hunt
- new broad PDB/Ghidra/analyzer work
- stale-pair relabel

## After current gate passes
Serial order remains:
`HEAD 1:1 -> WEAPON / NEAR -> TEMPORAL / SHADOW STABILITY -> REGRESSION -> RELEASE CANDIDATE`.
