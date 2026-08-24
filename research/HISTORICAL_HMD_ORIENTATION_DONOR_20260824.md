# C2VR - historical HMD orientation donor recovered from old tab

Date: 2026-08-24 archaeology import.

Physical package:
`C2VR_BREAKTHROUGH_HMD_ORIENTATION_NATIVE_v1.0.0_ONECLICK.zip`

Library chronology shows the package was created, but targeted search and the immediately following C2 timeline did **not** surface a returned `C2VR_BREAKTHROUGH_HMD_ORIENTATION_RESULT_*.zip`.

Classification:
**PREPARED / STATIC-SELFTESTED / NO RETURNED SCIENTIFIC RESULT SURFACED.**

Do not cite it as a HEAD PASS or FAIL.

## Why the package is still valuable
The package was built after two historical prerequisites:
1. fixed +10 degree Matrix34 yaw had mechanically survived 300/300 calls with 300/300 exact restores;
2. TTD had closed the authoritative camera-copy lineage through `Crysis2.exe+0x0016C993` into the local camera used by the primary `Renderer::SetCamera` return `+0x0057AC76`.

Those prerequisites have now been independently recovered into GitHub archaeology.

## Frozen target
One mutable scientific state only:
**the 9 Matrix34 orientation floats of `CSystem::m_ViewCamera`.**

The package deliberately did not mutate:
- translation;
- FOV;
- aspect;
- near/far;
- asymmetric projection;
- weapon state.

It also did not attempt to submit the Crysis image to OpenXR. The headset was only the live orientation source for a camera-carrier proof.

## HMD transform policy used by the package
The x64 OpenXR host published a recentered relative HMD quaternion.

The x86 pose client converted that quaternion into Cry basis form and used the historical center-orientation policy:

`rotated = gameBase * inverse(convertedHmdRotation)`

Equivalent implementation shape:
- obtain relative HMD rotation;
- convert XR quaternion to Cry 3x3 basis;
- transpose/invert that HMD basis;
- post-compose the game baseline with the inverse HMD rotation;
- write only the 3x3 orientation during the bounded call;
- restore the original 3x3 exactly after the native consumer.

## Runner target / seam
The package targeted the existing native camera carrier around:
`gameplay RenderWorld call +0x005E2476 -> RenderInternal +0x005DEF10`.

Self-verification recorded:
- `TARGET_0x005DEF10=PASS`
- `ONE_MUTABLE_STATE_3X3_ORIENTATION=PASS`
- `CENTER_ORIENTATION_INVERSE_CORRECTION=PASS`
- `NO_ALL_SETCAMERA_HOOK=PASS`

The intended mechanical PASS required >=300 sane HMD-derived orientation calls, survival through original RenderInternal, exact restore, >5 degree pose variation and restored callsite.

Again, no returned RESULT was surfaced, so those are **acceptance criteria**, not observed facts.

## Future use after PosePair closes
Current HEAD finalist in `docs/STATE.md` is already conceptually aligned with this historical package: game/body camera composed with relative HMD rotation, rotation-first, translation deferred.

Therefore:
- do not build another generic HMD-orientation bridge from scratch;
- use this package/source as a donor/reference only after the current P6/PosePair gate closes;
- rebase the idea onto the current exact T1 parent rather than reviving this old package wholesale;
- preserve current true-L/R, PosePair identity and per-eye projection architecture;
- require a fresh headset visual 1:1 verdict before promotion.
