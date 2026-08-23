# C2VR v17.2.6 EXACT_BLOCK120 P6

**STATUS: CURRENT UNTESTED LIVE FINALIST. DO NOT MODIFY BEFORE ITS FIRST RESULT.**

## Physical package
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

- size: `85,852` bytes
- SHA256: `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`
- original Library carrier verified by direct materialization
- ZIP CRC: PASS
- internal package manifest: **42/42 PASS**

## Parent/result lineage
P5 parent:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`

P5 physical package SHA256:
`D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`

P5 measured result:
- exact consumes `269`
- host submits `269`
- misses `53`
- exact hit ratio `83.5404%`
- stale drains `31`
- last pair wait `31 ms`
- max observed pair wait `47 ms`
- flashes/dropouts remained

## Exact P5 -> P6 runtime-source audit
Among runtime source files, **only `src/t1_host_x64.cpp` changes**.

Unchanged P5 -> P6 runtime source identities:
- `src/t1_camera.cpp` = `C71E6B52A6F326923A45E682392F79C96C84FFF1E1D66393769A821D9A5C42A1`
- `src/t1_dual_render.cpp` = `397D0577D3F07B776A17395733AB6500BCD05C8928A51608CE3FDD8DEA415C77`
- `src/t1_game_api.h` = `642AF56F086EE9EF8E674F495C2B610E9C38088FB0A2342B55CB0F53E2E52E02`
- `src/t1_ipc.h` = `DE00ABD099F5988BB930A6150FF16BA1A9E9AC1A55AE3EC5CC59DC7DEA54B931`
- `src/t1_proxy.cpp` = `34097291EEC0C27F54D18ABC91FE34F94EC3CCF86F45C6F2FDA240ACCD570D60`
- `src/exports.def` = `1CC314940EDE7C74D57252B087F4F34D9397FCAE95A20F711AD88CDF7CAD6F1D`

P5 host:
`5CB608E35C83C1A06A084F23FA80D22B97A11663D31964DA01AE3E841FFDD14C`

P6 host:
`EE58422BD20093D74F6165F528E38AE88D2BA6A613AAF20BEA8714D73E829E60`

The host diff changes the exact-pair watchdog from `45 ms` to `120 ms` and adds passive wait-timeout/histogram telemetry. It does **not** change camera, eye renderer, proxy transport, IPC ABI, weapon, temporal, or shadow source.

## Gate
P6 answers one question only:

> Are the remaining projection-layer flashes/dropouts caused by the 45 ms exact-pair watchdog expiring before slow-but-valid RC33 pairs complete?

Interpretation remains the canonical `docs/SYNC.md` decision:
- near-zero timeouts + flashes gone -> STOP increasing wait; move to pipeline lead `K`
- near-zero timeouts + flashes remain -> STOP timeout path; inspect presentation/publication seam
- many timeouts remain -> passive phase timestamps before any further mutation

Do not add HEAD, weapon, temporal, shadow, coordinate-basis, or publication-owner mutations before the first P6 result.
