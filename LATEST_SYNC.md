# Crysis2VR / C2VR — LATEST SYNC

SYNC_EPOCH = 2026-09-08
BRANCH = `cold/r2/replay-ownership`
ROLE = R2
STATE = COLD

Mandatory read order for this branch:
1. `docs/COLD/R2_REPLAY_SYNC_20260904.md` — latest R2 same-frame replay state and `PREP_ENVELOPE_CLOSURE`.
2. `docs/EVIDENCE_BOUNDARY.md` — evidence class, promotion scope and locked-vs-COLD boundary.
3. `docs/BRANCH_PROMOTION_POLICY.md` — branch/promotion rules.
4. `docs/PORTFOLIO_SYNC_20260831.md` — older cross-chat convergence snapshot.
5. The exact source/RESULT corpus supporting the protected replay substrate.

Current R2 truth:
- basic true same-frame LEFT/RIGHT replay is not the blocker;
- protected substrate has 2295/2295 L/R passes, distinct images and private/OpenXR transport;
- current first missing edge is `PREP_ENVELOPE_CLOSURE` around light/shadow preparation ownership;
- water history remains parked as a separate temporal owner;
- R1 CopyToStereo/resource-last-hop work remains a sibling boundary, not merged into R2.

COLD material may narrow UNKNOWN/NEXT but may not silently rewrite protected transport/quality/replay baseline, executed PASS/FAIL, FALSIFIED closure or another role's proven claim.

Do not create a second top-level RenderWorld/EF_StartEf stereo architecture merely because preparation ownership is still open. REUSE the proven same-frame substrate.
