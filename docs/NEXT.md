# Crysis 2 VR — NEXT

## CURRENT GATE

`EXACT HISTORICAL 191032 -> v6.0.1 PRIVATE_RTV REPRODUCTION`

Read first:
1. `docs/LATEST_OVERRIDE_20260825_GOODLINE_HARD_RED_V601_RECOVERY.md`
2. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `experiments/NEXT_EXPERIMENT.md`

## WHY

GOODLINE v1.0.0 is now `USER_VISUAL_HARD_RED`: user reported broken/unstable shadows and a blurred RIGHT eye. No descendants.

The strongest directly user-positive checkpoint recovered is:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_191032.zip`.

User described that run as "реально неплохой" / "выглядит реально хорошо": one normal monitor image, head-driven world, firing weapon, normal-looking textures. Its narrow blocker was `XR_RTV_CREATE_FAIL eye=0 image=0 hr=0x80070057`, so the image never reached Quest.

## NEXT RUNTIME

Run the exact one-delta historical child unchanged:

`CRYSIS2VR_Z_REPROJECTION_v6.0.1_PRIVATE_RTV_BRIDGE.zip`

SHA256:
`E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A`

Original runner:
`RUN_C2VR_Z_REPROJECTION_v6.0.1.bat`

Historical result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_193132.zip`

Known direct headset verdict for `193132` is UNBOUND, so it must be freshly reproduced before promotion.

## ONLY DELTA FROM USER-POSITIVE v6.0.0

XR output bridge only:
- do not create RTV directly on Oculus/OpenXR swapchain image;
- render existing reprojection into private typed LEFT/RIGHT RTs;
- CopyResource into acquired XR swapchain images;
- submit normally.

Do not change world camera, renderer source behavior, shadows, weapon, NEAR, pose policy, or later v6.1+ behavior in this LIVE.

## RUN POLICY

Preferred launcher is a hash-bound recovery wrapper that searches the machine for the exact historical ZIP, verifies SHA256, extracts it unchanged, and invokes its original BAT.

No F-key matrix. No tuning.

## PASS

Candidate PASS only if the fresh Quest run preserves the `191032` good properties and adds visible XR output:
- stable world/head;
- normal-looking textures;
- no broken/moving shadows;
- no RIGHT-eye softness regression;
- image visible in both Quest eyes;
- no binocular/telescope geometry.

## FAIL

Any of:
- black headset;
- broken/moving shadows;
- RIGHT-eye blur;
- binocular/telescope geometry;
- world/head regression;
- restore/hash failure.

On FAIL, hard-stop this whole-build parent and do not jump automatically to v6.1/v6.2/v6.3/v6.4.

## PARKED

- R2/T1 visible descendants;
- PosePair/K;
- final HEAD rewrite;
- weapon/NEAR merge;
- new temporal/shadow policies;
- later Z-reprojection descendants;
- release optimization.
