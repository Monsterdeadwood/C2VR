# C2VR — T1 v1.0.0 -> v1.0.1 HOSTFIX exact delta — 2026-08-25

Purpose: preserve exactly why `CUSTOM_DUAL_T1 v1.0.1 HOSTFIX` is the canonical T1 parent and prevent future branches from reviving the v1.0.0 launcher bug.

## Exact carriers

### T1 v1.0.0
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.0.zip`
- bytes `82,587`
- SHA256 `8CC59E1AA07E7BA365BBD54251773D5E4240D600B1E07DE26A083FCF3E1CA8D9`
- ZIP CRC PASS
- package manifest `20/20 PASS`

### T1 v1.0.1 HOSTFIX
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`
- bytes `83,442`
- SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- ZIP CRC PASS
- package manifest `20/20 PASS`

Both exact physical packages were recovered from persistent Library and compared directly.

## Runtime/source delta
All C/C++ runtime source is byte-identical between v1.0.0 and v1.0.1:
- `src/exports.def`
- `src/t1_camera.cpp`
- `src/t1_dual_render.cpp`
- `src/t1_game_api.h`
- `src/t1_host_x64.cpp`
- `src/t1_ipc.h`
- `src/t1_proxy.cpp`
- vendored OpenXR headers
- `analysis/analyze_t1.py`
- `T1_ARCHITECTURE.md`
- recovery tooling

Therefore v1.0.1 HOSTFIX did **not** change the camera, stereo, render transaction, IPC, proxy, OpenXR host binary source, or scientific experiment architecture.

## Actual hotfix
The substantive fix is entirely in `tools/Run-T1.ps1` plus corresponding validation/package metadata.

v1.0.0 used:
```powershell
$game=$null;$host=$null;$runError=''
```

PowerShell variable names are case-insensitive, so `$host` collides with the reserved automatic `$Host` variable in Windows PowerShell 5.1.

v1.0.1 changes that process variable to:
```powershell
$game=$null;$xrHost=$null;$runError=''
```

All later process references are correspondingly renamed from `$host` to `$xrHost`.

The package manifest itself explicitly records the hotfix as:
`PowerShell 5.1 reserved automatic variable $Host collision removed; process variable renamed to $xrHost.`

## Other package changes
Expected non-runtime changes:
- entrypoint renamed `...v1.0.0.bat` -> `...v1.0.1.bat`;
- README/package version metadata updated;
- static validator adds an explicit check that `$host` is absent and `$xrHost` is present;
- manifest/checksum files updated to represent the new package.

## Consequence
`CUSTOM_DUAL_T1 v1.0.1 HOSTFIX` is the correct canonical parent because it preserves the v1.0.0 experiment source while fixing runner compatibility on Windows PowerShell 5.1.

Do not downgrade to the v1.0.0 runner and do not interpret the HOSTFIX as a renderer/camera behavior change.

## Classification
- v1.0.0 package identity: **EXACT CARRIER PROVEN**
- v1.0.1 package identity: **EXACT CARRIER PROVEN**
- runtime C/C++ identity v1.0.0 -> v1.0.1: **BYTE-IDENTICAL PROVEN**
- HOSTFIX scope = PowerShell runner variable collision: **EXACT DELTA PROVEN**

No LIVE or mutation was performed for this comparison.
