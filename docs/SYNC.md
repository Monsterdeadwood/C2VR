# Crysis 2 VR — STATE SYNC

## 🚨 GLOBAL VISUAL OVERRIDE — 2026-08-25

Every C2VR branch must read these before planning a LIVE or choosing a parent:

1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/LATEST_OVERRIDE_20260825_T1_K0_HARD_RED.md`
3. `docs/FALSIFIED.md`
4. `docs/STATE.md`
5. `docs/NEXT.md`

The user's in-headset visual verdict outranks counters/static validation for camera/stereo/playability acceptance.

## CURRENT GATE

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

The old current-gate text `POSEPAIR / cadence K` is superseded.

Do NOT run cadence K, HEAD, weapon/NEAR, temporal or shadow descendants until an exact historical near-normal visual baseline is recovered, reproduced unchanged, and accepted again in headset.

## CURRENT HARD-RED BUILDS

### `063149`
Raw result:
`C2VR_RC33_V1721_RESULT_20260825_063149.zip`

Pair transport was alive, but user visual verdict was catastrophic camera/world instability with light/shadow state visibly moving/sliding.

Classification:
`USER_VISUAL_HARD_RED`.

### T1 PosePair-only K0
Package:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`

User ran it and reported it visually even worse than the prior rejected build.

Classification:
`USER_VISUAL_HARD_RED / RESULT_ZIP_NOT_BOUND`.

Absolute branch rule:
**NO direct K=1/K=2/HEAD/weapon/temporal/shadow descendants from either hard-red parent.**

## HISTORICAL HARD-RED CLASSES IMPORTED INTO GLOBAL SYNC

### All-SetCamera HMD feedback
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_171947.zip`.

Recovered proof:
- eyes collapsed toward equality after intervention;
- 52,170 adjacent camera-pair observations;
- 99.837% next input equalled previous injected output;
- cumulative `G * HMD^n` feedback.

STOP forever: do not apply HMD transform at every Renderer::SetCamera.

### Real Quest IPD/FOV grafted onto native monitor stereo
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260816_205430.zip`.

User reported flicker, wrong stereo and shadows disappearing/changing. Saved L/R captures showed lighting/shadow and near-geometry disagreement.

STOP forever as final VR shortcut.

### STABLE_CAMERA v2.2.0
Known result context:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_010329.zip`.

Even after simplifying camera ownership and disabling several rewrites, user still reported severe image flicker. Weapon motion also did not establish correct firing direction.

STOP: do not treat single-camera simplification + native stereo as sufficient VR.

### Native/NVIDIA monitor-stereo final direction
User explicitly rejected this as a final project direction after repeated flashes/flicker.

STOP: archaeology/control only.

### 2026-08-22 severe unbound visual RED
Recovered verdict: extreme lateral separation, blur and heavily compressed/bad-looking image.

Exact package identity not recovered with sufficient confidence.

Keep as `UNBOUND_VISUAL_RED`; never guess lineage.

## SALVAGE / REFERENCE CHECKPOINTS

These are scoped donors/references, not automatic whole-build GOLD.

### `CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`
User reported real head-driven in-game camera/world motion and described the state as very close; the main remaining problem was flicker/two-screen behavior.

Use as:
`CAMERA_OWNERSHIP_REFERENCE_ONLY`.

### `CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Use as:
`HEAD_OWNERSHIP_TOPOLOGY_REFERENCE`.

Key topology:
HMD x1 at `Crysis2.exe+0x0057AC76`; downstream SetCamera pass-through.

### `191909`
Use as low-divergence orientation/native-stereo control only.

### `203734 / 204156`
Use as 6DoF/IPD/FOV propagation component evidence only. Do not promote surrounding renderer policy because `205430` later failed visually.

### `021239`
Use as weapon/muzzle component donor only.

### x86 game + x64 OpenXR host
Infrastructure GOLD.

### `CUSTOM_DUAL_T1 v1.0.1`
Technical true-private-L/R proof only. Source authority does not equal visual-parent authority.

## PROVEN TECHNICAL FACTS THAT SURVIVE THE VISUAL RESET

- Exact retail target remains GOG Crysis 2 1.9 x86 DX11.
- `Crysis2.exe` SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`.
- `CryRenderD3D11.dll` SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`.
- x86 game/proxy + x64 OpenXR host split remains the infrastructure baseline.
- One prepared render-list may execute LEFT then RIGHT; do not add a second high-level RenderWorld or EF_StartEf.
- `CUSTOM_DUAL_T1 v1.0.1` proves true private retail L/R rendering as a primitive.
- stale pixels must never be relabelled as a new XR pose/FOV/ticket.
- counters alone are not visual proof.
- `FOB_NEAREST` is a separate near/camera-space family.

## RETAIL ANCHORS

Crysis2.exe:
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- direct RenderWorld call seam `+0x005E2476`
- `C3DEngine::SetupCamera +0x0057A730`
- once/logical-frame camera lineage return `+0x0057AC76`

CryRenderD3D11.dll:
- `EF_RenderScene +0x00101270`
- `EF_Scene3D +0x00101370`
- `EF_EndEf3D +0x001019A0`
- `RT_RenderScene +0x00107370`
- `PrepareDepthMaps +0x0011D390`
- `ProcessScene +0x00123EA0`
- LEFT SetCamera return `+0x0012412A`
- RIGHT SetCamera return `+0x00124304`
- `Renderer::SetCamera +0x00148340`
- `RC_SetCamera +0x001C38F0`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`
- `RC_RenderScene +0x001C48D0`
- NEAR SetCamera return `+0x000FF456`

## CROSS-BRANCH RULE

Before any new build/patch/LIVE:

`SYNC -> USER VISUAL LEDGER -> EXACT PARENT -> KNOWN USER VERDICT -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP/ADAPT/STOP`

A branch must not import a visually rejected policy from another branch merely because the donor has newer counters or a newer version number.

If the direct parent is `USER_VISUAL_HARD_RED`, STOP and choose an older accepted/reference checkpoint instead.

## NEXT RECOVERY ACTION

Recover the exact physical package and exact working runner for the nearest user-positive/near-normal Crysis camera checkpoint, starting with the A1 native-repair / single-source camera lineage.

First LIVE after recovery must reproduce that baseline unchanged.

Only after a fresh headset acceptance may one causal renderer mutation be introduced.

## PARKED

Until visual baseline recovery passes:
- cadence K;
- final HEAD composition;
- coordinate-sign LIVE experiments;
- weapon/NEAR integration;
- temporal-history isolation;
- second-eye shadow policy;
- release optimization.

Detailed historical research remains in `research/`, `docs/PROVEN.md`, `research/RESULT_INDEX.md` and archived prior state commits. This sync intentionally changes authorization/gating, not historical evidence.
