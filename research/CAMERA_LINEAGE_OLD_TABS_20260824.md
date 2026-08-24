# C2VR - recovered exact camera lineage from old TTD tabs

Date: 2026-08-24 archaeology import.

Purpose: preserve exact-retail camera lineage facts that existed only in older returned RESULT archives and were not present in the current GitHub corpus. This does not alter the current P6/PosePair serial gate.

## 1. Matrix34 orientation first-reader - PROVEN
Returned artifact:
`C2VR_BREAKTHROUGH_TTD_MATRIX_READER_RESULT_20260823_051824.zip`

Existing TTD target contract:
- selected `RenderInternal` hit #2 of 4;
- exact source CCamera `0x049C5AD8` in that trace;
- direct `RenderInternal` return landmark `Crysis2.exe+0x005E247B`.

Camera contract passed at the selected hit:
- FOV about `0.959931` rad;
- aspect about `1.3333`;
- near about `0.2400`.

Representative Matrix34 orientation fields tested:
- `CCamera+0x04`
- `CCamera+0x14`
- `CCamera+0x24`

All three produced the same concrete CPU reader before the direct RenderInternal return:

`Crysis2.exe+0x0016C993`

Returned result:
- `+0x04` stop EIP `0x0056C993`, read-before-return TRUE;
- `+0x14` stop EIP `0x0056C993`, read-before-return TRUE;
- `+0x24` stop EIP `0x0056C993`, read-before-return TRUE;
- `VERDICT: PROVEN`.

Classification:
**EXACT-RETAIL TTD LINEAGE PROVEN.**

Scope boundary:
This proves that the representative orientation components of the verified CCamera are consumed by the CPU at `+0x0016C993` before `RenderInternal` returns. It does not by itself prove that this reader is the final GPU/head ownership point.

## 2. Reader-time local copy identity
At the same exact reader, replay captured:
- `EBP = 0x049C5AD8` = verified source CCamera in that trace;
- `EBX = 0x0019E094` = local destination captured by the copy-reader experiment;
- `ESI = source+0x08` in the observed register layout;
- `EDI = destination+0x08` in the observed register layout.

The process addresses above are trace-local and must never be hardcoded. Reusable truth is the RVA/instruction role and source/destination relation.

## 3. Direct local-copy -> Renderer::SetCamera argument hypothesis - narrowly FALSIFIED
Returned artifact:
`C2VR_BREAKTHROUGH_TTD_COPY_TO_SETCAMERA_RESULT_20260823_061159.zip`

Frozen hypothesis:
After `+0x0016C993` creates/uses the stack-local camera copy, a later `Renderer::SetCamera` before `RenderInternal` return receives arg1 equal to that exact local destination, and the matching call returns through SetupCamera landmark `+0x0057AC76`.

Observed:
- copy EIP exact `+0x0016C993`;
- source EBP exact;
- local destination captured;
- no matching `Renderer::SetCamera` entry with `arg1 == captured destination` before the direct return.

Returned verdict:
`VERDICT: FALSIFIED`.

Scope boundary:
**Only the direct destination-as-SetCamera-arg handoff is falsified.**
The verified CCamera, Matrix34 reader and broader camera lineage remain valid.

## 4. v1.0.1 replay hotfix independently confirms the mismatch
Artifact:
`C2VR_BREAKTHROUGH_TTD_COPY_TO_SETCAMERA_RESULT_20260823_063916.zip`

The replay itself ended with an infrastructure marker because of a later debugger `.printf` syntax defect, so that archive is not promoted as a separate scientific verdict. However, before the script defect it captured the relevant exact trace data:

- `RenderInternal` camera = `0x049C5AD8`;
- reader `+0x0016C993`;
- local destination = `0x0019E094`;
- multiple `Renderer::SetCamera +0x00148340` entries before `RenderInternal` return;
- none had arg1 equal to `0x0019E094`.

Observed SetCamera return landmarks in that trace included:
- return `Crysis2.exe+0x0057AC76` with a different camera argument;
- `+0x00A0DC54`;
- `+0x00A0DD57`;
- `+0x00A80703`;
- `+0x00A8074B`;
- a renderer-side return.

This is supporting evidence for the narrow falsification above, not an additional independent PASS.

## 5. Old CSystem+0x420 TTD writer question remained unresolved by replay tooling
Several BT01 artifacts targeted:
`CSystem::m_ViewCamera.fov = CSystem+0x420`.

The later official x86 replay result successfully established:
- exact trace remained byte-identical;
- Crysis2.exe module base `0x00400000`;
- `CSystem::Render` candidate absolute `0x00496A40`;
- the old selective-trace positions `27D:0 / 637:0` cannot be treated as a CSystem::Render anchor.

Critically, the returned method note explicitly says:
**candidate CSystem+0x420 is NOT FALSIFIED**, because live CSystem was never derived and the required FOV write query was never actually made.

Classification:
**OLD TTD METHOD/TRACE LIMITATION / SEMANTIC WRITER QUESTION NOT TESTED.**

Current project impact:
Do not spend a new LIVE or broad replay cycle closing this historical writer question while P6 is the active gate. Current retail camera ownership/renderer architecture is already substantially stronger than this old branch.

## Current relevance
For future HEAD work after PosePair closes:
- `+0x0016C993` is a valid exact-retail CPU consumption landmark for the verified CCamera Matrix34 orientation;
- do not assume its local destination is passed directly to Renderer::SetCamera;
- prefer current upstream T1/SetupCamera/RenderWorld architecture and use this recovered reader only as an independent provenance cross-check.
