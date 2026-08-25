# Crysis 2 VR State

## CURRENT GATE — 2026-08-25

`EXACT HISTORICAL 191032 -> v6.0.1 PRIVATE_RTV REPRODUCTION`

This supersedes the R2/private-LR matrix and GOODLINE/v7 visual-parent attempts.

Read first:
1. `docs/LATEST_OVERRIDE_20260825_GOODLINE_HARD_RED_V601_RECOVERY.md`
2. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `experiments/NEXT_EXPERIMENT.md`
6. `docs/NEXT.md`

Evidence law:
`USER_HEADSET_VERDICT > captures > raw LIVE logs > counters > static validation > package intent`.

## NEW HARD RED

`CRYSIS2VR_GOODLINE_NATIVE_SINGLE_WINDOW_v1.0.0_ONECLICK.zip`
SHA256 `566BBBA4C9889DDD5B1F4974DF32330845EEE2F772B7EFD0469A9AF3DEFD07DA`.

Direct user headset verdict:
- shadows broken/unstable;
- RIGHT eye blurred;
- whole build rejected.

Classification:
`USER_VISUAL_HARD_RED`.

No direct visual descendants. Do not patch GOODLINE or revive v7/native ProcessScene stereo as the next baseline.

## STRONGEST DIRECT USER-POSITIVE RECOVERED CHECKPOINT

Result:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_191032.zip`

Parent:
`CRYSIS2VR_Z_REPROJECTION_v6.0.0.zip`
SHA256 `875853652D3A2ACC0E684A2E9BE2118D69FB2252E4B21B677DA4CF5105922656`.

Direct historical user-positive properties:
- user called it "реально неплохой" and said it looked "реально хорошо";
- one normal image on monitor;
- head motion drove the viewed world;
- weapon fired;
- textures looked normal.

Only critical blocker in that run:
`XR_RTV_CREATE_FAIL eye=0 image=0 hr=0x80070057`
so the image never reached Quest.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD/CAMERA/TEXTURE/WEAPON-BEHAVIOR ON DESKTOP`
`XR_VISIBLE_OUTPUT = FAIL`.

## CURRENT NEXT RUNTIME

Exact historical child:
`CRYSIS2VR_Z_REPROJECTION_v6.0.1_PRIVATE_RTV_BRIDGE.zip`
SHA256 `E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A`.

Historical runner:
`RUN_C2VR_Z_REPROJECTION_v6.0.1.bat`.

Historical result exists:
`CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_193132.zip`.

Direct user headset verdict for `193132` remains UNBOUND.

The next LIVE must execute the exact v6.0.1 package unchanged. Its only intended delta from the user-positive v6.0.0 is XR output: private typed eye RTs -> CopyResource into acquired XR swapchain images.

Do not import later v6.1+ changes.

## PRESERVED COMPONENT GREENS

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`
remains a separate `COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER` donor only. Do not confuse it with Z-reprojection v6.0.1 PRIVATE_RTV.

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` remains a camera-ownership component reference.

## PARKED

Until an accepted headset visual baseline exists:
- R2/T1 visible descendants;
- PosePair/K;
- final HEAD rewrite;
- weapon/NEAR merge;
- temporal/shadow mutation;
- later Z v6.1/v6.2/v6.3/v6.4;
- release optimization.

## RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
