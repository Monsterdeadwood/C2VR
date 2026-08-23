# Crysis 2 VR — FALSIFIED / STOPPED PATHS

Do not repeat these without new independent evidence.

- **Rebuild stereo from scratch** — STOP. `CUSTOM_DUAL_T1 v1.0.1` already proves true private L/R retail rendering.
- **Second top-level `RenderWorld` / second `EF_StartEf`** — forbidden. One prepared render-list executes twice.
- **Apply HMD transform at every `Renderer::SetCamera`** — FALSIFIED by cumulative feedback (`G -> G*HMD -> G*HMD^2 ...`).
- **Fake/partial CCamera as authoritative camera object** — unsafe; earlier partial shadow broke native stereo semantics. Use a real full CCamera or a fully verified shadow with exact lifetime/layout.
- **Standalone `RC_SetCamera` mutation as final eye ownership** — rejected because later RT-side state can supersede it.
- **Native Cry SBS / DisplayStereo / CopyToStereo as final VR transport** — rejected.
- **Mono RGB+depth/Z reprojection as final renderer** — visually and architecturally FALSIFIED; v15 late-sink line is not the shipping path.
- **`camera-0x3E8 == CSystem`** — FALSIFIED.
- **GPU constant-buffer hits as gameplay detector** — rejected.
- **Counters alone as visual proof** — rejected.
- **`SHDF_ZPASS_ONLY` as normal RIGHT-eye shadow policy** — rejected because it suppresses normal scene body too.
- **Wholesale v17.2 integration** — STOP. It mixes PosePair, HEAD/culling, weapon/NEAR, temporal and shadow mutations and destroys causal attribution.
- **Treating raw Present as logical game frame** — FALSIFIED by cadence evidence (~18901 Present vs ~1880 RenderWorld vs ~1241 successful producer frames in historical harvest).
- **P3 latest-pair stale submit / stale relabel** — FALSIFIED. It produced live output but `1738` pair-contract/pose mismatches and severe jitter/blur/one-eye asymmetry. Never relabel a stale pair as the current XR contract.
- **Old pixels relabelled with a new pose** — FALSIFIED. If last-good fallback is used later, pixels must keep the pose/FOV they were actually rendered with.
- **One fresh eye + one stale eye** — FALSIFIED as a valid stereo submission policy.
- **Universal `OpenXR +X -> Cry -X` rule as settled global truth** — STOP. Historical `003329` supports it locally, but retail/static and later v10 evidence conflict with that interpretation.
- **Universal `OpenXR +X -> Cry +X` rule as settled global truth** — also STOP until the `003329` conflict is closed. Do not silently promote either sign.
- **Random weapon XYZ/muzzle offset grids before rigid-transform closure** — STOP. They confound pivot, basis and ownership.
- **Head position as weapon rotation pivot** — STOP for final weapon math. Historical v7 object transform rotated around head position and mixes poorly with camera-space `FOB_NEAREST` semantics.
- **Independent position and rotation correction as assumed final weapon SE(3)** — STOP. Current v17-style decomposition is a bug candidate because translation/pivot coupling is missing. Prefer one rigid bind transform.
- **Automatic squeeze/grip-edge rebaseline as default weapon policy** — STOP. It can create discontinuous weapon snaps; next weapon proof must use fixed bind except explicit recenter/equip/rebind.
- **AIM-vs-GRIP pose-family hunt** — STOP unless new evidence appears. AIM is canonical; GRIP is only a low-priority control.
- **Gameplay aim/ballistics work during visual weapon gate** — STOP. Historical servo fallback is preserved, but ballistics remains a later blocker.
- **Broad weapon reverse now** — STOP while PosePair is current gate.
- **Broad HEAD/camera archaeology now** — STOP while PosePair is current gate. HEAD cold finalists are already prepared.
- **Temporal/shadow mutation now** — STOP until PosePair, HEAD and weapon/NEAR visual gates pass serially.
- **New broad symbol/corpus census for weapon functions** — STOP. When weapon gate opens, do a narrow `CryGameCrysis2.pdb/source -> retail` bridge for only `PostUpdateView`, `UpdateFPPosition`, `UpdateFPCharacter` (and ballistic symbols only if later required).
- **Repeating the old broad WAVE3 cadence gate instrumentation before P6** — STOP. P4/P5 already causally isolated exact-pair wait/deadline as a major contributor. Add phase timestamps only if P6 still misses materially.
- **Increasing wait beyond P6 after timeout starvation is closed** — STOP. If P6 drives timeouts near zero, the next timing tool is future-target pipeline lead, not a larger watchdog.

Historical resource `20500` / 320-byte per-view carrier work remains supporting archaeology, not authorization to restart broad GPU/resource searches.

Coordinate-basis conflict provenance is in `research/COORDINATE_BASIS_CONFLICT_20260824.md`.
