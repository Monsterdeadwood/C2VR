# Crysis 2 VR — CUSTOM_DUAL_T1 v1.0.1 MAIN SOURCE

**THIS IS THE SOURCE AUTHORITY FOR THE CURRENT MAIN BUILD.**

Do not use v17.2.x donor source as the parent for current integration. v17.2.x supplies a selective PosePair donor transaction only.

## Physical source package
Library artifact:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`

Identity:
- bytes: `83,442`
- SHA256: `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- internal manifest rows: `20`
- verification: `20/20 PASS`

Use:
`tools/extract_verified_custom_dual_t1_v1_0_1.py`

to recover the complete source package only after every manifest entry passes.

## Canonical runtime RESULT
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Identity:
- bytes: `68,872,488`
- SHA256: `986A1B8FBFB32908E1D11580D90005A72851FEDAE1EDDB3596144D341CD53367`

Runtime build identity captured by the RESULT:
- x64 host SHA256 `2F79B1D4C2233444E75BC895929FABEF41EF44734854E8448D158D151A87B028`
- x86 proxy SHA256 `A11FC3E91669FBD472013E4882CEE721F09CB0A9C25FBD981AF222E87F92B279`
- Zig path recorded as C2VR toolchain Zig 0.16.0

The source package predates the canonical RESULT and its runner builds the same named `CUSTOM_DUAL_T1 v1.0.1` path. Binary identity above is runtime evidence; source-package identity is independently protected by its own 20-file manifest.

## Exact main source identities
- `src/t1_camera.cpp` — 7,969 bytes — `03D87C773DEA4FBA9D9C4828DCCB8BC50AD518E12B4E490B8C624CC26509F8BE`
- `src/t1_dual_render.cpp` — 12,765 bytes — `64F3B8FC3DEBB9976894DD1494406E4166B626BAF6B9AEB2F3D2CF846900C9F2`
- `src/t1_game_api.h` — 847 bytes — `DC33ECA5986F7F20E8179C59E5B50376030C316D8998166CCE8147AF90923197`
- `src/t1_host_x64.cpp` — 22,617 bytes — `C88F9147D5C204B2D6E4C39FC271A34FDD5C3F9664431A2059306AE7C2468819`
- `src/t1_ipc.h` — 2,618 bytes — `4C98391543122FE9B3A9FFBBDAE76415568D51F7186D61DF1955A7BECBD2C90A`
- `src/t1_proxy.cpp` — 11,365 bytes — `4505003BE7574E0DFE7766FED603F41C7BC98FF882ED50E996A735A42C7F05CD`
- `src/exports.def` — 138 bytes — `1CC314940EDE7C74D57252B087F4F34D9397FCAE95A20F711AD88CDF7CAD6F1D`

The package also freezes the exact OpenXR header set used by T1.

## Runtime proof from canonical RESULT
PASS:
- center HMD inject/restore `2296/2296`
- center culling union `2296`
- exact custom eye cameras `2295/2295`
- private RT scene L/R `2295/2295`
- temporal snapshot/restore `2295/2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- exact per-eye FOV published
- frame pair contract `desync=0/0`
- ~20 XR capture pairs
- non-duplicate eyes, median sampled RGB MAE `35.9781`
- byte-exact restore PASS

FAIL:
- `PosePairContract`: runtime pair and pose ownership were not the same immutable current-XR-frame ticket; game/host pose desync `1/1`

Therefore the current integration rule is simple:

**KEEP T1 v1.0.1 renderer. PATCH ONLY PosePair rendezvous.**

## Child-build rule
The next child must be auditable as:

```text
CUSTOM_DUAL_T1 v1.0.1 exact source
        +
minimal PosePair rendezvous transplant from verified v17.2.1 donor
        =
PosePair child build
```

Do not mix HEAD/culling, weapon/NEAR, temporal-history policy or shadow-policy changes into that child.

See:
- `PACKAGE_SHA256.txt`
- `runtime/donors/v17.2.1/POSEPAIR_TRANSPLANT.md`
- `docs/STATE.md`
