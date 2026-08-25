# C2VR — VISUAL BASELINE RECOVERY MATRIX

## WHY THIS EXISTS

C2VR repeatedly lost useful behavior because entire packages were labelled `PASS`/`GOLD`/`GREEN` even when the headset result was bad, untested, or only one subsystem worked.

Recover **properties**, not version numbers.

A package may be GREEN for one property and RED or UNBOUND for another.

Read together with:
- `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
- `docs/HISTORICAL_VISUAL_ORACLES_20260815_19.md`
- `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
- `docs/FALSIFIED.md`

---

# STATUS LANGUAGE

Do not write bare `GREEN` for historical evidence.

Use:
- `NOT_LIVE` — claimed runtime experiment never executed.
- `LIVE_VISUAL_UNBOUND` — runtime executed, direct headset verdict not bound.
- `MECHANICAL_GREEN` — one mechanism proven, no visual acceptance implied.
- `COMPONENT_VISUAL_GREEN` — user accepted one visible property only.
- `FULL_USER_VISUAL_GREEN` — complete build accepted as current visual parent.
- `VISUAL_RED` — explicit user headset rejection.
- `COMPONENT_ONLY` — donor/oracle fact only.
- `UNBOUND_VISUAL_RED` — rejection known, exact package/result binding incomplete.
- `VACUOUS_PASS_INVALID` — PASS printed without required evidence.

Package-name words such as `GOLD`, `GREEN`, `CLEAN`, `MAIN`, `PROVEN`, `WORKING`, `SAFE_VISUAL`, `NO_BINOCULAR`, `ONE_WINDOW`, `LIVE_BACKBUFFER_GREEN`, `EXACT`, `FINAL` have zero acceptance authority.

---

# PROPERTY MATRIX

| Property | Best recovered reference | Status | Keep | Never infer |
|---|---|---|---|---|
| XR process architecture | x86 Crysis2 + x64 OpenXR host | `MECHANICAL_GREEN` / infrastructure | process split, Quest session in x64 host | visual correctness |
| Early live headset transport | `194212` | `MECHANICAL_GREEN` | real x64 session, shared texture, captured non-identical L/R, submit/copy | world lock or visual GOLD |
| Early world lock | `194212` | `VISUAL_RED/FAIL` | failure evidence | old `EVIDENCE/GOLD` label |
| Exact v1.0.5 WORLDLOCK package | physical v1.0.5 | package recovered, visual status OPEN | source/runner archaeology | `010051` as LIVE proof |
| `010051` | physical RESULT | `NOT_LIVE` | Zig/toolchain failure lesson | any Crysis/OpenXR visual conclusion |
| `011323` | physical RESULT | `NOT_LIVE` | loader/preflight failure lesson | any visual conclusion |
| World stability / no flicker | exact physical `v6.0.1 NO_FLICKER_FUSIONLOCK` | `COMPONENT_VISUAL_GREEN` | stable textures/shadows/objects, no empty-layer flicker, atomic publication | stereo fusion solved |
| v6.1 A/FUSION quad | exact physical A control | `MECHANICAL_GREEN` control | compositor/display 2D fusion control | true stereo / quality baseline |
| v6.1 Z reprojection `201832` | exact LIVE result | `VISUAL_RED` | failure/counter-motion evidence | “v6.1 worked” |
| Z reprojection v6.2/v6.3/v6.4 | `205523 / 221628 / 013731` | `LIVE_VISUAL_UNBOUND` | genuine runtime evidence | `SAFE_VISUAL` or other filename as acceptance |
| Camera ownership | `A1_NATIVE_REPAIR_RESULT_173053` + single-source `+0x0057AC76` | `COMPONENT_VISUAL_GREEN` / ownership reference | head-driven game-camera behavior, one upstream injection topology | old Nvidia/native stereo around it |
| Pose/IPD/FOV math | `203734/204156` | `MECHANICAL_GREEN` forensic | HMD pose, IPD/FOV propagation | surrounding renderer visual PASS |
| Near-camera owner identity | `FOB_NEAREST OWNER TRUTH` | `MECHANICAL_GREEN` | render-thread owner timing, dominant `+0x000FF456` | visual baseline |
| Weapon firing direction | `021239 / A1_HISTORY_FIX_175934` | `COMPONENT_VISUAL_GREEN` donor | controller-to-fire direction behavior | hand rig or renderer acceptance |
| v7 source-size direct L/R transport | `v7.0.2 / 001036` | `MECHANICAL_GREEN + LIVE_VISUAL_UNBOUND` | exact source-size transport evidence | historical good single-window identity |
| v8/v9 world/near experiments | council/result set | `COMPONENT_ONLY` | useful union/culling/depth facts | complete physical-stereo success |
| v10 unified near `034749` | exact LIVE result | `MECHANICAL_GREEN`; visual improvement only secondary-bound | WorldCenter/Union/FOBNearest/XR/restore structural facts | whole-build visual GOLD |
| v10.2 ZERO_NATIVE_ONE_WINDOW `020117` | exact LIVE result | `LIVE_VISUAL_UNBOUND` | runtime evidence | `ONE_WINDOW` name as accepted baseline |
| v11 CADENCE_FASTPATH | `133603` | `COMPONENT_ONLY` / arbiter rejected whole-fix claim | narrow cadence/structural evidence | visual GREEN |
| v11/v12 binocular/telescope family | historical user oracle | `UNBOUND_VISUAL_RED` / family-bound | rejection evidence | guessing one exact neighboring ZIP |
| v13 COMMAND_FORK_IDENTITY | `065321` | `LIVE_VISUAL_UNBOUND` | runtime/oracle evidence | visual success from name |
| v13.1 XR_NATIVE_IK_HANDS | `071102` | `LIVE_VISUAL_UNBOUND` | runtime/IK oracle evidence | playable hands or visual baseline |
| v14 DualWorld scheduler | v14.0.2/v14.0.3 | `VISUAL_RED` package/family, exact result binding partly OPEN | black-headset failure lesson | direct descendants as visual parent |
| v15.1 NO_BINOCULAR | physical package + CommandTwin15 runtime | `MECHANICAL_GREEN / VISUAL_NOT_TESTED` | dual scene mechanics, eye-axis/FOV numerical evidence | binocular issue fixed |
| True private retail L/R primitive | `CUSTOM_DUAL_T1 v1.0.1 / 212003` | `MECHANICAL_GREEN` | private RT transaction, real L/R execution, RC33 mechanics | visual parent authority |
| T1 PosePair K0 v1.0.2 | current user run | `VISUAL_RED` | forensic diff only | K1/K2/HEAD/weapon descendants |
| `063149` v17/P7 lineage | raw user run | `VISUAL_RED` | proof pair transport could be alive | visual transport/camera acceptance |
| Binocular fusion | none securely bound as accepted final | OPEN | must be proven in headset | eye-axis/FOV numbers alone |
| World scale | 18–19 Aug last-good single-window behavior profile | `COMPONENT/FULL-BEHAVIOR PROFILE`, exact identity OPEN | good-scale target | guessing package |
| Stable head motion | same profile + A1 reference | behavior proven historically, exact parent OPEN | world-lock target | screen-glued pose relabel / mouse-look |
| Shadows/light stability | exact v6.0.1 property | `COMPONENT_VISUAL_GREEN` | stable world materials/light/shadow behavior | later moving/sliding shadow states |
| Stock native stereo right-eye softness | `555666.rdc` | baseline defect control | causal stock comparison | blaming all RIGHT blur on XR transport |
| Analyzer PASS with missing prerequisites | historical v17 analyzers | `VACUOUS_PASS_INVALID` | analyzer-bug lesson | any evidence value |

---

# EXACT RECOVERY ANCHOR A — v6.0.1 WORLD STABILITY

Physical carrier:

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Exact size:
`164221 bytes`.

Exact SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact runner lineage:

```text
20_RUN_C2VR_FULL_VR.bat
 -> FUTURE_RUNS/CRYSIS2VR_BLACKBOX_ENGINE_TAP_v1.0.0/RUN_FULL_VR.bat
 -> tools/Build-Run-EngineTap.ps1
```

Exact recovery lineage:

```text
19_RECOVER_C2VR_BLACKBOX.bat
 -> RECOVER_ENGINE_TAP.bat
 -> tools/Recover-EngineTap.ps1
```

Recovered source hashes:
- `engine_tap.cpp` `60F29B0FAE02BC1E751B5FD916C1B82736D3CAA97EB4A99D3F07DE7379D28CB8`
- `c2vr_host_client.cpp` `2477C256F9E621DEFFB9F6114FE6275865FA86E9826FD2CD8D8A21143472DDFD`
- `c2vr_openxr_host.cpp` `21853D54D58C37BC90F0A610CF62475173F2CD942D7F40709FCB3BA6B3608D20`
- `porous_proxy.cpp` `39A96807DC15EB60AE110EA17C7D2D8A903DD4D8BE81184CCAE1A0A81D83B31E`
- `c2vr_shared.h` `104E933B47464069D40DE1231B0FA13449B1290AA8CE91F6355F941F4B329508`.

Historical user state:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did NOT fuse.

This is the strongest exact physical reproduction anchor currently recovered for world stability.

It is not final stereo.

---

# RECOVERY ANCHOR B — CAMERA OWNERSHIP

Primary references:
- `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`;
- `CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`;
- once/logical-frame landmark `Crysis2.exe+0x0057AC76`.

User-positive historical property:
head turning drove the in-game camera/world and the remaining dominant failure was flicker/two-screen behavior rather than catastrophic camera collapse.

Do not inherit the old native/Nvidia final stereo around this reference.

---

# RECOVERY ANCHOR C — TRUE PRIVATE L/R

Technical reference:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

Reuse only proven private-eye renderer transaction/restoration mechanics.

Do not promote T1 v1.0.1 to whole-build visual parent and do not descend from visually rejected T1 PosePair K0.

---

# RECOVERY ANCHOR D — WEAPON DIRECTION

References:
- `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_021239.zip`;
- `CRYSIS2VR_A1_HISTORY_FIX_RESULT_20260817_175934.zip`.

Preserve controller-directed firing only after world/camera/stereo baseline is accepted.

---

# HISTORICAL SINGLE-WINDOW BEHAVIOR PROFILE

18–19 Aug user oracle records:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- image present in headset;
- only hand/weapon visibly wrong.

Classification:
`USER_ACCEPTED_BEHAVIOR_PROFILE`.

Exact package/hash:
`OPEN`.

Do not guess it from v7/v10 filenames.

Also do not invent a mythical historical build that contained every later independent success. The recovered record supports several separate wins across different lineages.

---

# VACUOUS PASS RULE

A PASS is invalid unless its prerequisites are proven present.

Examples of invalid historical analyzer behavior include PASS-like output with:
- `None/None/None` frame/pose inputs;
- zero RightTouch/hand samples;
- empty no-fault fields where the target path never ran.

Future analyzer contract:

```text
PREREQUISITE_EVIDENCE_COUNT > 0
TARGET_PATH_EXECUTED = YES
REQUIRED_FIELDS_PRESENT = YES
```

If any prerequisite fails, verdict must be `NA/NOT_EXECUTED` or FAIL, never PASS.

---

# CURRENT OPEN ITEMS

Do not fill these by inference:

1. Exact physical ZIP/hash for the 18–19 Aug last-good native single-window behavior profile.
2. Direct user headset verdicts for Z-reprojection v6.2/v6.3/v6.4.
3. Direct adjacent primary user message for v10 `034749`; current visual-improvement attribution is secondary historical summary.
4. Direct user visual verdict for v7.0.2 `001036`.
5. Direct user visual verdicts for v13 `065321` and v13.1 `071102`.
6. Exact raw-result timestamp binding for v14.0.2/v14.0.3 black-headset reports.
7. Exact package binding inside the v11/v12 binocular/telescope family.

An OPEN label outranks a guessed conclusion.

---

# REQUIRED RESULT IDENTITY GATE

Before any RESULT enters visual lineage:

```text
PACKAGE_EXISTS        = YES/NO
BUILD_SUCCESS         = YES/NO
GAME_LAUNCHED         = YES/NO
XR_SESSION_RAN        = YES/NO
TARGET_CODE_EXECUTED  = YES/NO
HEADSET_IMAGE_EXISTED = YES/NO/UNKNOWN
USER_HEADSET_VERDICT  = ACCEPT/RED/NOT_TESTED
```

---

# REQUIRED VISUAL PROPERTY TABLE FOR NEW PARENTS

```text
LIVE_STATUS           = LIVE/NOT_LIVE
WORLD_STABILITY       = PASS/FAIL/UNTESTED
CAMERA_WORLD_LOCK     = PASS/FAIL/UNTESTED
BINOCULAR_FUSION      = PASS/FAIL/UNTESTED
TRUE_LR               = PASS/FAIL/UNTESTED
WORLD_SCALE           = PASS/FAIL/UNTESTED
SHADOW_LIGHT_STABLE   = PASS/FAIL/UNTESTED
WEAPON_DIRECTION      = PASS/FAIL/UNTESTED
RESTORE_HASHES        = PASS/FAIL
USER_HEADSET_VERDICT  = ACCEPT/RED/NOT_TESTED
```

Only a `FULL_USER_VISUAL_GREEN` whole-build result may become the next complete visual parent.

---

# RECOVERY ORDER

1. Reproduce the exact physical v6.0.1 unchanged to re-establish world/no-flicker stability with its real runner.
2. Continue exact recovery of the historical last-good native single-window identity without guessing.
3. Reproduce camera ownership separately from A1/single-source lineage.
4. Reintroduce true private L/R mechanics separately from T1.
5. Prove actual binocular fusion in headset.
6. Only then reopen HEAD translation, weapon/NEAR, temporal/shadow polish and cadence optimization.

This matrix outranks version-number recency, package names, and analyzer PASS labels for parent selection.
