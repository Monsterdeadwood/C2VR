# Crysis 2 VR — RESULT INDEX

Current rule:
`WORKING BUILD FIRST / USER VISUAL VERDICT FIRST / ONE PROPERTY AT A TIME`.

Read first:
- `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
- `docs/FALSIFIED.md`
- `docs/STATE.md`

Status language:
- `NOT_LIVE`
- `LIVE_VISUAL_UNBOUND`
- `MECHANICAL_GREEN`
- `COMPONENT_VISUAL_GREEN`
- `FULL_USER_VISUAL_GREEN`
- `VISUAL_RED`
- `COMPONENT_ONLY`
- `VACUOUS_PASS_INVALID`

---

# CURRENT VISUAL STATE

## `C2VR_RC33_V1721_RESULT_20260825_063149.zip`
**Class:** `VISUAL_RED`.

Runtime pair production/submission was alive, but user reported catastrophic camera/world instability and moving/sliding light/shadow state.

Do not use as visual parent.

## `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`
SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`.

**Class:** `VISUAL_RED / RESULT_ZIP_NOT_BOUND`.

User reported it visually even worse.

No K1/K2/HEAD/weapon/temporal/shadow descendant.

---

# EXACT RECOVERED VISUAL PROPERTY BASELINE

## v6.0.1 NO_FLICKER_FUSIONLOCK
Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

- bytes `164221`
- SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`

Historical user-visible state:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

**Class:**
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`
`BINOCULAR_FUSION = FAIL`.

Exact runner lineage recovered:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

This is the current first unchanged reproduction target.

---

# v17.2 WAIT / POSEPAIR LINEAGE

## v17.2.5 WAIT45 / P5
**Class:** last working wait-lineage ancestor, component timing evidence only.

Measurements:
- exact pair consumes `269`
- host submits `269`
- misses `53`
- exact ratio `83.5404%`
- `pair_wait_ms_max=47`
- completed/copies `354/354`
- flashes/dropouts remained visible

Earlier line was roughly `92 exact / 776 miss` (~10.6%).

Proven narrow fact:
bounded deadline/wait policy materially affected exact-pair acceptance in this lineage.

Not proven:
- final visual stability;
- timely prediction;
- whole-build parent authority.

## v17.2.6 EXACT_BLOCK120 / P6
Package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

SHA256:
`8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`.

**Correct class:** `LIVE_RUNTIME_RED_BEFORE_PAIR_PRODUCTION`.

P6 was executed.

Raw result:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`.

Observed:
- host published contracts through about `1533`;
- exact hits `0`;
- misses about `1409`;
- consumes/submits `0`;
- game RenderWorld about `900`;
- scene packets about `899`;
- pairs queued/completed/L/R `0`;
- fault `NO_LATCHED_RENDER_CONTRACT`;
- 120 ms wait policy present;
- restore/hash PASS.

**The old class `CURRENT UNTESTED FINALIST` is deleted.**

Do not state “No recorded P6 LIVE result found”.
Do not infer that 120 ms improved cadence.

A later noncanonical latch-grace run restored pair flow but was then user VISUAL RED, so cadence remains parked.

---

# CUSTOM_DUAL_T1 v1.0.1

**Class:** `MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

Canonical result:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

- bytes `68,872,488`
- SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAe1EDDB3596144D341CD53367`
- center HMD inject/restore `2296/2296`
- private LEFT `2295`
- private RIGHT `2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- sampled L/R median MAE `35.9781`
- FramePairContract desync `0/0`
- PosePair acceptance failed

Interpretation:
genuine non-duplicate private two-eye retail rendering is proven.

**The old class `PROVEN MAIN RENDERER PARENT` is too broad and is removed.**

T1 remains technical renderer source authority, not automatic visual-parent authority.

---

# CAMERA OWNERSHIP REFERENCE

## `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`
**Class:** `COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

Historical user-positive property:
head left/right drove the real game camera/world; main remaining problem was flicker/two-screen behavior.

Do not inherit old native/NVIDIA final stereo.

## Single-source owner
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

HMD x1 at `Crysis2.exe+0x0057AC76`; downstream SetCamera pass-through.

**Class:** ownership topology reference only.

---

# WEAPON / NEAR HISTORICAL RESULTS

## `20260817_010329`
**Class:** component evidence + visually unstable global image.

User-observed:
- right controller moved weapon/viewmodel;
- firing followed monitor/game-center aim;
- image still flickered.

## `021239 / A1_HISTORY_FIX_175934`
**Class:** `COMPONENT_VISUAL_GREEN: WEAPON_DIRECTION_DONOR`.

Preserved behavior:
controller-directed gameplay firing followed weapon/muzzle direction.

This is not proof of a good surrounding renderer or direct ballistic owner.

## v10 `034749`
Result:
`CRYSIS2VR_UNIFIED_NEAR_PROJECTION_RESULT_20260818_034749.zip`

- bytes `48,769,328`
- SHA256 `3E234BE937B305009C9DFE24D53B2C7E8E2A008AD873BF253C165386F132661F`

Primary result proves:
- WorldCenter structural PASS;
- UnionFrustum PASS;
- FOBNearestProjectionUnified PASS;
- XR transport live;
- native stereo hard off;
- restore PASS.

Primary arbiter stopped at:
`STRUCTURAL_ARBITER=READY_FOR_VISUAL_TEST`
`VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.

A later secondary historical summary attributes improved weapon/world counter-motion to this run, but the direct adjacent primary user message is not currently recovered.

**Correct class:**
`MECHANICAL_GREEN`
plus `SECONDARY_USER_VISUAL_SUMMARY`, not `FULL_USER_VISUAL_GREEN`.

The old class `PROVEN projection/weapon visual coupling` was too strong and is removed.

---

# Z-REPROJECTION v6.x

Genuine LIVE chronology:

```text
v6.0.0 -> 20260817_191032
v6.0.1 -> 20260817_193132
v6.1.0 -> 20260817_201832
v6.2.0 -> 20260817_205523
v6.3.0 -> 20260817_221628
v6.4.0 -> 20260818_013731
```

### v6.1 / `201832`
Direct user verdict:
- no meaningful improvement;
- weapon counter-moved against head turn;
- image very blurred.

**Class:** `VISUAL_RED`.

### v6.2 / v6.3 / v6.4
Full runtime evidence exists.
Direct user verdict is not securely bound.

**Class:** `LIVE_VISUAL_UNBOUND`.

Do not infer visual success from `FRESH_SOURCE`, `TIGHT_UNION`, `SAFE_VISUAL` package names.

---

# v7.0.2 SOURCE-SIZE TRANSPORT

Package:
`CRYSIS2VR_CLEAN_NATIVE_EYES_v7.0.2_SOURCE_SIZE_XR_TRANSPORT.zip`

- bytes `161846`
- SHA256 `B143D04F6CB0D3C77058380DCBD04A6196C64E21AB60EEC8B2FFDEEB54E3478E`

Result:
`CRYSIS2VR_CLEAN_NATIVE_SOURCE_SIZE_RESULT_20260819_001036.zip`

- bytes `36858996`
- SHA256 `C6D770A83D21AA628816F0EE86E4D25A54E884BADD237600F5E272C252128E0F`

**Class:** `MECHANICAL_GREEN / LIVE_VISUAL_UNBOUND`.

Do not equate `CLEAN_NATIVE_EYES` with the unknown historical accepted single-window baseline.

---

# v10.2 ZERO_NATIVE_ONE_WINDOW

Result:
`CRYSIS2VR_ZERO_NATIVE_ONE_WINDOW_RESULT_20260819_020117.zip`

- bytes `44,732,261`
- genuine runtime image present.

**Class:** `LIVE_VISUAL_UNBOUND`.

`ONE_WINDOW` is a design label, not user acceptance.

---

# v11 CADENCE_FASTPATH

Result:
`CRYSIS2VR_CADENCE_FASTPATH_RESULT_20260818_133603.zip`
SHA256 `15B55E5001AE1C5C5F813E9D0C49F58E36E921FA427BE9BAA3263770930917C`.

Local PASS counters existed, but own arbiter:
`STRUCTURAL_ARBITER=REJECT_DO_NOT_CALL_FIXED`
`VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.

**Class:** `COMPONENT_ONLY / MECHANICAL EVIDENCE`.

---

# v13 / v13.1

`CRYSIS2VR_COMMAND_FORK_IDENTITY_20260819_065321`
`CRYSIS2VR_XR_NATIVE_IK_HANDS_20260819_071102`

Both have genuine full runtime-image evidence.

Direct user headset verdicts are not securely bound.

**Class:** `LIVE_VISUAL_UNBOUND`.

---

# v14 DUALWORLD

`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip`
SHA256 `A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`.

User reported completely black headset.

v14.0.3 lazy-gate child also received black-headset report.

**Class:** package/family `VISUAL_RED`.

Exact one-to-one raw-result timestamp binding remains partly OPEN.

---

# v15.1 NO_BINOCULAR

Package:
`CRYSIS2VR_COMMAND_TWIN_NO_BINOCULAR_v15.1.0.zip`

- bytes `80107`
- SHA256 `01E95B124CCBDC1161CDF3889449BF32EEAD665764C42BD682EAF1033321FC19`.

Game mechanics:
- eye-axis dot `1.0`;
- tiny FOV error;
- 800 dual scene pairs;
- L/R SetCamera active;
- pair copies active.

But x64 host:
- `visual_projection_layers=0`;
- `submitted_frames=0`.

Associated analyzer:
`VERDICT=INCONCLUSIVE_NO_EYE_DRAW_BINDING_LOCK`
`VISUAL_LAYER_SUBMITTED=NO`.

**Class:** `MECHANICAL_GREEN / VISUAL_NOT_TESTED`.

`NO_BINOCULAR` does not prove binocular fusion.

---

# HISTORICAL SINGLE-WINDOW PROFILE

19-Aug user oracle records:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- hand/weapon still wrong.

**Class:** user-accepted behavior profile.

Exact package/hash remains OPEN.

Do not guess it and do not project later independent wins backward into it.

---

# v17.2 / v17.2.1 DONOR SOURCE AUTHORITY

**Class:** donor corpus, not wholesale visual parent.

Physical donor:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.1_ARGV_FIX_ONECLICK.zip`

- bytes `91,521`
- SHA256 `53688524B59E9C8F7B768BFA78BB80DEDC0981EB7FF699204E496887668D38A2`
- original manifest `27/27 PASS`

Contains PosePair, HEAD/culling, weapon/NEAR and temporal/shadow candidates.
Import only serially after visual baseline recovery.

---

# CANONICAL EYE TRANSACTION

`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 snapshot -> render-thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`.

One prepared render-list executes twice.
No second top-level RenderWorld/EF_StartEf.

**Class:** mechanical renderer fact only.

---

# SUPPORTING ARCHAEOLOGY

Historical RenderDoc/resource `20500` lineage remains supporting evidence, not current gate.

Mono RGB+depth/Z reprojection remains falsified as final renderer.

Stock native 65mm SBS has its own right-eye softness control, so later RIGHT blur requires causal comparison rather than automatic XR-transport blame.

---

# RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
