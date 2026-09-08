# C2VR META Promotion — R1 Registry Provenance Repair

CLAIM_ID: CONTROL-PLANE-ONLY
ROLE: META
TARGET: `docs/ACTIVE_CLAIMS.md`
EVIDENCE_CLASS: CONTROL_PLANE
PRIOR_SCOPE: R1 registry content present on main through a direct push rejected by the main provenance gate
NEW_SCOPE: identical research scope, authoritative registry delivered through required promote/* -> main route

## Accepted delta
Ratify the `C2-R1-COPY-SIDECAR-LAST-HOP` registry entry through the repository's governed promotion path.

No COLD conclusion is promoted. No canonical research claim changes status. No runtime/baseline/source fact changes.

The underlying R1 lane remains:
- branch `cold/r1/copy-sidecar-last-hop`;
- scope `COLD_ONLY`;
- canonical binding `UNBOUND_COLD_LANE`;
- primary fact: exact retail `CDeviceTexture+0x00 -> ID3D11Texture2D*` identity plus the `CopyToStereo -> RT_EndFrame/Present` renderer/immediate-context transaction.

## Why this promotion exists
Commit `622fd866aa7355095762f658145c4315b92f9442` placed the registry entry directly on main. Evidence integrity passed, but the Research Integrity Gate correctly rejected the delivery route because main changes must originate from a merge-time-fresh `promote/*` PR.

This promotion repairs provenance without pretending that the earlier red gate was green and without altering the research meaning of the registry.
