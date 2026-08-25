# Crysis 2 VR State

## LATEST VISUAL OVERRIDE — 2026-08-25

Current gate:

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

This supersedes the earlier assumption that cadence K/P6 is the immediate next gate.

### Recent USER HARD RED #1
Raw result:
`C2VR_RC33_V1721_RESULT_20260825_063149.zip`

Runtime pair production/submission was alive, but the user reported catastrophic camera/world instability with light/shadow state visibly sliding/moving.

Classification:
`USER_VISUAL_HARD_RED`.

### Recent USER HARD RED #2
Package:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`

The user ran it and reported that it is visually even worse than the previous rejected build.

Classification:
`USER_VISUAL_HARD_RED / RESULT_ZIP_NOT_BOUND`.

No fresh RESULT ZIP is bound to that verdict yet. Do not invent counters.

### Consequence
STOP direct descendants of both rejected visual parents.

Specifically:
- no `K=1` or `K=2` from T1 v1.0.2 PosePair K0;
- no HEAD child from it;
- no WEAPON/NEAR child from it;
- no temporal/shadow child from it;
- do not promote `063149` or T1 v1.0.2 based on counters/static validation.

Permanent precedence and historical evidence:
`docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`.

Newest override:
`docs/LATEST_OVERRIDE_20260825_T1_K0_HARD_RED.md`.

## SOURCE AUTHORITY VS VISUAL AUTHORITY

Technical main renderer source authority remains:
`CUSTOM_DUAL_T1 v1.0.1`.

It proves true private retail LEFT/RIGHT rendering:
- center HMD inject/restore `2296/2296` in its canonical technical result;
- private LEFT `2295`;
- private RIGHT `2295`;
- direct eye copies `2229`;
- OpenXR submits `2624`;
- median sampled L/R MAE `35.9781`;
- FramePairContract desync `0/0`.

But technical true-L/R proof is **not visual-parent acceptance**. The v1.0.2 user HARD RED explicitly prevents using T1 source authority as automatic justification for a cadence descendant.

Likewise v17.2.x remains a selective donor family, not a wholesale visual parent.

## HISTORICAL USER VISUAL FAILURES NOW BOUND TO POLICY

The following old failure classes are permanently frozen in the project memory:

1. **All-SetCamera HMD injection**
   - `171947` showed recursive `G * HMD^n` feedback;
   - eyes collapsed toward equality;
   - never repeat.

2. **Native/NVIDIA monitor stereo as final VR**
   - user explicitly rejected this direction after repeated flashes/flicker;
   - archaeology/control only.

3. **Real Quest IPD/FOV grafted onto native monitor-stereo**
   - `205430`: user reported wrong stereo, flicker, shadows disappearing/changing;
   - saved captures showed per-eye lighting/shadow/near-geometry disagreement;
   - do not reopen as final shortcut.

4. **STABLE_CAMERA v2.2.0**
   - `010329`: simpler single-camera-owner policy still flickered;
   - weapon-in-hand did not establish correct muzzle/ballistics;
   - simplification alone is not a visual fix.

5. **2026-08-22 unbound severe visual RED**
   - recovered user verdict: extreme lateral separation, blur and compressed/bad-looking image;
   - exact package identity not recovered;
   - keep `UNBOUND_VISUAL_RED`; never guess the lineage.

6. **2026-08-25 063149 and T1 PosePair K0**
   - both are now hard visual rejects;
   - no direct descendants.

## RECOVERY CHECKPOINTS / NOT WHOLE-BUILD GOLD

### A1 native repair camera checkpoint
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

User reported that head left/right movement drove the in-game camera/world and described the state as close, with the main remaining issue being flicker/two-screen behavior.

Classification:
`CAMERA_OWNERSHIP_REFERENCE_ONLY`.

### Single-source upstream camera owner
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Policy:
- HMD applied once at `Crysis2.exe+0x0057AC76`;
- downstream SetCamera calls pass through.

Classification:
`HEAD_OWNERSHIP_TOPOLOGY_REFERENCE`, not visual GOLD.

### 191909
Historical lower-divergence orientation/native-stereo control.

Classification:
`LOW_DIVERGENCE_CONTROL_ONLY`.

### 203734 / 204156
Useful 6DoF/IPD/FOV propagation evidence. Subsequent `205430` kills promotion of the surrounding renderer policy.

Classification:
`POSE_MATH_AND_IPC_COMPONENT_REFERENCE_ONLY`.

### 021239
Historical weapon/controller-to-real-fire component donor.

Classification:
`WEAPON_MUZZLE_COMPONENT_DONOR_ONLY`.

### x86 game + x64 OpenXR host
Infrastructure GOLD. Keep this process split.

## NEXT

Before another visual build:

1. recover the exact physical package and exact working runner corresponding to the nearest user-positive/near-normal Crysis camera checkpoint;
2. reproduce it unchanged;
3. bind a fresh raw RESULT and explicit headset verdict;
4. freeze that exact baseline;
5. make one causal visual mutation per child;
6. if the picture becomes catastrophic, STOP and revert immediately.

Do not resume cadence K until all are visually acceptable:
- stationary world;
- slow yaw;
- fast yaw/reversal;
- no camera falling/jumping;
- stable lighting/shadows;
- coherent non-duplicate L/R;
- exact restore/hashes.

Counters alone never establish visual PASS.

## CANONICAL RETAIL TARGETS / OFFSETS

Crysis2.exe:
- `CSystem::GetViewCamera +0x0006AE50`
- `CSystem::m_ViewCamera +0x3F0`
- `CSystem::Render +0x00096A40`
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- direct gameplay RenderWorld call seam `+0x005E2476`
- `C3DEngine::SetupCamera +0x0057A730`
- once/logical-frame main camera SetCamera return `+0x0057AC76`
- downstream landmarks `+0x00A0DD57`, `+0x00A8074B`

CryRenderD3D11.dll:
- `EF_RenderScene +0x00101270`
- `EF_Scene3D +0x00101370`
- `EF_EndEf3D +0x001019A0`
- `RT_RenderScene +0x00107370`
- `PrepareDepthMaps +0x0011D390`
- `ProcessScene +0x00123EA0`
- LEFT SetCamera return `+0x0012412A`
- LEFT EF_Scene3D `+0x0012413C`
- RIGHT SetCamera return `+0x00124304`
- RIGHT EF_Scene3D `+0x0012430F`
- renderer SetCamera vslot `+0xB8`
- `Renderer::SetCamera +0x00148340`
- `RC_SetCamera +0x001C38F0`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`
- `RC_RenderScene +0x001C48D0`
- NEAR owner `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- NEAR restore `+0x000FF4A3`
- near-enriched camera path `+0x0007AEB0`
- late camera CB producer `+0x0006AE2A`
- temporal/previous-matrix anchor `+0x000F95A0`
- `RT_SetCameraInfo` candidate `+0x000FB2E0`
- `mfSetCamera` candidate `+0x0008AF30`

## RENDERER FACTS THAT REMAIN PROVEN

One prepared render-list executes twice:
`SetCamera(L) -> EF_Scene3D -> SetCamera(R) -> EF_Scene3D`.

Do not add a second top-level `RenderWorld` or second `EF_StartEf`.

RT transaction:
`RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Stale pixels must never be relabelled with a newer pose/FOV/XR ticket.

## PARKED QUESTIONS

These are not current LIVE gates:
- pipeline-lead K timing;
- exact `003329` coordinate-sign conflict;
- final HEAD 1:1 composition / VIEW-space center pose;
- weapon fixed-bind SE(3) / upstream entity seam;
- exact retail weapon function mapping;
- temporal-history isolation;
- precise second-eye shadow policy.

They reopen only after a user-accepted visual baseline is recovered.

## IMPORTANT PATHS / IDENTITIES
- Retail: `C:\GOG Games\Crysis 2`, GOG retail `1.9.0.0`, 32-bit DX11
- Beta/source bridge: `C:\GOG Games\Crysis 2\crysis2(5620)_r\crysis2(5620)_01_13`
- Shared tools: `C:\GOG Games\VR Research Tools`
- Architecture infrastructure: x86 game/proxy + x64 OpenXR host

Retail hashes:
- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
