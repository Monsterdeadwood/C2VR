# C2VR — OpenXR ↔ Cry local-X evidence conflict

Status: **OPEN / COLD ONLY.** Do not spend a LIVE on this while PosePair P6 is the active gate.

## Why this exists
Two real evidence lines disagree about the sign of local X. Neither may be erased or promoted to universal truth yet.

## Path A — historical RESULT `20260817_003329`
`XR_EYE_CAMERA.tsv` reported `1722` complete applied L/R pairs:
- median stock CryEngine L/R separation `0.02220543`
- median exact Quest L/R separation `0.06677189`
- median dot(`stock R-L`, `exact R-L`) `-0.9999997`
- historical analysis concluded stock `R-L` aligns with `-CCamera basis column 0`
- this led to reflected mapping `XR (x,y,z) -> Cry (-x,-z,+y)`

The numeric result is real evidence. Do not discard it.

## Path B — retail/static + later working lineage
Retail `ProcessScene` closure:
- `ProcessScene +0x00123EA0`
- LEFT SetCamera return `+0x0012412A`
- LEFT `EF_Scene3D +0x0012413C`
- RIGHT SetCamera return `+0x00124304`
- RIGHT `EF_Scene3D +0x0012430F`

Retail decompile shows the LEFT path building a negative local-X translation before SetCamera. `FUN_1006ED10` is camera-copy/assignment-like; `FUN_1006F790` remains the main eye-transform helper requiring exact semantic closure.

Cry stereo source/donor semantics use LEFT `-halfIPD`, RIGHT `+halfIPD` followed by camera-matrix local-X translation.

Later working lineage `CRYSIS2VR_UNIFIED_NEAR_PROJECTION_v10.0.0_COUNCIL_RESET` uses:
`XR (x,y,z) -> Cry (+x,-z,+y)`
for frame-contract translation, and that lineage is associated with the visually improved result `CRYSIS2VR_UNIFIED_NEAR_PROJECTION_RESULT_20260818_034749.zip`.

## Current hypotheses
1. `003329` stock-eye labeling/classifier may have been reversed at that logger stage.
2. CCamera basis column/row semantic interpretation may have been wrong while the measured dot remained correct.
3. Later `+X` lineage may compensate elsewhere, so visual success alone cannot falsify `003329`.

Later code is known to use exact return-RVA eye classification, but this does not prove the exact `003329` writer used the same classifier.

## Current policy
- Treat universal `XR +X -> Cry -X` as **not settled**.
- Treat universal `XR +X -> Cry +X` as **not settled**.
- Preserve both evidence paths.
- Do not change P6 for this question.
- Before future HEAD/eye-position mutation, resolve COLD by either:
  - recovering the exact `003329` writer/classifier source; or
  - closing exact semantics of retail `FUN_1006F790` eye transform.

This conflict affects future HEAD/eye-position math, not the current PosePair timing gate.
