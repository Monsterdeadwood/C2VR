# Crysis 2 VR — EXPERIMENTS

Purpose: compact causal lineage. Preserve what each run proved so later branches do not repeat closed work.

## Main renderer proof — `CUSTOM_DUAL_T1 v1.0.1`
Canonical RESULT:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Key measurements:
- center HMD inject/restore `2296/2296`
- private LEFT passes `2295`
- private RIGHT passes `2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- sampled L/R median MAE `35.9781`
- FramePairContract desync `0/0`
- PosePairContract failed

**Proved:** real non-duplicate private retail LEFT/RIGHT rendering exists. Do not rebuild stereo.

## P3 — latest-pair fallback
Observed:
- pairs completed `1783`
- copies `1782`
- host consumed/submits `1760`
- exact hits only `22`
- misses `2104`
- pair-contract mismatch `1738`
- pose desync `1738`
- severe jitter/blur, one-eye asymmetry and moving/dancing shadow artifacts

**Verdict:** FALSIFIED. Latest stale pair must never be relabelled as the current XR contract.

## P4 — `v17.2.4 EXACT STALE DRAIN`
Policy:
- stale keyed pair is acquired, released and discarded
- never relabel or submit stale pixels

Observed:
- exact pair consumes `92`
- host submits `92`
- misses `776`
- stale drains `386`
- completed/copies `490`
- exact acceptance about `10.6%`
- occasional dark flashes remained

**Proved:** exact-only + stale drain is a valid architecture, but the then-current exact wait/deadline starved most XR frames.

## P5 — `v17.2.5 EXACT WAIT45`
Single causal timing change relative to P4: bounded exact wait raised to `45 ms`.

Observed:
- exact pair consumes `269`
- host submits `269`
- misses `53`
- exact ratio `83.5404%`
- stale drains `31`
- `pair_wait_ms_last = 31`
- `pair_wait_ms_max = 47`
- completed/copies `354/354`
- headset flashes/dropouts still remained
- shadows still ran

**Proved:** timeout/deadline is causally real. Raising only the bounded wait improved exact acceptance about 7.9x over P4. It did not prove final presentation timeliness.

## P6 — `v17.2.6 EXACT_BLOCK120`
Package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

SHA256:
`8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

Single intended runtime delta vs P5:
- exact watchdog ceiling `45 ms -> 120 ms`

No intended change to:
- camera/FOV
- weapon/NEAR
- temporal/shadow policy
- RC33 two-pass renderer
- transport identity semantics

Pre-LIVE validation:
- static `130/130 PASS`
- independent `98/98 PASS`

**Status:** prepared, no recorded LIVE RESULT yet.

See `experiments/NEXT_EXPERIMENT.md` and `docs/NEXT.md`.

## Historical camera experiments
### global SetCamera HMD / v1.0.3
Observed near-perfect feedback chain where later camera input was the previous injected output.

**Verdict:** FALSIFIED. Never apply HMD at every Renderer::SetCamera.

### SINGLE SOURCE / v1.0.4
Applied HMD only at once/frame `Crysis2.exe +0x0057AC76`, but used a fabricated/partial 128-byte camera shadow.

**Verdict:** ownership direction useful, partial CCamera unsafe.

### guarded in-place / v1.0.5 and v1.0.7
Mutated the real game-owned CCamera, called original SetCamera, then restored.

**Proved:** real-object bounded mutation avoids fake-camera corruption; however SetCamera was still too late for visibility/culling ownership.

### RenderWorld center HMD / Stage A
Moved the bounded camera transaction upstream around RenderWorld.

Observed:
- injections/restores `1476/1476`
- HMD rotation reached about `57.92°`
- XR L/R remained non-duplicate

**Interpretation:** strong mechanism evidence for upstream center-camera ownership, but not a retained five-minute visual 1:1 HEAD proof. Parked behind PosePair.

## Historical weapon / NEAR experiments
### `20260817_010329`
User observed right controller moving weapon/viewmodel; firing still followed monitor/game-center aim; image unstable.

**Proved:** controller pose reached visual weapon path. Did not prove ballistics.

### historical `021239` GOLD
Controller-driven gameplay aim servo + trigger gave user-confirmed firing following weapon/muzzle direction.

**Proved:** working gameplay-aim fallback donor exists. Not proof of direct ballistic owner.

### `20260818_034749` v10 projection coherence
Synchronizing WORLD and FOB_NEAREST projection removed the observed weapon counter-motion symptom.

**Proved:** projection mismatch can masquerade as bad weapon/controller pose.

## Historical cadence facts
- raw DXGI Present count is not a logical game-frame count
- historical example: about `18901` Present vs `1880` RenderWorld vs `1241` successful producer frames
- monitor VSync being forced off did not explain the cadence gap
- XR session/frame loop may continue while a projection layer is omitted
- fresh game render and XR submit need not be one-to-one

## Coordinate-basis conflict
Historical `RESULT 20260817_003329` and later retail/v10 evidence disagree about the local-X sign. Neither sign is currently PROVEN globally.

Do not rerun a LIVE for this while PosePair P6 is active. Closure path is COLD-only and documented in:
`research/COORDINATE_BASIS_CONFLICT_20260824.md`.

## METHODS ALREADY USED
- source/SDK/PDB/donor corpus harvest
- RenderDoc/GPU projection and constant-buffer provenance
- Ghidra/source-to-retail mapping
- retail ProcessScene decompile and exact eye callsite closure
- runtime loaded-memory / raw-stack propagation
- x86 proxy + x64 OpenXR host
- keyed mutex shared textures
- immutable frame-contract / exact-pair sequencing
- bounded wait causal tests
- TTD/ReClass for narrow writer/field questions

## DO NOT REPEAT
- broad stereo archaeology
- broad scheduler archaeology before P6
- latest-pair stale relabel
- second high-level RenderWorld/EF_StartEf
- all-SetCamera HMD injection
- mono reprojection as final renderer
- new broad weapon reverse before its serial gate
- new broad temporal/shadow reverse before its serial gate
- new broad coordinate-system hunt; only close the exact `003329` logger/helper conflict when HEAD gate opens
