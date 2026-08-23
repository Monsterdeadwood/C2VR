# C2VR v17.2.1 — ORIGINAL VERIFIED DONOR PACKAGE

**DONOR ONLY. NOT THE MAIN BUILD.**

Main build remains `CUSTOM_DUAL_T1 v1.0.1`.

## Provenance upgrade
The donor was first reconstructed from embedded text in:
`CRYSIS2VR_MASTER_CORPUS_ALL_EVIDENCE_20260821_100MB.md`.

That recovery produced 25 byte-verified textual files and remains a useful independent cross-check.

A stronger authority is now available: the physical original Library package:

`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.1_ARGV_FIX_ONECLICK.zip`

Original package identity:
- bytes: `91,521`
- SHA256: `53688524B59E9C8F7B768BFA78BB80DEDC0981EB7FF699204E496887668D38A2`

Its original `PACKAGE_FILES_SHA256.txt` contains 27 entries. Direct verification against the physical ZIP is:

```text
manifest_rows=27
verified=27
failed=0
```

The extra three members compared with corpus text recovery are compiled Python `__pycache__/*.pyc` files.

Primary reproduction tool:
`tools/extract_verified_v17_2_1_original.py`

Independent text-corpus cross-check:
`tools/extract_verified_v17_2_1.py`

Exact original-package manifest plus member sizes:
`ORIGINAL_PACKAGE_SHA256.txt`

## Core donor source identities
- `src/t1_ipc.h` — 2,824 bytes — `DE00ABD099F5988BB930A6150FF16BA1A9E9AC1A55AE3EC5CC59DC7DEA54B931`
- `src/t1_game_api.h` — 1,014 bytes — `642AF56F086EE9EF8E674F495C2B610E9C38088FB0A2342B55CB0F53E2E52E02`
- `src/t1_camera.cpp` — 8,111 bytes — `C71E6B52A6F326923A45E682392F79C96C84FFF1E1D66393769A821D9A5C42A1`
- `src/t1_proxy.cpp` — 16,526 bytes — `1CF91E61999A600C7A39E992EF610FFDF259ABD9B8D0E32373A13996DD8FC22C`
- `src/t1_dual_render.cpp` — 20,540 bytes — `397D0577D3F07B776A17395733AB6500BCD05C8928A51608CE3FDD8DEA415C77`
- `src/t1_host_x64.cpp` — 34,560 bytes — `A349AA6BC2781C4DCD1AF20E5EF5B571656B84BF005E2193637C3591F8D21C51`

The smaller runtime source files already imported into this directory were independently checked after GitHub write. The two larger source files are intentionally recovered from the original package by the deterministic extractor instead of being silently normalized through text transport.

## Why this donor exists
v17.2.1 mixes several future gates in one package: PosePair rendezvous, HEAD/culling, weapon/NEAR, temporal and shadow logic. Installing it wholesale would destroy causal attribution.

For the current gate, import **only** the PosePair contract/rendezvous pieces into `CUSTOM_DUAL_T1 v1.0.1`.

Current surgical handoff:
`POSEPAIR_TRANSPLANT.md`

Do not treat runtime claims made by this donor as accepted main-build results unless independently promoted in `docs/PROVEN.md`.
