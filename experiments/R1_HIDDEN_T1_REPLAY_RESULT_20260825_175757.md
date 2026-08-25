# C2VR R1 — HIDDEN T1 REPLAY — LIVE RESULT 2026-08-25 17:57:57

## STATUS

`LIVE / MECHANICAL PASS / USER PHASE VISUAL VERDICT NOT FULLY BOUND`

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`

SHA256:
`E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`

## RAW MECHANICAL RESULT

- phase reached `DONE`; experiment_done=1.
- hidden private replay pairs: 824.
- LEFT / RIGHT eye builds: 824 / 824.
- SPARSE pairs: 96.
- FULL pairs: 728.
- RT scene LEFT / RIGHT: 824 / 824.
- temporal snapshot LEFT / RIGHT: 824 / 824.
- temporal restore LEFT / RIGHT: 824 / 824.
- temporal leak: 0.
- pose mismatch: 0.
- center restore commands: 824.
- hidden replay fault: none.

Isolation remained exact:
```text
private_eye_publication=0
private_eye_shared_copy=0
private_eye_openxr_submit=0
```

Visible headset transport intentionally remained the inherited v6 mono path:
`MONO_BACKBUFFER_TO_TWO_OPENXR_EYES`.

Saved visible L/R XR captures were duplicate by design; this run did NOT test visible true stereo.

## VERDICT

R1 closes the mechanical question that T1 private LEFT/RIGHT replay can execute under the v6 world owner with balanced eye passes and exact temporal restore without requiring publication of those private eyes.

It does NOT establish binocular fusion or whole-build visual GREEN.

The next useful diagnostic is a bounded R2 visible-source mux that preserves the exact v6 world owner and exposes the already-rendered private L/R through the inherited safe Present/OpenXR transport, with internal baseline and recovery controls.

No PosePair/K/final HEAD/weapon/NEAR/new temporal-shadow policy is authorized by this result.