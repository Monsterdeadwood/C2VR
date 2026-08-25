# Crysis 2 VR

Native VR integration research for **Crysis 2 retail 1.9 / CryEngine DX11**.

## 🚨 CURRENT STATUS — VISUAL SAFETY OVERRIDE ACTIVE

**ACTIVE — WORKING BUILD FIRST, USER VISUAL VERDICT FIRST.**

The project is **NOT currently in cadence K, HEAD, weapon, temporal or shadow integration**.

Current gate:

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

Two recent descendants are now hard visual rejects:

1. `C2VR_RC33_V1721_RESULT_20260825_063149.zip`
   - pair transport alive;
   - user reported catastrophic camera/world instability and moving/sliding light/shadow state;
   - **USER_VISUAL_HARD_RED**.

2. `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`
   - SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`;
   - user ran it and reported it visually even worse;
   - **USER_VISUAL_HARD_RED / RESULT_ZIP_NOT_BOUND**.

Therefore:
- **DO NOT build K=1/K=2 from that T1 K0 package**;
- **DO NOT promote `063149` or its direct descendants**;
- **DO NOT treat source cleanliness, hashes, counters, or technical L/R proof as visual acceptance**.

The permanent parent-selection authority is:

**`docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`**

A `USER_VISUAL_HARD_RED` package may not be used as a direct visual parent again unless a future exact causal revert/bisect explicitly removes the failed policy and the user re-accepts the resulting baseline in-headset.

## SOURCE AUTHORITY ≠ VISUAL PARENT AUTHORITY

Main renderer source authority remains:
`CUSTOM_DUAL_T1 v1.0.1`.

True private LEFT/RIGHT retail rendering is technically PROVEN. That remains valuable.

But after the v1.0.2 user HARD RED, the T1 source authority **must not be confused with a visually accepted parent**.

Likewise v17.2.x remains a selective donor family, not a wholesale parent.

## HISTORICAL VISUAL GUARDS NOW FROZEN

Recovered Crysis 2 user verdicts permanently stop several repeated mistakes:
- all-`SetCamera` HMD injection caused recursive camera multiplication and eye collapse;
- native/NVIDIA monitor stereo was explicitly rejected as final VR;
- real Quest IPD/XrView FOV grafted onto native monitor stereo produced flicker and L/R light/shadow disagreement;
- `STABLE_CAMERA v2.2.0` still flickered and did not establish correct firing ownership;
- counters alone never override a headset RED.

See:
- `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
- `docs/FALSIFIED.md`
- `docs/LATEST_OVERRIDE_20260825_T1_K0_HARD_RED.md`

## CURRENT RECOVERY ANCHORS

These are **component/reference checkpoints**, not whole-build GOLD unless explicitly stated:

- `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`
  - user reported real head-driven camera/world behavior;
  - remaining problem was flicker/two-screen behavior;
  - useful camera-ownership reference.

- `CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
  - HMD applied once at `Crysis2.exe+0x0057AC76`;
  - all downstream `SetCamera` calls pass through;
  - useful HEAD ownership topology reference, not visual GOLD.

- `191909`
  - historical lower-divergence orientation/native-stereo control;
  - control only, not final VR geometry.

- `203734 / 204156`
  - useful HMD 6DoF/IPD/FOV propagation evidence;
  - renderer policy not accepted because `205430` subsequently failed visually.

- `021239`
  - weapon/muzzle component donor only;
  - do not inherit monitor-stereo as final VR.

- x86 game + x64 OpenXR host split
  - infrastructure GOLD.

- `CUSTOM_DUAL_T1 v1.0.1`
  - true-L/R renderer technical proof only until a user-accepted visual baseline is restored.

## NEXT

Before another visual build:

1. recover the **exact physical package + exact runner** associated with the nearest user-positive/near-normal Crysis camera checkpoint;
2. reproduce that baseline unchanged;
3. bind fresh RESULT + explicit in-headset verdict;
4. freeze it;
5. add **one causal visual mutation per child**.

Do not resume cadence K until stationary world, slow yaw, fast yaw/reversal and light/shadow stability are visually acceptable.

## Start here
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md` — permanent headset-verdict ledger, blacklist, salvage whitelist and parent-selection law
2. `docs/LATEST_OVERRIDE_20260825_T1_K0_HARD_RED.md` — newest state override
3. `docs/FALSIFIED.md` — permanent stopped paths
4. `docs/STATE.md` — detailed project state and current gate
5. `docs/SYNC.md` — canonical cross-branch runtime snapshot and offsets
6. `runtime/main/CUSTOM_DUAL_T1_v1.0.1/README.md` — technical T1 renderer source authority, not automatic visual authority
7. `runtime/donors/v17.2.1/POSEPAIR_TRANSPLANT.md` — selective v17.2.1 donor map and STOP list
8. `research/SOURCE_CORPUS_CURRENT_STATUS_20260825.md` — authoritative source/beta/mod/donor availability overlay
9. `research/SOURCE_CORPUS_REGISTRY.md` — detailed corpus registry
10. `research/RESULT_INDEX.md` — result/build lineage
11. `docs/PROVEN.md` — facts that must not be re-researched
12. `docs/GATES.md` — serial acceptance ladder

Before downloading, rescanning, or calling a beta/mod/donor “new”, check the current-status overlay and corpus registry. Existing exact/local corpora must be re-harvested narrowly when possible instead of duplicated.

## Canonical renderer facts that remain useful

One prepared render-list may execute twice for the two eyes. Do not add a second high-level `RenderWorld` / `EF_StartEf`.

`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`

RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Pixel data and the render pose/FOV/contract metadata that produced it are one atomic publication unit. Stale pixels must never be relabelled as a newer XR contract.

## Working model
`SYNC -> USER VISUAL LEDGER -> THINK -> KEEP/ADAPT/STOP -> ONE CAUSAL MUTATION -> LIVE -> USER VERDICT -> PROVEN/FALSIFIED -> SYNC`

**PARALLELIZE EVIDENCE — SERIALIZE MUTATION.**

## Repository map
- `docs/` — canonical state, user visual acceptance ledger, proven/falsified facts, gates, workflow and policy
- `research/` — evidence indexes, source/beta/mod/donor registry and focused blocker research
- `experiments/` — reproducible causal experiments
- `runtime/` — accepted technical source authorities and selective donors
- `tools/` — deterministic extraction/build/analysis tooling

## Exact retail baseline
- Game path: `C:\GOG Games\Crysis 2`
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)_r\crysis2(5620)_01_13`
- Shared research tools: `C:\GOG Games\VR Research Tools`
- Crysis2.exe SHA256: `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256: `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
