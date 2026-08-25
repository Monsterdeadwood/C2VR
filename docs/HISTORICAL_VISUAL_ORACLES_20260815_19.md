# C2VR — HISTORICAL VISUAL ORACLES — 15–19 AUGUST 2026

## PURPOSE

This file reconstructs C2VR history from the user's headset verdicts, raw RESULTs, physical package identity, and exact runner lineage.

The purpose is not nostalgia. It prevents a future branch from resurrecting a visually failed architecture because an old ZIP was called `GOLD`, `MAIN`, `CLEAN`, `NO_BINOCULAR`, or because a RESULT ZIP existed.

For visual/playability acceptance:

`USER_HEADSET_VERDICT > XR_CAPTURE > RAW LIVE RESULT > counters > package README > intended architecture`

A technical fact may be KEEP while the whole package is VISUAL RED.

## NEW GLOBAL IDENTITY RULE

`RESULT ZIP != LIVE`.

A RESULT archive counts as a visual/runtime experiment only if the game/runtime actually executed the experiment being claimed.

At minimum distinguish:

```text
PACKAGE_EXISTS
BUILD_ATTEMPTED
GAME_LAUNCHED
XR_SESSION_RAN
TARGET_CODE_EXECUTED
HEADSET_IMAGE_EXISTED
USER_HEADSET_VERDICT
```

A ZIP containing only `FAILURE.txt`, build logs, or preflight output must never enter visual lineage as a tested build.

---

# 1. EARLY BRING-UP — OPENXR ALIVE WAS NOT VR

## 1.1 Mouse-look / SendInput head control

Early bring-up used:

`HMD yaw/pitch -> SendInput mouse-look -> Crysis game camera`

The user observed that head motion changed the view, but it behaved like mouse look rather than a spatial VR camera.

KEEP:
- OpenXR pose acquisition;
- input plumbing;
- launch/injection evidence.

STOP:
- mouse emulation as final HEAD ownership;
- treating mouse-like yaw/pitch as true roll/6DoF.

## 1.2 `C2VR_NATIVE_MVP_v0.1.2`

User-observed state:
- game loaded;
- HMD movement affected view;
- headset was black.

Classification:
`TECHNICAL_BRINGUP_KEEP / VISUAL_HARD_RED`.

Permanent lesson:
`OPENXR_SESSION_ALIVE != VISIBLE_VR`.

## 1.3 First visible two-eye transport

The first visible eye output established another trap.

User verdict:
- image existed;
- effectively “two screens in two eyes”;
- horizon/world did not remain spatially locked when head rotated/tilted.

Permanent lesson:

`TWO_EYE_TEXTURES != VR`

and

`NON_DUPLICATE_LR != FUSED_STEREO`.

---

# 2. EARLY NATIVE x64 HOST LINEAGE — FALSE GOLD CORRECTION

## 2.1 `194212`: strong XR transport proof, NOT visual GOLD

Historical tested package lineage:
`CRYSIS2VR_C2_NATIVE_OPENXR_X64_v1.0.4.1_ZIG_AUTOFIND`

Result:
`CRYSIS2VR_C2_NATIVE_RESULT_20260815_194212.zip`

The run genuinely proved substantial infrastructure:
- x64 OpenXR session alive;
- Crysis shared texture opened;
- native SBS image reached headset;
- submit/copy counts were live;
- pose valid;
- physical Quest IPD present;
- 19 OpenXR L/R captures existed;
- later captures were non-identical.

But the same handoff recorded:
- `NativeProjectionLock=False`;
- `CameraLock=False`;
- `CameraInject=False`;
- `HORIZON_WORLD_LOCK=No`;
- user sees a flat image;
- no true roll/world lock.

Old collectors placed this material under labels such as `EVIDENCE/GOLD` / `MAIN_PROVEN_XR`.

That old label is now formally corrected.

Classification:
`XR_TRANSPORT_TECHNICAL_PROOF = KEEP`
`VISUAL_WORLD_LOCK = FAIL`
`VISUAL_GOLD = NO`.

Permanent lesson:
A true L/R headset image can still be a flat non-world-locked presentation.

## 2.2 Pose-relabel semantic failure

The early flat-image behavior exposed a semantic contract error:
- Crysis render camera was not yet HMD-driven;
- current HMD pose was nevertheless supplied as the OpenXR projection-view pose for pixels rendered from a different/static camera.

The compositor was therefore told that the pixels had been rendered from the current head pose when they had not.

Permanent STOP:

`OLD/STATIC PIXELS + CURRENT HMD POSE = INVALID CONTRACT`.

Pixels + render pose + FOV + ticket/contract identity are one atomic truth unit.

## 2.3 Physical `v1.0.5 WORLDLOCK_DIRECT_CAMERA` recovered

Exact physical package recovered from Library:

`CRYSIS2VR_C2_NATIVE_OPENXR_X64_v1.0.5_WORLDLOCK_DIRECT_CAMERA.zip`

Size:
`95,604 bytes`

SHA256:
`6D4D9D7120C43111AAA84FC0A36BE65BE4E83617E321B6FD9F390D26A52727B0`

Runner lineage:
`START_C2VR_v1.0.5.bat -> tools/Build-And-Run.ps1`.

Intended behavior:
- before native camera lock, use a frozen/recentered layer pose instead of falsely relabelling static pixels with current HMD pose;
- after camera lock, use HMD-driven Crysis camera plus current OpenXR eye pose;
- accept a broader Matrix34 camera fingerprint for camera locking.

Important: package intent is NOT proof of a successful LIVE.

## 2.4 `010051` was NOT a VR test

Physical result recovered:

`CRYSIS2VR_C2_NATIVE_RESULT_20260816_010051.zip`

Size:
`676 bytes`

SHA256:
`FC65F37E1B5F70F424866B99650C8B66FEA6A54EAD7C5434FFF32A736FB16216`

Contents:
- `BUILD_RUN.log`
- `FAILURE.txt`

Failure:
`Downloaded Zig failed its version self-test.`

Recorded state:
`GameFilesTouched=False`.

Therefore:
- Crysis did not test world-lock;
- OpenXR did not test the new camera policy;
- no user visual conclusion exists for this run.

Classification:
`BUILD/TOOLCHAIN_FAIL / NOT_LIVE / NOT_VISUAL_EVIDENCE`.

## 2.5 Physical `v1.0.5.1_ZIG_PORTABLE_FIX` recovered

Package:
`CRYSIS2VR_C2_NATIVE_OPENXR_X64_v1.0.5.1_ZIG_PORTABLE_FIX.zip`

Size:
`98,478 bytes`

SHA256:
`546A5C63D951E9C5A5B7C82922C4DAB14D0B6992B72535A2999154E3EFA2FF21`

Its own README explicitly states that `010051` did not test Crysis or OpenXR at all.

The world-lock/direct-camera experiment remained behaviorally unchanged from v1.0.5; this child repaired Zig/toolchain discovery only.

Classification:
`BUILD_FIX = KEEP`
`WORLDLOCK_VISUAL_VERDICT = OPEN`.

No recovered evidence currently promotes v1.0.5/v1.0.5.1 to a user-accepted visual checkpoint.

## 2.6 Physical `v1.0.6_OBSERVATORY_DEEP` recovered

Package:
`CRYSIS2VR_C2_NATIVE_OPENXR_X64_v1.0.6_OBSERVATORY_DEEP.zip`

Size:
`104,932 bytes`

SHA256:
`7B4907F04865A7A6E8AFC4B578FB955420123B93C1B12DF4A90EE7556446E1E3`

This was instrumentation around the same v1.0.5 world-lock experiment, not an independently accepted visual architecture.

Classification:
`OBSERVABILITY_CHILD = KEEP`
`VISUAL_PASS = NOT ESTABLISHED`.

## 2.7 `011323` cleanroom result was also NOT LIVE

Physical result:
`CRYSIS2VR_C2_NATIVE_RESULT_20260816_011323.zip`

Size:
`3,774 bytes`

SHA256:
`432E36FB784315A74A8BA6245FDC82B249B08877AC57F569CB6434C34601DAFF`

Result belonged to the early cleanroom x64-host lineage.

Failure:
`No x64 OpenXR loader found in the Crysis2 cache, Windows System32, or Oculus runtime.`

Recorded:
`GameFilesTouched=False`.

Classification:
`PREFLIGHT/LOADER_FAIL / NOT_LIVE / NOT_VISUAL_EVIDENCE`.

A later package `CRYSIS2VR_C2_CLEANROOM_OPENXR_X64_v1.1.2_LOADER_SELFPROVISION.zip` exists, but a fresh user visual verdict is not yet bound here.

---

# 3. CAMERA FEEDBACK FAILURE

## `171947` all-SetCamera injection

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_171947.zip`

User observation:
- eyes nearly collapsed to the same image;
- camera accumulated/moved incorrectly.

Runtime proof:
- 52,170 adjacent camera-pair observations;
- 99.837% `next_camera_input == previous_injected_output`;
- median matrix error 0.

Failure:

`G -> G*HMD -> G*HMD^2 -> G*HMD^3 ...`

Permanent STOP:
Never apply HMD at every downstream `Renderer::SetCamera`.

Salvage:
The later once/logical-frame single-source ownership around `Crysis2.exe+0x0057AC76` remains useful.

---

# 4. EXACT EYE MATH WAS NOT A VISUAL PASS

## `203734 / 204156`

These runs were historically over-promoted because their telemetry looked excellent:
- real HMD XYZ/6DoF;
- very accurate Quest IPD propagation;
- exact XrView FOV propagation.

Saved XR captures later corrected the interpretation.

Critical within-run control from `204156`:
- `camera_locked=0`: image looked normal;
- after `camera_locked=1`, even a small HMD rotation produced huge black near/viewmodel blades and broken geometry.

Recovered mechanism:
- world camera near plane around `0.12`;
- `FOB_NEAREST` near plane around `0.03`;
- world-eye asymmetry was inherited into the near camera instead of being recomputed for its near plane;
- near off-axis effect therefore became roughly 4x too strong;
- visibility was still prepared from a narrower center frustum before wider Quest eye views, producing culling/popping/disappearing geometry.

Classification:
`POSE/IPD/FOV MATH = KEEP`
`SURROUNDING EXACT-EYE RENDERER = VISUAL RED`.

Permanent lesson:
Perfect pose/IPD/FOV counters do not promote the renderer around them.

---

# 5. NATIVE / NVIDIA / MONITOR-STEREO FAMILY

## `205430`

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_205430.zip`

User verdict:
- flicker;
- wrong stereo;
- shadows disappeared/changed;
- eye-dependent lighting/state instability.

Saved L/R captures corroborated non-parallax disagreement in lighting/shadow/near state.

Permanent STOP:
Do not convert the monitor-oriented native stereo into final VR merely by grafting real Quest IPD/FOV onto it.

## `STABLE_CAMERA v2.2.0 / 010329`

Even after simplifying camera policy heavily, the user still reported severe image flicker. Weapon could move in hand while firing still followed monitor/game center.

Permanent lesson:
Simpler camera ownership does not repair a binocularly incoherent renderer by itself.

## `A1_HISTORY_FIX_RESULT_20260817_175934`

User verdict separated two systems very clearly:
- controller hand/weapon could be crooked but fired along weapon direction;
- image remained the bad two-image flickering Nvidia/CryEngine stereo;
- old renderer should be thrown away.

Classification:
`WEAPON_DIRECTION_COMPONENT = KEEP`
`SURROUNDING RENDERER = HARD RED`.

---

# 6. FALSE GOLD — REWRITE v4.0.0

Package:
`CRYSIS2VR_REWRITE_v4.0.0_EXACT_XR_STEREO_GOLD_WEAPON_PORTABLE.zip`

SHA256:
`08A8C4238EDC8046C2B46A3BECA1D19A86825DE9FE8C2ACADE62B2CF51047BB6`

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_023510.zip`

Immediate user verdict rejected both image and hand behavior.

Classification:
`USER_VISUAL_HARD_RED`.

Permanent lesson:
`GOLD_WEAPON` in a filename has zero evidentiary value.

---

# 7. A1 NATIVE REPAIR — CAMERA-CLOSER REFERENCE

Result:
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

User observation:
- head left/right drove the in-game camera/world;
- main remaining problem was flicker / two-screen behavior;
- state was described as very close.

Classification:
`CAMERA_OWNERSHIP_REFERENCE_ONLY`.

Do not inherit its native/Nvidia final stereo.

---

# 8. v6.0.1 — PHYSICALLY RECOVERED WORLD-STABILITY BASELINE

This is now an exact recovered carrier, not a memory fragment.

Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Exact size:
`164,221 bytes`

Exact SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`

Exact inherited runner lineage inside the physical archive:

```text
20_RUN_C2VR_FULL_VR.bat
 -> FUTURE_RUNS/CRYSIS2VR_BLACKBOX_ENGINE_TAP_v1.0.0/RUN_FULL_VR.bat
 -> tools/Build-Run-EngineTap.ps1
```

Recovery lineage:

```text
19_RECOVER_C2VR_BLACKBOX.bat
 -> RECOVER_ENGINE_TAP.bat
 -> tools/Recover-EngineTap.ps1
```

This matters because the project must reuse this actual runner, not invent a new BAT/PS1.

Historical user result preserved by its direct descendants:
- flicker gone;
- shadows stable;
- textures stable;
- objects stable;
- eyes still did NOT fuse.

Classification:

`WORLD_STABILITY_NO_FLICKER_REFERENCE = GREEN`

`BINOCULAR_STEREO = FAIL`.

The v6.0.1 change was narrow:
- XR64 kept/reused the most recent complete frame when Quest requested another frame before the next game Present;
- it stopped emitting empty projection layers as the normal continuity response;
- packet/frame metadata publication ordering was corrected before keyed-mutex release.

Important modern restriction:
Last-good reuse is allowed only with the original render pose/FOV/metadata that produced those pixels. Never relabel reused pixels as a newer HMD contract.

Recovered source identities:
- `engine_tap.cpp` `60F29B0FAE02BC1E751B5FD916C1B82736D3CAA97EB4A99D3F07DE7379D28CB8`
- `c2vr_host_client.cpp` `2477C256F9E621DEFFB9F6114FE6275865FA86E9826FD2CD8D8A21143472DDFD`
- `c2vr_openxr_host.cpp` `21853D54D58C37BC90F0A610CF62475173F2CD942D7F40709FCB3BA6B3608D20`
- `porous_proxy.cpp` `39A96807DC15EB60AE110EA17C7D2D8A903DD4D8BE81184CCAE1A0A81D83B31E`
- `c2vr_shared.h` `104E933B47464069D40DE1231B0FA13449B1290AA8CE91F6355F941F4B329508`.

## v6.1.0 A/FUSION_PROOF_QUAD

Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.1.0_A_FUSION_PROOF_QUAD_PORTABLE.zip`

SHA256:
`1CDF50E1EF1E25A1CCB33C48D0795732CDF1601F586F5F4FFAE75B489913AEFE`

This intentionally submitted one VIEW-space BOTH-eye quad as a 2D fusion control.

A PASS could only prove compositor/display fusion, never real stereo.

Classification:
`COMPOSITOR_CONTROL_ONLY`.

---

# 9. STOCK 65MM STEREO HAD ITS OWN RIGHT-EYE BLUR

A clean stock-Crysis RenderDoc control is important because it prevents us from blaming every historical eye-quality defect on the C2VR bridge.

Control:
- stock Crysis 2;
- native 65 mm SBS;
- no OpenXR;
- no C2VR DLL;
- no camera injection.

Valid capture:
`555666.rdc`

Size:
`288,668,138 bytes`.

Observed resources included:
`StereoL`, `StereoR`, `MotionBlurData`, `SSAO_BlurKernelP`, `sunshaftsMap`, `ShadowChanMasks*`, `cDeferredAmbient`.

Visual/measurement result:
- RIGHT was visibly softer even on static surfaces;
- approximate sharpness LEFT `328`, RIGHT `162`, roughly 2x worse.

Single-variable controls:
- `r_MotionBlur=0`: problem remained;
- `r_SSAO=0`: problem remained, and measured RIGHT/LEFT sharpness did not recover.

Package for the motion-blur-only control:
`CRYSIS2VR_STOCK_65MM_MOTIONBLUR_OFF_RENDERDOC_v1.0.0.zip`
SHA256 `50EB4F2E66EA2CC3F38C6836F9045CD2A11FFCCE1B00F3FD1608DE1720880AFB`.

Permanent lesson:
Some right-eye blur/asymmetry exists in stock native stereo itself. That does NOT make a later bad VR build acceptable, but it changes causal attribution: not every right-eye softness defect is OpenXR transport corruption.

---

# 10. v8/v9/v10 — CLEANER IMAGE WAS NOT FULL VR PASS

Historical v10-era evidence preserved that no-flicker behavior must not regress and that disabling some post effects could make the image cleaner.

But user-visible failures remained:
- wrong/strange world scale;
- first-person weapon counter-rotating against head motion;
- jitter/blur under side-to-side head movement.

Result explicitly referenced by later design:
`CRYSIS2VR_WORLD_NEAR_DUAL_DEPTH_RESULT_20260818_022454.zip`.

Permanent lesson:
Cleaner image / no flicker is a component PASS only. It does not establish world scale, NEAR ownership, binocular fusion, or comfort.

---

# 11. FOB_NEAREST OWNER TRUTH — EVIDENCE KEEP, VISUAL REJECT

Results:
- `CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_012736.zip`
- `CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_013107.zip`

Useful runtime fact:
- render-thread next-eye prediction produced balanced NEAR ownership;
- dominant near caller was `+0x000FF456` for both eyes;
- old `near_left=55 / near_right=6634` asymmetry was a cross-thread/global-active-eye classification artifact.

But the contemporaneous user visual verdict remained broken.

Classification:
`NEAR_OWNER_TIMING_EVIDENCE = KEEP`
`VISUAL_BASELINE = REJECT`.

Related reverse control:
`CRYSIS2VR_NATIVE_NEAR_PASSTHROUGH_v7.0.4_REVERSE_CONTROL.zip`
SHA256 `EEA8857B1B45D97668EFD09CDB168E7010B223AAD22F2FDE7F01D255074AC8F7`.

Numeric reverse-control PASS does not make it a visual parent.

---

# 12. CLEAN_NATIVE_EYES v7.0.2 — TECHNICAL, VISUAL STATUS UNBOUND

Package:
`CRYSIS2VR_CLEAN_NATIVE_EYES_v7.0.2_SOURCE_SIZE_XR_TRANSPORT.zip`

Result:
`CRYSIS2VR_CLEAN_NATIVE_SOURCE_SIZE_RESULT_20260819_001036.zip`.

Known causal scope:
- host swapchain/source-size transport change;
- game-side core remained byte-identical to its parent;
- target was direct source-size private-eye transfer.

No sufficiently direct user headset verdict is recovered that promotes this exact package to the historical “last good single-window”.

Classification:
`TECHNICAL_EVIDENCE_KEEP / VISUAL_STATUS_UNBOUND`.

---

# 13. 18–19 AUGUST “LAST GOOD NATIVE SINGLE-WINDOW” PROFILE

A dedicated historical visual oracle explicitly ordered the project to recover the last good native single-window branch and retire the SBS/Nvidia/two-window/black-headset interpretations.

Recorded good behavior profile:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- image present in headset;
- only hand/weapon visibly wrong.

This is one of the strongest user-accepted behavior profiles in the project.

But the same contemporaneous handoff recorded its exact package/hash lineage as a blind zone that had to be reconstructed before mutation.

Classification:
`USER_ACCEPTED_BEHAVIOR_PROFILE = HIGH_PRIORITY_KEEP`
`EXACT_PACKAGE_IDENTITY = OPEN`.

Do not guess the package from temporal adjacency.

---

# 14. PRESENT WAS NOT AUTHORITATIVE EYE IDENTITY

A later no-Cry-stereo temporal experiment scheduled logical eye renders but Present did not preserve that identity 1:1.

One control recorded:
- planned LEFT/RIGHT `417/417`;
- effectively captured roughly `396/264`;
- branch also crashed.

Permanent rule:

`PRESENT != AUTHORITATIVE EYE OWNER`.

Do not infer eye identity from a global/main-thread marker and expect Present to preserve it through the render-thread pipeline.

---

# 15. `181936` — ROUTE REACHED, THREAD/COPY POLICY DEAD

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_181936.zip`

Historical evidence:
- first pair reached OpenXR;
- crash `0xC0000005` after RC copy #3;
- old RC callback performed `CopyResource/Flush` in an unproven thread/context and copied near-black data.

Classification:
`ROUTE_REACHED = KEEP`
`RC_CALLBACK_COPY/FLUSH POLICY = HARD STOP`
`VISUAL_BUILD = HARD RED`.

---

# 16. v11/v12 BINOCULAR / TELESCOPE FAMILY

User repeatedly described this era as telescope/binocular, severely misaligned, and completely wrong despite technical counters improving.

Exact single-package binding remains incomplete.

Classification:
`FAMILY_BOUND_VISUAL_HARD_RED`.

A later `NO_BINOCULAR`-named technical path could make eye-axis and asymmetric-FOV metrics numerically excellent.

That does not close the historical headset complaint.

Permanent rule:

`EYE_AXIS_DOT + FOV_NUMERIC_MATCH != BINOCULAR_FUSION_PROOF`.

---

# 17. DUALWORLD v14 — BLACK HEADSET FAMILY

## v14.0.2

Package:
`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip`

SHA256:
`A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`

User verdict:
headset completely black.

Contemporary result files include `C2VR_DUALWORLD14_RESULT_20260819_162623.zip` and `...162900.zip`, but exact one-to-one verbal binding remains uncertain.

## v14.0.3 lazy gate

Package:
`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.3_LAZY_GATE_HOTFIX.zip`.

User again reported startup OpenXR signaling and a black headset.

Permanent STOP:
Do not patch-number forward from a black-headset parent. Revert to a visible baseline first.

---

# 18. FRUSTUM_COHERENCE v1.2.6 — GOOD IDEA, NOT A LIVE PASS

Package:
`CRYSIS2VR_FRUSTUM_COHERENCE_FOB_NEAREST_v1.2.6_OVERWRITE_LAB.zip`

SHA256:
`E59D1266CDFD12BD7F853813C276CDD65C2C2B3ECA00CE269D50B902D5A692F6`.

Intent was sensible:
- recompute near-camera XR asymmetry for the near plane;
- use union L/R frustum for visibility;
- keep HMD translation disabled while testing.

But the historical result failed generated-source compilation and did not launch a valid Crysis/OpenXR visual test. v1.2.7 was a build fix with architecture unchanged.

Classification:
`ARCHITECTURAL_CANDIDATE / NOT_VISUAL_GOLD / v1.2.6 NOT_LIVE`.

---

# 19. GLOBAL LESSONS

1. `RESULT ZIP != LIVE`.
2. `OPENXR_SESSION_ALIVE != VISIBLE_VR`.
3. `VISIBLE L/R != WORLD-LOCKED VR`.
4. `NON_DUPLICATE L/R != FUSED STEREO`.
5. `CURRENT HMD POSE != VALID LAYER POSE` unless those pixels were rendered from that pose.
6. `GOOD CAMERA MOTION != GOOD STEREO`.
7. `GOOD WEAPON DIRECTION != GOOD RENDERER`.
8. `NO FLICKER != CORRECT STEREO`.
9. `GOOD COUNTERS != USER VISUAL PASS`.
10. `GOOD OWNER ORACLE != GOOD PLAYABLE BUILD`.
11. `PRESENT != EYE OWNER`.
12. `EYE AXIS/FOV NUMERIC MATCH != BINOCULAR FUSION`.
13. `GOLD/CLEAN/MAIN/NO_BINOCULAR` in a package name is not evidence.
14. Downstream GPU/CB camera mutation is a diagnostic/verifier technique, not default final gameplay-camera ownership.
15. Stock native stereo itself contains right-eye postprocess/image-quality asymmetry; causal attribution must use stock controls.
16. When a user-accepted baseline existed, recover its exact physical carrier and runner before mutation.

---

# 20. RECOVERY PRIORITY

Do not choose by newest version number.

## A. World stability / no flicker
Use the exact recovered physical v6.0.1 carrier:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Reproduce with its real inherited runner. Do not write a replacement launcher.

## B. Camera ownership
Use:
- `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`;
- single-source `+0x0057AC76` topology.

Do not inherit native/Nvidia final stereo.

## C. Historical best complete behavior profile
Recover the exact package behind the 18–19 Aug “last good native single-window” behavior profile.
Do not guess it from v7 filenames.

## D. True private L/R mechanics
Use `CUSTOM_DUAL_T1 v1.0.1` only as a renderer primitive, not automatic visual parent.

## E. Weapon direction
Preserve `021239/175934` controller-to-fire behavior only after camera/stereo baseline is accepted.

The next useful visual build must come from one exact recovered baseline plus one causal mutation, not another multi-system synthesis.
