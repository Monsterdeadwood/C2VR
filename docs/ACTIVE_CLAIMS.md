# Crysis2VR / C2VR — ACTIVE CLAIMS REGISTRY

CONTROL_PLANE_ONLY. This file records concurrency/branch ownership only. It is not evidence and cannot promote a claim.

## Active COLD lanes

| ROLE | CLAIM_ID | BRANCH | BASE_MAIN_SHA | PRIMARY FACT | SCOPE |
|---|---|---|---|---|---|
| R2 | UNASSIGNED | `cold/r2/replay-ownership` | `c38a6bf2f9c61a6218ce3594757b0e84cf75973d` | close selective per-eye ownership/history under the one-RenderWorld same-frame replay architecture without reopening a second RenderWorld | COLD_ONLY |
| R3 | UNASSIGNED | `cold/r3/render-graph` | `c38a6bf2f9c61a6218ce3594757b0e84cf75973d` | classify CryEngine renderer domains as PAIR-SHARED, EYE-LOCAL and EYE-HISTORY using exact retail evidence while keeping execution substrate separate | COLD_ONLY |

Global quality/scale control is not silently absorbed into R2 or R3.

## Claim collision law
Before creating a new C2VR research branch, search this registry and existing branches. If the same ROLE + PRIMARY FACT already exists, REUSE/ADAPT/FIX/EXTEND that lane.

## Main drift law
`BASE_MAIN_SHA` pins the accepted world the COLD lane started from.

Before any COLD conclusion is used to authorize LIVE or promotion:
1. compare `BASE_MAIN_SHA..main`;
2. classify changes touching protected transport/quality baseline, same claim, replay substrate, temporal/history ownership or exact target identity;
3. relevant drift => `DRIFT_RECONCILE` before promotion;
4. no blind semantic rebase.

Governance-only/non-overlapping drift may be acknowledged as `MAIN_DRIFT_ACK`.

Once a COLD branch has unique commits, do not automatically move its ref to follow main.
