# Crysis2VR / C2VR — LATEST SYNC

Mandatory read order for any new or resumed chat/role:
1. `docs/EVIDENCE_BOUNDARY.md` — evidence class, promotion scope and locked-vs-COLD boundary.
2. `docs/BRANCH_PROMOTION_POLICY.md` — choose `main`, `cold/*`, `live/*` or `promote/*` before writing.
3. `docs/ACTIVE_CLAIMS.md` — reuse the existing role/claim branch and inspect its pinned `BASE_MAIN_SHA`; do not duplicate research.
4. `docs/PORTFOLIO_SYNC_20260831.md` — cross-chat convergence view.
5. The assigned role's exact `STATE/NEXT/EVIDENCE/RESULT` lineage or global-control state.
6. The exact source/RESULT corpus for the active CLAIM_ID.

For any generic continuation prompt, resolve current status/owner first: `ACTIVE` -> own FIRST_MISSING_EDGE only; `PENDING` -> ingest/validate; `HOLD/BLOCKED` -> blocker only; `CLOSED/PROVEN/FALSIFIED/SUPERSEDED/DO_NOT_REPEAT` -> STOP that PRIMARY_FACT; `UNBOUND` -> COLD only; conflict -> adjudicate before mutation. Generic continuation never authorizes sibling-claim takeover or LIVE/build by itself.

COLD material may narrow UNKNOWN/NEXT but may not silently rewrite protected transport/quality/replay baseline, executed PASS/FAIL, FALSIFIED closure or another role's proven claim.

COLD and LIVE branches are never wholesale-merged into `main`; accepted facts return only through a fresh claim-scoped `promote/*` branch.

Before LIVE/promotion, compare the COLD branch's pinned `BASE_MAIN_SHA` to current `main`; relevant drift requires reconciliation, not blind rebasing.

Do not collapse global quality/scale control, R2 replay and R3 renderer-graph into one state.
