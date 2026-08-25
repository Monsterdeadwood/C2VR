# C2VR — USER VISUAL ACCEPTANCE LEDGER / PERMANENT LINEAGE GUARD

## PURPOSE
This file is a permanent project guard against repeating visually failed Crysis 2 VR architectures.

The user's in-headset visual verdict is an acceptance signal, not anecdotal commentary.

## PRECEDENCE
For visual/playability questions use this order:

`USER_HEADSET_VERDICT > deterministic L/R captures > raw RESULT/runtime logs > counters > static validation > design intent`

A package can have perfect counters and still be a HARD VISUAL RED.

Words such as "пиздец", "моргает", "камера уезжает/проваливается", "тени пропадают/ездят", "неправильное стерео", "экран перед лицом" are hard rejection evidence when attached to a known run/package.

## PARENT SELECTION LAW
1. A `USER_VISUAL_HARD_RED` package MUST NOT be used as the direct parent of another visual/camera/stereo descendant.
2. It may be reused only as a narrow donor for a source-proven component, with the failed visual policy excluded explicitly.
3. `PASS`, `GOLD`, `CLEAN`, `MAIN`, `source authority`, or high counters never override a user visual RED.
4. If a run changed camera + stereo + temporal + shadow + weapon/NEAR together, it cannot establish which of those policies is good.
5. One new visual LIVE = one causal mutation from the nearest non-red or partially accepted checkpoint.
6. If exact package/result identity is missing, record `UNBOUND_VISUAL_RED`; never guess the package from neighboring chat messages.
7. A technical renderer proof is not automatically a visual-parent proof.

---

# HARD RED LEDGER

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

## 203734 / 204156 camera-pose component proof
Historical telemetry showed real HMD XYZ/6DoF and highly accurate Quest eye/IPD/FOV propagation.

However the subsequent `205430` visual result exposed severe shared eye-state problems.

KEEP AS:
`POSE_MATH_AND_IPC_COMPONENT_REFERENCE_ONLY`.

Never promote the renderer policy around it as visually accepted.

## 021239 weapon/muzzle component donor
Result context:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_021239.zip`.

Historical engineering conclusion preserved weapon/controller-to-real-fire behavior while the old stereo path was rejected.

KEEP AS:
`WEAPON_MUZZLE_COMPONENT_DONOR_ONLY`.

Do not infer that its camera/stereo was visually accepted.

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

# CURRENT RECOVERY POLICY
The current project gate is no longer cadence `K`.

It is:
`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`.

Required sequence:
1. recover exact physical package + runner for the nearest user-positive/near-normal Crysis camera checkpoint;
2. reproduce that checkpoint without adding new renderer policy;
3. bind a fresh RESULT + explicit user headset verdict;
4. freeze the exact visual baseline;
5. add ONE renderer/stereo mutation at a time;
6. if the user says the picture becomes catastrophic, STOP and revert immediately;
7. only after stationary world + slow yaw + fast yaw/reversal + stable light/shadows are visually acceptable may cadence/HEAD/weapon gates advance.

No future branch may cite counters alone to bypass this ledger.
