# C2VR - OLD TAB ARCHAEOLOGY 2026-08-24

Purpose: preserve useful historical controls recovered from old conversation tabs / Library artifacts without overriding the current PosePair/P6 serial gate.

## Native +10 degree Matrix34 yaw control - recovered exact result
Artifact:
`C2VR_BREAKTHROUGH_CONTROL_YAW10_RESULT_20260823_044756.zip`

Target recorded by the result:
`CSystem=0x04985690 -> m_ViewCamera=0x04985A80 -> Matrix34 3x3 orientation`, applying a +10 degree CryEngine yaw only to the orientation basis around original `RenderInternal`.

### Mechanical result
- target hits: `300`
- completed hits: `300`
- yawed basis survived: `300`
- exact orientation restores: `300`
- bypass hits: `0`
- inflight after disable: `0`
- callsite restored: `True`
- FOV/aspect/near baseline held: `True`
- process alive: `True`
- `YAW_CONTROL_MECHANICAL_PASS=True`

The result therefore proves the prepared mutation/restore mechanism executed deterministically and survived through the intended native path for all 300 hits.

### Scientific boundary
The same artifact records:
- `USER_VISUAL=U`
- `USER_DIRECTION=L`
- final `VERDICT: NO SCIENTIFIC RESULT`

Therefore this run is classified:

**MECHANICAL_ONLY / NO VISUAL OWNERSHIP PROOF.**

It must not be cited as proof that the chosen Matrix34 seam is the final headset-visible 1:1 HEAD owner.

Current project impact:
- preserve it as evidence that a bounded native orientation mutation/restore can survive the path cleanly;
- do not repeat the identical control while PosePair/P6 remains the current gate;
- after PosePair closes, HEAD work should converge on the existing T1 upstream center-camera mechanism first, using this historical control only as supporting transport/mutation evidence.

## TTD camera-cache lineage FAIL archives - scientific candidates were NOT EXECUTED
Recovered artifacts:
- `C2VR_BREAKTHROUGH_TTD_CAMERA_CACHE_LINEAGE_CLOSURE_RESULT_20260823_035844_FAIL.zip`
- `C2VR_BREAKTHROUGH_TTD_CAMERA_CACHE_LINEAGE_CLOSURE_RESULT_20260823_042741_FAIL.zip`

Frozen target in both:
16-field renderer camera/projection cache bank, intended to recover stable writer-to-reader temporal lineage from already-known RT_SetCameraInfo/thread sources toward later shader/CB consumption in an existing trace.

The filename suffix `_FAIL` is **not a scientific falsification**.

### 035844 result
Its own `FAIL.txt` says:
- `OBSERVED: MECHANICAL_FAILURE`
- `VERDICT: NOT_EXECUTED`
- `NEXT: fix replay transport only; no scientific candidate budget spent`
- reason: Microsoft.WinDbg AppX package/replay transport missing.

### 042741 result
Its own `FAIL.txt` also says:
- `OBSERVED: MECHANICAL_FAILURE`
- `VERDICT: NOT_EXECUTED`
- no debugger candidate passed a real TTD replay probe.

The bundled x86/x64 cdb probes attempted to load the `.run` file as a dump and reported `Could not match Dump File signature / invalid file format`, Win32 error 87.

Classification:
**INFRASTRUCTURE / REPLAY TRANSPORT FAILED / SCIENTIFIC CACHE CANDIDATES NOT TESTED.**

Do not mark any of the 16 cache fields FALSIFIED from these archives.

## BT01 CSystem+0x420 FOV writer replay - transport progressed, semantic verdict still unassigned
Recovered artifacts:
- `C2VR_BT01_TTD_REPLAY_OWNER_WINDDBG_TOOL_RESULT_20260823_035919.zip`
- `C2VR_BT01_TTD_REPLAY_OWNER_WINDDBG_TOOL_RESULT_20260823_042844.zip`

Frozen target:
`CSystem::m_ViewCamera.fov / CSystem+0x420` upstream writer before `CSystem::Render` -> `RenderWorld+0x5E2360`.

Trace identity retained by the returned artifacts:
`34877319449D3693792FC47B8F6410861866A9F844C384F7505EED505A22AE1E`.

### 035919 / FIX7
Replay transport failed before semantic evaluation:
- daemon command invocation returned failure;
- handoff records `REPLAY_TRANSPORT=WINDDBG_TOOL_COMMAND_FAILED`;
- `SEMANTIC_VERDICT=NOT_ASSIGNED`.

### 042844 / FIX8
This fixed the PowerShell `$args`/argument-vector collision and successfully:
- ensured daemon;
- opened the exact TTD trace;
- obtained session/cursor;
- queried info/architecture/capabilities/index state;
- moved replay position.

It then failed to resolve the Crysis2.exe module base because the modules invocation/parser contract was still wrong. Handoff records:
- `REPLAY_TRANSPORT=MODULE_BASE_PARSE_FAILED`
- `SEMANTIC_VERDICT=NOT_ASSIGNED`.

Classification:
**INFRASTRUCTURE / REPLAY TOOLING PROGRESS / FOV-WRITER OWNERSHIP QUESTION STILL OPEN IN THAT OLD BRANCH.**

No extra LIVE is justified today merely to close it because current T1/PosePair work already has stronger camera/render architecture and the serial gate is P6.

## Early RC33 v17.2.1 progression - compile failure then real two-pass runtime before shared-resource blocker
Two old returned results show a useful implementation staircase.

### `C2VR_RC33_V1721_RESULT_20260823_041450.zip`
Mechanical preflight and x64 host build passed, but x86 `t1_proxy.cpp` failed to compile because `adopt_device` was undeclared.

The artifact correctly classified itself:
- `AUTOMATED_GATE=RED`
- `RUN_CLASS=INFRASTRUCTURE_ONLY`
- `PRIMARY FACT = NOT RESOLVED`
- `FALSIFIED: None newly falsified by this RESULT`.

Classification:
**INFRASTRUCTURE BUILD FAILURE.**

It is not negative evidence against RC33 true L/R.

### `C2VR_RC33_V1721_RESULT_20260823_044015.zip`
A later compile-fixed build reached real runtime and proves several mechanical RC33 components executed before a concrete transport/resource blocker:
- `architecture=RC33_TWO_PASS_TRUE_LR`
- `renderworld_calls=1083`
- `custom_pairs_queued=2`
- eye camera LEFT/RIGHT ok `2/2`, failures `0/0`
- axis guard `last_axis_dot=1.000000`
- RT push LEFT/RIGHT `2/2`
- RT scene LEFT/RIGHT `2/2`
- temporal snapshot/restore LEFT/RIGHT `2/2`
- right shadow skip `2`
- pose/frame/contract mismatch counters `0`

The run then hit a concrete blocker:
`FAULT CREATE_DIRECT_EYE_SHARED_FAILED`.

Consequences:
- `direct_pair_copies=0`
- host consumed/submitted `0`
- pair MAE remained unavailable/zero
- PRIMARY scientific true-L/R integration fact stayed unresolved.

The analyzer itself states:
- `RUN_CLASS=LIVE`
- `PRIMARY FACT = NOT RESOLVED`
- `VISUAL_SUCCESS_CLAIMED=NO`.

Classification:
**MECHANICAL RC33 TWO-PASS SUBSYSTEM SUPPORT / DIRECT SHARED-EYE RESOURCE TRANSPORT FAILURE / NO SCIENTIFIC STEREO PASS.**

This old blocker was later superseded by T1, where private eye RTs/direct copies/OpenXR submits and non-duplicate L/R images were proven. Therefore do not reopen `CREATE_DIRECT_EYE_SHARED_FAILED` as a current problem.

## Current serial order remains unchanged
This archaeology import does **not** alter current state:
`P6 EXACT_BLOCK120 -> PosePair/timeliness verdict -> HEAD 1:1 -> WEAPON/NEAR -> temporal/shadow -> regression`.

## Promotion rule for future old-tab results
Classify every recovered artifact explicitly as:
- `PROVEN`
- `FALSIFIED`
- `MECHANICAL_ONLY`
- `INFRASTRUCTURE`
- `PREPARED/UNRUN`
- `SUPERSEDED`
- `HISTORICAL TOOLING`

A clean counter/restore run without a valid visual/causal observation is never promoted to scientific PASS. A debugger/build/parser failure never falsifies a scientific target unless the scientific prediction was actually exercised with valid plumbing.