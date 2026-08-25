# Crysis 2 VR — NEXT EXPERIMENT

## CURRENT GATE

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

## NEXT RUNTIME

`R1 HIDDEN T1 REPLAY`

Status:
`PREPARED / UNRUN`.

Package:
`CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`

Bytes:
`191925`

SHA256:
`330382153381C01CDE23FA15D777A6F54796F761D8DEC3F0A2BC2D07AC78EC79`.

Static validation only:
`R1_STATIC=PASS (70/70)`.

No runtime PASS is claimed.

Full experiment record:
`experiments/R1_HIDDEN_T1_REPLAY_PREPARED_20260825.md`.

## PREFLIGHT — exactly 5 lines

**MISSING FACT:** does hidden T1 private-eye replay itself perturb the historically stable v6 visible camera/world/shadow/temporal state?
**WHY THIS PARENT:** exact physical v6.0.1 is the strongest bounded world-stability anchor; exact T1 v1.0.1 is the proven private-L/R mechanical donor.
**PASS:** OFF_A stable, hidden replay mechanically executes during SPARSE/FULL, visible v6 output remains stable through SPARSE/FULL/OFF_B, isolation counters stay 0/0/0.
**FAIL:** OFF_A stable but replay phases trigger camera/world/shadow instability, or only FULL fails, or hidden isolation/mechanical execution fails.
**BASELINE MUST HOLD:** v6 x64 host/IPC/Present-cache/launch/build/restore are byte-identical; no PosePair/K/HEAD/weapon/NEAR/new temporal/shadow/submission policy.

## LINEAGE

BASE_PACKAGE:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

T1 DONOR:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`
SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`.

BASE_SCRIPT:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

UNCHANGED LAUNCH PATH:
YES, byte-identical.

UNCHANGED BUILD PATH:
YES, byte-identical.

UNCHANGED RESTORE PATH:
YES, byte-identical.

## PATCH

Only hidden x86 renderer replay is added.

Quest-visible output remains:
`V601_MONO_PRESENT_CACHE_UNCHANGED`.

Hidden private-eye contract:
```text
private_eye_publication=0
private_eye_shared_copy=0
private_eye_openxr_submit=0
```

No private T1 eye can become the headset image in R1.

## BUILD

Use only inherited:
`20_RUN_C2VR_FULL_VR.bat`.

No new launcher and no new PowerShell build path.

## RUN

Automatic phases after the first valid scene/center snapshot:

```text
0–10 s   OFF_A
10–25 s  SPARSE_1_OF_10
25–45 s  FULL
45–55 s  OFF_B
>55 s    DONE
```

Audio:
- 1 beep: SPARSE;
- 2 beeps: FULL;
- 3 beeps: OFF_B;
- long beep: DONE.

Use comparable head movement in every phase and judge only:
- world/camera stability;
- shadow/light stability;
- textures/objects;
- flicker/blanking.

If OFF_A is already bad, classify `R1_INVALID_BASELINE`.
If catastrophic corruption appears later, user may exit immediately; partial result is still evidence.

## RESULT_TEMPLATE

```text
LIVE_STATUS=LIVE/NOT_LIVE
OFF_A_VISUAL=STABLE/BAD/UNTESTED
SPARSE_VISUAL=STABLE/BAD/UNTESTED
FULL_VISUAL=STABLE/BAD/UNTESTED
OFF_B_VISUAL=STABLE/BAD/UNTESTED
PRIVATE_PUBLICATION=0/FAIL
PRIVATE_SHARED_COPY=0/FAIL
PRIVATE_OPENXR_SUBMIT=0/FAIL
REPLAY_PAIRS=<n>
SPARSE_PAIRS=<n>
FULL_PAIRS=<n>
TEMPORAL_LEAK=<n>
CENTER_RESTORE_COMMANDS=<n>
RESTORE=PASS/FAIL
RETAIL_HASHES_POST=PASS/FAIL
USER_HEADSET_VERDICT=R1_INVALID_BASELINE/R1_REPLAY_POISONS_STATE/R1_FULL_RATE_ONLY_BAD/R1_REPLAY_VISUALLY_INERT/UNTESTED
```

## PASS / FAIL

`R1_REPLAY_VISUALLY_INERT` authorizes R2 only: expose already-rendered private L/R under the same game-owned v6 contract.

`R1_REPLAY_POISONS_STATE` sends work back inside the x86 T1 replay/state restore transaction.

`R1_FULL_RATE_ONLY_BAD` sends work to replay scheduling/cadence/cost, not XR submission.

`R1_INVALID_BASELINE` invalidates the bisect and requires exact v6 baseline recovery first.

## FORBIDDEN

No K=1/K=2, final HEAD, weapon/NEAR, coordinate-sign LIVE, new temporal/shadow policy, new x64 host ownership, or PosePair descendant in this run.
