# C2VR — P6 startup/session-reentry contract-latch race — 2026-08-25

## Verdict

`COLD-CLOSED BLOCKER LOCALIZATION`

The executed P6 RED result does not indicate a broken RC33 eye renderer or IPC ABI. It exposes a startup/session-reentry ordering race in the game-side `dRC` gate.

## Exact packages/results

Known-good P5:
- package `CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
- bytes `82,867`
- SHA256 `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`
- raw RESULT `C2VR_RC33_V1721_RESULT_20260823_170445.zip`
- RESULT SHA256 `7B1CF8E0CBBF87930CE8FE8D810341527804C3AEC8C9C90999251F3186724DD2`
- `354/354` completed/copies
- `269` exact consumes
- `269` host submits
- exact hit ratio `0.835404`

Executed P6 RED:
- package `CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- bytes `85,852`
- SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`
- raw RESULT `C2VR_RC33_V1721_RESULT_20260825_012454.zip`
- RESULT SHA256 `0A4101E1C63E10EA57CD982A32A58918E8A2D263FAC64F794628D7E7B2514F07`
- game `custom_pairs_queued=0`, `pairs_completed=0`, `rt_scene_left/right=0/0`
- host `exact_pair_consumes=0`, `host_submits=0`
- fault `NO_LATCHED_RENDER_CONTRACT`

`BUILD_COMMANDS.log` from the P6 RESULT compiled directly from the P6 package source path, so the inherited `V1721` RESULT filename is not package identity.

## Source chain

P5 and P6 `src/t1_dual_render.cpp` are byte-identical.

In `t1_camera.cpp`, a center snapshot exists only after a RenderWorld call sees a live host/contract and publishes it:

```cpp
T1FrameContract fc={};
int have=T1_HostRunning()&&T1_ReadContract(&fc);
...
if(have&&apply_center_6dof(camera,fc)){
    publish_snapshot(camera,fc);
    ...
}
```

In the inherited `dRC` gate, once private eye targets are ready, absence of that first snapshot was treated as a permanent global fault:

```cpp
if(!T1_GetCenterCamera(center,sizeof(center),&cc)||
   !T1_GetSnapshotContract(&fc)){
    T1_Fault("NO_LATCHED_RENDER_CONTRACT");
    return;
}
```

`T1_HostRunning()` itself requires `!faulted`. Therefore one premature `dRC` call can set `faulted=1`, after which later RenderWorld calls can no longer enter the host-contract snapshot path. The temporary ordering miss becomes self-locking.

## Raw timing comparison

P5 recovery/re-entry:
- game `ENGINE_EYES_READY` at `17:05:48.925`
- host `XR_STATE 4/5` at `17:05:49.006`
- shared eyes ready at `17:05:49.076`
- by `17:05:49.835`: `pairs=18`, `rt=18/18`
- final: `354/354`

P6 recovery/re-entry:
- game `ENGINE_EYES_READY` at `01:25:48.700`
- game `FAULT NO_LATCHED_RENDER_CONTRACT` at the same `01:25:48.700`
- host does not reach `XR_STATE 4/5` until `01:25:48.858`
- shared eyes ready at `01:25:48.702`
- thereafter pairs remain `0`, RT remains `0/0`

The runner already starts the game only after an earlier valid host session. Both runs later show an OpenXR session transition and re-entry. Therefore this is more precisely a **startup/session-reentry rendezvous race**, not merely initial process-launch ordering.

## First missing edge

Canonical chain:

`HOST publish N -> GAME observes N -> GAME validates N -> GAME queues N -> LEFT -> RIGHT -> completion N -> HOST accepts N -> submit N`

The P6 failure occurs before `GAME queues N` because `dRC` permanently faults while the local RenderWorld snapshot is temporarily unavailable.

## Minimal recovery mutation

Do not change launcher, OpenXR host architecture, IPC, ABI, renderer bootstrap, restore path, packaging, HEAD, weapon, temporal or shadow policy.

Relative to executed P6, change only `src/t1_dual_render.cpp`:
- missing first snapshot is a fail-closed WAIT, not a global fault;
- render/submit no eye pair on that call;
- never reuse stale pixels;
- log once `WAIT_LATCHED_RENDER_CONTRACT fail_closed=1 fault=0`;
- allow a later RenderWorld to publish the first valid snapshot.

This is one causal mutation against the first missing edge.

## Lineage

Working ancestor is the exact physical P5 package and its raw RESULT above. `SCRIPT_LINEAGE_GAP` is CLOSED.

P5/P6 launcher and recovery files are byte-identical:
- `RUN_C2VR_V17_TRUE_LR.cmd` SHA256 `9CF526A7F08B19A2974B4FA454C23966768D7CC4C782CE46EF14ECA86353DCD4`
- `tools/Run-V17.ps1` SHA256 `AD6B3D7614700E2117F550AEB626D8432C88F9513924FEBA4524FA623237F6F5`
- `RECOVER_V17.cmd` SHA256 `53EF1565B315AB737176112E76DE31A329C9645184BB2B3C406D3C372D87B659`
- `tools/Recover-V17.ps1` SHA256 `CD020C2D50ACCE0818D487373E009DEF0477F23F53966D543596A500D5DF6C5F`

## Next gate

Run the minimal P6 latch-wait child once.

PASS for this recovery edge:
- no `NO_LATCHED_RENDER_CONTRACT` global fault;
- center inject/restore becomes nonzero;
- queued pairs become nonzero;
- LEFT and RIGHT become nonzero;
- completed pairs become nonzero;
- exact host consumes/submits become nonzero;
- exact retail hashes and restore remain PASS.

If that edge is green, evaluate the unchanged P6 120ms wait telemetry from the run and return to MASTER 3 cadence. HEAD remains blocked until MASTER 3 transport acceptance passes.