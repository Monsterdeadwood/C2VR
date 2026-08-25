# Crysis 2 VR - CUSTOM_DUAL_T1 v1.0.1 SOURCE AUTHORITY

## SUPERSEDED VISUAL-PARENT WARNING

**THIS DIRECTORY IS A TECHNICAL SOURCE AUTHORITY ONLY. IT IS NOT THE CURRENT VISUAL PARENT.**

The old instruction:

`KEEP T1 v1.0.1 renderer. PATCH ONLY PosePair rendezvous.`

is **SUPERSEDED**.

A PosePair-only K0 child was built and run later:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`.

The user reported that child visually even worse than the already-rejected prior build.

Classification:
`VISUAL_RED`.

Therefore:
- do NOT build K1/K2 from T1 PosePair K0;
- do NOT treat this directory as authorization for another PosePair child;
- do NOT import HEAD/weapon/temporal/shadow on top of the rejected child;
- current gate is `VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`.

Read current authority first:
- `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
- `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
- `docs/FALSIFIED.md`
- `docs/GATES.md`
- `docs/NEXT.md`

## WHAT THIS DIRECTORY STILL PROVES

`CUSTOM_DUAL_T1 v1.0.1` remains the technical source authority for the proven private-eye renderer primitive.

Classification:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

It proves a renderer mechanism, not a whole-build visual baseline.

## PHYSICAL SOURCE PACKAGE

Library artifact:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`

Identity:
- bytes `83,442`
- SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- manifest rows `20`
- verification `20/20 PASS`

Use:
`tools/extract_verified_custom_dual_t1_v1_0_1.py`

to recover the exact source only after manifest verification.

## CANONICAL TECHNICAL RESULT

`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Identity:
- bytes `68,872,488`
- SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAE1EDDB3596144D341CD53367`

Runtime binary identity:
- x64 host `2F79B1D4C2233444E75BC895929FABEF41EF44734854E8448D158D151A87B028`
- x86 proxy `A11FC3E91669FBD472013E4882CEE721F09CB0A9C25FBD981AF222E87F92B279`

## EXACT SOURCE IDENTITIES

- `src/t1_camera.cpp` - 7,969 bytes - `03D87C773DEA4FBA9D9C4828DCCB8BC50AD518E12B4E490B8C624CC26509F8BE`
- `src/t1_dual_render.cpp` - 12,765 bytes - `64F3B8FC3DEBB9976894DD1494406E4166B626BAF6B9AEB2F3D2CF846900C9F2`
- `src/t1_game_api.h` - 847 bytes - `DC33ECA5986F7F20E8179C59E5B50376030C316D8998166CCE8147AF90923197`
- `src/t1_host_x64.cpp` - 22,617 bytes - `C88F9147D5C204B2D6E4C39FC271A34FDD5C3F9664431A2059306AE7C2468819`
- `src/t1_ipc.h` - 2,618 bytes - `4C98391543122FE9B3A9FFBBDAE76415568D51F7186D61DF1955A7BECBD2C90A`
- `src/t1_proxy.cpp` - 11,365 bytes - `4505003BE7574E0DFE7766FED603F41C7BC98FF882ED50E996A735A42C7F05CD`
- `src/exports.def` - 138 bytes - `1CC314940EDE7C74D57252B087F4F34D9397FCAE95A20F711AD88CDF7CAD6F1D`

## TECHNICAL RUNTIME PROOF

Canonical T1 result mechanically proved:
- center HMD inject/restore `2296/2296`
- center culling union `2296`
- custom eye cameras `2295/2295`
- private RT scene L/R `2295/2295`
- temporal snapshot/restore `2295/2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- exact per-eye FOV published
- FramePairContract desync `0/0`
- non-duplicate eyes, median sampled RGB MAE `35.9781`
- byte-exact restore PASS

Known failure in that result:
- PosePairContract acceptance failed;
- game/host pose desync `1/1`.

Later visual evidence proves that simply adding a PosePair K0 child is not the current solution.

## CURRENT REUSE LAW

Allowed:
- use T1 source to understand/recover the private LEFT/RIGHT transaction;
- use its exact RC33/RT mechanics as a narrow donor after a user-positive visual baseline is reproduced;
- compare exact source hashes against future renderer work.

Forbidden:
- call T1 v1.0.1 the current whole-build visual parent;
- call the PosePair transplant the current next step;
- generate another direct PosePair/K child from this README;
- infer visual correctness from its strong counters.

## CURRENT FIRST REPRODUCTION TARGET

The exact user-positive world-stability package is now:

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Its bounded historical property:
- no flicker;
- stable shadows/textures/objects;
- binocular fusion still failed.

T1 is a separate true-L/R technical axis to be reintroduced only after the stable visual property is reproduced.
