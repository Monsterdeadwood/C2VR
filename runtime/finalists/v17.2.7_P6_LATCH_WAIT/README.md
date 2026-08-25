# C2VR v17.2.7 — P6 LATCH WAIT

Status: **COLD PASS / LIVE PENDING**.

Package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.7_P6_LATCH_WAIT_ONECLICK.zip`

SHA256:
`14DE36BC5F6B977AB076B06C571E41A48C255A13E803F3698DC3D6BA8BBB5AF7`

Size: `100,455` bytes.

## Lineage

BASE_PACKAGE = `CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`

BASE_SCRIPT = `RUN_C2VR_V17_TRUE_LR.cmd -> tools\Run-V17.ps1`

KNOWN_GOOD_RESULT = `C2VR_RC33_V1721_RESULT_20260823_170445.zip`

Physical intermediate = executed P6 `v17.2.6 EXACT_BLOCK120`.

P5/P6 launcher/build/restore scripts remain byte-identical. P7 does not create a new launcher, host, IPC protocol or renderer bootstrap.

## Only runtime delta relative to executed P6

`src/t1_dual_render.cpp` only.

Old behavior:
- if the first center-camera/contract snapshot was not yet latched after private eye targets became ready, `dRC` called global `T1_Fault("NO_LATCHED_RENDER_CONTRACT")`.
- `T1_HostRunning()` requires `!faulted`, so the transient ordering miss self-locked the run.

P7 behavior:
- missing first snapshot returns fail-closed;
- no eye pair is rendered/submitted for that call;
- no stale pixels or mono fallback;
- logs once `WAIT_LATCHED_RENDER_CONTRACT fail_closed=1 fault=0`;
- later RenderWorld may publish the valid snapshot.

P6 host `120 ms` watchdog and passive latency telemetry remain unchanged.

## Cold validation

- static validation `130/130 PASS`
- independent verification `98/98 PASS`
- ZIP CRC PASS
- IPC ABI unchanged: `T1FrameContract=196`, `T1Shared=1084`

## LIVE gate

PASS requires the first missing edge to recover:
`center latch -> queue -> LEFT -> RIGHT -> completion -> exact host consume -> submit`.

MASTER 3 K, HEAD, WEAPON/NEAR and TEMPORAL/SHADOW remain blocked until this recovery is green.

See `research/P6_STARTUP_LATCH_RACE_20260825.md`.