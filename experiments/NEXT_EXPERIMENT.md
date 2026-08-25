# Crysis 2 VR — NEXT EXPERIMENT

## DECISION

**STOP direct descendants of current USER VISUAL HARD-RED builds. The next runtime is not a new experiment. It is an unchanged reproduction of an exact recovered historical property baseline.**

Authoritative state:
- `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
- `docs/FALSIFIED.md`
- `docs/GATES.md`
- `docs/NEXT.md`

## CURRENT GATE

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

Do NOT run K/HEAD/weapon/NEAR/temporal/shadow work while this gate is open.

## CURRENT HARD REDS

Do not derive a visual child from:
- `C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage;
- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`.

T1 K0 SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`.

Both are user visual rejects.

## EXACT RECOVERED BASE PACKAGE

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Bytes:
`164221`

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact runner lineage:

```text
20_RUN_C2VR_FULL_VR.bat
 -> FUTURE_RUNS/CRYSIS2VR_BLACKBOX_ENGINE_TAP_v1.0.0/RUN_FULL_VR.bat
 -> tools/Build-Run-EngineTap.ps1
```

Historical user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

## MISSING FACT

Can the exact physical v6.0.1 package, executed unchanged through its original runner lineage on the frozen retail target, reproduce the historical world-stability/no-flicker behavior today?

Nothing else is being tested.

## PREFLIGHT — exactly 5 lines

**MISSING FACT:** does exact physical v6.0.1 unchanged still reproduce stable textures/shadows/objects and no periodic XR blank/flicker behavior?
**WHY THIS PARENT:** its exact ZIP/hash/runner are physically recovered and its user-positive property is specifically bounded; later parents are visually red or unbound.
**PASS:** exact package/runner identity matches, unchanged reproduction launches/restores correctly, and the user confirms the historical no-flicker/stable-world property is reproduced.
**FAIL:** identity mismatch, runner mismatch, runtime/preflight failure, or the unchanged package no longer reproduces its bounded property; record exact failure without adding a mutation.
**BASELINE MUST HOLD:** frozen retail hashes, x86 game+x64 host architecture, no new camera/stereo/weapon/temporal/shadow code, no new BAT/PS1 scaffold.

## LINEAGE

BASE_PACKAGE:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

BASE_SCRIPT:
`20_RUN_C2VR_FULL_VR.bat` through the inherited `RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1` chain.

KNOWN_GOOD_RESULT:
historical user property is known; exact old result ZIP identity is not required to invent a new runner and must not be guessed.

WHAT IS REUSED:
all files and launch/build/restore behavior byte-for-byte from the physical recovered package.

ONLY DELTA:
**NONE.** This is an unchanged reproduction.

UNCHANGED LAUNCH PATH:
YES.

UNCHANGED BUILD PATH:
YES.

UNCHANGED RESTORE PATH:
YES.

EXPECTED NEW RESULT:
fresh raw result + explicit user headset verdict for the v6.0.1 property only.

## PATCH

NONE.

No source edits.
No BAT edits.
No PS1 edits.
No IPC edits.
No camera edits.
No stereo edits.
No weapon edits.
No temporal/shadow edits.

## BUILD

Use the exact historical package's own build path only.

If the historical runner fails because a tool path has become unavailable, classify `LINEAGE/ENVIRONMENT FAILURE`; do not silently rewrite infrastructure in the same causal run.

## RUN

User observes only:
- periodic flicker/blanking;
- texture/object stability;
- shadow/light stability;
- whether the image remains judgeable.

Record stereo fusion separately as expected unresolved behavior.

Do not evaluate weapon polish or cadence tuning in this run.

## RESULT_TEMPLATE

```text
LIVE_STATUS=LIVE/NOT_LIVE
PACKAGE_SHA_MATCH=PASS/FAIL
RUNNER_IDENTITY=PASS/FAIL
RETAIL_HASHES_PRE=PASS/FAIL
WORLD_STABILITY=PASS/FAIL/UNTESTED
FLICKER_BLANKING=PASS/FAIL/UNTESTED
SHADOW_LIGHT_STABLE=PASS/FAIL/UNTESTED
BINOCULAR_FUSION=PASS/FAIL/UNTESTED
RESTORE=PASS/FAIL
RETAIL_HASHES_POST=PASS/FAIL
USER_HEADSET_VERDICT=ACCEPT_PROPERTY/RED/NOT_TESTED
```

## PASS / FAIL

PASS means only:
`v6.0.1 WORLD_STABILITY_NO_FLICKER property reproduced`.

It does NOT mean:
- stereo fusion solved;
- camera ownership solved;
- T1 ready to merge;
- K ready;
- weapon ready.

After PASS, freeze this exact reproduction and choose one single next causal axis.

Primary separate camera reference remains:
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` plus the single-source `+0x0057AC76` topology.

True private-L/R reference remains:
`CUSTOM_DUAL_T1 v1.0.1`.

## FORBIDDEN

- K=1/K=2;
- final HEAD composition;
- weapon/NEAR integration;
- temporal-history mutation;
- second-eye shadow mutation;
- coordinate-sign LIVE;
- new BAT/PS1 scaffold;
- any analyzer PASS whose prerequisites are absent;
- calling this reproduction whole-build GOLD if only the no-flicker/stable-world property passes.
