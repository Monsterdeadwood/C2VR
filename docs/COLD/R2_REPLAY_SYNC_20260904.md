# Crysis2VR / C2VR — R2 replay sync

SYNC_EPOCH = 2026-09-04
ROLE = R2
BRANCH = `cold/r2/replay-ownership`
STATE = COLD
SCOPE = COLD_ONLY / no canonical claim promotion

## Protected exact target
- retail Crysis 2 1.9 / CryEngine DX11
- game path: `C:\GOG Games\Crysis 2`
- preserve the repository's frozen executable / renderer hashes and protected transport-quality baseline

## PROVEN / RETAIN
1. True same-frame LEFT/RIGHT scene replay exists in the current R2 substrate.
2. Executed substrate records **2295 LEFT / 2295 RIGHT** eye passes with distinct L/R images and private/OpenXR transport functioning.
3. The native-eye model remains:

```text
XR LEFT/RIGHT SetCamera
 -> stock EF_Scene3D / RC33
 -> RC_CopyToStereoTex(0/1)
 -> native $StereoL / $StereoR
 -> EndFrame drain
 -> atomic L/R export
 -> OpenXR
```

4. `RC_CopyToStereoTex` enqueues immutable command 35 with eye/channel identity; retail `CopyToStereo` selects `$StereoL` for channel 0 and `$StereoR` for channel 1.
5. One prepared render list may execute for both eyes. Do not add a second high-level `RenderWorld` / `EF_StartEf` merely to obtain stereo.
6. Native `ProcessScene` is the same-frame L/R scheduler. Render-thread eye ownership should remain target-derived/private (`OUR_EYE_L/R` style), not a generic global-eye invention.

## FALSIFIED / DO NOT REOPEN
- Treating the project as still blocked on basic two-eye scheduling.
- A second top-level `RenderWorld` / `EF_StartEf` as the default stereo architecture.
- Relabelling stale pixels with a newer pose/FOV/display-time transaction.
- Reopening private/OpenXR transport merely because downstream FX/visibility differs between eyes.

## STILL UNKNOWN — FIRST MISSING EDGE
`PREP_ENVELOPE_CLOSURE`

The missing fact is ownership of the preparation envelope that feeds light visibility and shadow-frustum/caster construction when the camera/frustum is widened for same-frame replay.

Current cold ordering:

```text
SetupCamera
 -> UpdateLightSources
 -> PrepareLightSourcesForRendering_0/_1
 -> InitShadowFrustums
 -> visibility / object traversal
 -> per-eye scene execution
```

The exact C2 reader binding that proves which camera/frustum must own this one preparation epoch remains open. Donor/source evidence shows `InitShadowFrustums` receives `SRenderingPassInfo`, and `UpdateGSMLightSourceDynamicShadowFrustum()` reads `passInfo.GetCamera()`, but donor semantics remain candidate evidence until retail correspondence is closed.

## Replay ownership constraint
The current architecture target remains **one preparation envelope + same-frame L/R execution**, not two independent high-level world preparations unless exact retail evidence forces that conclusion.

A narrowly owned render-thread eye path may skip only genuinely pair-shared preparation on RIGHT after exact ownership proof. Do not use blanket `SHDF_ZPASS_ONLY` or broad right-eye suppression as a substitute for ownership closure.

## Parked temporal owner
Water history remains parked, not solved:
- previous reflection texture;
- owner ViewProj / previous-camera projection history;
- these must advance atomically per logical frame/pair, not independently once per eye.

Do not mix water-history repair into PREP_ENVELOPE_CLOSURE.

## R1 boundary
R1's later `RC_COPY_SIDECAR_TRANSACTION + EXACT_STEREO_RESOURCE_LAST_HOP` work is adjacent evidence, not R2 ownership. R2 may consume its proven resource/transaction facts but must not collapse the roles.

## STOP RULE
Remain COLD. The next meaningful advance is exact-retail closure of the camera/frustum reader feeding the light/shadow preparation envelope, with the existing 2295/2295 same-frame substrate treated as protected. No new scheduler, second RenderWorld, or broad replay analyzer is justified by the current evidence.
