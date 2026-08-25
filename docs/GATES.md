# Crysis 2 VR — GATES

## STATUS LANGUAGE

A technical PASS is not automatically a visual PASS.

Use:
- `MECHANICAL_GREEN`
- `COMPONENT_VISUAL_GREEN`
- `FULL_USER_VISUAL_GREEN`
- `VISUAL_RED`
- `LIVE_VISUAL_UNBOUND`
- `NOT_LIVE`

A PASS with absent prerequisites is `VACUOUS_PASS_INVALID`.

See `docs/HISTORICAL_AUDIT_PASS2_20260825.md`.

---

# G0 — TRUE TWO-EYE RENDERER PRIMITIVE

**MECHANICAL_GREEN.**

`CUSTOM_DUAL_T1 v1.0.1` executed genuine non-duplicate private LEFT/RIGHT rendering.

This proves a renderer primitive, not a user-accepted whole VR build.

Do not rebuild stereo from scratch.

---

# GV — VISUAL BASELINE RECOVERY

**CURRENT GATE.**

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

This gate supersedes the old statement that PosePair/cadence is current.

Why:
- `C2VR_RC33_V1721_RESULT_20260825_063149.zip` is USER VISUAL HARD RED despite live pair transport;
- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip` is USER VISUAL HARD RED and was reported even worse;
- therefore timing/HEAD/weapon/temporal/shadow work on those parents is uninterpretable.

## Exact recovered world-stability anchor

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`

Historical user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

First reproduction of this property must reuse its exact historical runner unchanged.

## Camera ownership reference

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user-positive property:
- head movement drove the real in-game camera/world;
- remaining major issue was flicker/two-screen behavior.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

## Historical single-window behavior profile

User oracle records:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- image present in headset;
- only hand/weapon visibly wrong.

Exact package/hash remains OPEN.
Do not guess it from neighboring v7/v10 packages.

## GV PASS

A complete candidate may become the next whole-build visual parent only after an unchanged reproduction or one-variable child receives explicit in-headset acceptance:
- stationary head -> stationary world;
- slow yaw -> no fall/jump/shear;
- fast yaw/reversal -> no camera explosion or eye-time split;
- lighting/shadows spatially stable;
- no severe flicker;
- no monitor-panel/two-screen behavior;
- world scale credible;
- L/R coherent and non-duplicate where true stereo is expected;
- byte-exact restore and retail hashes PASS.

Required classification:
`FULL_USER_VISUAL_GREEN`.

Counters alone cannot pass GV.

## GV FAIL

Any catastrophic headset verdict immediately marks that exact package `VISUAL_RED` and forbids it as direct visual parent.

---

# G1 — POSE/PIXEL CONTRACT

**PARKED UNTIL GV PASSES.**

Goal:
every submitted LEFT/RIGHT pair carries one immutable render contract: pixels + exact render pose + FOV + pair/ticket identity.

Rules:
- stale/mismatched pairs are never relabelled;
- one fresh eye + one stale eye is invalid;
- cached last-good pixels retain the metadata that actually rendered them.

A future G1 PASS requires both mechanical identity and user-visible coherence.

The old PosePair K0 package is NOT the parent for this gate.

---

# G2 — HEAD 1:1 + VISIBILITY ENVELOPE

**PARKED UNTIL GV + G1.**

PASS:
- yaw/pitch 1:1;
- no doubled angle;
- head stop -> world stops;
- return HMD -> world returns;
- no accumulated translation;
- no culling pop;
- stable light/shadow behavior;
- survives active head motion.

Known topology reference:
HEAD high before visibility/list selection; EYES low in per-eye render transaction.

Do not restart broad HEAD archaeology before recovering visual baseline.

---

# G3 — WEAPON / FOB_NEAREST

**PARKED.**

Known anchors:
- owner region `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- restore `+0x000FF4A3`
- object owner `+0x00102100`
- `Renderer::SetCamera +0x00148340`

PASS:
- head still -> weapon still;
- controller only -> weapon moves, WORLD does not;
- head only -> no weapon counter-motion;
- both eyes coherent;
- no flicker.

Historical weapon-direction behavior is a donor component only, not permission to import its old renderer.

---

# G4 — TEMPORAL / SHADOW STABILITY

**PARKED.**

Serial candidate order only after earlier visual gates:
1. TAA/AA OFF control if needed;
2. LEFT-authoritative temporal / RIGHT isolated;
3. separate eye histories if required;
4. reset/freeze-restore only if required.

Never use `SHDF_ZPASS_ONLY` as the normal RIGHT scene policy.

---

# G5 — REGRESSION

PASS all:
- normal mono launch;
- stereo L/R alive;
- head 1:1;
- weapon correct;
- shadows/light coherent;
- HUD both eyes;
- save/load;
- menu -> gameplay;
- cutscene transitions;
- no accumulating drift/state corruption;
- byte-exact d3d11 restore;
- retail hashes unchanged.

---

# G6 — RELEASE CANDIDATE

At least 10 minutes actual gameplay with head motion, movement, weapon use and traversal, with no tearing, drift, eye divergence, black eye, crash or state corruption.

PASS -> STOP FORENSICS -> RELEASE CANDIDATE.
