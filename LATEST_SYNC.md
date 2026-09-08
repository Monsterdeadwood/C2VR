# Crysis2VR / C2VR — LATEST SYNC

SYNC_EPOCH = 2026-09-08
BRANCH = `cold/r1/copy-sidecar-last-hop`
ROLE = R1 / NATIVE ENGINE STEREO + RESOURCE EXPORT
STATE = COLD
LIVE = NO
BUILD = NO

Mandatory read order for this branch:
1. `docs/COLD/R1_COPY_SIDECAR_LAST_HOP_SYNC_20260904.md`
2. `docs/EVIDENCE_BOUNDARY.md`
3. `docs/BRANCH_PROMOTION_POLICY.md`
4. exact v5.2.0 source/provenance corpus
5. R2/R3 sibling state only for borrowed facts, never role collapse

Current R1 truth:
- CryEngine/native stereo scheduling remains the execution owner;
- retail `$StereoL/$StereoR`, eye-specific `CopyToStereo`, `RC_CopyToStereoTex` vs `RT_CopyToStereoTex`, and `CTexture+0x1C=m_pDevTexture` are retained;
- exact package anchor: `CRYSIS2VR_CLEAN_EYE_CORE_v5.2.0_RC_OBSERVE_PRESENT_SAFE_COPY_PORTABLE.zip`;
- current gate: `RC_COPY_SIDECAR_TRANSACTION + EXACT_STEREO_RESOURCE_LAST_HOP`;
- unresolved proof gaps are only the exact retail `CDeviceTexture+0x00 -> ID3D11Texture2D*` identity and exact `CopyToStereo -> RT_EndFrame/Present` renderer/immediate-context timeline;
- no temporal snapshot, new scheduler or LIVE/build is authorized by this lane.

COLD material may narrow UNKNOWN/NEXT but may not silently rewrite protected transport/quality/replay baseline, executed PASS/FAIL, FALSIFIED closure or another role's proven claim.
