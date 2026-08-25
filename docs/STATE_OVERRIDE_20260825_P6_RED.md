# C2VR STATE OVERRIDE — 2026-08-25 — P6 EXECUTED / RED

This file overrides older statements that `v17.2.6 EXACT_BLOCK120 P6` was `PREPARED / UNRUN`.

## EVIDENCE PRIORITY

Raw executed RESULT wins over package README and older state summaries.

Raw RESULT:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`
SHA256 `0A4101E1C63E10EA57CD982A32A58918E8A2D263FAC64F794628D7E7B2514F07`

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

Machine preflight verified exact retail hashes and `RESTORE_VERIFY = PASS`.

## CORRECT INTERPRETATION

P6 is **EXECUTED / RED**, but it does **not** answer the intended 120 ms cadence question because the run failed earlier than pair production.

The failure is now COLD-localized more precisely as a startup/session-reentry rendezvous race. See:
`research/P6_STARTUP_LATCH_RACE_20260825.md`.

P5/P6 game-side `src/t1_dual_render.cpp` is byte-identical. The inherited `dRC` path permanently calls `T1_Fault("NO_LATCHED_RENDER_CONTRACT")` if private eye targets become ready before the first valid RenderWorld snapshot. `T1_HostRunning()` requires `!faulted`, so this temporary ordering miss becomes self-locking.

Raw P6 timing:
- game `ENGINE_EYES_READY` `01:25:48.700`
- game `FAULT NO_LATCHED_RENDER_CONTRACT` `01:25:48.700`
- host `XR_STATE 4/5` only at `01:25:48.858`

P5 survived the same re-entry region and then reached `354/354` pairs.

This does NOT falsify RC33 true L/R, stereo separation, camera math, HEAD, weapon, temporal or shadow candidates.

## CURRENT GATE

`MASTER 2 REGRESSION RECOVERY / CONTRACT LATCH RENDEZVOUS`

Canonical chain:
`HOST publish N -> GAME observes N -> GAME validates N -> GAME queues N -> LEFT -> RIGHT -> completion N -> HOST accepts N -> submit N`

The current recovery target is the transient pre-queue latch condition. Do not start MASTER 3 K experiments until exact pair production/submission is green again.

## WORKING ANCESTOR — PHYSICAL RECOVERY COMPLETE

`SCRIPT_LINEAGE_GAP = CLOSED`

Exact physical P5 package recovered:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
bytes `82,867`
SHA256 `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`

Exact raw P5 RESULT recovered:
`C2VR_RC33_V1721_RESULT_20260823_170445.zip`
SHA256 `7B1CF8E0CBBF87930CE8FE8D810341527804C3AEC8C9C90999251F3186724DD2`

P5 RESULT:
- `pairs_completed/copies = 354/354`
- `exact_pair_consumes = 269`
- `host_submits = 269`
- `xr_frame_misses = 53`
- exact hit ratio `0.835404`
- `stale_pair_drains = 31`
- `pair_wait_ms_last = 31`
- `pair_wait_ms_max = 47`
- visual flashes/dropouts remained

P5/P6 launcher/recovery hashes are byte-identical:
- `RUN_C2VR_V17_TRUE_LR.cmd` `9CF526A7F08B19A2974B4FA454C23966768D7CC4C782CE46EF14ECA86353DCD4`
- `tools/Run-V17.ps1` `AD6B3D7614700E2117F550AEB626D8432C88F9513924FEBA4524FA623237F6F5`
- `RECOVER_V17.cmd` `53EF1565B315AB737176112E76DE31A329C9645184BB2B3C406D3C372D87B659`
- `tools/Recover-V17.ps1` `CD020C2D50ACCE0818D487373E009DEF0477F23F53966D543596A500D5DF6C5F`

## NEXT CHILD

Candidate:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.7_P6_LATCH_WAIT_ONECLICK.zip`

Lineage:
- BASE_PACKAGE = exact working P5
- physical intermediate = executed P6
- P6 host 120 ms watchdog + passive telemetry retained unchanged
- runner/build/restore/logging/packaging retained byte-for-byte
- only first-party runtime delta relative to P6 = `src/t1_dual_render.cpp`

Mutation:
- temporary missing center camera/contract snapshot no longer sets global fault;
- it returns fail-closed without rendering/submitting an eye pair;
- no old pixels, no mono fallback;
- one log marker: `WAIT_LATCHED_RENDER_CONTRACT fail_closed=1 fault=0`;
- later RenderWorld can latch a valid contract and RC33 proceeds normally.

Cold validation:
- static `130/130 PASS`
- independent `98/98 PASS`
- IPC ABI `196/1084` unchanged

## NEXT LIVE PASS

Require at minimum:
- no `NO_LATCHED_RENDER_CONTRACT` global fault;
- `center_inject_ok > 0`
- `custom_pairs_queued > 0`
- `rt_scene_left > 0` and `rt_scene_right > 0`
- `pairs_completed > 0`
- `exact_pair_consumes > 0`
- `host_submits > 0`
- exact retail hashes PASS
- restore PASS

After this recovery edge is green, evaluate unchanged P6 120 ms timing telemetry and return to MASTER 3 cadence. HEAD, WEAPON/NEAR and TEMPORAL/SHADOW remain STOPPED until MASTER 3 transport acceptance is green.