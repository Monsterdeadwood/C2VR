# C2VR — HISTORICAL VISUAL ORACLES — 15–19 AUGUST 2026

## PURPOSE

This document reconstructs the visual history that was repeatedly lost when technical counters, package names, and later design summaries were allowed to overwrite the user's actual headset verdict.

It complements `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md` and `docs/FALSIFIED.md`.

For visual acceptance:

`USER_HEADSET_VERDICT > XR_CAPTURE > RAW RESULT > counters > package README > intended architecture`

A technical fact may be KEEP while the package that produced it is VISUAL REJECT.

---

# 1. EARLY BRING-UP: OPENXR ALIVE IS NOT VR

## 1.1 Mouse-look head control

Early bring-up used:

`HMD yaw/pitch -> SendInput mouse-look -> Crysis game camera`

User verdict:
- head movement changed the view;
- it behaved like a mouse;
- no true VR roll;
- not a real VR camera.

Classification:
- `OPENXR/INPUT BRING-UP = KEEP`
- `MOUSE_LOOK_AS_HEAD_OWNER = HARD STOP`

Permanent rule:
Never use mouse emulation as proof of HEAD ownership. It mixes HMD, body and game aim and cannot establish proper roll/6DoF.

## 1.2 `C2VR_NATIVE_MVP_v0.1.2`

User verdict:
- game loaded;
- HMD movement worked as mouse-look;
- headset was black.

What this proved:
- OpenXR host/session alive;
- pose alive;
- game launch/injection alive.

What it did NOT prove:
- visible VR output;
- camera ownership;
- stereo.

Classification:
`TECHNICAL_BRINGUP_KEEP / VISUAL_HARD_RED`.

## 1.3 First visible two-eye output

User verdict after the first visible eye transport:
- image existed;
- "two screens in two eyes";
- horizon did not stay spatially stable when head rotated/tilted.

Permanent rule:
`TWO_EYE_TEXTURES != VR`.

Transport success alone cannot promote a build to visual baseline.

---

# 2. OLD-PIXELS / NEW-POSE CONTRACT FAILURE

## 2.1 v1.0.4 flat image in front of face

User verdict:
"передо мной просто плоская картинка".

Known semantic error:
- Crysis render camera was NOT HMD-driven;
- `XrCompositionLayerProjectionView.pose` used the CURRENT HMD pose anyway.

The compositor was told, semantically, that the submitted image had already been rendered from the current HMD pose even though it had not.

This could produce the observed screen-glued-to-face behavior.

Classification:
`POSE_RELABEL = HARD STOP`.

Permanent rule:
Never attach a newer/current HMD pose to pixels that were rendered from a different/static/older pose.
Pixels + render pose + FOV + contract identity are one atomic truth unit.

---

# 3. CAMERA FEEDBACK FAILURE

## 3.1 `171947` all-SetCamera injection

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_171947.zip`

User observation:
- eyes nearly collapsed to the same image;
- camera moved/accumulated incorrectly.

Runtime proof:
- 52,170 adjacent camera-pair observations;
- 99.837% `next_camera_input == previous_injected_output`;
- median matrix error 0.

Failure:
`G -> G*HMD -> G*HMD^2 -> G*HMD^3 ...`

Permanent rule:
Never apply HMD at every downstream `Renderer::SetCamera`.

Salvage:
The later single-source discovery around `Crysis2.exe+0x0057AC76` remains a valuable upstream ownership topology reference.

---

# 4. NATIVE / NVIDIA / MONITOR-STEREO FAMILY

## 4.1 `205430` real Quest IPD/FOV graft

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_205430.zip`

User verdict:
- flicker;
- wrong stereo;
- shadows disappeared/changed;
- eye-dependent lighting/state instability.

Permanent rule:
Do not turn Crysis monitor stereo into final VR merely by replacing monitor eye separation/FOV with real Quest IPD/XrView values.

Shared deferred/screen-space/shadow/temporal state can remain binocularly incoherent even if eye geometry is mathematically different.

## 4.2 `STABLE_CAMERA v2.2.0` / `010329`

Result context:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_010329.zip`

The branch simplified camera policy heavily, but user still reported severe flicker.
Weapon could appear controlled, but firing remained tied to monitor/game center.

Permanent rule:
A simpler camera owner does not repair a broken stereo/render-state architecture by itself.

## 4.3 `A1_HISTORY_FIX_RESULT_20260817_175934`

This result is a critical component-separation checkpoint.

User verdict:
- the only useful thing was the crooked controller weapon/hand that fired along the weapon direction;
- the image was still the bad two-image Nvidia/CryEngine stereo and flickered;
- user explicitly ordered the old stereo path thrown away completely.

Classification:
- `WEAPON_DIRECTION_COMPONENT = KEEP`
- `HAND_RIG_VISUAL = BAD`
- `NVIDIA/CRY STEREO VISUAL BASELINE = HARD RED`

Permanent rule:
Never use weapon-direction success as permission to preserve the renderer that surrounded it.

## 4.4 Native/NVIDIA project-direction rejection

The user explicitly rejected the old NVIDIA/3D/native-monitor-stereo route as a final architecture even though head movement had partially worked.

This is not merely an old implementation bug. It is a project-level STOP decision.

---

# 5. FALSE GOLD: REWRITE v4.0.0

Package:
`CRYSIS2VR_REWRITE_v4.0.0_EXACT_XR_STEREO_GOLD_WEAPON_PORTABLE.zip`

Historical SHA256:
`08A8C4238EDC8046C2B46A3BECA1D19A86825DE9FE8C2ACADE62B2CF51047BB6`

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_023510.zip`

The package attempted exact XrView pose/IPD/asymmetric FOV on persistent eye-camera shadows while keeping native ProcessScene and separate NEAR handling.

Immediate user verdict:
"да хуйня полная ... рука тоже из жопы крутится ... изображение ... не настроить"

Classification:
`USER_VISUAL_HARD_RED`.

Permanent rule:
The string `GOLD_WEAPON` in a filename has zero evidentiary value.
Do not inherit this package as a visual parent.
021239/A1-era weapon firing may be reused only as a narrow component donor.

---

# 6. A1 NATIVE REPAIR: CAMERA-CLOSER CHECKPOINT

Result:
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

User observation:
- turning head left/right did move the in-game camera/world;
- the main remaining problem was the flicker / two-screen behavior;
- user described the state as very close.

Classification:
`CAMERA_OWNERSHIP_REFERENCE_ONLY`.

This is important because it proves a historically better camera behavior existed before later renderer mutations.
Do not inherit its native/Nvidia final stereo.

---

# 7. v6.0.x: WORLD STABILITY / NO-FLICKER CHECKPOINT

## 7.1 v6.0.0 regression result

Historical architecture decision states that v6.0.0 visually restored:
- normal mono world;
- normal textures;
- stable shadows.

Native Cry stereo/SBS remained rejected.

The remaining faults were narrowed to XR pacing and binocular composition.

## 7.2 v6.0.1 user result

This is one of the strongest partial-green visual checkpoints in project history.

Recorded user result:
- flicker is gone;
- shadows/textures/objects are stable;
- eyes still do not fuse.

The v6.0.1 pacing change kept a local last-good completed frame in XR64 instead of submitting zero projection layers every time Quest requested a frame before the next game Present.

Important distinction:
This is NOT final stereo. The world image was still not a correct binocular VR pair.

Classification:
`WORLD_STABILITY_NO_FLICKER_REFERENCE = KEEP`
`BINOCULAR_STEREO = FAIL`

Exact physical v6.0.1 package carrier/hash is still not recovered with enough confidence. Do not invent it.

Closest preserved descendant/documentary carrier:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.2_NO_FLICKER_EXACT_SOURCE_PROJECTION_PORTABLE.zip`
SHA256 `FA9835A71744211F84B84C0923BEF51EC316BD5FD426B3411CEE6AFEA68801D5`

That descendant contains `ARCHITECTURE_DECISION_v6.0.1.md` and the inherited runner lineage, but it is not automatically the exact visual v6.0.1 package.

## 7.3 v6.1.0 A fusion-proof quad

Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.1.0_A_FUSION_PROOF_QUAD_PORTABLE.zip`
SHA256 `1CDF50E1EF1E25A1CCB33C48D0795732CDF1601F586F5F4FFAE75B489913AEFE`

Purpose:
Change only composition primitive to a single VIEW-space BOTH-eye quad to prove that a stable 2D image can fuse without pretending it is stereo.

A PASS here would only prove compositor/display fusion, not final stereo.

Classification:
`COMPOSITOR_CONTROL_ONLY`.

---

# 8. v8/v9/v10: DO NOT CONFUSE CLEANER IMAGE WITH FULL VR PASS

Historical v10-era council evidence preserved two important facts:
- no-flicker behavior was already considered GREEN and must not regress;
- `r_MotionBlur=0` and `r_PostMSAA=0` corresponded to a cleaner image reported by the user.

But the same era still had user-visible failures including:
- wrong/strange world scale;
- first-person weapon counter-rotating against head motion;
- jitter/blur on side-to-side head motion.

Result explicitly referenced by v10.1 design:
`CRYSIS2VR_WORLD_NEAR_DUAL_DEPTH_RESULT_20260818_022454.zip`

Its two user-visible failures were recorded as:
1. wrong / strange WORLD scale;
2. first-person weapon counter-rotating against head motion.

Permanent rule:
A cleaner/no-flicker image is a component PASS only. It does not establish world scale, near/viewmodel ownership, stereo fusion or comfort.

## v8/v9 near ownership

Historical numeric `near_left=55 / near_right=6634` was later proven to be invalid ownership evidence caused by a cross-thread/global active-eye assumption.

Permanent rule:
Never use a main-thread/global active-eye variable to classify render-thread `FOB_NEAREST` ownership.

---

# 9. FOB_NEAREST OWNER TRUTH: EVIDENCE KEEP, VISUAL REJECT

Fresh results:
- `CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_012736.zip`
- `CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_013107.zip`

The runtime result established a strong technical fact:
- LEFT/RIGHT CopyToStereo boundary alternation was coherent;
- near events assigned using render-thread next-eye prediction were balanced;
- dominant NEAR caller was `+0x000FF456` on both eyes;
- old v7 near asymmetry evidence was false.

But the contemporaneous user visual oracle explicitly says the actual visual result was completely wrong/broken.

Classification:
`OWNER_TIMING_EVIDENCE = KEEP`
`VISUAL_BASELINE = REJECT`

Permanent rule:
Never promote a diagnostic/oracle package to visual parent just because its causal counter result is excellent.

---

# 10. NATIVE_NEAR_PASSTHROUGH: REVERSE CONTROL ONLY

Package family:
`CRYSIS2VR_NATIVE_NEAR_PASSTHROUGH_v7.0.4_REVERSE_CONTROL.zip`

Historical SHA256:
`EEA8857B1B45D97668EFD09CDB168E7010B223AAD22F2FDE7F01D255074AC8F7`

Numeric reverse-control checks passed, but the branch was not accepted as the desired visual baseline.

Classification:
`CAUSAL_REVERSE_CONTROL = KEEP`
`VISUAL_PARENT = NO`

---

# 11. 19 AUGUST GOOD SINGLE-WINDOW REFERENCE

A dedicated `CRYSIS2VR USER VISUAL ORACLE — 18–19 AUGUST 2026` records the project decision:

RETIRE:
- SBS/Nvidia path;
- two-window target;
- black-headset/moving-monitor interpretations;
- global active-eye near ownership.

KEEP / RECOVER:
`last good native single-window branch`

Recorded visual characteristics to recover:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- image present in headset;
- only hand/weapon still visibly wrong.

This is one of the most important recovery targets in the entire project.

Critical archival fact:
The contemporaneous handoff itself says the exact good single-window lineage/hash was still a blind zone and must be reconstructed before mutation.

Therefore classification is:
`USER_ACCEPTED_BEHAVIOR_PROFILE = KEEP`
`EXACT_PACKAGE_IDENTITY = OPEN`

Do not guess the parent package from temporal adjacency.

---

# 12. NO-CRY-STEREO TEMPORAL EYES: PRESENT IS NOT EYE AUTHORITY

A later no-Cry-stereo temporal experiment established another structural STOP:
- two logical eye renders could be scheduled around RenderWorld;
- Present capture did not preserve that eye identity 1:1;
- observed scheduling/capture counts included `417/417` planned against `396/264` effectively captured;
- L/R could therefore represent different moments/cameras rather than a coherent binocular pair;
- branch also crashed `0xC0000005`.

Permanent rule:
`PRESENT != AUTHORITATIVE EYE OWNER`.

Never infer eye identity from a main-thread/global marker and expect Present to preserve it.

---

# 13. `181936`: COUNTERS ALIVE, VISUAL/THREAD PATH DEAD

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_181936.zip`

Historical manifest records:
- first pair reached OpenXR;
- then crash `0xC0000005` at `CryRenderD3D11.dll+0x0008A117` after RC copy #3;
- old RC callback performed `CopyResource/Flush` and copied a near-black swapchain/backbuffer.

Classification:
`ROUTE_REACHED = KEEP AS FORENSIC FACT`
`RC_CALLBACK_COPYRESOURCE/FLUSH POLICY = HARD STOP`
`VISUAL BASELINE = HARD RED`

Permanent rule:
Nonzero L/R/RC/copy counters do not make a renderer path safe or visible.
Do not perform unsafe D3D copy/flush work from an unproven render-command callback/thread context.

---

# 14. v11/v12 BINOCULAR / TELESCOPE FAMILY

User repeatedly described this era as:
- telescope / binocular view;
- severe eye misalignment;
- completely wrong despite technical progress.

Classification:
`FAMILY_BOUND_VISUAL_HARD_RED`.

Do not guess one exact neighboring v11/v12 ZIP as the sole cause without binding the exact user RESULT.

## Important later lesson
A later v15.1-style "NO_BINOCULAR" technical path could report approximately:
- eye-axis dot near +1;
- tiny asymmetric FOV numerical errors;
- hundreds of dual scene pairs;

Yet historical user binocular complaints were not thereby globally closed.

Permanent rule:
`EYE_AXIS_DOT + FOV_NUMERIC_MATCH != VISUAL_FUSION_PROOF`.

Binocular acceptance requires actual headset fusion and pixel/render-owner coherence.

---

# 15. DUALWORLD v14 BLACK-HEADSET FAMILY

## v14.0.2
Package:
`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip`
SHA256 `A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`

User verdict:
headset completely black.

Contemporary result files include:
- `C2VR_DUALWORLD14_RESULT_20260819_162623.zip`
- `C2VR_DUALWORLD14_RESULT_20260819_162900.zip`

Exact one-to-one binding to the verbal verdict is not strong enough to assign blindly.

## v14.0.3 lazy gate
Package:
`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.3_LAZY_GATE_HOTFIX.zip`

User again reported startup OpenXR signaling and completely black headset output.

Permanent rule:
Do not patch-number-forward from a black-headset parent. Revert to a visible baseline first.
High-level duplicate-DualWorld is not the preferred final scheduler.

---

# 16. GLOBAL ARCHITECTURAL LESSONS RECOVERED FROM USER HISTORY

1. `OPENXR_SESSION_ALIVE != VISIBLE_VR`.
2. `TWO_EYE_TEXTURES != VR`.
3. `NON_DUPLICATE_L/R != FUSED_STEREO`.
4. `CURRENT_HMD_POSE != VALID_LAYER_POSE` unless those pixels were rendered from that pose.
5. `GOOD_CAMERA_MOTION != GOOD_STEREO`.
6. `GOOD_WEAPON_DIRECTION != GOOD_RENDERER`.
7. `NO_FLICKER != CORRECT_STEREO`.
8. `GOOD_COUNTERS != USER VISUAL PASS`.
9. `GOOD OWNER ORACLE != GOOD PLAYABLE BUILD`.
10. `PRESENT != EYE OWNER`.
11. `EYE AXIS/FOV NUMERIC MATCH != BINOCULAR FUSION`.
12. `GOLD/CLEAN/NO_BINOCULAR` in a package name is not evidence.
13. Never simultaneously mutate world stereo + transport + near camera + weapon and then claim causality.
14. When a user-accepted single-window baseline existed, recover its exact physical lineage before replacing the renderer.
15. Downstream GPU/constant-buffer camera mutation is a diagnostic/verifier technique, not a default final gameplay-camera owner. CPU camera, culling, shadows, sky, NEAR and gameplay systems may already have consumed a different camera.

---

# 17. RECOVERY PRIORITY AFTER THIS RECONSTRUCTION

Do not choose the newest package.
Recover properties independently:

### A. World stability reference
v6.0.1 behavior:
- no flicker;
- stable textures/shadows/objects;
- binocular fusion still unresolved.

### B. Camera ownership reference
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` and single-source `+0x0057AC76` lineage.

### C. Historical best complete behavior profile
19 Aug `last good native single-window branch`:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image visible;
- hand/weapon still wrong.

Exact package/hash remains to be recovered before any mutation.

### D. Weapon direction donor
A1/021239/175934-era controller-to-fire behavior only.
Do not inherit the surrounding renderer.

### E. True private L/R renderer primitive
`CUSTOM_DUAL_T1 v1.0.1` technical proof only.
Do not use it as automatic visual parent after later user HARD RED descendants.

The next useful build must be a reproduction/bisect from one recovered accepted/reference lineage, not another multi-system synthesis.
