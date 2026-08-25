# Crysis 2 VR — NEXT EXPERIMENT

## CURRENT GATE

`EXACT HISTORICAL 191032 -> v6.0.1 PRIVATE_RTV REPRODUCTION`

## PREFLIGHT — exactly 5 lines

MISSING FACT = does the exact one-delta child of user-positive `191032` preserve that good world/camera/texture behavior while finally making the image visible in Quest?
WHY THIS PARENT = `191032` has a direct positive user verdict; GOODLINE/v7 and R2/T1 are user visual HARD RED or otherwise unsuitable as visual parents.
ONE MUTATION CATEGORY = XR output bridge only: private typed eye RTs then CopyResource to acquired OpenXR swapchain images.
PASS = Quest output is visible while world/head/textures/shadows remain stable, RIGHT eye is not blurred, and no binocular/telescope geometry appears.
FAIL = black headset, broken/moving shadows, RIGHT-eye blur, binocular/telescope geometry, world/head regression, or restore/hash failure.

## LINEAGE

BASE_PACKAGE = `CRYSIS2VR_Z_REPROJECTION_v6.0.0.zip`
BASE_PACKAGE_SHA256 = `875853652D3A2ACC0E684A2E9BE2118D69FB2252E4B21B677DA4CF5105922656`
BASE_SCRIPT = `RUN_C2VR_Z_REPROJECTION_v6.0.0.bat`
KNOWN_USER_POSITIVE_RESULT = `CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_191032.zip`
KNOWN_USER_POSITIVE_PROPERTIES = one normal monitor image; head drives world; weapon fires; textures normal; user called it "реально неплохой" and "реально хорошо".
KNOWN_BLOCKER = `XR_RTV_CREATE_FAIL eye=0 image=0 hr=0x80070057`; no Quest image.

CHILD_PACKAGE = `CRYSIS2VR_Z_REPROJECTION_v6.0.1_PRIVATE_RTV_BRIDGE.zip`
CHILD_SHA256 = `E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A`
CHILD_SCRIPT = `RUN_C2VR_Z_REPROJECTION_v6.0.1.bat`
HISTORICAL_CHILD_RESULT = `CRYSIS2VR_Z_REPROJECTION_RESULT_20260817_193132.zip`
HISTORICAL_CHILD_USER_VERDICT = `UNBOUND`

WHAT IS REUSED = exact historical v6.0.0 world/camera/game-side renderer behavior and its historical runner lineage.
ONLY DELTA = replace direct RTV creation on Oculus swapchain textures with private typed LEFT/RIGHT RTs, render existing reprojection there, then CopyResource to acquired XR swapchain images.
UNCHANGED WORLD/CAMERA POLICY = YES.
UNCHANGED WEAPON/GAMEPLAY POLICY = YES.
UNCHANGED NATIVE-STEREO-OFF POLICY = YES.
LATER v6.1+ CHANGES IMPORTED = NO.

## EXECUTION

Use a hash-bound wrapper only to locate and launch the exact historical child package. The wrapper must not rewrite the renderer or runner.

Required historical ZIP SHA256:
`E683FA148794DDA2F671BD6C0ADDF6AF535482FE3F2A43DE23539778608E032A`

Inside that package run only:
`RUN_C2VR_Z_REPROJECTION_v6.0.1.bat`

After the run, collect the generated:
`CRYSIS2VR_Z_REPROJECTION_RESULT_*.zip`

## OBSERVE

- image visible in Quest left/right;
- world remains stable under slow and fast yaw;
- shadows/light do not move per eye;
- RIGHT eye is not softer than LEFT in the pathological GOODLINE/native-stereo way;
- textures remain normal;
- no binocular/telescope geometry;
- weapon behavior remains at least no worse than the `191032` checkpoint.

## FORBIDDEN

- no GOODLINE descendants;
- no v7/native ProcessScene headset renderer;
- no R2/T1 phase matrix;
- no K/PosePair;
- no v6.1/v6.2/v6.3/v6.4 imports;
- no new weapon/NEAR mutation;
- no new temporal/shadow mutation;
- no IPD/FOV tuning in this LIVE.
