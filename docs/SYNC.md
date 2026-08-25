# Crysis 2 VR — STATE SYNC

## GLOBAL VISUAL OVERRIDE — 2026-08-25

Every C2VR branch must read these before choosing a parent or planning a LIVE:

1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `docs/STATE.md`
6. `docs/NEXT.md`
7. `docs/GATES.md`

User headset verdict outranks counters/static validation for visual/playability acceptance.

Bare `GREEN` is forbidden. Qualify as `MECHANICAL_GREEN`, `COMPONENT_VISUAL_GREEN`, or `FULL_USER_VISUAL_GREEN`.

`RESULT ZIP != LIVE` and `VACUOUS_PASS` is invalid evidence.

## CURRENT GATE

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

Old PosePair/cadence-K current-gate text is superseded.

Do not run cadence K, final HEAD, weapon/NEAR, temporal or shadow descendants until visual baseline recovery succeeds.

## FIRST EXACT REPRODUCTION ANCHOR

Physical package recovered:

`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact inherited runner:

`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

This is the first exact unchanged reproduction target.
It is not final stereo.

## CAMERA OWNERSHIP REFERENCE

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user-positive property:
head motion drove the actual game camera/world; old renderer still had flicker/two-screen behavior.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

Single-source topology reference:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

HMD x1 at `Crysis2.exe+0x0057AC76`; downstream SetCamera pass-through.

## TRUE-L/R TECHNICAL REFERENCE

`CUSTOM_DUAL_T1 v1.0.1 / CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

Classification:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

Do not rebuild stereo and do not confuse source authority with visual-parent authority.

## CURRENT HARD-RED BUILDS

### `063149`
`C2VR_RC33_V1721_RESULT_20260825_063149.zip`

Pair transport alive; user reported catastrophic camera/world instability with moving/sliding light/shadow state.

`VISUAL_RED`.

### T1 PosePair-only K0
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`.

User reported it visually even worse.

`VISUAL_RED / RESULT_ZIP_NOT_BOUND`.

Absolute rule:
NO direct K1/K2/HEAD/weapon/temporal/shadow descendants from either.

## CORRECTED P6 STATUS

P6 is LIVE, not merely statically verified.

Package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`.

Raw result:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`.

It produced:
- host contract publication;
- zero exact hits/consumes/submits;
- zero queued/completed eye pairs;
- game RenderWorld/scene activity alive;
- fault `NO_LATCHED_RENDER_CONTRACT`;
- restore/hash PASS.

Classification:
`LIVE_RUNTIME_RED_BEFORE_PAIR_PRODUCTION`.

Do not state P6 as “not LIVE-proven”.
Do not interpret 120 ms as successful cadence improvement.

## HISTORICAL EVIDENCE CORRECTIONS

### `194212`
Real XR transport proof, but `CameraLock=False`, `CameraInject=False`, `HORIZON_WORLD_LOCK=No`, flat image.

`MECHANICAL_GREEN: transport`, NOT visual GOLD.

### `010051 / 011323`
Both are `NOT_LIVE` preflight/build failures. No visual conclusion.

### v6.1 lines
- A/FUSION_PROOF_QUAD = compositor control only.
- Z-reprojection `201832` = direct user VISUAL RED: blur + weapon counter-motion.

Do not merge these into “v6.1 worked”.

### v7.0.2 `001036`
Genuine technical LIVE, direct user visual verdict unbound.

### v10 `034749`
Strong structural/mechanical result. Primary arbiter says `READY_FOR_VISUAL_TEST`; whole-build visual GREEN is not proven. Later weapon/world improvement attribution is secondary historical summary only.

### v10.2 `020117`
Genuine LIVE, user visual verdict unbound.

### v11 CADENCE_FASTPATH
Local PASS counters exist, but own arbiter says `REJECT_DO_NOT_CALL_FIXED` and visual verdict unresolved.

### v13 / v13.1
Genuine runtime LIVE; user visual verdicts unbound.

### v15.1 `NO_BINOCULAR`
Dual-scene mechanics ran, but host submitted zero visual projection layers. `MECHANICAL_GREEN / VISUAL_NOT_TESTED` only.

## HISTORICAL SINGLE-WINDOW PROFILE

18–19 Aug user oracle records:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- only hand/weapon visibly wrong.

Exact package/hash remains OPEN.

Do not guess it from v7/v10 names and do not back-project later independent wins into it.

## PROVEN TECHNICAL FACTS THAT SURVIVE VISUAL RESET

- exact target remains GOG Crysis 2 1.9 x86 DX11;
- x86 game/proxy + x64 OpenXR host split remains infrastructure baseline;
- one prepared render-list may execute LEFT then RIGHT; no second high-level RenderWorld/EF_StartEf;
- T1 proves private retail L/R renderer mechanics;
- stale pixels must never be relabelled with new pose/FOV/ticket;
- `FOB_NEAREST` is a separate near/camera-space family;
- counters, names and analyzer PASS alone are not visual proof.

## RETAIL ANCHORS

Crysis2.exe:
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- direct RenderWorld seam `+0x005E2476`
- `C3DEngine::SetupCamera +0x0057A730`
- once/logical-frame camera lineage `+0x0057AC76`

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

`SYNC -> AUDIT STATUS -> EXACT PARENT -> KNOWN USER VERDICT -> UNCHANGED REPRO -> ONE MUTATION -> LIVE -> USER VERDICT -> KEEP/ADAPT/STOP`

If a direct parent is `VISUAL_RED`, STOP.
If a historical verdict is `UNBOUND`, do not promote it by inference.

## NEXT RECOVERY ACTION

First reproduce the exact v6.0.1 package unchanged with its recovered runner to restore the known world-stability/no-flicker property.

Then treat A1/single-source as a separate camera-ownership axis and T1 as a separate true-L/R axis.

Continue archival recovery of the old single-window package in parallel, but never guess its identity.

## PARKED

Until visual baseline recovery passes:
- cadence K;
- final HEAD composition;
- coordinate-sign LIVE experiments;
- weapon/NEAR integration;
- temporal-history isolation;
- second-eye shadow policy;
- release optimization.

Retail hashes:
- Crysis2.exe `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
