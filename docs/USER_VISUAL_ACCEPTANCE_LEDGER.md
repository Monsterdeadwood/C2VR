# C2VR — USER VISUAL ACCEPTANCE LEDGER / PERMANENT LINEAGE GUARD

## PURPOSE
This file is a permanent project guard against repeating visually failed Crysis 2 VR architectures.

The user's in-headset visual verdict is an acceptance signal, not anecdotal commentary.

## PRECEDENCE
For visual/playability questions use this order:

`USER_HEADSET_VERDICT > deterministic L/R captures > raw RESULT/runtime logs > counters > static validation > design intent`

A package can have perfect counters and still be a HARD VISUAL RED.

Words such as "пиздец", "моргает", "камера уезжает/проваливается", "тени пропадают/ездят", "неправильное стерео", "экран перед лицом", "бинокуляр/подзорная труба", "в очках всё чёрное" are hard rejection evidence when attached to a known run/package.

## PARENT SELECTION LAW
1. A `USER_VISUAL_HARD_RED` package MUST NOT be used as the direct parent of another visual/camera/stereo descendant.
2. It may be reused only as a narrow donor for a source-proven component, with the failed visual policy excluded explicitly.
3. `PASS`, `GOLD`, `CLEAN`, `MAIN`, `NO_BINOCULAR`, `source authority`, or high counters never override a user visual RED.
4. If a run changed camera + stereo + temporal + shadow + weapon/NEAR together, it cannot establish which of those policies is good.
5. One new visual LIVE = one causal mutation from the nearest non-red or partially accepted checkpoint.
6. If exact package/result identity is missing, record `UNBOUND_VISUAL_RED`; never guess the package from neighboring chat messages.
7. A technical renderer proof is not automatically a visual-parent proof.
8. A black headset result is a hard execution/transport/render failure even if the desktop/game process is alive.
9. Telescope/binocular geometry is a visual architecture failure, not a cosmetic convergence problem to tune indefinitely.
10. Pixels + render pose + FOV + ticket/contract identity are one atomic truth. Never relabel old/static pixels with a newer HMD pose.
11. A clean numeric eye-axis/FOV match is not binocular-fusion proof.
12. A diagnostic/oracle build may be KEEP for one fact while remaining visually rejected as a whole build.

---

# HARD RED LEDGER

## Early bring-up — visible transport is not VR

### `C2VR_NATIVE_MVP_v0.1.2`
User-observed state:
- game launched;
- HMD movement drove mouse-like view movement;
- headset remained black.

Classification:
`TECHNICAL_BRINGUP_KEEP / VISUAL_HARD_RED`.

Permanent stop:
- mouse-look/SendInput is not final HEAD ownership;
- live OpenXR/session/pose does not imply visible VR output.

### First visible two-eye stage
User observation was effectively “two screens in two eyes”; horizon/world did not remain spatially locked.

Permanent stop:
`TWO_EYE_TEXTURES != VR` and `NON_DUPLICATE_LR != FUSED_STEREO`.

### Early pose-relabel / flat-screen stage
User described a flat image in front of the face while Crysis pixels were not actually rendered from the current HMD pose, yet the current pose was supplied to the OpenXR projection view.

Permanent stop:
never tell the compositor that pixels were rendered from a pose they were not rendered from.

## 2026-08-16 — all-SetCamera HMD feedback loop
Runtime evidence: `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_171947.zip`.

User observation: after HMD injection the eyes became nearly the same and the camera moved away/collapsed.

Recovered runtime proof:
- pre-intervention L/R difference about `19.60..23.75`;
- after intervention median L/R difference about `1.34`;
- `52,170` adjacent camera-pair observations;
- `99.837%` had `next_camera_input == previous_injected_output`;
- median matrix error `0`.

Failure mechanism:
`G -> G*HMD -> G*HMD^2 -> G*HMD^3 ...`

PERMANENT STOP:
- never apply the same HMD transform to every `Renderer::SetCamera` call;
- never accept repeated downstream camera multiplication as HEAD ownership.

Useful salvage only: the later single-source discovery that `Crysis2.exe+0x0057AC76` is a once-per-logical-frame upstream camera lineage.

## 2026-08-16 — `203734 / 204156` exact-eye camera state: math PASS, visual RED
Historical telemetry proved real HMD XYZ/6DoF and very accurate Quest eye/IPD/FOV propagation, but later examination of the saved XR captures corrected the earlier optimistic interpretation.

Critical within-run control from `204156`:
- `camera_locked=0`: image looked normal;
- immediately after `camera_locked=1`, even with a small HMD rotation, weapon/near geometry expanded into huge black blades.

Recovered cause:
- ordinary world camera near plane about `0.12`;
- `FOB_NEAREST` near plane about `0.03`;
- exact XR asymmetry from the world eye had been inherited unchanged by the near camera;
- because asymmetry values live on the near plane, the near/viewmodel off-axis effect became roughly 4x too strong;
- additionally, RenderWorld visibility still used a much narrower center frustum before the wider Quest eye passes, causing culling/popping/disappearing world geometry.

Classification:
`POSE_MATH_IPD_FOV_PROOF = KEEP`
`EXACT_EYE_RENDERER_POLICY = USER_VISUAL_HARD_RED`

Permanent rule:
beautiful IPD/FOV/pose numbers do not promote the renderer around them.

## 2026-08-16 — real Quest IPD/FOV on native monitor-stereo
Runtime evidence: `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_205430.zip`.

User observation: everything flickered, stereo was wrong, shadows disappeared/changed.

Saved L/R captures independently showed non-parallax eye disagreement: lighting/shadow changes, large near-geometry differences, and one-eye brightness differences.

Historical comparison showed the major visual break appeared when the path moved from the weak native monitor-stereo geometry to real Quest IPD + `XrView` FOV.

PERMANENT STOP:
- do not use native Crysis monitor stereo as final VR by simply replacing its small eye separation/FOV with real Quest IPD/FOV;
- native shared screen-space/deferred state is not proof of two independent VR views;
- culling-only fixes cannot be assumed to solve shared deferred/shadow/temporal ownership.

## 2026-08-17 — STABLE_CAMERA v2.2.0 still visually broken
Known result context: `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_010329.zip`.

This control had already disabled positional HEAD, exact L/R rewrite, XrView FOV rewrite, union-culling rewrite and FOB_NEAREST rewrite, leaving a simpler HMD-rotation + native-stereo path.

User observation: image still flickered badly; weapon could be in hand but firing direction remained tied to monitor center.

PERMANENT STOP:
- a single world-camera owner plus native stereo is not sufficient visual VR;
- controller-driven viewmodel motion is not proof of gameplay muzzle/ballistic ownership;
- never merge weapon success into camera/stereo acceptance.

## 2026-08-17 — native/NVIDIA monitor-stereo route rejected as project direction
Context includes `CRYSIS2VR_RENDERER_FACTFIND_RECOVERED_RESULT_20260817_160453.zip` and nearby native-stereo investigation.

User explicitly rejected continuing the old NVIDIA/3D/native-monitor-stereo route because head motion existed but flashes/flicker remained and requested a different stereo architecture.

PERMANENT STOP:
- do not resurrect driver/NVIDIA/native-monitor-stereo as the final renderer because an old counter or source path looks convenient;
- old native stereo may be used only as archaeology/control evidence.

## 2026-08-17 — A1 history fix: weapon-direction donor only
Result:
`CRYSIS2VR_A1_HISTORY_FIX_RESULT_20260817_175934.zip`.

User verdict:
- the only useful part was the crooked controller hand/weapon that fired along weapon direction;
- the picture remained the bad two-image flickering Nvidia/CryEngine stereo;
- user explicitly ordered that renderer path discarded completely.

Classification:
`WEAPON_DIRECTION_COMPONENT = KEEP`
`SURROUNDING_RENDERER = USER_VISUAL_HARD_RED`.

## 2026-08-17 — false GOLD rewrite v4.0.0
Package:
`CRYSIS2VR_REWRITE_v4.0.0_EXACT_XR_STEREO_GOLD_WEAPON_PORTABLE.zip`

Historical SHA256:
`08A8C4238EDC8046C2B46A3BECA1D19A86825DE9FE8C2ACADE62B2CF51047BB6`

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_023510.zip`.

Immediate user verdict: image still wrong and hand rotation also visibly broken; the package was rejected outright.

Classification:
`USER_VISUAL_HARD_RED`.

Permanent rule:
`GOLD_WEAPON` in a filename does not make a package GOLD.

## 2026-08-17 — unsafe old RC copy route
Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_181936.zip`.

Historical evidence:
- first pair reached OpenXR;
- then crash `0xC0000005` after RC copy #3;
- old RC callback performed `CopyResource/Flush` in an unproven command/thread context and copied near-black data.

Classification:
`ROUTE_REACHABILITY = KEEP`
`RC_COPY_FLUSH_POLICY = HARD_STOP`
`VISUAL_BUILD = HARD_RED`.

## 2026-08-19 — telescope / binocular geometry HARD RED
Recovered user verdict on the Crysis v11/v12-era renderer family: headset view behaved like looking through a telescope/binocular and was rejected as completely wrong.

A later verdict in the same family described the renderer as fully bad, again binocular, and visually misaligned.

Exact single package/result binding is not recovered with enough confidence from chat history, although the physical library contains the contemporary v11/v12 families, including `CRYSIS2VR_RT_SEAM_FRAME_OWNERSHIP_v11.x` and `CRYSIS2VR_POROUS_COMMAND_FORK_v12.0.0_DIAGNOSTIC_TWIN.zip`.

Classification:
`FAMILY_BOUND_VISUAL_HARD_RED / EXACT_PACKAGE_UNBOUND`.

PERMANENT STOP:
- do not revive telescope/binocular/stale-pair style eye composition;
- do not solve this class by arbitrary eye-spacing/convergence tuning;
- do not promote a contemporary v11/v12 package merely because it is temporally adjacent to the user verdict;
- eye-axis dot + very small FOV numeric error is not headset fusion proof.

## 2026-08-19 — DualWorld Cleanroom v14.0.2 black headset
Package family is exact:
`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip`

Recovered package SHA256:
`A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`.

User verdict: headset output was completely black.

Contemporary result artifacts include `C2VR_DUALWORLD14_RESULT_20260819_162623.zip` and `C2VR_DUALWORLD14_RESULT_20260819_162900.zip`, but the exact one-to-one chat binding is not strong enough to assign either result blindly.

Classification:
`USER_VISUAL_HARD_RED / PACKAGE_BOUND / RESULT_UNBOUND`.

PERMANENT STOP:
- do not use high-level DualWorld duplication as a preferred final scheduler;
- black headset output is not a camera-quality baseline;
- do not call a package working because engine-side calls/counters are alive while no usable headset image exists.

## 2026-08-19 — DualWorld Cleanroom v14.0.3 still black
Package:
`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.3_LAZY_GATE_HOTFIX.zip`.

User verdict: OpenXR signaled during startup again and the headset was still completely black.

Classification:
`USER_VISUAL_HARD_RED / PACKAGE_BOUND / RESULT_UNBOUND`.

PERMANENT STOP:
- lazy-gating the same DualWorld architecture did not establish visual recovery;
- do not continue patch-number iteration on a black-headset parent without first reverting to a visible baseline.

## 2026-08-22 — UNBOUND severe geometry/image-quality RED
Recovered user visual verdict: extreme lateral separation, blur and heavily compressed/bad-looking image.

Exact package/result identity is not recovered with sufficient confidence.

Classification: `UNBOUND_VISUAL_RED`.

Rule: do not attach this verdict to a guessed package. If the exact result is recovered later, bind it here.

## 2026-08-25 — v17-derived RC33 result HARD RED
Raw result: `C2VR_RC33_V1721_RESULT_20260825_063149.zip`.

Transport/pair counters were alive, but user visual verdict was catastrophic camera/world instability with light/shadow state visibly moving/sliding.

Classification: `USER_VISUAL_HARD_RED`.

PERMANENT STOP:
- do not promote this run or a direct visual descendant as canonical parent;
- nonzero exact pairs/submits do not make it a transport visual PASS;
- do not use this run to justify HEAD, weapon, temporal or shadow acceptance.

## 2026-08-25 — CUSTOM_DUAL_T1 v1.0.2 POSEPAIR_ONLY K0 HARD RED
Package:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`

User verdict after running it: visually even worse than the already-rejected prior build.

No new RESULT ZIP is bound yet, so do not invent counters or a result identity.

Classification:
`USER_VISUAL_HARD_RED / RESULT_ZIP_NOT_BOUND`

PERMANENT STOP:
- DO NOT create `K=1`, `K=2`, HEAD, weapon, temporal or shadow descendants from this package;
- technical T1 source authority does not make this child a visual parent;
- the clean-PosePair hypothesis is visually falsified as the next-parent choice.

---

# PARTIAL POSITIVE / SALVAGE CHECKPOINTS
These are NOT whole-build GOLD unless explicitly stated. They preserve narrow things that the user observed as closer to correct.

## v6.0.1 — strongest recovered world-stability checkpoint
Exact historical package name recovered:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Historical file size:
`164221 bytes`.

User result preserved by its direct descendant:
- flicker was gone;
- shadows/textures/objects were stable;
- eyes still did NOT fuse.

Classification:
`WORLD_STABILITY_NO_FLICKER_REFERENCE = KEEP`
`BINOCULAR_STEREO = FAIL`.

Important mechanism preserved from the v6.0.1 design:
- cache/reuse the last complete frame instead of emitting empty projection layers when XR outruns game Present;
- publish frame/packet metadata before releasing keyed mutex ownership;
- do not pair frame N pixels with frame N-1 metadata.

Current archival state:
- exact ZIP SHA is still not recovered;
- source identity is substantially recoverable from the v6.0.2 differential:
  - `engine_tap.cpp` `60F29B0FAE02BC1E751B5FD916C1B82736D3CAA97EB4A99D3F07DE7379D28CB8`
  - `c2vr_host_client.cpp` `2477C256F9E621DEFFB9F6114FE6275865FA86E9826FD2CD8D8A21143472DDFD`
  - `c2vr_openxr_host.cpp` `21853D54D58C37BC90F0A610CF62475173F2CD942D7F40709FCB3BA6B3608D20`
  - `porous_proxy.cpp` `39A96807DC15EB60AE110EA17C7D2D8A903DD4D8BE81184CCAE1A0A81D83B31E`
  - `c2vr_shared.h` `104E933B47464069D40DE1231B0FA13449B1290AA8CE91F6355F941F4B329508`.

The descendant `v6.0.2` is evidence for the differential, not permission to call it the exact v6.0.1 carrier.

## v6.1.0 A — compositor fusion control only
Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.1.0_A_FUSION_PROOF_QUAD_PORTABLE.zip`
SHA256 `1CDF50E1EF1E25A1CCB33C48D0795732CDF1601F586F5F4FFAE75B489913AEFE`.

It intentionally submitted one VIEW-space BOTH-eye quad as a 2D panel. Its own design explicitly said that a PASS would prove compositor/display fusion only, not stereo.

A historical result analysis rejected v6.1.0 as a visual-success baseline due to low source ray density / quality and lack of real L/R stereo production.

Classification:
`COMPOSITOR_CONTROL_ONLY`, never visual GOLD.

## A1 native-repair era — camera ownership was close
Result reference:
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`.

User observation: turning the head left/right moved the in-game camera/world correctly; the remaining major problem was flicker / two-screen stereo behavior; user described the state as very close.

KEEP AS:
`CAMERA_OWNERSHIP_REFERENCE_ONLY`.

Do not inherit its old final stereo architecture blindly.

## Single-source camera ownership v1.0.4
Package:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Policy:
- HMD injected once at `Crysis2.exe+0x0057AC76`;
- downstream `SetCamera` calls pass through.

A following user observation described the image as red but at least somewhat stereo-like.

KEEP AS:
`HEAD_OWNERSHIP_TOPOLOGY_REFERENCE`, not visual GOLD.

## 191909 orientation/native-stereo control
Historical comparison showed much less L/R divergence than later real-IPD/FOV runs.

KEEP AS:
`LOW_DIVERGENCE_CONTROL_ONLY`.

It is not valid final VR geometry because native eye separation remained monitor-oriented.

## 203734 / 204156 — downgraded to forensic component proof
These are NOT a near-good visual renderer.

KEEP ONLY:
- HMD pose propagation;
- IPD/FOV math;
- within-run control proving `camera_locked=0` normal vs `camera_locked=1` corrupt near geometry.

DO NOT KEEP:
- surrounding exact-eye projection policy;
- near-camera projection inheritance;
- old center-culling policy.

Classification:
`POSE_MATH_AND_IPC_COMPONENT_REFERENCE_ONLY / VISUAL_RENDERER_RED`.

## 021239 / 175934 weapon-direction donor
Result context includes:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_021239.zip`
`CRYSIS2VR_A1_HISTORY_FIX_RESULT_20260817_175934.zip`.

Historical evidence preserved controller-to-weapon-direction/fire behavior while the surrounding renderer was rejected.

KEEP AS:
`WEAPON_MUZZLE_DIRECTION_COMPONENT_DONOR_ONLY`.

Do not infer that camera/stereo or hand rig was visually accepted.

## `FOB_NEAREST OWNER TRUTH` — owner evidence only
Results include:
`CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_012736.zip`
`CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_013107.zip`.

Useful fact:
render-thread prediction produced balanced near ownership and identified the dominant near caller around `+0x000FF456`, falsifying the old global-active-eye asymmetry.

But contemporaneous visual verdict was broken.

KEEP AS:
`NEAR_OWNER_TIMING_EVIDENCE_ONLY`.

## v7.0.2 clean-native source-size transport — technical lineage, visual verdict unbound
Package:
`CRYSIS2VR_CLEAN_NATIVE_EYES_v7.0.2_SOURCE_SIZE_XR_TRANSPORT.zip`

Result:
`CRYSIS2VR_CLEAN_NATIVE_SOURCE_SIZE_RESULT_20260819_001036.zip`.

Known causal scope:
- only x64 host swapchain sizing changed vs v7.0.1;
- game-side engine tap/client stayed byte-identical;
- direct 1:1 private L/R source-size transport was the technical target.

The archive/result is useful technical evidence, but no sufficiently direct user headset verdict has been recovered that promotes it to the “last good single-window” visual baseline.

Classification:
`TECHNICAL_EVIDENCE_KEEP / VISUAL_STATUS_UNBOUND`.

## 18–19 Aug “last good native single-window” behavior profile
A dedicated historical user visual oracle explicitly says to RECOVER this branch and retire SBS/Nvidia/two-window/black-headset paths.

Recorded good behavior:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- image present in headset;
- only hand/weapon still visibly wrong.

Classification:
`USER_ACCEPTED_BEHAVIOR_PROFILE = HIGH_PRIORITY_KEEP`
`EXACT_PACKAGE_IDENTITY = OPEN`.

Critical rule:
Do NOT guess this package from temporal adjacency. The historical handoff itself recorded the exact good single-window hash/lineage as a blind zone to recover before mutation.

## x86 game + x64 OpenXR host split
This is an infrastructure invariant recovered after failed attempts to create OpenXR session inside x86 Crysis2.

KEEP AS:
`INFRASTRUCTURE_GOLD`.

It says nothing by itself about visual camera/stereo correctness.

## CUSTOM_DUAL_T1 v1.0.1 canonical RESULT
Canonical technical result:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

It proves true private L/R retail rendering and exact renderer mechanics.

KEEP AS:
`TRUE_LR_RENDERER_TECHNICAL_PROOF`.

It is NOT sufficient evidence to choose a visual parent after the v1.0.2 user HARD RED.

---

# UNTESTED / MISLABELLED HISTORICAL CANDIDATES

## FRUSTUM_COHERENCE_FOB_NEAREST v1.2.6
Package:
`CRYSIS2VR_FRUSTUM_COHERENCE_FOB_NEAREST_v1.2.6_OVERWRITE_LAB.zip`
SHA256 `E59D1266CDFD12BD7F853813C276CDD65C2C2B3ECA00CE269D50B902D5A692F6`.

Architectural intent was sensible and directly targeted two captured failures:
- recompute XR asymmetry for the live near plane of `FOB_NEAREST`;
- use union L/R frustum during RenderWorld visibility;
- keep positional HMD XYZ disabled while validating projection/visibility.

But historical run evidence shows the v1.2.6 child itself had a generated-source compile artifact and did not establish a real visual PASS; v1.2.7 was a build fix with architecture unchanged.

Classification:
`UNTESTED_ARCHITECTURAL_CANDIDATE / NOT_VISUAL_GOLD`.

Never cite v1.2.6 as “the fix that worked”.

---

# CURRENT RECOVERY POLICY
The current project gate is no longer cadence `K`.

It is:
`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`.

Recovery priority is property-based, not version-based:
1. recover the exact `last good native single-window` package/runner if possible;
2. recover/reconstruct v6.0.1 world-stability/no-flicker behavior without pretending it is stereo;
3. preserve A1/single-source camera ownership separately;
4. preserve T1 true-private-L/R mechanics separately;
5. preserve weapon-direction donor separately;
6. combine only after each property is revalidated against an unchanged baseline.

Required sequence for a visual parent:
1. exact physical package + exact runner;
2. unchanged reproduction;
3. fresh RESULT + explicit user headset verdict;
4. freeze exact hashes;
5. ONE visual mutation per child;
6. immediate STOP/revert on catastrophic visual regression.

No future branch may cite counters alone to bypass this ledger.
