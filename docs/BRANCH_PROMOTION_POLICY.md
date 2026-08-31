# Crysis2VR / C2VR — BRANCH / PROMOTION POLICY

Updated: 2026-08-31.

This policy prevents COLD renderer research from contaminating accepted exact-retail or global quality/scale truth.

## Branch classes

### `main`
Accepted canon only: governance, exact evidence records, `GLOBAL_LOCKED`, `ROLE_PROVEN`, accepted global control state and reconciled historical evidence.

### `cold/<role>/<claim>`
Research-only. Active lanes:
- `cold/r2/replay-ownership`
- `cold/r3/render-graph`

Global quality/scale control, R2 replay and R3 graph remain separate scopes even when they share exact evidence.

### `live/<role>/<claim>/<run>`
Created only after COLD saturation and the exact five-line LIVE preflight. MUST branch fresh from current `main`, never from COLD. Copy only the bounded experiment delta for one PRIMARY FACT.

### `promote/<role>/<claim>`
Created fresh from current `main` after an independently promotable static claim or valid exact-retail RESULT. Contains only the accepted promotion delta.

## Hard no-wholesale-merge law
- NEVER merge `cold/*` into `main` wholesale.
- NEVER merge `live/*` into `main` wholesale.
- Promotion is claim-scoped reconstruction on a fresh `promote/*` branch.
- Valid causal FAIL may promote to FALSIFIED if transport and baseline remained valid.

## Canonical-file write barrier on COLD
COLD branches must not modify as authoritative truth:
- `docs/PROVEN.md`
- `docs/FALSIFIED.md`
- `docs/STATE.md`
- `docs/SYNC.md`
- `docs/NEXT.md`
- `LATEST_SYNC.md`
- protected transport/quality baseline manifests or global claim state.

Proposed authoritative deltas belong as shadow drafts under `docs/COLD/` with `SCOPE=COLD_ONLY`.

## Promotion gate
Record `CLAIM_ID`, ROLE, exact target/build, evidence class, prior/new scope, artifact/source identity, PASS/FAIL, baseline status, contradictions resolved and exact canonical files changed.

Static proof may promote static ABI/layout/control-flow facts. Runtime eye ownership, temporal ownership, visual quality, cadence or causal effect require execution unless the claim itself is strictly static.

## Cross-role law
Global quality/scale, R2 and R3 imports are `BORROWED_EVIDENCE` until independently closed in the receiving scope.

## Read order
1. `docs/EVIDENCE_BOUNDARY.md`
2. `docs/BRANCH_PROMOTION_POLICY.md`
3. `docs/PORTFOLIO_SYNC_20260831.md`
4. assigned ROLE_LOCK/global-control state
5. exact RESULT/source for the active claim
