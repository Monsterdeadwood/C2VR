# C2VR — ANALYZER KNOWN BUGS

## 2026-08-25 — Z-reprojection v6.0.1 / RESULT 220427

Source result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

## BUG 1 — OpenXR transport false negative

Generated verdict:
`OpenXRTransport=FAIL submit=4691 gameCopies=4108 eyeStageCopies=0`.

Raw evidence from the same RESULT:

```text
XR_SESSION_CREATE_RETURN r=0
XR_SESSION_OK
XR_BEGIN_SESSION_OK
C2VR_Z_REPROJECT_STEREO_VISIBLE
submit_count=4691
ever_submitted=1
```

Classification:
`FALSE_NEGATIVE`.

Likely parser/logic risk:
using the final lifecycle snapshot `SESSION_RUNNING=0` after session shutdown as if it meant the session never ran.

Future analyzer should distinguish:

```text
SESSION_RUNNING_NOW
SESSION_EVER_BEGAN
EVER_SUBMITTED
SUBMIT_COUNT
```

A normal final stopped session must not erase earlier runtime success.

## BUG 2 — eye-stage copy counter false zero

Generated verdict:
`eyeStageCopies=0`.

Raw authoritative status:
`eye_stage_copies=9382`.

Classification:
`FALSE_NEGATIVE / WRONG FIELD OR PARSE PATH`.

Future analyzer must read the exact raw key and require the field to exist before assigning PASS/FAIL.

## BUG 3 — restore false negative

Generated verdict:
`Restore=FAIL`.

Raw restore record:

```text
RESTORE_OK=True
d3d11_restore=True
system_cfg_restore=True
```

Classification:
`FALSE_NEGATIVE / RESTORE PARSER BUG`.

Future analyzer must treat the explicit RESTORE record as authority for launcher restore status.

## REQUIRED ANALYZER CONTRACT

A generated summary may not override contradictory raw executed evidence.

For every PASS/FAIL field record:

```text
PREREQUISITE_EVIDENCE_COUNT = N
SOURCE_FILE                  = exact file
SOURCE_KEY                   = exact key/event
TARGET_PATH_EXECUTED         = YES/NO
VERDICT                      = PASS/FAIL/NA
```

If the prerequisite evidence is absent:
`NA/NOT_EXECUTED`, never PASS and never a guessed FAIL.

If final-state lifecycle differs from earlier runtime history, report both.

## PROCESS RULE

Patch analyzer logic as an isolated tooling task.
Do not combine analyzer repair with renderer/camera/stereo mutation in one LIVE.
