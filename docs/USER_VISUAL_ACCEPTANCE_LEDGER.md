# C2VR - USER VISUAL ACCEPTANCE LEDGER / PERMANENT LINEAGE GUARD

## PURPOSE

This file prevents visually failed Crysis 2 VR architectures from being remembered as working because of counters, package names, static checks, or later summaries.

The user's in-headset verdict is an acceptance signal, not anecdotal commentary.

For second-pass provenance also read:
- `docs/HISTORICAL_VISUAL_ORACLES_20260815_19.md`
- `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
- `docs/FALSIFIED.md`

## PRECEDENCE

For visual/playability questions:

`USER_HEADSET_VERDICT > deterministic L/R captures > raw LIVE RESULT/runtime logs > counters > static validation > design intent`

A package can have perfect counters and still be a visual HARD RED.

User terms such as:
- `пиздец`
- `моргает`
- `камера уезжает/проваливается`
- `тени пропадают/ездят`
- `неправильное стерео`
- `экран перед лицом`
- `бинокуляр/подзорная труба`
- `в очках всё чёрное`

are hard visual evidence when bound to a known run/package.

## STATUS LANGUAGE

Bare `GREEN` is forbidden.

Use:
- `NOT_LIVE`
- `LIVE_VISUAL_UNBOUND`
- `MECHANICAL_GREEN`
- `COMPONENT_VISUAL_GREEN`
- `FULL_USER_VISUAL_GREEN`
- `VISUAL_RED`
- `COMPONENT_ONLY`
- `UNBOUND_VISUAL_RED`
- `VACUOUS_PASS_INVALID`

`FULL_USER_VISUAL_GREEN` is the only status that can authorize a whole-build visual parent.

## PARENT SELECTION LAW

1. A `VISUAL_RED` package MUST NOT be used as the direct parent of another visual/camera/stereo descendant.
2. It may be reused only as a narrow donor for a proven component with the failed visual policy explicitly excluded.
3. `PASS`, `GOLD`, `GREEN`, `CLEAN`, `MAIN`, `PROVEN`, `NO_BINOCULAR`, `ONE_WINDOW`, `SAFE_VISUAL`, source authority, or high counters never override a headset RED.
4. If a run changed camera + stereo + temporal + shadow + weapon/NEAR together, it cannot establish which policy is good.
5. One new visual LIVE = one causal mutation from a reproduced property baseline.
6. If exact package/result identity is missing, record `OPEN`, `UNBOUND`, or family-bound evidence. Never guess from neighboring timestamps.
7. A technical renderer proof is not visual-parent proof.
8. A black headset result is a visual/runtime failure even if the desktop/game process is alive.
9. Telescope/binocular geometry is a visual architecture failure, not a convergence setting to tune indefinitely.
10. Pixels + render pose + FOV + ticket/contract identity are one atomic truth. Never relabel old/static pixels with a newer HMD pose.
11. Numeric eye-axis/FOV match is not binocular-fusion proof.
12. A diagnostic/oracle build may prove one fact while remaining visually rejected as a whole.
13. `RESULT ZIP != LIVE`. Target runtime execution must be proven.
14. `VACUOUS_PASS` is invalid. A PASS with zero/None/missing prerequisites has no evidentiary value.

---

# HARD RED LEDGER

## Early bring-up - visible transport is not VR

### `C2VR_NATIVE_MVP_v0.1.2`
User-observed state:
- game launched;
- HMD movement drove mouse-like view movement;
- headset remained black.

Classification:
`MECHANICAL_GREEN: BRINGUP`
`VISUAL_RED`.

Permanent stop:
- mouse-look/SendInput is not final HEAD ownership;
- live OpenXR/session/pose does not imply visible VR output.

### First visible two-eye stage
User observation:
- image existed;
- effectively two screens in two eyes;
- horizon/world did not remain spatially locked.

Permanent stop:
`TWO_EYE_TEXTURES != VR`
`NON_DUPLICATE_LR != FUSED_STEREO`.

### Early pose-relabel / flat-screen stage
User described a flat image in front of the face while the submitted current HMD pose did not match the camera that rendered those pixels.

Permanent stop:
never tell the compositor that pixels were rendered from a pose they were not rendered from.

## 2026-08-16 - all-SetCamera HMD feedback loop
Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_171947.zip`.

User observation:
- eyes nearly collapsed to the same image;
- camera moved/accumulated incorrectly.

Runtime proof:
- pre-intervention L/R difference about `19.60..23.75`;
- post-intervention median L/R difference about `1.34`;
- `52,170` adjacent camera-pair observations;
- `99.837%` had next input equal previous injected output;
- median matrix error `0`.

Failure:
`G -> G*HMD -> G*HMD^2 -> G*HMD^3 ...`

Permanent stop:
never apply HMD at every downstream `Renderer::SetCamera`.

Useful salvage:
single-source once/logical-frame camera lineage around `Crysis2.exe+0x0057AC76`.

## 2026-08-16 - `203734 / 204156` exact-eye math, visual RED
Telemetry proved:
- real HMD XYZ/6DoF;
- accurate Quest IPD propagation;
- accurate XrView FOV propagation.

Saved XR captures corrected the earlier optimistic interpretation.

Critical within-run control from `204156`:
- `camera_locked=0`: image looked normal;
- `camera_locked=1`: small HMD rotation produced huge black near/viewmodel blades and broken geometry.

Recovered cause:
- world near about `0.12`;
- `FOB_NEAREST` near about `0.03`;
- world-eye asymmetry was inherited unchanged into the near camera;
- near off-axis effect became roughly 4x too strong;
- narrow center-frustum visibility preceded wider Quest-eye views and caused culling/popping.

Classification:
`MECHANICAL_GREEN: POSE_IPD_FOV_MATH`
`VISUAL_RED: SURROUNDING_RENDERER`.

## 2026-08-16 - real Quest IPD/FOV on native monitor stereo
Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_205430.zip`.

User verdict:
- flicker;
- wrong stereo;
- shadows disappeared/changed;
- eye-dependent lighting/state instability.

Saved L/R captures corroborated lighting/shadow/near disagreement.

Permanent stop:
real Quest IPD/FOV does not turn native monitor stereo into correct VR.

## 2026-08-17 - STABLE_CAMERA v2.2.0
Known result context:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_010329.zip`.

User observation:
- image still flickered badly;
- weapon could move in hand;
- firing still followed monitor/game-center aim.

Permanent stop:
single-camera simplification + native stereo is not sufficient VR.

## 2026-08-17 - native/NVIDIA final direction rejected
The user explicitly rejected the native/NVIDIA/monitor-stereo path after repeated flicker/flashes.

Classification:
`VISUAL_RED AS FINAL ARCHITECTURE`.

Use only for archaeology/control.

## 2026-08-17 - A1 history fix, weapon-direction donor only
Result:
`CRYSIS2VR_A1_HISTORY_FIX_RESULT_20260817_175934.zip`.

User verdict:
- crooked controller weapon/hand could fire along weapon direction;
- image remained bad two-image flickering Nvidia/Cry stereo;
- renderer should be discarded.

Classification:
`COMPONENT_VISUAL_GREEN: WEAPON_DIRECTION`
`VISUAL_RED: SURROUNDING_RENDERER`.

## 2026-08-17 - false GOLD rewrite v4.0.0
Package:
`CRYSIS2VR_REWRITE_v4.0.0_EXACT_XR_STEREO_GOLD_WEAPON_PORTABLE.zip`

SHA256:
`08A8C4238EDC8046C2B46A3BECA1D19A86825DE9FE8C2ACADE62B2CF51047BB6`.

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_023510.zip`.

Immediate user verdict rejected image and hand behavior.

Classification:
`VISUAL_RED`.

`GOLD_WEAPON` in a filename has zero authority.

## 2026-08-17 - unsafe old RC copy route
Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_181936.zip`.

Historical evidence:
- first pair reached OpenXR;
- crash `0xC0000005` after RC copy #3;
- RC callback performed `CopyResource/Flush` in an unproven thread/context and copied near-black data.

Classification:
`MECHANICAL_GREEN: ROUTE_REACHABILITY`
`HARD_STOP: RC_COPY_FLUSH_POLICY`
`VISUAL_RED`.

## Z-reprojection v6.1 / `201832`
This is a different v6.1 line from A/FUSION_PROOF_QUAD.

Direct user verdict:
- no meaningful improvement;
- head left made weapon move right;
- image very blurred.

Classification:
`VISUAL_RED`.

Never merge it with the separate compositor-control v6.1 line into “v6.1 worked”.

## 2026-08-19 - telescope/binocular family
User rejected the v11/v12-era family as telescope/binocular, severely misaligned, and visually wrong.

Exact single package/result binding remains unresolved.

Classification:
`UNBOUND_VISUAL_RED / FAMILY_BOUND`.

Permanent stop:
- do not revive telescope/binocular eye composition;
- do not tune arbitrary convergence as the fix;
- do not guess a neighboring package as accepted;
- eye-axis/FOV numeric match is not fusion proof.

## 2026-08-19 - DualWorld v14.0.2
Package:
`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip`

SHA256:
`A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`.

User verdict:
headset completely black.

Contemporary result ZIPs exist, but exact one-to-one result timestamp binding remains open.

Classification:
`VISUAL_RED / PACKAGE_BOUND / RESULT_UNBOUND`.

## v14.0.3 lazy gate
User again reported startup OpenXR signaling and a black headset.

Classification:
`VISUAL_RED / PACKAGE_BOUND / RESULT_UNBOUND`.

Do not patch-number forward from a black-headset parent.

## 2026-08-22 - severe geometry/image-quality RED
Recovered user verdict:
- extreme lateral separation;
- blur;
- compressed/bad-looking image.

Exact package/result identity remains unresolved.

Classification:
`UNBOUND_VISUAL_RED`.

## 2026-08-25 - `063149`
Raw result:
`C2VR_RC33_V1721_RESULT_20260825_063149.zip`.

Pair transport was alive, but user reported catastrophic camera/world instability with moving/sliding light/shadow state.

Classification:
`VISUAL_RED`.

No direct visual descendants.

## 2026-08-25 - T1 PosePair-only K0
Package:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`.

User verdict:
visually even worse than prior rejected build.

No fresh RESULT ZIP is bound. Do not invent counters.

Classification:
`VISUAL_RED / RESULT_ZIP_NOT_BOUND`.

No K1/K2/HEAD/weapon/temporal/shadow descendants.

---

# FALSE-LIVE / FALSE-PASS GUARDS

## `010051`
`CRYSIS2VR_C2_NATIVE_RESULT_20260816_010051.zip`

- size `676` bytes;
- SHA256 `FC65F37E1B5F70F424866B99650C8B66FEA6A54EAD7C5434FFF32A736FB16216`;
- Zig self-test failed;
- `GameFilesTouched=False`.

Classification:
`NOT_LIVE`.

It did not test WORLDLOCK.

## `011323`
`CRYSIS2VR_C2_NATIVE_RESULT_20260816_011323.zip`

- size `3774` bytes;
- SHA256 `432E36FB784315A74A8BA6245FDC82B249B08877AC57F569CB6434C34601DAFF`;
- OpenXR loader preflight failed;
- `GameFilesTouched=False`.

Classification:
`NOT_LIVE`.

## VACUOUS_PASS
Historical analyzer output can report PASS when required inputs are absent, including patterns such as:
- `FramePoseIntegrity` with `None/None/None`;
- RightTouch/hand checks with zero observations;
- empty no-fault fields when target code never ran.

Classification:
`VACUOUS_PASS_INVALID`.

Future analyzer law:
if prerequisites are absent, return `NA/NOT_EXECUTED` or FAIL, never PASS.

---

# PARTIAL POSITIVE / SALVAGE CHECKPOINTS

These are NOT whole-build GOLD unless explicitly marked `FULL_USER_VISUAL_GREEN`.

## v6.0.1 - exact physical world-stability checkpoint
Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Exact size:
`164221 bytes`.

Exact SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact inherited runner:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did NOT fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`
`BINOCULAR_FUSION = FAIL`.

Important mechanism:
- cache/reuse last complete frame rather than emit empty projection layers when XR outruns game Present;
- publish frame/packet metadata before keyed-mutex release;
- keep pixels and their render metadata atomic.

Recovered source hashes:
- `engine_tap.cpp` `60F29B0FAE02BC1E751B5FD916C1B82736D3CAA97EB4A99D3F07DE7379D28CB8`
- `c2vr_host_client.cpp` `2477C256F9E621DEFFB9F6114FE6275865FA86E9826FD2CD8D8A21143472DDFD`
- `c2vr_openxr_host.cpp` `21853D54D58C37BC90F0A610CF62475173F2CD942D7F40709FCB3BA6B3608D20`
- `porous_proxy.cpp` `39A96807DC15EB60AE110EA17C7D2D8A903DD4D8BE81184CCAE1A0A81D83B31E`
- `c2vr_shared.h` `104E933B47464069D40DE1231B0FA13449B1290AA8CE91F6355F941F4B329508`.

The previous ledger statement that the exact v6.0.1 ZIP SHA was unrecovered is superseded.

## v6.1 A/FUSION_PROOF_QUAD
Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.1.0_A_FUSION_PROOF_QUAD_PORTABLE.zip`
SHA256 `1CDF50E1EF1E25A1CCB33C48D0795732CDF1601F586F5F4FFAE75B489913AEFE`.

It intentionally submitted one VIEW-space both-eye 2D quad.

Classification:
`MECHANICAL_GREEN: COMPOSITOR_CONTROL_ONLY`.

Later quality analysis rejected it as a visual-success renderer. It is not true stereo.

## A1 native-repair camera checkpoint
Result:
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`.

User-positive property:
turning head left/right moved the real game camera/world; remaining major problem was flicker/two-screen behavior.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

Do not inherit old native/NVIDIA final stereo.

## Single-source camera ownership
Package:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Policy:
- HMD injected once at `Crysis2.exe+0x0057AC76`;
- downstream SetCamera calls pass through.

Classification:
`COMPONENT_ONLY: HEAD_OWNERSHIP_TOPOLOGY_REFERENCE`.

## `191909`
Classification:
`COMPONENT_ONLY: LOW_DIVERGENCE_NATIVE_STEREO_CONTROL`.

Not final VR geometry.

## `203734 / 204156`
KEEP only:
- pose propagation;
- IPD/FOV math;
- `camera_locked=0` vs locked corruption control.

Classification:
`MECHANICAL_GREEN: POSE_MATH`
`VISUAL_RED: RENDERER_POLICY`.

## `021239 / 175934`
KEEP only controller-directed firing behavior.

Classification:
`COMPONENT_VISUAL_GREEN: WEAPON_DIRECTION_DONOR`.

Do not infer camera/stereo/hand-rig acceptance.

## `FOB_NEAREST OWNER TRUTH`
Results include:
- `CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_012736.zip`
- `CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_013107.zip`

Useful fact:
render-thread prediction produced balanced near ownership and identified dominant near caller around `+0x000FF456`.

Contemporaneous visual result was rejected.

Classification:
`MECHANICAL_GREEN: NEAR_OWNER_TIMING`
`VISUAL_RED: WHOLE BUILD`.

## v7.0.2 source-size transport
Package:
`CRYSIS2VR_CLEAN_NATIVE_EYES_v7.0.2_SOURCE_SIZE_XR_TRANSPORT.zip`

- size `161846` bytes;
- SHA256 `B143D04F6CB0D3C77058380DCBD04A6196C64E21AB60EEC8B2FFDEEB54E3478E`.

Result:
`CRYSIS2VR_CLEAN_NATIVE_SOURCE_SIZE_RESULT_20260819_001036.zip`

- size `36858996` bytes;
- SHA256 `C6D770A83D21AA628816F0EE86E4D25A54E884BADD237600F5E272C252128E0F`.

Classification:
`MECHANICAL_GREEN / LIVE_VISUAL_UNBOUND`.

Do not promote it to historical good single-window baseline without direct user evidence.

## v10 `034749`
Result:
`CRYSIS2VR_UNIFIED_NEAR_PROJECTION_RESULT_20260818_034749.zip`

- size `48,769,328` bytes;
- SHA256 `3E234BE937B305009C9DFE24D53B2C7E8E2A008AD873BF253C165386F132661F`.

Primary arbiter proves strong structural facts:
- WorldCenter PASS;
- UnionFrustum PASS;
- FOBNearestProjectionUnified PASS;
- XR transport live;
- old native stereo off;
- restore PASS.

But primary arbiter states:
`STRUCTURAL_ARBITER=READY_FOR_VISUAL_TEST`
`VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.

A later secondary historical summary attributes improved weapon/world counter-motion to this run, but the direct adjacent primary user message is not securely recovered.

Classification:
`MECHANICAL_GREEN`
`SECONDARY_USER_VISUAL_SUMMARY`
`FULL_USER_VISUAL_GREEN = NO`.

## v10.2 ZERO_NATIVE_ONE_WINDOW `020117`
Genuine LIVE with full runtime image.

Direct user visual verdict is not securely bound.

Classification:
`LIVE_VISUAL_UNBOUND`.

`ONE_WINDOW` in the name is not acceptance evidence.

## v11 CADENCE_FASTPATH
Local structural PASS counters existed, but its own arbiter said:
`STRUCTURAL_ARBITER=REJECT_DO_NOT_CALL_FIXED`
`VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.

Classification:
`COMPONENT_ONLY`.

## v13 / v13.1
Full runtime evidence exists for:
- `CRYSIS2VR_COMMAND_FORK_IDENTITY_20260819_065321`
- `CRYSIS2VR_XR_NATIVE_IK_HANDS_20260819_071102`.

Direct user visual verdicts remain unbound.

Classification:
`LIVE_VISUAL_UNBOUND`.

## v15.1 NO_BINOCULAR
Package:
`CRYSIS2VR_COMMAND_TWIN_NO_BINOCULAR_v15.1.0.zip`

- size `80107` bytes;
- SHA256 `01E95B124CCBDC1161CDF3889449BF32EEAD665764C42BD682EAF1033321FC19`.

Game-side mechanics included:
- eye-axis dot `1.0`;
- tiny FOV errors;
- hundreds of dual scene pairs/copies.

But host status had:
`visual_projection_layers=0`
`submitted_frames=0`.

Associated analyzer:
`VERDICT=INCONCLUSIVE_NO_EYE_DRAW_BINDING_LOCK`
`VISUAL_LAYER_SUBMITTED=NO`.

Classification:
`MECHANICAL_GREEN / VISUAL_NOT_TESTED`.

The package name `NO_BINOCULAR` does not prove binocular fusion was fixed.

## x86 game + x64 OpenXR host
Classification:
`MECHANICAL_GREEN: INFRASTRUCTURE`.

It says nothing by itself about visual camera/stereo correctness.

## CUSTOM_DUAL_T1 v1.0.1
Canonical result:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

Proves true private L/R retail renderer mechanics.

Classification:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

Not sufficient whole-build visual-parent evidence after later user HARD RED descendants.

---

# HISTORICAL SINGLE-WINDOW BEHAVIOR PROFILE

18-19 Aug user visual oracle explicitly records a useful reference behavior:
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

Do not guess it from temporal adjacency.
Do not back-project every later independent success into this unknown package.

---

# UNTESTED / MISLABELLED CANDIDATES

## FRUSTUM_COHERENCE_FOB_NEAREST v1.2.6
Package:
`CRYSIS2VR_FRUSTUM_COHERENCE_FOB_NEAREST_v1.2.6_OVERWRITE_LAB.zip`
SHA256 `E59D1266CDFD12BD7F853813C276CDD65C2C2B3ECA00CE269D50B902D5A692F6`.

The child had a generated-source compile artifact and did not establish a valid visual PASS. v1.2.7 was a build fix with architecture unchanged.

Classification:
`NOT_VISUAL_GOLD / ARCHITECTURAL_CANDIDATE ONLY`.

Never cite v1.2.6 as the fix that worked.

---

# CURRENT RECOVERY POLICY

Current gate:
`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`.

Property-based recovery order:
1. reproduce exact physical v6.0.1 unchanged with its real runner to recover no-flicker/stable-world behavior;
2. continue archival recovery of the exact historical single-window package without guessing;
3. preserve/reproduce A1/single-source camera ownership separately;
4. preserve T1 private-L/R mechanics separately;
5. preserve weapon-direction donor separately;
6. combine only after each property is revalidated against an unchanged baseline.

Required sequence for any new whole-build visual parent:
1. exact physical package + exact runner;
2. unchanged reproduction;
3. fresh RESULT + explicit headset verdict;
4. freeze exact hashes;
5. one visual mutation per child;
6. immediate STOP/revert on catastrophic regression.

No future branch may cite counters, names, static PASS, or vacuous analyzer PASS to bypass this ledger.

## OPEN ITEMS MUST REMAIN OPEN

1. Exact physical package/hash behind the 18-19 Aug last-good native single-window behavior profile.
2. Direct user verdicts for Z-reprojection v6.2/v6.3/v6.4.
3. Direct adjacent primary user message for v10 `034749`.
4. Direct user visual verdict for v7.0.2 `001036`.
5. Direct user visual verdicts for v13/v13.1.
6. Exact raw-result timestamp binding for v14 black-headset reports.
7. Exact package binding inside the v11/v12 telescope/binocular family.

An OPEN label is safer than a false GOLD.
