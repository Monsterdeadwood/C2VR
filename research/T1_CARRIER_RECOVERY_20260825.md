# C2VR — CUSTOM_DUAL_T1 v1.0.1 carrier recovery — 2026-08-25

Purpose: close the highest-risk archival gap for the proven C2VR main renderer parent without changing runtime behavior.

## Recovered exact carrier
Persistent Library contains the exact package expected by:
`tools/extract_verified_custom_dual_t1_v1_0_1.py`

Carrier:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`

Observed identity after materialization:
- bytes: `83,442`
- SHA256: `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- ZIP CRC test: PASS
- package directory: `CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1/`
- internal manifest: `PACKAGE_FILES_SHA256.txt`
- manifest rows: `20`
- exact internal SHA verification: `20/20 PASS`

This is therefore the exact source authority required by the existing extractor, not a reconstruction from logs or a neighboring build.

## Verified package contents
The package manifest closes these exact files:
- `PACKAGE_MANIFEST.json`
- `README_RU.txt`
- `RECOVER_CRYSIS2VR_CUSTOM_DUAL_T1.bat`
- `RUN_CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.1.bat`
- `STATIC_VALIDATION.txt`
- `T1_ARCHITECTURE.md`
- `analysis/analyze_t1.py`
- `analysis/static_validate.py`
- `src/exports.def`
- `src/t1_camera.cpp`
- `src/t1_dual_render.cpp`
- `src/t1_game_api.h`
- `src/t1_host_x64.cpp`
- `src/t1_ipc.h`
- `src/t1_proxy.cpp`
- `src/third_party/openxr/include/openxr/openxr.h`
- `src/third_party/openxr/include/openxr/openxr_platform.h`
- `src/third_party/openxr/include/openxr/openxr_platform_defines.h`
- `tools/Recover-T1.ps1`
- `tools/Run-T1.ps1`

The package's own manifest remains the authority for per-file SHA256 values. Do not regenerate or normalize the package and call it byte-identical.

## Exact scientific RESULT carrier
Persistent Library also contains:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Materialized identity:
- bytes: `68,872,488`
- SHA256: `986A1B8FBFB32908E1D11580D90005A72851FEDA E1EDDB3596144D341CD53367` with whitespace removed below
- canonical SHA256: `986A1B8FBFB32908E1D11580D90005A72851FEDAE1EDDB3596144D341CD53367`

This matches the retained 2026-08-19 source/integrity manifest.

Important distinction:
- HOSTFIX ZIP = exact source/build/recovery authority.
- RESULT ZIP = exact runtime evidence carrier.
- Git compact docs = promoted scientific state.

All three must remain distinguishable.

## Original T1 result classification
The original automatic diagnosis did not call the whole visual gate proven because headset visual arbitration was still required. It nevertheless recorded the core mechanical evidence later incorporated into the canonical project state, including:
- center inject/restore `2296/2296`;
- cull union `2296`;
- custom eye cameras `2295/2295`;
- RT scene LEFT/RIGHT `2295/2295`;
- direct pair copies `2229`;
- OpenXR submits `2624`;
- sampled eyes not byte-duplicate, median RGB MAE `35.9781`;
- frame desync `0`;
- PosePair desync still present at that stage;
- byte-exact retail restore PASS.

Do not rewrite the historical artifact's verdict. Current project-level PROVEN state may be stronger because it combines later evidence.

## EOL / Git normalization warning
The original package contains mixed line-ending identities. Examples observed:
- most C/C++/Python/Markdown source: LF;
- BAT launchers: CRLF;
- some TXT files: CRLF;
- `Recover-T1.ps1`: LF;
- `Run-T1.ps1`: CRLF.

Repository `.gitattributes` intentionally normalizes several text classes. Therefore a repository text copy must not be advertised as the original package byte identity unless its stored blob hash is explicitly checked against the package manifest.

The immutable original ZIP SHA above remains the easiest byte-exact authority.

## Preservation status
Previous status: `EXTERNAL-CARRIER DEPENDENT / carrier location unresolved`.

New status:
**CARRIER RECOVERED + MATERIALIZED + CRC PASS + PACKAGE MANIFEST 20/20 PASS + RESULT CARRIER SHA VERIFIED.**

The source package no longer represents an unknown/lost dependency. It remains outside ordinary Git binary history unless deliberately promoted as a binary carrier later.

## Runtime gate discipline
No runtime mutation occurred during this recovery. No game launch occurred. No new T1 scientific claim is introduced.

Active serial runtime gate remains:
`P6 PosePair -> HEAD 1:1 -> WEAPON/NEAR -> TEMPORAL/SHADOW -> REGRESSION -> RELEASE`.
