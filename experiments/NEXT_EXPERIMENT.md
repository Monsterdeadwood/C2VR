# Crysis 2 VR — NEXT EXPERIMENT

## Decision
**KEEP architecture. Run the already-built PosePair timing finalist unchanged.**

Do not build a new weapon/HEAD/temporal variant before this result.

## Target build
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

SHA256:
`8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

P6 differs from the previous WAIT45 finalist only by the bounded exact-pair watchdog ceiling:
`45 ms -> 120 ms`.

It is not a fixed sleep. The wait exits as soon as the exact pair arrives.

Recorded validation before LIVE:
- static `130/130 PASS`
- independent `98/98 PASS`
- game-side camera/FOV/weapon/shadow/temporal/RC33 code unchanged from P5

## Why this is the current gate
Latest causal P5 result:
- `269 exact_pair_consumes`
- `269 host_submits`
- `53 misses`
- exact ratio `83.5404%`
- `pair_wait_ms_max = 47`
- `354/354` completed/copies
- flashes/dropouts remained

The previous line was roughly `92 exact / 776 miss` (~10.6%). A single bounded-wait change raised exact acceptance about 7.9x, so watchdog/deadline timing is already a proven contributor.

## PREFLIGHT — exactly 5 lines
**MISSING FACT:** whether extending only the bounded exact-pair wait ceiling to 120 ms eliminates or materially reduces remaining exact misses and headset flashes/dropouts.
**WHY NOT COLD:** code identity and rendezvous logic are already verified; only LIVE can tell whether the missing projection layers are caused by the watchdog expiring before the complete exact pair reaches the host.
**PASS:** exact ratio approaches 100%, misses collapse, flashes/dropouts disappear or materially collapse, true L/R remains alive/fused, no new black eye or renderer regression.
**FAIL:** misses remain material despite 120 ms, or exact identity is high while flashes remain, or the proven true-L/R primitive regresses.
**BASELINE MUST HOLD:** `CUSTOM_DUAL_T1 v1.0.1` true private L/R architecture, one prepared render-list executed twice, exact retail hashes, no second RenderWorld/EF_StartEf, no HEAD/weapon/temporal/shadow policy changes.

## Required telemetry
Capture at minimum:
- exact_pair_consumes
- host_submits
- pair misses / zero-layer frames
- pair wait distribution and max
- completed pair count / copy count
- contract/ticket identity mismatch counters
- layerCount submission counts

Visual report must include:
- whether flashes/dropouts remain
- whether both eyes remain alive and distinct
- whether depth/fusion regresses
- stationary hold
- slow yaw
- fast yaw reversals

Counters alone are not PASS.

## Interpretation after P6
### If exact ratio ~100% and flashes disappear
KEEP exact identity. **Do not increase timeout again.** Next experiment becomes pipeline lead:
`targetDisplayTime = predictedDisplayTime + K*predictedDisplayPeriod`
with minimal successful `K`, candidate batch `K=0,1,2,3`.

### If exact ratio ~100% but flashes remain
Identity is closed, timing freshness is not. Move to pipeline lead and/or coherent last-good complete stereo pair with its own original render pose/FOV. Never relabel old pixels with a new pose.

### If misses remain high
Stay on PosePair rendezvous timing. Investigate only the existing chain:
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
