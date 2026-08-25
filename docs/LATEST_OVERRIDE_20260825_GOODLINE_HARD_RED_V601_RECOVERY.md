# C2VR LATEST OVERRIDE — GOODLINE HARD RED / EXACT V6.0.1 RECOVERY

Date: 2026-08-25

This file supersedes any older NEXT/STATE text that selects v7/CLEAN_NATIVE_EYES, GOODLINE, R2/T1, cadence K, or native CryEngine stereo as the next visual parent.

## USER VISUAL HARD RED — GOODLINE v1.0.0

Package:
`CRYSIS2VR_GOODLINE_NATIVE_SINGLE_WINDOW_v1.0.0_ONECLICK.zip`

SHA256:
`566BBBA4C9889DDD5B1F4974DF32330845EEE2F772B7EFD0469A9AF3DEFD07DA`

Direct user headset verdict after LIVE:
- shadows are badly broken / unstable;
- RIGHT eye is visibly blurred;
- overall build rejected.

Classification:
`USER_VISUAL_HARD_RED`.

Permanent consequence:
- GOODLINE must not be a direct visual parent;
- do not patch-number forward from GOODLINE;
- do not revive the v7/CryEngine native ProcessScene stereo path as the next visual baseline;
- its RIGHT-eye softness and eye-dependent shadow/deferred behavior are consistent with the previously documented stock-native-stereo caveat.

## STRONGEST RECOVERED DIRECT USER-POSITIVE CHECKPOINT

Raw result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_191032.zip`

Parent package:
`CRYSIS2VR_Z_REPROJECTION_v6.0.0.zip`

SHA256:
`875853652D3A2ACC0E684A2E9BE2118D69FB2252E4B21B677DA4CF5105922656`

Historical direct user verdict:
- "реально неплохой";
- one normal image on the monitor;
- head motion drove the viewed world;
- weapon fired;
- textures looked normal;
- user said it looked "реально хорошо";
- only critical blocker: image did not reach the Quest headset.

The raw failure was narrow and explicit:
`XR_RTV_CREATE_FAIL eye=0 image=0 hr=0x80070057`

Therefore `191032` is classified as:
`COMPONENT_VISUAL_GREEN: WORLD/CAMERA/TEXTURE/WEAPON-BEHAVIOR ON DESKTOP`
`XR_VISIBLE_OUTPUT = FAIL`

It is NOT claimed as a full headset visual green.

## EXACT ONE-DELTA HISTORICAL CHILD

Package:
`CRYSIS2VR_Z_REPROJECTION_v6.0.1_PRIVATE_RTV_BRIDGE.zip`

Exact SHA256:
`E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A`

Historical runner:
`RUN_C2VR_Z_REPROJECTION_v6.0.1.bat`

Historical result exists:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_193132.zip`

The one intended mutation from v6.0.0 was XR output only:
- stop creating RTVs directly on Oculus/OpenXR swapchain textures;
- create private typed LEFT/RIGHT render targets;
- run the existing reprojection into those private RTs;
- `CopyResource` private eye textures into acquired XR swapchain images;
- submit with `xrEndFrame`.

Do NOT import later v6.1+ pose/near/weapon changes into this recovery LIVE.

Direct user headset verdict for `193132` is currently UNBOUND. Do not promote it to visual green before a fresh reproduction.

## CURRENT GATE

`EXACT HISTORICAL 191032 -> v6.0.1 PRIVATE_RTV REPRODUCTION`

First LIVE must reproduce the exact historical v6.0.1 package unchanged by SHA.

Preferred execution is a wrapper that:
1. searches for the exact historical ZIP;
2. accepts it only if SHA256 equals `E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A`;
3. extracts it unchanged;
4. launches its original `RUN_C2VR_Z_REPROJECTION_v6.0.1.bat`;
5. collects the resulting `CRYSIS2VR_Z_REPROJECTION_RESULT_*.zip`.

No renderer rewrite is allowed in this LIVE.

## PASS / FAIL

PASS candidate only if the fresh headset run preserves the user-positive 191032 properties while finally reaching Quest:
- stable world/head behavior;
- normal-looking textures;
- no native-stereo RIGHT-eye softness regression;
- no eye-dependent moving/broken shadows;
- image visible in both Quest eyes;
- no binocular/telescope catastrophe.

FAIL if:
- black headset;
- broken shadows;
- RIGHT-eye blur appears;
- severe binocular/telescope geometry;
- head/world regression;
- later-v6.1 behavior appears.

If FAIL, hard-stop v6.0.1 as a whole visual parent. Do not jump automatically to v6.1/v6.2/v6.3/v6.4.

## PARENT SELECTION LAW

`USER_HEADSET_VERDICT > captures > raw LIVE logs > counters > static checks > package intent`

One visual LIVE = one causal mutation. No Frankenstein merges until an accepted visual baseline exists.
