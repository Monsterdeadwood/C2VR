# C2VR — PosePair packet atomicity and pacing handoff

Date: 2026-08-24
Role: branch STATE SYNC only. No new LIVE performed in this branch.

## Cross-branch position
Remote `main` already advanced beyond this branch's earlier PosePair planning.

Current gate remains:
**POSEPAIR / PROJECTION-LAYER EXACT-PAIR CADENCE GATING.**

Latest imported LIVE:
- `v17.2.5 WAIT45`
- exact consumes `269`
- host submits `269`
- misses `53`
- exact ratio `83.5404%`
- stale drains `31`
- `pair_wait_ms_last=31`
- `pair_wait_ms_max=47`
- completed/copies `354/354`
- headset flashes/dropouts remained

Authorized NEXT remains unchanged:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`.

This note does not replace P6.

## Historical pacing evidence that must not be lost

### v6.0.1 no-flicker root cause
Historical provenance:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.1.0_A_FUSION_PROOF_QUAD_PORTABLE.zip::CRYSIS2VR_BLACKBOX_LAB_BOOTSTRAP_v1.0.0/V601_FLICKER_FUSION_ROOT_CAUSE.txt`

Observed failure in v6.0.0 host:
- after consuming producer keyed-mutex key `1`, the next Quest `xrWaitFrame` could arrive before the next Crysis `Present`;
- host `AcquireSync(1)` then missed;
- host submitted zero composition layers;
- mismatched game/HMD cadence therefore produced periodic blank XR frames by construction.

Historical fix:
- cache the last complete Crysis frame locally;
- refresh only when a new complete producer frame is available;
- otherwise keep a coherent last-good frame alive;
- acceptance counter `empty_layer_after_takeover` must remain `0`.

Important: this is historical pacing evidence, not authorization to bypass current exact identity by relabelling stale pixels.

### v6.0.0 metadata publication race
The same historical root-cause note records a second concrete race:
- keyed mutex key `1` was released before `eye_pair_packet_id` metadata was published;
- XR64 could pair frame `N` pixels with frame `N-1` pose/FOV metadata.

Historical fix:
1. publish packet metadata while producer still owns both mutexes;
2. `MemoryBarrier`;
3. release producer mutexes to key `1`;
4. host reads packet ID only after acquiring both key `1` mutexes.

Project law preserved from this result:
**pixels and their render metadata form one atomic publication unit.**

## Historical reuse telemetry
Provenance:
`CRYSIS2VR_CADENCE_FASTPATH_RESULT_20260818_133603.zip` / v11 cadence fastpath.

Measured:
- target refresh `72.000 Hz`
- active submit `59.700 Hz`
- cadence ratio `0.829`
- fresh packed frames `1276`
- reused packed frames `379`
- game mutex misses `1320`
- packed pose age avg `38.8874 ms`
- packed pose age max `138.8912 ms`
- submits `1655`

The v11 note explicitly states v10 already reused the last private packed frame when a new game texture was unavailable.

Interpretation:
- reuse itself is not synonymous with pair/pose desynchronization;
- age/reuse streak and pixel-metadata identity must be measured separately;
- the old age maxima are not a release target and do not prove modern visual acceptability.

## Relation to current exact-PosePair line
Current exact-contract policy and historical last-good policy solve different failure classes:

- exact current ticket prevents stale relabel / mixed pose;
- packet atomicity prevents `N pixels + N-1 metadata`;
- pacing fallback can prevent ordinary producer-cadence misses from becoming visible blank frames, but only if the complete pair keeps the pose/FOV that actually rendered it.

Therefore the valid reserve policy is:
`complete cached L/R pixels + their original render pose/FOV/contract identity`.

Invalid policies remain:
- old pixels + current/new pose;
- one fresh eye + one stale eye;
- stale pair relabelled as current XR ticket.

## Why P6 still runs first
P5 causally proved wait/deadline starvation is a major contributor by improving exact acceptance from about `10.6%` to `83.5404%` with a single bounded-wait change.

P6 changes only `45 ms -> 120 ms` and is already built/verified. It must remain the next mutation so causal attribution is preserved.

Post-P6 decision:
- timeouts near zero + flashes gone: STOP timeout growth; KEEP exact identity; move to pipeline lead.
- timeouts near zero + flashes remain: STOP timeout path; inspect presentation/timeliness and publication ownership.
- many timeouts remain: add passive phase timestamps before any new mutation.
- coherent last-good complete-pair fallback remains a reserve policy only, not a pre-P6 replacement.

## HEAD implication from this branch
`CUSTOM_DUAL_T1 v1.0.1` already has an upstream center-HMD owner:
- center HMD inject/restore `2296/2296`
- union cull `2296/2296`
- direct call seam `Crysis2.exe +0x005E2476 -> RenderInternal +0x005DEF10`

Historical source-guided notes establish why this seam was chosen: HMD center mutation lives for the full RenderWorld/RenderInternal call and occurs earlier than `Renderer::SetCamera`, so visibility/culling and downstream copies can see one coherent center camera.

Therefore after PosePair closes, the first HEAD task should be:
**visual validation/convergence of the existing T1 upstream center-HMD owner before starting new broad HEAD reverse.**

Do not treat this as HEAD visual PASS yet. T1 counters prove execution, not 1:1 headset quality.

## Coordinate-basis conflict
This branch does not resolve the existing local-X conflict. Preserve both evidence paths in `research/COORDINATE_BASIS_CONFLICT_20260824.md` and do not promote either sign while PosePair is current gate.

## METHOD ALREADY USED in this line
- historical keyed-mutex producer/consumer pacing experiments
- packet metadata/pixel publication ordering
- last-good frame reuse
- v10/v11 cadence telemetry and pose-age measurement
- T1 center-HMD RenderWorld call-seam execution
- current P4/P5 exact wait experiments from concurrent branch

## STOP / do not repeat
- no new broad cadence analyzer before P6
- no forced zero-layer-as-release-policy claim based only on mechanism
- no stale relabel
- no second RenderWorld / second EF_StartEf
- no all-Renderer::SetCamera HMD injection
- no new HEAD mutation before current gate closes

## Unresolved
1. P6 visual and exact/miss verdict.
2. If P6 closes timeout starvation, whether timely prediction requires pipeline lead `K`.
3. If exact identity is high but flashes persist, whether presentation ownership/timeliness or last-good continuity is the remaining blocker.
4. Release-safe bounds for cached-pair age/reuse streak if the reserve fallback is needed.
5. HEAD 1:1 visual verdict using the already-existing T1 upstream center owner.
