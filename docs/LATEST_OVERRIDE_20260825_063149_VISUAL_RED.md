# C2VR latest override — 2026-08-25 063149 visual RED

## Precedence
This file supersedes older NEXT/STATE text where it conflicts.

## Raw executed result
`C2VR_RC33_V1721_RESULT_20260825_063149.zip`

The latch/recovery edge is CLOSED at runtime:
- LEFT/RIGHT RC33 executed `74/74`;
- completed pair path is alive;
- host exact accepts/submits are nonzero;
- deterministic L/R capture is non-duplicate;
- restore passed.

Therefore STOP contract-latch research.

## Visual verdict
`USER_VISUAL_VERDICT = HARD RED`.

User reports catastrophic camera/world instability with light/shadow state visibly sliding/moving. Counter-only PASS on temporal/shadow bookkeeping does not override this visual failure.

The executed v17.2.x-derived child is NOT a valid clean MASTER3 K=0 cadence sample because it also carries later-gate renderer policies. Do not promote it to canonical parent.

## Source authority correction
MAIN source authority remains:
`CUSTOM_DUAL_T1 v1.0.1`

Exact physical carrier recovered:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`
SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`

Canonical result:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`
SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAE1EDDB3596144D341CD53367`

Per `runtime/donors/v17.2.1/POSEPAIR_TRANSPLANT.md`, v17.2.x is a selective PosePair donor only. Do NOT import its RIGHT Touch/NEAR, donor temporal-history ownership, donor RIGHT-only shadow policy, or other later-gate mutations into the transport child.

## Prepared next child
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`
SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`

Classification: `PREPARED / UNRUN`.

BASE_PACKAGE = `CUSTOM_DUAL_T1 v1.0.1 HOSTFIX`
BASE_SCRIPT = inherited T1 BAT -> `tools/Run-T1.ps1`
KNOWN_GOOD_RESULT = canonical T1 RESULT above
ONLY DELTA = immutable PosePair rendezvous and versioned cross-x86/x64 contract ABI
WATCHDOG = fixed 45 ms
K = 0 clean control

Launcher/build/restore/logging/packaging are inherited byte-for-byte.

The child preserves original T1 stock-center temporal/shadow ownership and does not transplant donor RIGHT Touch/NEAR, donor rightHistory/pairBase temporal policy, or donor RIGHT-only shadow policy.

## Decision tree after this LIVE
1. If camera/light/shadow catastrophic motion disappears but exact ratio is below `0.98`: KEEP clean T1 parent and next child changes only pipeline lead `K=1`.
2. If catastrophic camera/world motion remains even on this clean T1 parent: STOP cadence mutation. Next LIVE is a separate HEAD isolation/control child from this same lineage; do not simultaneously change temporal/shadow/weapon.
3. If exact ratio >= `0.98` and visual transport is stable for 3 minutes with non-duplicate L/R, restore/hash PASS: transport PASS, then unlock HEAD.

HEAD, WEAPON/NEAR and TEMPORAL/SHADOW remain serial gates. Counters alone never establish visual PASS.
