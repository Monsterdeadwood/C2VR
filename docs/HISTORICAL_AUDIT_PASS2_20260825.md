# C2VR — HISTORICAL EVIDENCE AUDIT PASS 2 — 2026-08-25

## PURPOSE

This is a hostile second pass over old C2VR `PASS / GREEN / GOLD / WORKING / NO_BINOCULAR / ONE_WINDOW / LIVE_BACKBUFFER_GREEN / SAFE_VISUAL` claims.

The goal is to prevent technical labels, analyzer bugs, package names, and result-shell ZIPs from being remembered as user-accepted VR.

This file does not promote a new build. It tightens evidence classification.

---

# 1. EVIDENCE STATUS TAXONOMY

Use only these meanings:

- `NOT_LIVE` — package/result exists, but target runtime experiment never executed.
- `LIVE_VISUAL_UNBOUND` — game/runtime executed, but no direct user headset verdict is bound.
- `MECHANICAL_GREEN` — a specific engine/transport/math mechanism is proven; no visual acceptance implied.
- `COMPONENT_VISUAL_GREEN` — user accepted one visible property only, e.g. no flicker or stable shadows.
- `FULL_USER_VISUAL_GREEN` — user accepted the complete build as the current visual parent.
- `VISUAL_RED` — user explicitly rejected the headset result.
- `COMPONENT_ONLY` — useful donor/oracle fact from a build that is not a visual parent.
- `UNBOUND_VISUAL_RED` — user rejection is known but exact package/result binding is not secure.
- `VACUOUS_PASS_INVALID` — analyzer printed PASS despite missing/zero/None prerequisite evidence.

`GREEN` without one of the qualified meanings above is forbidden in future state documents.

---

# 2. RESULT ZIP IS NOT LIVE

A result archive cannot enter runtime/visual lineage from filename alone.

Minimum identity gate:

```text
PACKAGE_EXISTS        = YES/NO
BUILD_SUCCESS         = YES/NO
GAME_LAUNCHED         = YES/NO
XR_SESSION_RAN        = YES/NO
TARGET_CODE_EXECUTED  = YES/NO
HEADSET_IMAGE_EXISTED = YES/NO/UNKNOWN
USER_HEADSET_VERDICT  = ACCEPT/RED/NOT_TESTED
```

Known false-LIVE examples:

## `010051`
`CRYSIS2VR_C2_NATIVE_RESULT_20260816_010051.zip`

- physical ZIP recovered;
- size 676 bytes;
- SHA256 `FC65F37E1B5F70F424866B99650C8B66FEA6A54EAD7C5434FFF32A736FB16216`;
- Zig self-test failed;
- `GameFilesTouched=False`.

Classification: `NOT_LIVE`.

It did NOT test the v1.0.5 WORLDLOCK policy.

## `011323`
`CRYSIS2VR_C2_NATIVE_RESULT_20260816_011323.zip`

- size 3,774 bytes;
- SHA256 `432E36FB784315A74A8BA6245FDC82B249B08877AC57F569CB6434C34601DAFF`;
- x64 OpenXR loader preflight failed;
- `GameFilesTouched=False`.

Classification: `NOT_LIVE`.

---

# 3. FALSE EARLY GOLD — `194212`

`CRYSIS2VR_C2_NATIVE_RESULT_20260815_194212.zip` genuinely proved:
- x64 Quest OpenXR session;
- shared Crysis texture transport;
- live submit/copy;
- captured non-identical L/R images.

But the same historical state recorded:
- `CameraLock=False`;
- `CameraInject=False`;
- `HORIZON_WORLD_LOCK=No`;
- user sees a flat image.

Old `EVIDENCE/GOLD` / `MAIN_PROVEN_XR` labels were therefore overclaims.

Classification:
`MECHANICAL_GREEN: XR transport`
`VISUAL_RED/NOT_ACCEPTED: world lock`.

---

# 4. EXACT PHYSICAL v6.0.1 — REAL COMPONENT VISUAL GREEN

Package physically recovered:

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

- size `164221` bytes;
- SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact inherited runner lineage:

```text
20_RUN_C2VR_FULL_VR.bat
 -> FUTURE_RUNS/CRYSIS2VR_BLACKBOX_ENGINE_TAP_v1.0.0/RUN_FULL_VR.bat
 -> tools/Build-Run-EngineTap.ps1
```

Historical user result preserved by direct descendants:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`
`VISUAL_FAIL: BINOCULAR_FUSION`.

This is an exact reproduction anchor, not a full VR GOLD.

---

# 5. TWO DIFFERENT v6.1 LINES MUST NOT BE CONFUSED

## A/FUSION_PROOF_QUAD
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.1.0_A_FUSION_PROOF_QUAD_PORTABLE.zip`
SHA256 `1CDF50E1EF1E25A1CCB33C48D0795732CDF1601F586F5F4FFAE75B489913AEFE`.

It intentionally submitted one VIEW-space BOTH-eye 2D quad.

Correct interpretation:
- `MECHANICAL/CONTROL_GREEN`: compositor can show/fuse the controlled 2D surface;
- NOT real stereo;
- later quality review rejected it as visual-success baseline due source density/quality and absence of true L/R.

## Z_REPROJECTION v6.1 / `201832`
This is a different lineage.

User directly reported:
- no meaningful improvement;
- when head turns left, weapon moves right;
- image very blurred.

Classification:
`VISUAL_RED`.

Never merge these two v6.1 histories into one “v6.1 worked” statement.

---

# 6. Z-REPROJECTION CHRONOLOGY — LIVE DOES NOT MEAN ACCEPTED

Full runtime artifacts prove these experiments genuinely executed:

```text
v6.0.0 -> 20260817_191032
v6.0.1 -> 20260817_193132
v6.1.0 -> 20260817_201832
v6.2.0 -> 20260817_205523
v6.3.0 -> 20260817_221628
v6.4.0 -> 20260818_013731
```

For v6.2/v6.3/v6.4 the direct user headset verdict is not securely bound in the recovered corpus.

Therefore all three are:
`LIVE_VISUAL_UNBOUND`.

Names such as `FRESH_SOURCE_HANDSPACE`, `TIGHT_UNION`, `SAFE_VISUAL_WEAPON_LAG_OFF` are design labels only.

Do not promote any of them from the filename.

---

# 7. v6.2.2 B0.1 — PACKAGE EXISTS, VISUAL STATUS OPEN

Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.2.2_B0_1_SDK_PIPE_DEADLOCK_FIX_PORTABLE.zip`

- size `117334` bytes;
- SHA256 `DCF1C103B5DD4EB4172F245D6E26F590DC5040CE7E37C981F1818B5F1FEC44BE`.

Its architecture attempted custom dual rendering without native stereo/SBS.
The previous B0 result `022926` completed only a few pairs before `0xC0000005`.

No direct positive headset verdict is bound.

Classification:
`LIVE/PACKAGE EVIDENCE ONLY / VISUAL_UNBOUND`.

---

# 8. v7.0.2 SOURCE-SIZE TRANSPORT — TECHNICAL ONLY

Package:
`CRYSIS2VR_CLEAN_NATIVE_EYES_v7.0.2_SOURCE_SIZE_XR_TRANSPORT.zip`

- size `161846` bytes;
- SHA256 `B143D04F6CB0D3C77058380DCBD04A6196C64E21AB60EEC8B2FFDEEB54E3478E`.

Result:
`CRYSIS2VR_CLEAN_NATIVE_SOURCE_SIZE_RESULT_20260819_001036.zip`

- size `36858996` bytes;
- SHA256 `C6D770A83D21AA628816F0EE86E4D25A54E884BADD237600F5E272C252128E0F`.

The run is genuine LIVE technical evidence.
No direct user headset verdict recovered promotes it to the historical good single-window baseline.

Classification:
`MECHANICAL_GREEN / LIVE_VISUAL_UNBOUND`.

`CLEAN_NATIVE_EYES` is not an acceptance label.

---

# 9. v8/v9 — PARTIAL NUMERIC PROGRESS, ARCHITECTURE REJECTED

Recovered council evidence separates valid facts from the failed architecture:
- WORLD union/culling work had useful effects;
- old `FOB_NEAREST` projection remained unhandled in key runs;
- signed/isolated near-layer ownership assumptions failed;
- close weapon/arm geometry still contaminated depth;
- source resolution/producer mismatch remained;
- some post-effect settings made image cleaner.

Classification:
`COMPONENT_ONLY`.

Do not remember v8/v9 as a complete no-flicker physical stereo solution.

---

# 10. v10 `034749` — STRUCTURAL GREEN, FULL VISUAL STATUS NOT PRIMARY-BOUND

Result:
`CRYSIS2VR_UNIFIED_NEAR_PROJECTION_RESULT_20260818_034749.zip`

- size `48,769,328` bytes;
- SHA256 `3E234BE937B305009C9DFE24D53B2C7E8E2A008AD873BF253C165386F132661F`;
- genuine LIVE;
- XR captures present;
- pose/IPD live.

Primary arbiter established mechanical facts:
- WorldCenter PASS;
- UnionFrustum PASS;
- FOBNearestProjectionUnified PASS;
- source-size resolution path PASS;
- XR transport live;
- old native stereo hard off;
- restore PASS.

But the same primary arbiter explicitly stated:

`STRUCTURAL_ARBITER=READY_FOR_VISUAL_TEST`

`VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.

A later secondary historical audit says the user observed that weapon/world counter-motion improved here.
The direct adjacent primary user message has not yet been recovered strongly enough.

Classification:
- `MECHANICAL_GREEN` — proven;
- `COMPONENT_VISUAL_GREEN` — secondary historical summary only, lower confidence than direct user binding;
- `FULL_USER_VISUAL_GREEN` — NO.

Do not call `034749` whole-build GOLD.

---

# 11. v10.2 ZERO_NATIVE_ONE_WINDOW — REAL LIVE, USER VERDICT UNBOUND

Result:
`CRYSIS2VR_ZERO_NATIVE_ONE_WINDOW_RESULT_20260819_020117.zip`

- size `44,732,261` bytes;
- contains full `Crysis2_runtime_image.bin`;
- therefore genuine runtime LIVE.

No direct user headset verdict is securely recovered.

Classification:
`LIVE_VISUAL_UNBOUND`.

`ONE_WINDOW` in the package name is not proof of the historical accepted single-window baseline.

---

# 12. v11 CADENCE_FASTPATH — DO NOT TURN STRUCTURAL PASS INTO VISUAL GREEN

Result:
`CRYSIS2VR_CADENCE_FASTPATH_RESULT_20260818_133603.zip`
SHA256 `15B55E5001AE1C5C5F813E9D0C49F58E36E921FA427BE9BAA3263770930917C`.

The run contained several local PASS/GREEN counters, but its own arbiter said:

`STRUCTURAL_ARBITER=REJECT_DO_NOT_CALL_FIXED`

`VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.

Classification:
`COMPONENT/MECHANICAL EVIDENCE ONLY`.

Any later shorthand such as “v10/v11 projection GREEN” must be qualified to the exact sub-property.

---

# 13. v11/v12 TELESCOPE/BINOCULAR FAMILY

User visual rejection is known at family level:
- telescope/binocular geometry;
- severe misalignment;
- visually wrong.

Exact single package binding remains unresolved.

Classification:
`FAMILY_BOUND_VISUAL_RED`.

Do not invent one exact neighboring ZIP as the cause or as the acceptable exception.

---

# 14. v13 / v13.1 — GENUINE LIVE, VISUAL STATUS UNBOUND

Full runtime image evidence exists for:
- `CRYSIS2VR_COMMAND_FORK_IDENTITY_20260819_065321`;
- `CRYSIS2VR_XR_NATIVE_IK_HANDS_20260819_071102`.

Therefore these are not preflight shells.

However no direct user headset verdict is securely bound in the current corpus.

Classification:
`LIVE_VISUAL_UNBOUND / ORACLE-COMPONENT ONLY`.

Do not infer visual success from `COMMAND_FORK_IDENTITY` or `XR_NATIVE_IK_HANDS` names.

---

# 15. v14 DUALWORLD — BLACK-HEADSET FAMILY REMAINS RED

Known package-bound user evidence:

`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip`
SHA256 `A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`

User reported completely black headset.

`v14.0.3_LAZY_GATE_HOTFIX` also received a black-headset user report.

The exact one-to-one mapping between the verbal report and neighboring raw result ZIP timestamps remains weaker than desired.

Classification:
`PACKAGE/FAMILY VISUAL_RED / EXACT_RESULT_BINDING_OPEN`.

Do not fabricate a result binding to make the history look cleaner.

---

# 16. v15.1 `NO_BINOCULAR` — NAME IS PARTICULARLY MISLEADING

Physical package:
`CRYSIS2VR_COMMAND_TWIN_NO_BINOCULAR_v15.1.0.zip`

- size `80107` bytes;
- SHA256 `01E95B124CCBDC1161CDF3889449BF32EEAD665764C42BD682EAF1033321FC19`.

Game-side mechanics looked impressive:
- `eye_axis_dot=1.000000000`;
- FOV errors around `5.96e-08`;
- 800 dual scene pairs;
- 800 LEFT/RIGHT SetCamera calls;
- 787 pair copies.

But the host status explicitly said:

```text
architecture=RT_DRAW_PROJECTION_ORACLE_NO_VISUAL_SUBMIT
visual_projection_layers=0
submitted_frames=0
```

And the associated projection analyzer said:

`VERDICT=INCONCLUSIVE_NO_EYE_DRAW_BINDING_LOCK`

`VISUAL_LAYER_SUBMITTED=NO`.

Therefore the name `NO_BINOCULAR` was never visually validated by this run.

Classification:
`MECHANICAL_GREEN / VISUAL_NOT_TESTED`.

Permanent rule:
`eye_axis_dot + tiny FOV error + dual scene pairs != headset fusion`.

---

# 17. VACUOUS PASS — ANALYZER BUG CLASS

Historical analyzers can print PASS even when the data required by the test is absent.

Observed examples include PASS-like output for fields such as:
- FramePoseIntegrity with `None/None/None`;
- RightTouch visual contract with `right=0`, `hand=0/0`;
- no-fault checks with empty data.

This is not evidence.

Classification:
`VACUOUS_PASS_INVALID`.

Future gate rule:
1. every PASS must declare minimum prerequisite evidence;
2. if prerequisite count/value is missing, zero, None, or target path never executed, verdict is `NA/NOT_EXECUTED` or FAIL, never PASS;
3. overall PASS cannot be assembled from vacuous child PASSes.

A better historical model already existed in some v10-era arbiters:
- if mechanical path was not engaged, they emitted `NOT_ENGAGED_DO_NOT_INTERPRET_VISUALLY`;
- they required user headset/capture evidence separately.

Use that style going forward.

---

# 18. PACKAGE-NAME TOXICITY LIST

These tokens have zero acceptance authority:

```text
GOLD
GOLDEN
GREEN
CLEAN
MAIN
PROVEN
WORKING
SAFE_VISUAL
NO_BINOCULAR
ONE_WINDOW
LIVE_BACKBUFFER_GREEN
EXACT
FINAL
```

They describe author intent or a narrow engineering property only.

No visual promotion without bound headset/capture evidence.

---

# 19. “ONE MYTHICAL OLD PERFECT BUILD” IS NOT SUPPORTED

A later historical audit correctly noticed that several real successes existed in different lineages:
- v6.0.1: world/no-flicker stability;
- v10 `034749`: structural world/near coherence and secondary evidence of improved weapon/world relationship;
- CUSTOM_DUAL_T1 v1.0.1: true private independent retail L/R renderer mechanics.

This does NOT erase the 19-Aug user oracle that says a “last good native single-window branch” had good scale/head behavior and visible headset image.

Correct synthesis:
- there was a user-remembered useful single-window behavior profile;
- its exact package/hash remains OPEN;
- later independent wins must not be back-projected into that unknown package;
- do not invent a mythical old build where every later solved property already coexisted.

---

# 20. CURRENT HIGH-CONFIDENCE SAFE MEMORY

## Exact physical reproduction anchor
`v6.0.1 NO_FLICKER_FUSIONLOCK`
- exact ZIP/hash/runner recovered;
- user-positive only for world stability/no-flicker;
- stereo fusion still failed.

## Camera reference
`A1_NATIVE_REPAIR_RESULT_20260817_173053`
- user-positive camera/world behavior reference;
- old renderer still flickered/two-screen;
- component only.

## True-L/R technical primitive
`CUSTOM_DUAL_T1 v1.0.1 / 212003`
- independent private L/R mechanics proven;
- not a visual parent after later hard-red descendants.

## Weapon direction donor
`021239 / A1_HISTORY_FIX_175934`
- controller-directed firing component only;
- surrounding renderer rejected.

## Historical accepted behavior profile
18–19 Aug “last good native single-window”:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- hand/weapon still wrong.

Exact physical package identity remains OPEN.

---

# 21. OPEN ITEMS — DO NOT FILL BY GUESSING

These remain intentionally unresolved:

1. Exact physical ZIP/hash behind the 18–19 Aug “last good native single-window” user behavior profile.
2. Direct user headset verdicts for Z-reprojection v6.2/v6.3/v6.4.
3. Direct adjacent primary user message for `034749`; current visual improvement attribution is secondary historical summary.
4. Direct user visual verdict for v7.0.2 `001036`.
5. Direct user visual verdicts for v13 and v13.1.
6. Exact raw result timestamp binding for the v14.0.2/v14.0.3 black-headset reports.
7. Exact package binding inside the v11/v12 telescope/binocular family.

These OPEN labels are a feature, not a deficiency. An honest unknown is safer than a false GOLD.

---

# 22. RULE FOR THE NEXT RUNTIME

Do not assemble another multi-generation super-build from all historical components.

First reproduce one exact known property baseline unchanged.

For any future visual candidate report separately:

```text
LIVE_STATUS
WORLD_STABILITY
CAMERA_WORLD_LOCK
BINOCULAR_FUSION
TRUE_LR
WORLD_SCALE
SHADOW_LIGHT_STABILITY
WEAPON_DIRECTION
RESTORE_HASHES
USER_HEADSET_VERDICT
```

Only `FULL_USER_VISUAL_GREEN` may become the next whole-build visual parent.
