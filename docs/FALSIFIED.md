# Crysis 2 VR — FALSIFIED / STOPPED PATHS

Canonical current sources: `C2VR_STATE_SYNC_20260823.md`, `C2VR_MAIN_INTEGRATOR_BLUEPRINT_20260823.md`.

- **Rebuilding stereo from scratch** — STOP. True private L/R execution is already proven by `CUSTOM_DUAL_T1 v1.0.1`.
- **Second top-level `RenderWorld` / second `EF_StartEf` path** — forbidden for the current build. One prepared render-list executes twice.
- **Applying HMD transform at every `Renderer::SetCamera`** — FALSIFIED by feedback-loop behavior (`G -> G*HMD -> G*HMD^2 -> ...`).
- **Standalone `RC_SetCamera` mutation as final eye ownership** — rejected because later RT-side state can supersede it.
- **Native Cry SBS / DisplayStereo / CopyToStereo as final VR transport** — rejected.
- **Mono RGB+depth/Z reprojection as final renderer** — visually and architecturally FALSIFIED; v15 late-sink lineage is not the shipping path.
- **`camera-0x3E8 == CSystem`** — FALSIFIED.
- **GPU constant-buffer hits as a gameplay detector** — rejected.
- **Counters alone as visual proof** — rejected.
- **`SHDF_ZPASS_ONLY` as a RIGHT-eye shadow policy** — rejected because it suppresses normal scene body as well.
- **Wholesale v17.2 integration** — STOP. It mixes PosePair, HEAD/culling, temporal/shadow and NEAR/weapon changes, destroying causal attribution.
- **New broad scheduler research** — STOP. The current PosePair finalist is an immutable host-owned current-XR-frame ticket.
- **New generic camera hunting** — STOP unless the visual HEAD gate later falsifies the known ownership direction.
- **New weapon reverse before the serial gate reaches WEAPON/NEAR** — STOP; exact NEAR anchors and donor transaction already exist.
- **New temporal reverse before PosePair/HEAD/WEAPON integration is visually accepted** — STOP.

Historical resource `20500` / broad per-view provenance work is retained as supporting archaeology, but it is no longer authorization to leave the working-build ladder.
