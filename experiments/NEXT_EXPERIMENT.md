# Crysis 2 VR — NEXT EXPERIMENT

## Decision
**ADAPT. P6 has now executed and returned RED before eye-pair production.**

Do not run pipeline-lead K, HEAD, weapon/NEAR, temporal or shadow experiments while the contract-latch edge is red.

Corrected state override:
`docs/STATE_OVERRIDE_20260825_P6_RED.md`

## Latest raw runtime evidence
Raw RESULT:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`

The inherited `V1721` result prefix is not package identity. `BUILD_COMMANDS.log` compiled directly from:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK\src`

Therefore the old `P6 = PREPARED / UNRUN` classification is superseded.

P6 package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`

## P6 verdict
Host:
- `contract_id = 1533`
- `xr_frame_requests = 1533`
- `xr_frame_exact_hits = 0`
- `xr_frame_misses = 1409`
- `exact_pair_consumes = 0`
- `host_submits = 0`
- `exact_wait_timeouts = 11`
- `pair_wait_ms_last = 125.000`
- `last_completed_contract = 0`
- fault `NO_LATCHED_RENDER_CONTRACT`

Game:
- `host_alive = 1`
- `session_running = 1`
- `views_valid = 1`
- `renderworld_calls = 900`
- `scene_packets = 899`
- `custom_pairs_queued = 0`
- `pairs_completed = 0`
- `rt_scene_left = 0`
- `rt_scene_right = 0`
- `direct_pair_copies = 0`
- fault `NO_LATCHED_RENDER_CONTRACT`

Retail hashes matched and `RESTORE_VERIFY = PASS`.

## Correct interpretation
This run does **not** test whether 120 ms is the right final watchdog. It failed earlier than pair production.

The current blocker is:
`HOST publish N -> GAME observes N -> GAME validates N -> GAME queues N`

Stop at the first missing edge. Do not repair cadence/presentation downstream while the game-side contract latch is red.

## Last working ancestor
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
SHA256 `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`

P5 runtime result:
- `pairs_completed/copies = 354/354`
- `exact_pair_consumes = 269`
- `host_submits = 269`
- `xr_frame_misses = 53`
- exact hit ratio `83.5404%`
- stale drains `31`
- wait last/max `31/47 ms`
- flashes/dropouts remained

This is the last lineage that satisfies the MASTER 3 precondition that exact pairs were actually rendered and submitted.

## SCRIPT LINEAGE GATE
The exact P5 package identity is known, but its standalone physical ZIP/runner bytes have not yet been recovered from the currently accessible Library/GitHub corpus.

Classification:
`SCRIPT_LINEAGE_GAP`

Do **not** silently reconstruct a new launcher from P6 or write a fresh BAT/PS1 scaffold.

Required recovery order:
`BASE_PACKAGE -> BASE_SCRIPT -> KNOWN_GOOD_RESULT -> MINIMAL_DELTA`.

Known base identity:
- BASE_PACKAGE: `v17.2.5 EXACT_WAIT45 P5`
- BASE_SCRIPT family: inherited `RUN_C2VR_V17_TRUE_LR.cmd -> tools\Run-V17.ps1`
- KNOWN_GOOD_RESULT: P5 counters above
- MINIMAL_DELTA: passive contract-publication/latch telemetry only

## PREFLIGHT — exactly 5 lines
**MISSING FACT:** after host publishes contract N, does the x86 game side observe the new contract sequence/id at all, and if so where is it rejected before queue publication?
**WHY NOT CADENCE K:** P6 produced zero queued pairs, zero LEFT/RIGHT RC33 calls and zero submits, so MASTER 3 cadence is downstream of the first missing edge.
**PASS:** one exact N is seen by game, validates, queues, reaches LEFT then RIGHT, completion N publishes and host accepts/submits the same N.
**FAIL:** the first edge remains absent; record whether failure is mapping/open, ABI/version/size, sequence observation, validation rejection or queue publication.
**BASELINE MUST HOLD:** P5 launcher/build/restore/logging/packaging and RC33/OpenXR/IPC architecture remain unchanged; no HEAD/weapon/NEAR/temporal/shadow mutation.

## Required telemetry for the next child
On host and game sides, record only what localizes the first missing edge:
- mapping/open success
- ABI/version/size
- host publish sequence before/after
- contract id
- predictedDisplayTime
- game-observed sequence/id
- validation result and rejection reason
- queue publication id
- LEFT begin/end
- RIGHT begin/end
- completion publication
- host accept/submit identity
- monotonic timestamps at publish and observe

Failed execution must still package the normal RESULT logs and restore report.

## After the latch is green
Return to MASTER 3, preserving the same working parent:
1. choose/document rendezvous policy;
2. fixed watchdog;
3. `K=0` one LIVE;
4. `K=1` only if needed;
5. `K=2` only if needed;
6. fail closed on an exact-pair miss;
7. require `exact_hit_ratio >= 0.98`, three minutes without visible flashes, deterministic private L/R non-duplicate proof, byte-exact restore and retail-hash PASS.

Only then unlock HEAD -> WEAPON/NEAR -> TEMPORAL/SHADOW.