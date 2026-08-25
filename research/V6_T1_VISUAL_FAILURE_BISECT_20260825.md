# C2VR — v6 STABILITY vs T1 TRUE-L/R CAUSAL BISECT — 2026-08-25

## PURPOSE

Do not immediately build another `v6 + T1 + PosePair + HEAD` super-child.

The current evidence supports a narrower question:

**Can the proven T1 private-eye replay execute underneath the historically stable v6 world owner without perturbing the v6 camera/world/shadow/temporal state?**

This separates engine replay corruption from XR contract/submission corruption.

---

# WHY v6 IS MORE THAN A FLAT-SCREEN CONTROL

Exact physical v6.0.1:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Its bounded user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- binocular fusion still failed.

Its architecture already preserved:
- native CryEngine stereo OFF;
- one normal mono RenderWorld;
- one HMD-center camera path before RenderWorld;
- atomic pixel+packet publication;
- XR last-good cache/reuse instead of empty layers when XR outruns Present.

Later v7 documentation explicitly described the retained foundation as:
- single-source HMD center 6DoF before RenderWorld;
- union visibility/culling coverage;
- exact XrView LEFT/RIGHT camera contract.

Therefore A1 camera ownership is a useful historical reference, but it is not automatically the next mutation. v6 already contains an upstream camera/world-owner model worth preserving first.

---

# WHY T1 IS A DONOR, NOT THE NEXT PARENT

`CUSTOM_DUAL_T1 v1.0.1` mechanically proves:
- one prepared render list can execute private LEFT and RIGHT;
- private RT transaction works;
- nonduplicate L/R can be produced;
- direct eye copies and OpenXR submits can occur.

But later PosePair/v17 descendants received catastrophic user visual verdicts.

Therefore the missing causal edge is not “can Crysis render two eyes?”. It can.

The missing edge is:

`stable v6 world owner -> T1 eye replay -> ??? -> visual corruption`

We need to determine whether corruption begins inside the replay itself or only after contract/submission policy is changed.

---

# HYPOTHESES

## H1 — PRIVATE REPLAY STATE LEAK

T1 private LEFT/RIGHT replay itself perturbs persistent renderer state despite nominal restore:
- process/fill thread camera state;
- temporal previous matrices;
- deferred/HDR state;
- shadow state;
- viewport/RT stack;
- NEAR state;
- late camera CB state.

Prediction:
Even if the headset continues displaying the untouched v6 center image, merely executing hidden T1 replay before Present makes the visible v6 world/shadows/camera become unstable.

## H2 — REPLAY IS STATE-SAFE, HOST/CONTRACT IS WRONG

T1 replay is safe when driven from one game-owned frame contract, but later host-driven PosePair/cadence changes make the center/world camera jump or use a mismatched XR identity.

Prediction:
Hidden replay leaves the visible v6 center output stable. Corruption appears only when private pair publication/submission or host-driven contract ownership is enabled.

## H3 — REPLAY IS SAFE AT LOW DUTY, FAILS AT FULL DUTY

No direct state leak exists, but full-rate double-eye replay changes game cadence enough to create stale/late camera behavior or renderer scheduling instability.

Prediction:
Sparse hidden replay is visually stable; full-rate hidden replay becomes unstable while the displayed source remains v6 center.

## H4 — SUBMISSION/PROJECTION ONLY

Hidden replay remains stable at all tested duty cycles, and only submitting the private pair creates the bad headset image.

Then investigate:
- rendered-pixel pose/FOV identity;
- L/R sign/basis;
- near/projection family;
- XR layer view pose/FOV;
- pair publication timing.

---

# REQUIRED ORDER

## R0 — EXACT v6.0.1 UNCHANGED REPRO

First runtime remains exactly the current `experiments/NEXT_EXPERIMENT.md`:
- exact physical package;
- exact inherited runner;
- no code changes;
- confirm no-flicker/stable-world property today.

If R0 fails, STOP. Do not perform T1 bisect against a dead control.

## R1 — HIDDEN T1 REPLAY, v6 OUTPUT UNCHANGED

Fork exact v6.0.1 only after R0 PASS.

Preserve byte-identical:
- x64 host behavior;
- XR submission path;
- last-good cache/reuse;
- v6 center image source;
- v6 frame-contract production;
- launch/build/restore lineage unless exact source fork requires only the existing build path.

Only causal mutation:
execute T1 private-eye replay inside x86 **without publishing/submitting those private eyes to the headset**.

The headset continues to receive the original v6 center output.

Use the already-published v6 frame contract for eye data. Do NOT add host-driven PosePair/K ownership.

### Automatic R1 phases

Use one causal feature with timed duty-cycle phases, no keys:

```text
PHASE 0: 10 s — hidden replay OFF
PHASE 1: 15 s — hidden L/R replay sparse, e.g. every 4th logical game frame
PHASE 2: 20 s — hidden L/R replay every eligible logical game frame
PHASE 3: 10 s — hidden replay OFF again
```

The OFF -> sparse -> full -> OFF ladder distinguishes persistent state leakage from load/cadence sensitivity while changing only one feature.

Do not alter XR image source between phases.

### Passive evidence

Record per phase:
- logical RenderWorld count;
- hidden replay attempts/completions L/R;
- RC push/pop balance;
- camera restore equality/hash;
- viewport/RT restore checks;
- temporal snapshot/restore balance if T1 donor requires it;
- shadow counters only as observation, not mutation;
- Present/game cadence;
- XR submit cadence;
- cached-frame age;
- v6 visible source hash/capture;
- private L/R captures for offline comparison;
- crash/fault state.

No IPC ABI change is preferred. Use package-local log files where possible.

---

# R1 VERDICTS

## R1-A — FAIL IN SPARSE PHASE

Visible v6 center world/camera/shadows become unstable when hidden replay starts at low duty.

Conclusion:
`PRIVATE_REPLAY_STATE_LEAK = PROVEN/STRONG`.

Next work:
bisect T1 restore/state transaction inside x86 only.

Do NOT touch PosePair/K/XR submission.

## R1-B — SPARSE PASS, FULL FAIL

Sparse hidden replay stable; full-rate hidden replay destabilizes output or cadence.

Conclusion:
`FULL_RATE_REPLAY_SCHEDULING/CADENCE = PRIMARY SUSPECT`.

Next work:
measure replay cost/ordering and logical-frame ownership before any submission experiment.

## R1-C — ALL HIDDEN PHASES PASS

Visible v6 output remains stable before/during/after hidden T1 replay, restores balance, no persistent state corruption.

Conclusion:
`T1_REPLAY_STATE_SAFETY = PROVISIONALLY GREEN`.

The catastrophic late builds are then more likely downstream of:
- host-driven contract ownership;
- pair publication/submission;
- rendered-pixel pose/FOV mismatch;
- coordinate/projection semantics.

Only then authorize R2.

---

# R2 — PRIVATE L/R SUBMIT UNDER GAME-OWNED v6 CONTRACT

R2 exists only after R0 PASS + R1-C PASS.

Change one thing from R1:
submit the already-proven private T1 L/R pair instead of the v6 center image.

Keep:
- one v6 HMD-center RenderWorld;
- same v6 game-owned frame contract;
- no host-driven PosePair request;
- no K lead;
- no HEAD rewrite;
- no weapon/NEAR mutation;
- no new temporal/shadow policy;
- same launcher/build/restore lineage.

Goal:
isolate the visual effect of changing only the headset image source from stable v6 center to true private L/R.

If R2 fails while R1 passed, the failure is downstream of replay state safety and can be attacked as projection/submission identity rather than broad camera archaeology.

---

# WHY NOT A1 NEXT

A1 remains valuable as a camera-ownership oracle, but it should not be merged before R1 because:
- v6 already has an HMD-center pre-RenderWorld path;
- introducing A1 changes camera ownership at the same time as eye replay;
- that would destroy the causal separation between upstream camera and downstream stereo transaction.

Use A1 only if unchanged v6 reproduction shows that the historical v6 head/world behavior cannot be reproduced or if R1/R2 later prove a specific camera-owner deficiency.

---

# WHY NOT v6.0.2 NEXT

v6.0.2 changed mono projection metadata while preserving the same mono pixel source.

It is useful historical evidence, but mono duplication cannot close final physical stereo.

Do not spend another primary LIVE on mono-FOV tuning unless R2 later proves that the exact same projection-description bug remains the blocker for true L/R submission.

---

# WHY THIS BISECT IS HIGH VALUE

The recent catastrophic builds mix several possible causes:
- upstream camera contract timing;
- private eye replay state;
- pair publication;
- XR pose/FOV semantics;
- cadence;
- temporal/shadow state.

R1 holds the visible output fixed and changes only hidden eye replay.

That creates a strong causal fork:

```text
v6 visible output breaks
    -> replay/state/scheduling problem inside game

v6 visible output remains stable
    -> replay is not sufficient cause
    -> move downstream to pair submission/projection contract
```

This is more informative than another direct visually complex `v6 + T1 + PosePair` build.

---

# CURRENT AUTHORIZATION

Current NEXT remains R0 exact unchanged v6.0.1 reproduction.

R1 is a COLD prepared decision, not yet authorized to build before R0 PASS.

No K/HEAD/weapon/temporal/shadow work is reopened by this document.
