# C2VR — Z-REPROJECTION v6.0.1 LIVE RESULT 20260825_220427

Date: 2026-08-25

## RESULT IDENTITY

Result archive:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

Result ZIP SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Result ZIP bytes:
`24512034`

Runtime path was the recovered historical v6.0.1 lineage:
`CRYSIS2VR_RECOVER_EXACT_V601_PRIVATE_RTV_v1.0.0/RECOVERED_EXACT_V601_PRIVATE_RTV/CRYSIS2VR_Z_REPROJECTION_v6.0.1`

Expected historical child package from the recovery plan:
`CRYSIS2VR_Z_REPROJECTION_v6.0.1_PRIVATE_RTV_BRIDGE.zip`

Expected historical child SHA256:
`E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A`

Important provenance qualification:
the fresh RESULT proves the runtime/path execution and behavior below. The source ZIP SHA is the hash-bound recovery target from project state; the RESULT itself does not independently re-emit that source ZIP SHA, so do not pretend the RESULT alone re-proves package identity.

## RAW LIVE FACTS

Target runtime executed.

OpenXR host log proves:
- Oculus OpenXR runtime active;
- Quest 3 active;
- XR session creation succeeded;
- `XR_BEGIN_SESSION_OK` occurred;
- private eye staging became ready;
- `Z_REPROJECT_PIPELINE_READY` occurred;
- eye swapchains became ready in `PRIVATE_RTV_COPY_TO_XR` mode;
- first mono+depth synthesized stereo frame was submitted to Quest;
- XR capture recorder saved 33 stereo pair captures.

Raw status counters:

```text
SESSION_OK                 = 1
ever_texture_opened         = 1
ever_submitted              = 1
submit_count                = 4691
copy_count                  = 4108
eye_stage_ready             = 1,1
eye_stage_copies            = 9382
reproject_ready              = 1
reproject_draws              = 9382
xr_capture_count             = 33
native_pair_active           = 0
native_eye_left_records      = 0
native_eye_right_records     = 0
```

Game-side status:

```text
transport                    = MONO_CENTER_RGBA16F_RGB_PLUS_INVZ
mono_pair_valid               = 1
pack_frames                   = 4109
pack_draws                    = 4109
host_consumed_frame_seq       = 4108
camera_locked                 = 1
pose_valid                    = 1
ipd_mm                        = 62.8501
```

Camera/world instrumentation:

```text
HMD center 6DoF applied       = 4160
wide mono union camera        = 4160
```

Raw restore record:

```text
RESTORE_OK=True
d3d11_restore=True
system_cfg_restore=True
```

## ARCHITECTURE TRUTH

This LIVE is NOT true native/private LEFT+RIGHT scene rendering.

Actual headset source:

```text
ONE center scene
  -> RGBA16F color + inverse scene depth
  -> x64 OpenXR host
  -> depth reprojection synthesizes LEFT and RIGHT
  -> private typed eye RTs
  -> CopyResource into acquired XR swapchain images
  -> xrEndFrame
```

Therefore this result proves a working XR output bridge and synthetic stereo path, not final true-L/R renderer correctness.

Native Cry stereo was not the headset source in this LIVE:

```text
native_eye_left_records  = 0
native_eye_right_records = 0
```

## XR CAPTURE FACT

The RESULT contains 33 recorded stereo pair captures.

Offline pair inspection shows LEFT and RIGHT are not simple duplicates. This is compatible with the depth-reprojection implementation, but it is NOT binocular-fusion or headset-acceptance proof.

User headset verdict for this fresh LIVE is currently:
`UNBOUND`.

Do not infer ACCEPT from captures or counters.

## ANALYZER CONTRADICTION — IMPORTANT

`Z_REPROJECTION_VERDICT.txt` printed:

```text
OpenXRTransport=FAIL submit=4691 gameCopies=4108 eyeStageCopies=0
Restore=FAIL
PRIMARY_RESULT=PIPELINE_INCOMPLETE
```

Those fields conflict with the raw status/log evidence from the same RESULT:

```text
XR_BEGIN_SESSION_OK          = observed
ever_submitted               = 1
submit_count                 = 4691
eye_stage_copies             = 9382
RESTORE_OK                   = True
d3d11_restore                = True
system_cfg_restore           = True
```

Classification of these verdict fields:
`ANALYZER_FALSE_NEGATIVE / SUMMARY_PARSER_BUG`.

Likely failure mode to investigate later:
- judging transport from final `SESSION_RUNNING=0` lifecycle snapshot rather than `ever_submitted`/submit history;
- reading the wrong eye-stage counter/field;
- restore parser not consuming the authoritative RESTORE record.

Do NOT repair the analyzer during this visual-gate sync. Record the contradiction first, then patch it as a separate deterministic task.

## WHAT THIS LIVE CLOSED

The narrow historical v6.0.0 blocker:

`XR_RTV_CREATE_FAIL eye=0 image=0 hr=0x80070057`

is mechanically closed by the v6.0.1 private RTV bridge.

Fresh runtime proves:

```text
private typed eye staging
-> CopyResource to XR swapchain
-> real Quest submits
```

works in the target environment.

Therefore:
`XR RTV / PRIVATE STAGING BRIDGE` is no longer the first missing edge.

Do not rebuild this bridge merely because the visual renderer is still unresolved.

## WHAT THIS LIVE DID NOT CLOSE

Still unproven until the user's direct headset verdict is bound:
- whole-build visual acceptance;
- binocular fusion;
- comfortable stereo geometry;
- stable world under head motion in headset;
- shadow/light stability in headset;
- absence of pathological RIGHT-eye softness;
- final renderer architecture;
- true private/native L/R scene rendering.

The project-wide previous rule remains active:
`mono RGB+depth/Z reprojection is not the final renderer architecture`.

This LIVE may be kept as a transport/control component even if its whole visual output is later rejected.

## CLASSIFICATION

```text
LIVE_STATUS                         = LIVE
TARGET_RUNTIME_EXECUTED             = YES
XR_SESSION_RAN                      = YES
XR_SUBMITS                          = YES / 4691
PRIVATE_RTV_XR_BRIDGE               = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT      = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER        = NO
USER_HEADSET_VERDICT                = UNBOUND
FULL_USER_VISUAL_GREEN              = NO
ANALYZER_PRIMARY_RESULT             = NOT AUTHORITATIVE FOR TRANSPORT/RESTORE
```

## CURRENT GATE AFTER 220427

`BIND 220427 USER HEADSET VERDICT / VISUAL BASELINE DECISION`

No new renderer mutation should be made until the fresh in-headset result is explicitly classified.

### If user ACCEPTS the visual result

Freeze this exact LIVE as a component visual/control baseline.

Do NOT promote mono+depth reprojection to final renderer merely because it looks acceptable.

The next causal question becomes source geometry / true-LR integration while preserving the now-proven XR bridge.

### If user REJECTS the visual result

Classify the whole v6.0.1 visual parent `VISUAL_RED`.

Keep only the proven narrow donor:
`PRIVATE_RTV_XR_BRIDGE`.

Then continue recovery of the exact historical user-accepted single-window behavior profile instead of tuning this Z-reprojection renderer indefinitely.

## FORBIDDEN NEXT MOVES UNTIL VERDICT

- no K/PosePair;
- no R2/T1 visible descendant;
- no GOODLINE descendant;
- no v17 whole-build resurrection;
- no arbitrary IPD/FOV/convergence tuning;
- no broad weapon/NEAR rewrite;
- no temporal/shadow mutation;
- no analyzer-driven claim that the runtime never submitted.

One fresh LIVE. One explicit user verdict. Then KEEP / ADAPT / STOP.
