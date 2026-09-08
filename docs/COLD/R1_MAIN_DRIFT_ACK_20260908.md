# Crysis2VR / C2VR — R1 MAIN DRIFT ACK 2026-09-08

BRANCH = `cold/r1/copy-sidecar-last-hop`
PINNED_BASE = `82f8c8e29b2b6fb902197cdde4863fa1b26907fb`
CURRENT_MAIN = `622fd866aa7355095762f658145c4315b92f9442`
VERDICT = `MAIN_DRIFT_ACK / CONTROL-PLANE ONLY`

This R1 lane was created from main and then registered in `main/docs/ACTIVE_CLAIMS.md`. The resulting main drift is the control-plane registration of this branch itself; it does not change native `$StereoL/$StereoR`, `CopyToStereo`, `RC_CopyToStereoTex`/`RT_CopyToStereoTex`, `CTexture+0x1C=m_pDevTexture`, the v5.2.0 source/provenance anchor, or either remaining R1 proof gap.

No semantic rebase is required. Keep the branch pinned and consume future main changes only after overlap classification.
