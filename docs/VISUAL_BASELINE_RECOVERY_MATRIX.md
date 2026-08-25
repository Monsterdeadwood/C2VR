# C2VR — VISUAL BASELINE RECOVERY MATRIX

## WHY THIS EXISTS

C2VR historically lost good properties because whole packages were labelled `PASS`/`GOLD` even when the headset image was bad, then later branches inherited the entire package.

From now on, recover **properties**, not version numbers.

A package may be GREEN for one property and RED for another.

Legend:
- `GREEN` — keep/recover this property.
- `RED` — explicitly rejected / falsified.
- `YELLOW` — technically proven or useful, but not a visual-parent PASS.
- `OPEN` — exact package/user binding still missing.

| Property | Best recovered reference | Status | What to keep | What must NOT be inherited |
|---|---|---|---|---|
| XR process architecture | x86 Crysis2 + x64 OpenXR host | GREEN | process split, Quest session in x64 host | in-process x86 OpenXR session attempts |
| Visible headset output | historical single-window profile | GREEN behavior / OPEN identity | one visible headset image path | black-headset parents |
| World stability / no flicker | `CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip` | GREEN property | stable textures/shadows/objects, no empty-layer flicker, atomic packet publication | its fake/mono binocular composition as final stereo |
| Camera ownership | `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` + single-source `+0x0057AC76` topology | YELLOW/GREEN property | head-driven real game camera behavior, one upstream injection | Nvidia/native monitor stereo around it; all-SetCamera feedback |
| Pose/IPD/FOV math | `203734/204156` | YELLOW | HMD pose propagation, accurate eye/IPD/FOV math | exact-eye renderer policy, inherited near asymmetry, old center culling |
| Near-camera owner identity | `FOB_NEAREST OWNER TRUTH` | YELLOW | render-thread owner timing, dominant `+0x000FF456` seam | visual build, global active-eye classification |
| Weapon firing direction | `021239` / `A1_HISTORY_FIX_RESULT_20260817_175934` | YELLOW/GREEN component | controller-to-fire direction behavior | crooked hand rig and surrounding Nvidia renderer |
| True private retail L/R renderer primitive | `CUSTOM_DUAL_T1 v1.0.1` / result `20260819_212003` | YELLOW technical | private RT transaction, true L/R execution, RC33 mechanics | automatic visual-parent status; later T1 PosePair K0 visual policy |
| Source-size direct L/R transport | `CLEAN_NATIVE_EYES v7.0.2` / result `001036` | YELLOW | exact causal host sizing / direct-eye evidence | promotion to “last good single-window” without user verdict |
| Compositor fusion control | `v6.1.0 A/FUSION_PROOF_QUAD` | YELLOW control | prove one 2D image can be displayed/fused | calling it real stereo or quality baseline |
| Binocular fusion | none currently bound as accepted final | OPEN | must be proven in headset | telescope/binocular families, numeric-only eye-axis/FOV PASS |
| World scale | 18–19 Aug “last good native single-window” profile | GREEN behavior / OPEN identity | good world scale behavior | v10-era wrong/strange scale branches |
| Stable head motion | same historical single-window profile + A1 camera reference | GREEN behavior / OPEN exact parent | world remains stable under head motion | screen-glued pose relabel, mouse-look, camera collapse |
| Shadows / lighting coherence | v6.0.1 stable-world property | GREEN property | stable textures/shadows/objects | `205430`, `063149`, any moving/sliding L/R light/shadow state |
| Temporal continuity | v6.0.1 packet/cache lesson | YELLOW/GREEN mechanism | no empty XR layers, metadata published before mutex release | stale pixels relabelled with current/new pose |
| High-level DualWorld scheduler | v14.0.2/v14.0.3 | RED | forensic lessons only | direct descendants; black-headset lineage |
| Native/Nvidia/monitor stereo final transport | A1/native era | RED | archaeology and low-divergence control only | final renderer authority |
| Current T1 PosePair K0 | `CUSTOM_DUAL_T1 v1.0.2 POSEPAIR_ONLY K0` | RED | nothing as visual parent; source diff may be forensic evidence | K1/K2/HEAD/weapon/temporal/shadow descendants |

---

# EXACT RECOVERY TARGETS

## Target A — historical last-good native single-window

Known behavior profile:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- image present in headset;
- hand/weapon still visibly wrong.

State:
`EXACT_PACKAGE/HASH = OPEN`.

Do not guess from neighboring filenames.

## Target B — v6.0.1 no-flicker baseline

Exact package name recovered:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Historical size:
`164221 bytes`.

Exact ZIP SHA:
`OPEN`.

Recovered v6.0.1 source hashes:
- `engine_tap.cpp` `60F29B0FAE02BC1E751B5FD916C1B82736D3CAA97EB4A99D3F07DE7379D28CB8`
- `c2vr_host_client.cpp` `2477C256F9E621DEFFB9F6114FE6275865FA86E9826FD2CD8D8A21143472DDFD`
- `c2vr_openxr_host.cpp` `21853D54D58C37BC90F0A610CF62475173F2CD942D7F40709FCB3BA6B3608D20`
- `porous_proxy.cpp` `39A96807DC15EB60AE110EA17C7D2D8A903DD4D8BE81184CCAE1A0A81D83B31E`
- `c2vr_shared.h` `104E933B47464069D40DE1231B0FA13449B1290AA8CE91F6355F941F4B329508`

Historical user state:
- flicker gone;
- textures/shadows/objects stable;
- eyes still did not fuse.

Use it to recover WORLD STABILITY, not to claim stereo solved.

## Target C — camera ownership

Primary references:
- `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`
- `CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
- upstream once/logical-frame return landmark `Crysis2.exe+0x0057AC76`.

Goal:
recover real head-driven game-camera behavior without importing the old native/Nvidia final renderer.

## Target D — true private L/R execution

Technical reference:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

Goal:
reuse only the proven private-eye renderer transaction and restoration mechanics.

Do not inherit current T1 PosePair K0 visual policy.

## Target E — weapon direction

References:
- `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_021239.zip`
- `CRYSIS2VR_A1_HISTORY_FIX_RESULT_20260817_175934.zip`.

Goal:
preserve controller-driven firing direction later, after camera/stereo baseline is accepted.

---

# REQUIRED BUILD-DESCENDANT RULE

Before a package can become a new visual parent, its report must contain a property table:

```text
WORLD_STABILITY     = PASS/FAIL/UNTESTED
CAMERA_WORLD_LOCK   = PASS/FAIL/UNTESTED
BINOCULAR_FUSION    = PASS/FAIL/UNTESTED
TRUE_LR             = PASS/FAIL/UNTESTED
WORLD_SCALE         = PASS/FAIL/UNTESTED
SHADOW_LIGHT_STABLE = PASS/FAIL/UNTESTED
WEAPON_DIRECTION    = PASS/FAIL/UNTESTED
RESTORE_HASHES      = PASS/FAIL
USER_HEADSET_VERDICT= ACCEPT/RED/NOT_TESTED
```

A package with any catastrophic visual RED is not a parent merely because other rows are PASS.

---

# RECOVERY ORDER

1. Locate exact physical carrier for the old single-window accepted behavior if possible.
2. Locate or reconstruct exact v6.0.1 source/runner lineage and reproduce WORLD STABILITY only.
3. Reproduce camera ownership separately.
4. Reintroduce true private L/R transaction separately.
5. Prove binocular fusion in headset.
6. Only then reopen HEAD translation, weapon/NEAR, temporal/shadow polish and cadence optimization.

This matrix outranks version-number recency for parent selection.
