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

Evidence order for visual/playability acceptance:
`USER_HEADSET_VERDICT > deterministic captures > raw LIVE logs/status > counters > generated analyzer summary > static validation > package intent`.

---

# G0 — QUEST / PRIVATE-RTV BRIDGE

**MECHANICAL_GREEN on 220427.**

Canonical current control result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Proven raw runtime facts:
- XR session created and began;
- `submit_count=4691`;
- `eye_stage_copies=9382`;
- `reproject_draws=9382`;
- 33 XR stereo-pair captures;
- raw restore PASS.

The historical direct-XR-RTV creation blocker is closed.

Current source is still:
`CENTER RGB + inverse depth -> x64 depth reprojection -> synthetic LEFT/RIGHT -> private eye RTs -> XR swapchains`.

Therefore:
- `PRIVATE_RTV_XR_BRIDGE = MECHANICAL_GREEN`;
- `MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN`;
- `TRUE_PRIVATE_LR_SCENE_RENDER = NO` for this control.

Do not rebuild transport while the current gate is quality/scale closure.

---

# G1 — CLEAN MONO QUALITY CONTROL

**CURRENT FIRST GATE.**

Fresh direct 220427 user verdict:
- world scale is wrong/problematic;
- otherwise the branch is broadly normal/promising and worth finishing;
- whole build is not a visual HARD RED;
- it is not yet `FULL_USER_VISUAL_GREEN`.

Historical quality donor:
`CRYSIS2VR_FULL_POSE_WORLD_NEAR_RESULT_20260818_030228.zip`
SHA256 `8EFAE73A7B6E30230D56FC3E66DC6BAE3D78E9118425C79F246748F0FBD26D72`.

Recovered accepted property:
```text
r_MotionBlur=0
r_PostMSAA=0
```

Classification:
`COMPONENT_VISUAL_GREEN: CLEAN_MONO_IMAGE_QUALITY_SETTINGS`.

Fresh 220427 RESULT does not prove whether those two values were active.

## G1 procedure

1. Recover authoritative 220427 values of `r_MotionBlur` and `r_PostMSAA` from the exact package/config lineage.
2. If both are already `0`, do not create a redundant quality child.
3. Otherwise create one child whose only mutation category is those known image-quality CVars.
4. Keep source dimensions, projection, IPD, worldScale, reprojection math, weapon/NEAR, shadows, temporal policy and cadence unchanged.
5. Require direct headset verdict.

## G1 PASS

```text
same world/head behavior
same scale defect, not worse
image at least as clean as 220427
no new blur/regression
XR bridge unchanged
restore/hash baseline holds
```

G1 does not claim scale fixed.

---

# G2 — SCALE / SOURCE-PROJECTION CONTRACT

**CURRENT SECOND GATE, immediately after G1.**

Known 220427 facts:
```text
source_eye / game_texture = 1600x1200
union_fov_deg             = 114.086
union_ratio               = 0.963753
```

Historical 030228 already exposed:
```text
calculated source target ~= 2032x1968
actual producer          = 1400x1050
WORLD union projection   = 110.747 deg / 1.02737
FOB_NEAREST              = 55 deg / 1.33333
```

The scale defect is therefore treated first as a projection/source-resolution/reprojection-rectangle contract problem.

Before mutation map:
- actual producer dimensions;
- center RenderWorld projection/FOV/ratio;
- packed-depth projection;
- XR LEFT/RIGHT FOV;
- reprojection sampling rectangle;
- XR swapchain dimensions;
- submitted `subImage` rectangle.

Then change the first proven mismatch only.

## G2 PASS

```text
world scale natural
world/head remains stable
image quality preserved
no binocular/telescope catastrophe
XR bridge unchanged
restore/hash baseline holds
```

Forbidden:
- arbitrary `worldScale` grid;
- arbitrary IPD/convergence sweep;
- renderer-family rewrite in the same test.

---

# G3 — TRUE PRIVATE L/R RENDERER INTEGRATION

**PARKED UNTIL G1 + G2.**

Technical primitive remains proven:
`CUSTOM_DUAL_T1 v1.0.1 / 212003 = MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

This is a donor primitive, not current whole-build visual parent authority.

Do not resurrect as parent:
- `C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage;
- T1 PosePair K0 visual descendant;
- GOODLINE/R2 whole-build branches;
- native/NVIDIA/monitor-stereo final renderer;
- DualWorld black-headset family.

Any future merge must start from the accepted post-G2 control and import only the required true-L/R mechanism.

---

# G4 — POSE / PIXEL CONTRACT + HEAD 1:1

**PARKED UNTIL G3.**

Every submitted pair must carry one immutable render contract:
`pixels + exact render pose + FOV + pair/ticket identity`.

Rules:
- never relabel stale pixels with current pose;
- one fresh eye plus one stale eye is invalid;
- last-good reuse retains the metadata that actually rendered it;
- HEAD belongs upstream of visibility/list selection;
- EYES belong in the per-eye render transaction.

PASS requires direct user-visible coherence, not counters alone.

Old PosePair/P6 timing work remains causal evidence only, not the current gate.

---

# G5 — WEAPON / FOB_NEAREST

**PARKED.**

Preserved anchors:
- owner region `+0x000FF340`;
- NEAR SetCamera return `+0x000FF456`;
- restore `+0x000FF4A3`;
- object owner `+0x00102100`;
- `Renderer::SetCamera +0x00148340`.

Historical controller-directed firing is a weapon-direction donor only.

PASS:
- head still -> weapon still;
- controller only -> weapon moves, WORLD does not;
- head only -> no counter-motion;
- both eyes coherent;
- no flicker;
- firing direction follows intended weapon/controller authority.

---

# G6 — TEMPORAL / SHADOW STABILITY

**PARKED.**

Only after renderer/head/weapon visual gates are stable.

Never use `SHDF_ZPASS_ONLY` as normal RIGHT-eye scene policy.

Do not reopen temporal/shadow mutation to explain the current scale defect.

---

# G7 — REGRESSION

PASS all:
- normal mono launch;
- Quest output alive;
- coherent stereo;
- natural world scale;
- head 1:1;
- weapon correct;
- shadows/light coherent;
- HUD both eyes;
- save/load;
- menu -> gameplay;
- cutscene transitions;
- no accumulating drift/state corruption;
- byte-exact D3D11 restore;
- retail hashes unchanged.

---

# G8 — RELEASE CANDIDATE

At least 10 minutes actual gameplay with head motion, movement, weapon use and traversal, with no tearing, drift, eye divergence, black eye, crash or state corruption.

PASS -> STOP FORENSICS -> RELEASE CANDIDATE.

---

## CURRENT ORDER

`220427 CONTROL -> G1 QUALITY -> G2 SCALE -> G3 TRUE L/R -> G4 POSE/HEAD -> G5 WEAPON/NEAR -> G6 TEMPORAL/SHADOW -> G7 REGRESSION -> G8 RELEASE`

Current rule:
`SYNC -> EXACT CURRENT CONTROL -> ONE MISSING FACT -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP / ADAPT / STOP`.
