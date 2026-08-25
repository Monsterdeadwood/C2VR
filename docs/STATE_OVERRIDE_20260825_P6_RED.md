# C2VR STATE OVERRIDE — 2026-08-25 — P6 EXECUTED / RED

This file overrides older statements that `v17.2.6 EXACT_BLOCK120 P6` was `PREPARED / UNRUN`.

## EVIDENCE PRIORITY

Raw executed RESULT wins over package README and older state summaries.

Raw RESULT:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`

Despite the inherited `V1721` result prefix, `BUILD_COMMANDS.log` records compilation directly from:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK\src`

Therefore P6 was executed. The inherited runner/result naming must not be used to classify the run as old v17.2.1.

Canonical P6 package identity:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`

## P6 RUNTIME RESULT

Host:
- `contract_id = 1533`
- `xr_frame_requests = 1533`
- `xr_frame_exact_hits = 0`
- `xr_frame_misses = 1409`
- `exact_pair_consumes = 0`
- `host_submits = 0`
- `exact_wait_timeouts = 11`
- `pair_wait_ms_last = 125.000`
- `stale_pair_drains = 0`
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
- `two_pass_active = 0`
- fault `NO_LATCHED_RENDER_CONTRACT`

Build identity recorded by RESULT:
- host SHA256 `CC1A9925742C112E0D7988CAE5F1769A097B414A38897867209F6E0454110798`
- proxy SHA256 `D92783BAD6AEFE2D3E29EF88937718B9CE973581BF057F1A99F9F5639C5E26AB`
- IPC ABI `T1FrameContract:196,T1Shared:1084`

Machine preflight verified exact retail hashes:
- Crysis2.exe `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

Restore:
`RESTORE_VERIFY = PASS`

## CORRECT INTERPRETATION

P6 is **EXECUTED / RED**, but it does **not** answer the intended 120 ms cadence question because the run failed earlier than pair production.

The host produced frame contracts, but the game-side renderer never latched a valid contract into a queued eye transaction.

This does NOT falsify RC33 true L/R, P5, stereo separation, camera math, HEAD, weapon, temporal or shadow candidates.

## CURRENT GATE

`MASTER 2 REGRESSION RECOVERY / CONTRACT LATCH`

Canonical first missing edge:
`HOST publish N -> GAME observes N -> GAME validates N -> GAME queues N`

The first unproven transition is game-side observation/validation/queueing of the published host contract.

Do not start MASTER 3 cadence K experiments while this edge is red.

## WORKING ANCESTOR

Last executed lineage that actually rendered and submitted exact pairs:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
SHA256 `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`

P5 RESULT:
- `pairs_completed/copies = 354/354`
- `exact_pair_consumes = 269`
- `host_submits = 269`
- `xr_frame_misses = 53`
- exact hit ratio `0.835404`
- `stale_pair_drains = 31`
- `pair_wait_ms_last = 31`
- `pair_wait_ms_max = 47`
- user visual: flashes/dropouts remained

## NEXT

Before any new BAT/PS1/build package:
1. recover the exact physical P5 package/runner bytes;
2. if unavailable, declare `SCRIPT_LINEAGE_GAP` rather than rebuilding launch/build/restore infrastructure;
3. fork only enough telemetry to prove host publish -> game observe -> validate -> queue;
4. keep OpenXR host architecture, IPC ABI, RC33 renderer, launcher, build, restore, logging and RESULT packaging unchanged;
5. once exact pair production/submission is green again, return to MASTER 3 pipeline-lead `K=0`, then `K=1`, then `K=2` one LIVE at a time.

HEAD, WEAPON/NEAR and TEMPORAL/SHADOW remain STOPPED until MASTER 3 transport acceptance is green.