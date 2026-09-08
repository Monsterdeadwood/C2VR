# Crysis2VR / C2VR — R1 CopyToStereo sidecar sync

SYNC_EPOCH = 2026-09-04
ROLE = R1 / NATIVE ENGINE STEREO + RESOURCE EXPORT
BRANCH = `cold/r1/copy-sidecar-last-hop`
STATE = COLD
LIVE = NO
BUILD = NO

## Source/provenance authority
Exact preserved package:
`CRYSIS2VR_CLEAN_EYE_CORE_v5.2.0_RC_OBSERVE_PRESENT_SAFE_COPY_PORTABLE.zip`

Known source SHA prefixes from the preserved package lineage:
- `engine_tap.cpp` = `A8CE07595E547821...`
- `c2vr_host_client.cpp` = `FB0A8892FC612322...`

Do not substitute an unverified later package for this source/provenance anchor.

## PROVEN / RETAIN
1. CryEngine owns native stereo scheduling and per-eye rendering. R1 does not invent a parallel eye scheduler.
2. Retail native eye targets are `$StereoL` and `$StereoR`.
3. `CopyToStereo(channel)` is eye-specific: channel 0/1 maps into the native LEFT/RIGHT stereo target lineage.
4. Command-side and render-thread ownership are distinct:
   - `RC_CopyToStereoTex` is the command/enqueue side;
   - `RT_CopyToStereoTex` is the render-thread execution side.
5. `CTexture + 0x1C = m_pDevTexture` is retail-closed.
6. Present-safe observation/export is the correct synchronization direction. Do not export an eye merely because command-side enqueue happened.
7. R2 separately owns the already-proven same-frame L/R replay substrate. R1 consumes that fact but does not reopen its scheduler.

## PRIMARY GATE
`RC_COPY_SIDECAR_TRANSACTION + EXACT_STEREO_RESOURCE_LAST_HOP`

The intended transaction is:

```text
RC_CopyToStereoTex(channel)
 -> immutable eye/resource publication intent
 -> RT_CopyToStereoTex / stock CopyToStereo
 -> native $StereoL or $StereoR CTexture
 -> exact current CDeviceTexture
 -> exact retail ID3D11Texture2D*
 -> committed pair/render token
 -> RT_EndFrame / Present-safe export
 -> host
```

## STILL UNKNOWN — two exact proof gaps
1. `CDeviceTexture + 0x00 -> current retail ID3D11Texture2D*` last-hop identity.
2. Exact retail timeline/ordering that proves the `CopyToStereo` write and the eventual `RT_EndFrame` / `Present` export occur on the same renderer/immediate-context transaction without relabelling stale pixels.

These are proof gaps, not permission to replace the native stereo path.

## Transaction rule
Pixels plus the exact render/eye identity that produced them must be committed atomically. The branch target is PREPARE -> native WRITE -> VERIFY -> COMMIT. A DIRECT/command-side passthrough without proof of completed native write is non-exportable.

Do not publish a newer pose/FOV/display-time token onto older `$StereoL/$StereoR` pixels.

## FALSIFIED / DO NOT REOPEN
- A new top-level stereo scheduler in R1.
- Treating `RC_CopyToStereoTex` enqueue as proof that GPU/resource contents are ready.
- Export from a guessed `CTexture` field beyond the proven `+0x1C = m_pDevTexture` hop.
- Assuming `CDeviceTexture+0x00` is the retail `ID3D11Texture2D*` without exact target proof.
- Treating a generic Present hook as sufficient without closing same-renderer/immediate-context provenance.
- Temporal snapshot/history work belongs elsewhere; no temporal snapshot is authorized by this lane.

## Sibling boundaries
- R2: same-frame replay, `PREP_ENVELOPE_CLOSURE`, water history parked.
- R3: renderer graph / pair-shared vs eye-local vs eye-history ownership.
- R1: only native eye-resource completion/export transaction and last-hop provenance.

## STOP RULE
Remain COLD. No LIVE/build is justified until the exact last-hop resource identity and Present timeline are closed or a specific contradiction proves one of them cannot be closed statically from the exact retail/source corpus.
