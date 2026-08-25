# Crysis 2 VR — STATE SYNC

## GLOBAL OVERRIDE — 2026-08-25 / 220427 LIVE

Every C2VR branch must read these before choosing a parent, planning a LIVE, writing a BAT/PS1, or changing renderer policy:

1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
3. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
4. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
5. `docs/FALSIFIED.md`
6. `docs/STATE.md`
7. `docs/NEXT.md`
8. `experiments/NEXT_EXPERIMENT.md`

For visual/playability acceptance:
`USER_HEADSET_VERDICT > deterministic captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > design intent`.

Bare `GREEN` remains forbidden.

`RESULT ZIP != LIVE` remains true, and the inverse is also important: a buggy generated summary must not erase raw proof that a LIVE actually executed.

## CURRENT GATE

`220427 V6.0.1 LIVE -> BIND USER HEADSET VERDICT -> VISUAL BASELINE DECISION`

Old text that says v6.0.1 PRIVATE_RTV is PREPARED/UNRUN is superseded.

Old PosePair/K, GOODLINE, R2/T1 visible-matrix, v17-whole-build and broad visual-rewrite gates remain superseded.

## FRESH RESULT

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Raw runtime facts:

```text
TARGET_RUNTIME_EXECUTED   = YES
XR_SESSION_RAN            = YES
XR_SUBMITS                = 4691
ever_submitted            = 1
eye_stage_ready           = 1,1
eye_stage_copies          = 9382
reproject_draws            = 9382
xr_capture_count           = 33
raw RESTORE_OK            = True
```

This mechanically closes the v6.0.0 direct-XR-RTV failure.

## EXACT ARCHITECTURE OBSERVED

Fresh headset source:

```text
CENTER scene color + inverse depth
 -> x64 host depth reprojection
 -> synthetic LEFT / RIGHT
 -> private typed eye RTs
 -> CopyResource to XR swapchain images
 -> Quest submit
```

No native/private independent scene-eye records were the source:

```text
native_eye_left_records  = 0
native_eye_right_records = 0
```

Classification:

```text
PRIVATE_RTV_XR_BRIDGE          = MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN
TRUE_PRIVATE_LR_SCENE_RENDER   = NO
USER_HEADSET_VERDICT           = UNBOUND
FULL_USER_VISUAL_GREEN         = NO
```

Mono RGB+depth/Z reprojection remains a diagnostic/control path, not the assumed final renderer.

## ANALYZER FALSE NEGATIVE

Fresh generated verdict says `OpenXRTransport=FAIL`, `eyeStageCopies=0`, `Restore=FAIL`, `PRIMARY_RESULT=PIPELINE_INCOMPLETE`.

Raw evidence from the same RESULT says:
- XR begin occurred;
- 4691 submits occurred;
- `ever_submitted=1`;
- `eye_stage_copies=9382`;
- raw restore is PASS.

Classification:
`ANALYZER_FALSE_NEGATIVE / SUMMARY_PARSER_BUG`.

Do not repeat the LIVE to satisfy a broken summary parser.
Do not repair the analyzer together with a renderer mutation.

## CURRENT FIRST MISSING FACT

`WHAT DID THE USER ACTUALLY SEE IN QUEST DURING 220427?`

Required direct verdict axes:
- world stability;
- camera/world lock;
- binocular fusion;
- world scale;
- shadows/light;
- RIGHT-eye quality;
- geometry/weapon behavior;
- overall ACCEPT/RED.

Until that is bound:
`NO NEW VISUAL CHILD`.

## DECISION AFTER USER VERDICT

### ACCEPT

Freeze the 220427 path as a component visual/control baseline.
Keep its private-RTV XR bridge unchanged.
Do not call mono+depth reprojection final.

Then isolate true-L/R/source-geometry integration as the next single mutation category.

### RED

Hard-stop v6.0.1 as a whole visual parent.
Salvage only `PRIVATE_RTV_XR_BRIDGE`.
Continue exact recovery of the historical user-accepted single-window profile.

Do not patch-number forward through later Z versions automatically.

## HARD REDS THAT MUST NOT REAPPEAR AS PARENTS

- `C2VR_RC33_V1721_RESULT_20260825_063149.zip`: live pairs but catastrophic camera/world + moving/sliding light/shadow state.
- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`: user said visually even worse.
- R2 `201208`: binocular/telescope visual catastrophe.
- GOODLINE v1.0.0 SHA `566BBBA4C9889DDD5B1F4974DF32330845EEE2F772B7EFD0469A9AF3DEFD07DA`: broken shadows + blurred RIGHT eye.
- native/NVIDIA/monitor-stereo final renderer.
- native stereo + real Quest IPD/FOV shortcut.
- all-SetCamera HMD feedback loop.
- DualWorld black-headset family.
- later uncontrolled Frankenstein merges.

## PARTIAL AUTHORITIES TO KEEP SEPARATE

### World stability
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Historical accepted property:
flicker gone; shadows/textures/objects stable; binocular fusion still failed.

### Camera ownership
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` plus single-source `Crysis2.exe+0x0057AC76` topology.

### True private L/R mechanics
`CUSTOM_DUAL_T1 v1.0.1 / CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.
Technical primitive only, not visual parent authority.

### Weapon direction
Keep only controller-directed firing donor facts from the accepted narrow evidence.

### Historical accepted behavior profile
One window; OpenXR dual eye; good world scale; stable head; headset image present; mainly hand/weapon wrong.
Exact package/hash remains OPEN. Never guess it from a neighboring version name.

## CROSS-BRANCH RULE

`SYNC -> AUDIT STATUS -> EXACT PARENT -> USER VERDICT -> ONE MISSING FACT -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP / ADAPT / STOP`

If current fresh user verdict is missing, bind it before creating another visual descendant.

## PARKED NOW

- K/PosePair;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- later Z descendants;
- convergence/IPD/FOV tuning;
- release optimization;
- broad reverse archaeology.
