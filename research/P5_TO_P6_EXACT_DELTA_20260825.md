# C2VR — exact P5 -> P6 delta proof — 2026-08-25

Purpose: independently verify the causal scope of the current P6 finalist from the exact physical P5 and P6 packages before any new LIVE. This corrects the shorthand phrase "only one source change" into a precise statement: **one causal runtime policy change plus passive host telemetry additions; game-side runtime source is byte-identical.**

## Exact packages

### P5
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
- bytes: `82,867`
- SHA256: `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`
- ZIP CRC: PASS
- package manifest: `39/39 PASS`

### P6
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
- bytes: `85,852`
- SHA256: `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`
- ZIP CRC: PASS
- package manifest: `42/42 PASS`

Both were compared directly from exact Library package bytes, not reconstructed source or chat snippets.

## Package-level delta

P5 contains 40 files total; P6 contains 43 files total.

Across the 40 common relative paths:
- `32` files are byte-identical;
- `8` common files differ;
- `3` P6-only files are added;
- `0` P5 files are removed.

P6-only documentation/preflight files:
- `CROSS_BRANCH_STATE_SYNC_P6.txt`
- `PREFLIGHT_V1726.txt`
- `V1726_README.txt`

Changed common files:
- `src/t1_host_x64.cpp`
- `analysis/static_validate.py`
- `analysis/verify_package.py`
- `STATIC_VALIDATION.txt`
- `INDEPENDENT_VERIFICATION.txt`
- `SELF_VERIFICATION.txt`
- `PACKAGE_MANIFEST.json`
- `PACKAGE_FILES_SHA256.txt`

The last seven are package validation/metadata artifacts reflecting the P6 host change and new telemetry checks. The only changed first-party runtime source file is `src/t1_host_x64.cpp`.

## Game-side runtime identity

The following first-party game/in-process runtime files are byte-identical P5 -> P6:

| File | P5/P6 SHA256 |
|---|---|
| `src/exports.def` | `1CC314940EDE7C74D57252B087F4F34D9397FCAE95A20F711AD88CDF7CAD6F1D` |
| `src/t1_camera.cpp` | `C71E6B52A6F326923A45E682392F79C96C84FFF1E1D66393769A821D9A5C42A1` |
| `src/t1_dual_render.cpp` | `397D0577D3F07B776A17395733AB6500BCD05C8928A51608CE3FDD8DEA415C77` |
| `src/t1_game_api.h` | `642AF56F086EE9EF8E674F495C2B610E9C38088FB0A2342B55CB0F53E2E52E02` |
| `src/t1_ipc.h` | `DE00ABD099F5988BB930A6150FF16BA1A9E9AC1A55AE3EC5CC59DC7DEA54B931` |
| `src/t1_proxy.cpp` | `34097291EEC0C27F54D18ABC91FE34F94EC3CCF86F45C6F2FDA240ACCD570D60` |

Therefore P5 -> P6 does **not** change:
- retail camera/RenderWorld/cull mutation;
- RC33 two-eye game-side transaction;
- per-eye renderer camera/projection code;
- NEAR/right-controller game-side handling;
- shadow policy;
- temporal policy;
- shared-memory ABI/layout;
- x86 proxy shared-texture publication logic;
- keyed-mutex producer side;
- stale-pair publication semantics.

This is exact byte identity, not inferred semantic similarity.

## Only changed runtime source: `src/t1_host_x64.cpp`

P5 SHA256:
`5CB608E35C83C1A06A084F23FA80D22B97A11663D31964DA01AE3E841FFDD14C`

P6 SHA256:
`EE58422BD20093D74F6165F528E38AE88D2BA6A613AAF20BEA8714D73E829E60`

The exact source diff contains two categories.

### A. One causal policy mutation

P5:
```cpp
uint32_t budget=45;
```

P6:
```cpp
uint32_t budget=120;
```

Both call the same existing rendezvous:
```cpp
exact=wait_exact_pair(requested,budget);
```

The wait loop still exits immediately when `consume_exact_pair(requested)` succeeds. Therefore `120 ms` is a fail-closed watchdog ceiling, not a forced 120 ms sleep.

Exact-only submission is preserved. If the requested exact contract is not available by the watchdog, the frame remains a miss rather than relabelling a stale pair.

### B. Passive observability additions

P6 also adds host-side counters/histogram state:
- `g_exactWaitTimeouts`
- `<20 ms`
- `<30 ms`
- `<40 ms`
- `<60 ms`
- `>=60 ms`

It increments the appropriate latency bin when the exact pair arrives and increments the timeout counter when the watchdog expires.

It also exposes these values in status/log output and expands `EXACT_WAIT_POLICY` logging.

These additions are intentionally observational. They do add a few counter increments/branches to the x64 wait/status path, so the scientifically precise statement is **not** "the package differs by only one line". The correct statement is:

> P6 has one causal timing-policy mutation, `45 -> 120 ms`, plus passive host wait telemetry; all game-side runtime code and the rest of the exact-pair architecture are byte-identical to P5.

## Validation changes are expected, not extra runtime mutations

P5 validation checks:
- exact wait 45 ms
- exact-only submit preserved
- wait policy telemetry

P6 validation checks:
- exact wait 120 ms
- exact-only submit preserved
- wait policy telemetry
- new wait histogram

Counts therefore increase:
- static `129/129 -> 130/130`
- independent `97/97 -> 98/98`

This is validation coverage for the new passive telemetry and does not indicate another renderer/game mutation.

## Package manifest self-description

P6's package manifest states:
- parent: `v17.2.5_EXACT_WAIT45_P5`
- causal runtime change: exact-pair watchdog `45ms -> 120ms`
- wait returns immediately on exact pair
- shadow/temporal change: `NONE`

The exact byte comparison independently confirms those substantive claims, with the clarification that passive wait telemetry was also added.

## Scientific interpretation

### What P6 can causally answer
Whether remaining P5 projection-layer misses/flashes are substantially caused by the 45 ms exact-pair watchdog expiring before a slow-but-valid pair reaches host visibility.

### What P6 cannot answer by itself
- HEAD ownership correctness;
- weapon rigid-bind correctness;
- final NEAR visual correctness;
- temporal/shadow release stability;
- whether every remaining flash is a watchdog miss if timeout count collapses while visual flashes remain.

### PASS direction
- exact wait timeouts approach zero;
- exact-pair ratio rises toward 1;
- host submits become continuous;
- flashes/dropouts materially collapse;
- true L/R remains alive and fused;
- no renderer/game baseline regression.

### Branching after result
- **timeouts collapse + flashes collapse**: KEEP exact architecture, STOP increasing watchdog, ADAPT to pipeline lead/timing prediction.
- **timeouts collapse + flashes remain**: STOP watchdog path, inspect Present/publication/timeliness seam.
- **timeouts remain material**: add passive phase timestamps before any further mutation.

## Classification

- exact P5 carrier recovered: **PROVEN**
- P5 manifest integrity `39/39`: **PROVEN**
- exact P6 carrier integrity `42/42`: **PROVEN**
- P5 -> P6 game-side runtime byte identity: **PROVEN**
- one causal runtime policy mutation `45 -> 120 ms`: **PROVEN**
- additional passive host telemetry: **PROVEN**
- P6 LIVE visual/runtime verdict: **UNRUN**

No game launch, OpenXR session, hook, DLL install, or runtime mutation occurred during this comparison.
