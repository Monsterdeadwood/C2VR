# C2VR — VISUAL BASELINE RECOVERY MATRIX

## WHY THIS EXISTS

C2VR repeatedly lost useful behavior because entire packages were labelled `PASS`/`GOLD` even when the headset result was bad, then later branches inherited the whole package.

Recover **properties**, not version numbers.

A package may be GREEN for one property and RED for another.

Legend:
- `GREEN` — keep/recover this property.
- `RED` — explicitly rejected/falsified.
- `YELLOW` — technically useful/proven, but not a visual-parent PASS.
- `OPEN` — exact package/user binding remains unresolved.
- `NOT_LIVE` — package/result existed, but claimed runtime experiment never executed.

| Property | Best recovered reference | Status | What to keep | What must NOT be inherited |
|---|---|---|---|---|
| XR process architecture | x86 Crysis2 + x64 OpenXR host | GREEN | process split, Quest session in x64 host | in-process x86 OpenXR session attempts |
| Early true headset transport | `194212` | YELLOW technical | x64 session, shared texture, real captured L/R, submit/copy transport | old `GOLD/MAIN_PROVEN_XR` visual label, flat non-world-locked camera |
| Visible headset output | historical single-window profile | GREEN behavior / OPEN identity | one visible headset image path | black-headset parents |
| World stability / no flicker | exact physical `v6.0.1 NO_FLICKER_FUSIONLOCK` | GREEN property | stable textures/shadows/objects, no empty-layer flicker, atomic packet publication | its mono/fake binocular composition as final stereo |
| Camera ownership | `A1_NATIVE_REPAIR_RESULT_173053` + single-source `+0x0057AC76` | YELLOW/GREEN property | head-driven game-camera behavior, one upstream injection | native/Nvidia final stereo; all-SetCamera feedback |
| Pose/IPD/FOV math | `203734/204156` | YELLOW forensic | HMD pose propagation, accurate eye/IPD/FOV math | exact-eye renderer policy, inherited near asymmetry, old center culling |
| Near-camera owner identity | `FOB_NEAREST OWNER TRUTH` | YELLOW | render-thread owner timing, dominant `+0x000FF456` | visual build, global active-eye classification |
| Weapon firing direction | `021239 / A1_HISTORY_FIX_175934` | YELLOW/GREEN component | controller-to-fire direction behavior | crooked hand rig and surrounding Nvidia renderer |
| True private retail L/R renderer primitive | `CUSTOM_DUAL_T1 v1.0.1 / 212003` | YELLOW technical | private RT transaction, true L/R execution, RC33 mechanics | automatic visual-parent status; later T1 PosePair K0 visual policy |
| Source-size direct L/R transport | `CLEAN_NATIVE_EYES v7.0.2 / 001036` | YELLOW | exact causal host sizing/direct-eye evidence | promotion to “last good single-window” without user verdict |
| Compositor fusion control | `v6.1.0 A/FUSION_PROOF_QUAD` | YELLOW control | one 2D image fusion/display control | calling it real stereo or quality baseline |
| Binocular fusion | none currently bound as accepted final | OPEN | must be proven in headset | telescope/binocular families, numeric-only eye-axis/FOV PASS |
| World scale | 18–19 Aug “last good native single-window” profile | GREEN behavior / OPEN identity | good world scale behavior | v10-era wrong/strange-scale branches |
| Stable head motion | same single-window profile + A1 camera reference | GREEN behavior / OPEN exact parent | world stays stable under head motion | screen-glued pose relabel, mouse-look, camera collapse |
| Shadows / lighting coherence | exact v6.0.1 stable-world property | GREEN property | stable textures/shadows/objects | `205430`, `063149`, moving/sliding L/R light/shadow state |
| Temporal continuity | v6.0.1 packet/cache ordering | YELLOW/GREEN mechanism | complete last-good continuity, metadata before mutex release | stale pixels relabelled with new/current HMD pose |
| Stock native stereo right-eye quality | stock 65mm RenderDoc `555666.rdc` | YELLOW baseline defect | stock control proving RIGHT softness exists before C2VR | blaming every right-eye blur on XR transport |
| High-level DualWorld scheduler | v14.0.2/v14.0.3 | RED | forensic lessons only | direct descendants; black-headset lineage |
| Native/Nvidia/monitor stereo final transport | A1/native era | RED | archaeology/controls only | final renderer authority |
| Current T1 PosePair K0 | `CUSTOM_DUAL_T1 v1.0.2 POSEPAIR_ONLY K0` | RED | source diff only as forensic evidence | K1/K2/HEAD/weapon/temporal/shadow descendants |
| v1.0.5 WORLDLOCK intended camera policy | physical v1.0.5 / v1.0.5.1 | OPEN / first result NOT_LIVE | package/source/runner for archaeology | treating `010051` as a world-lock test |
| Cleanroom v1.1.1 result `011323` | physical result | NOT_LIVE | loader/preflight lesson only | any visual/runtime conclusion |

---

# EXACT RECOVERY TARGETS

## Target A — historical last-good native single-window

Known user-accepted behavior profile:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- image present in headset;
- hand/weapon still visibly wrong.

State:
`EXACT_PACKAGE/HASH = OPEN`.

Do not guess from neighboring filenames.

## Target B — exact v6.0.1 no-flicker baseline

Physical carrier recovered:

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Exact size:
`164221 bytes`.

Exact SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact runner lineage inside the recovered archive:

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

Recovered v6.0.1 source hashes:
- `engine_tap.cpp` `60F29B0FAE02BC1E751B5FD916C1B82736D3CAA97EB4A99D3F07DE7379D28CB8`
- `c2vr_host_client.cpp` `2477C256F9E621DEFFB9F6114FE6275865FA86E9826FD2CD8D8A21143472DDFD`
- `c2vr_openxr_host.cpp` `21853D54D58C37BC90F0A610CF62475173F2CD942D7F40709FCB3BA6B3608D20`
- `porous_proxy.cpp` `39A96807DC15EB60AE110EA17C7D2D8A903DD4D8BE81184CCAE1A0A81D83B31E`
- `c2vr_shared.h` `104E933B47464069D40DE1231B0FA13449B1290AA8CE91F6355F941F4B329508`.

Historical user state:
- flicker gone;
- textures/shadows/objects stable;
- eyes still did not fuse.

Use it to recover WORLD STABILITY only. Do not call stereo solved.

## Target C — camera ownership

Primary references:
- `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`;
- `CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`;
- once/logical-frame landmark `Crysis2.exe+0x0057AC76`.

Goal:
recover real head-driven game-camera behavior without importing native/Nvidia final stereo.

## Target D — true private L/R execution

Technical reference:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

Reuse only proven private-eye transaction/restoration mechanics.
Do not inherit current T1 PosePair K0 visual policy.

## Target E — weapon direction

References:
- `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_021239.zip`;
- `CRYSIS2VR_A1_HISTORY_FIX_RESULT_20260817_175934.zip`.

Preserve controller-directed firing only after camera/stereo baseline is accepted.

---

# CORRECTED EARLY NATIVE LINEAGE

## `194212`

Keep as technical XR transport evidence only:
- real x64 OpenXR session;
- real headset submits/copies;
- real captured L/R.

Reject its old visual-GOLD interpretation:
- `CameraLock=False`;
- `CameraInject=False`;
- `HORIZON_WORLD_LOCK=No`;
- user sees flat image.

## v1.0.5 WORLDLOCK physical package

`CRYSIS2VR_C2_NATIVE_OPENXR_X64_v1.0.5_WORLDLOCK_DIRECT_CAMERA.zip`

SHA256:
`6D4D9D7120C43111AAA84FC0A36BE65BE4E83617E321B6FD9F390D26A52727B0`.

The package is useful for source/runner archaeology, but its first result did not execute the experiment.

## `010051`

`CRYSIS2VR_C2_NATIVE_RESULT_20260816_010051.zip`
SHA256 `FC65F37E1B5F70F424866B99650C8B66FEA6A54EAD7C5434FFF32A736FB16216`.

Only build failure:
`Downloaded Zig failed its version self-test.`

`GameFilesTouched=False`.

Classification:
`NOT_LIVE`.

## v1.0.5.1 Zig fix

`CRYSIS2VR_C2_NATIVE_OPENXR_X64_v1.0.5.1_ZIG_PORTABLE_FIX.zip`
SHA256 `546A5C63D951E9C5A5B7C82922C4DAB14D0B6992B72535A2999154E3EFA2FF21`.

World-lock code unchanged; toolchain discovery fixed.
No recovered user visual PASS currently bound.

## v1.0.6 observatory

`CRYSIS2VR_C2_NATIVE_OPENXR_X64_v1.0.6_OBSERVATORY_DEEP.zip`
SHA256 `7B4907F04865A7A6E8AFC4B578FB955420123B93C1B12DF4A90EE7556446E1E3`.

Instrumentation child only. Do not infer world-lock acceptance from its existence.

## `011323`

`CRYSIS2VR_C2_NATIVE_RESULT_20260816_011323.zip`
SHA256 `432E36FB784315A74A8BA6245FDC82B249B08877AC57F569CB6434C34601DAFF`.

Loader/preflight failure:
`No x64 OpenXR loader found...`

`GameFilesTouched=False`.

Classification:
`NOT_LIVE`.

---

# STOCK NATIVE STEREO QUALITY CONTROL

Clean stock 65 mm SBS RenderDoc capture:
`555666.rdc`, `288,668,138 bytes`.

No OpenXR, no C2VR DLL, no camera injection.

Measured/observed:
- LEFT sharpness roughly `328`;
- RIGHT roughly `162`;
- RIGHT visibly softer even on static surfaces.

Motion-blur-only control package:
`CRYSIS2VR_STOCK_65MM_MOTIONBLUR_OFF_RENDERDOC_v1.0.0.zip`
SHA256 `50EB4F2E66EA2CC3F38C6836F9045CD2A11FFCCE1B00F3FD1608DE1720880AFB`.

`r_MotionBlur=0` did not remove the issue.
`r_SSAO=0` also did not remove it.

Use this as a causal baseline: stock native stereo has its own eye-quality asymmetry. Do not automatically blame every historical right-eye blur on the OpenXR transport.

---

# REQUIRED RESULT IDENTITY GATE

Before a RESULT can enter the visual lineage, report:

```text
PACKAGE_EXISTS       = YES/NO
BUILD_SUCCESS        = YES/NO
GAME_LAUNCHED        = YES/NO
XR_SESSION_RAN       = YES/NO
TARGET_CODE_EXECUTED = YES/NO
HEADSET_IMAGE_EXISTED= YES/NO/UNKNOWN
USER_HEADSET_VERDICT = ACCEPT/RED/NOT_TESTED
```

If `GAME_LAUNCHED=NO` or the target runtime code never executed, the result is `NOT_LIVE` and cannot prove or falsify visual architecture.

---

# REQUIRED VISUAL PROPERTY TABLE FOR NEW PARENTS

```text
WORLD_STABILITY      = PASS/FAIL/UNTESTED
CAMERA_WORLD_LOCK    = PASS/FAIL/UNTESTED
BINOCULAR_FUSION     = PASS/FAIL/UNTESTED
TRUE_LR              = PASS/FAIL/UNTESTED
WORLD_SCALE          = PASS/FAIL/UNTESTED
SHADOW_LIGHT_STABLE  = PASS/FAIL/UNTESTED
WEAPON_DIRECTION     = PASS/FAIL/UNTESTED
RESTORE_HASHES       = PASS/FAIL
USER_HEADSET_VERDICT = ACCEPT/RED/NOT_TESTED
```

A catastrophic visual RED forbids direct-parent promotion even when other rows are PASS.

---

# RECOVERY ORDER

1. Reproduce exact physical v6.0.1 unchanged with its actual inherited runner to recover WORLD STABILITY / no-flicker behavior.
2. Continue recovering the exact package behind the historical last-good native single-window behavior profile.
3. Reproduce camera ownership separately from A1/single-source lineage.
4. Reintroduce true private L/R mechanics separately from T1.
5. Prove actual binocular fusion in headset.
6. Only then reopen HEAD translation, weapon/NEAR, temporal/shadow polish, and cadence optimization.

This matrix outranks version-number recency and old package labels for parent selection.
