# C2VR — OLD TAB ARCHAEOLOGY 2026-08-24

Purpose: preserve useful historical controls recovered from old conversation tabs / Library artifacts without overriding the current PosePair/P6 serial gate.

## Native +10° Matrix34 yaw control — recovered exact result
Artifact:
`C2VR_BREAKTHROUGH_CONTROL_YAW10_RESULT_20260823_044756.zip`

Target recorded by the result:
`CSystem=0x04985690 -> m_ViewCamera=0x04985A80 -> Matrix34 3x3 orientation`, applying a +10° CryEngine yaw only to the orientation basis around original `RenderInternal`.

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

## Current serial order remains unchanged
This archaeology import does **not** alter current state:
`P6 EXACT_BLOCK120 -> PosePair/timeliness verdict -> HEAD 1:1 -> WEAPON/NEAR -> temporal/shadow -> regression`.

## Promotion rule for future old-tab results
Classify every recovered artifact explicitly as:
- `PROVEN`
- `FALSIFIED`
- `MECHANICAL_ONLY`
- `PREPARED/UNRUN`
- `SUPERSEDED`
- `HISTORICAL TOOLING`

A clean counter/restore run without a valid visual/causal observation is never promoted to scientific PASS.