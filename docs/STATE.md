# Crysis 2 VR State

## CURRENT GATE — 2026-08-25

`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`

This supersedes PosePair/cadence K as the current gate.

Authoritative read order:
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `docs/GATES.md`
6. `docs/NEXT.md`

Evidence law:
- `RESULT ZIP != LIVE`;
- bare `GREEN` is forbidden;
- package names do not establish acceptance;
- `VACUOUS_PASS` is invalid;
- user headset verdict outranks counters for visual acceptance.

## CURRENT USER VISUAL HARD REDS

### `063149`
Raw result:
`C2VR_RC33_V1721_RESULT_20260825_063149.zip`

Pair transport/submission was alive, but user reported catastrophic camera/world instability with light/shadow state visibly sliding/moving.

Classification:
`VISUAL_RED`.

### T1 PosePair K0
Package:
`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip`

SHA256:
`7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`

User reported it visually even worse.

Classification:
`VISUAL_RED / RESULT_ZIP_NOT_BOUND`.

No K1/K2/HEAD/weapon/temporal/shadow descendants from either red parent.

## CORRECTED P6 STATE

P6 is LIVE, not merely statically verified.

Package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`.

Raw result:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`.

Observed:
- host contracts published;
- exact hits/consumes/submits `0`;
- game RenderWorld/scene activity alive;
- eye pairs queued/completed `0`;
- `NO_LATCHED_RENDER_CONTRACT`;
- 120 ms wait policy present;
- restore/hash PASS.

Classification:
`LIVE_RUNTIME_RED_BEFORE_PAIR_PRODUCTION`.

P5 remains the last working v17.2 wait-lineage ancestor, but visible flashes remained there and v17.2 is not the current visual-parent path.

## FIRST EXACT PHYSICAL RECOVERY ANCHOR

Package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

Size:
`164221 bytes`.

SHA256:
`E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Exact runner:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user-positive property:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

This is the first unchanged reproduction target.
It is not final stereo.

## CAMERA OWNERSHIP REFERENCE

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user-positive property:
head left/right drove the real in-game camera/world; dominant remaining problem was flicker/two-screen stereo.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

Single-source topology reference:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Known policy:
HMD x1 at `Crysis2.exe+0x0057AC76`; downstream SetCamera calls pass through.

## TRUE PRIVATE L/R TECHNICAL AUTHORITY

`CUSTOM_DUAL_T1 v1.0.1`
Canonical result:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`.

Proves:
- real private LEFT/RIGHT retail render execution;
- nonduplicate L/R;
- RC33 transaction mechanics.

Classification:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

Source authority does not equal visual-parent authority.

## HISTORICAL AUDIT PASS 2 CORRECTIONS

### `194212`
Real XR transport, but flat non-world-locked image.
`MECHANICAL_GREEN` only.

### `010051 / 011323`
`NOT_LIVE`; build/preflight failures only.

### v6.1
- A/FUSION quad = 2D compositor control only.
- Z-reprojection `201832` = direct VISUAL RED: blur + weapon counter-motion.

### Z v6.2/v6.3/v6.4
Genuine LIVE; direct user verdicts remain `LIVE_VISUAL_UNBOUND`.

### v7.0.2 `001036`
Genuine source-size transport LIVE; user visual status UNBOUND.

### v10 `034749`
Strong structural/mechanical result, but primary arbiter stopped at `READY_FOR_VISUAL_TEST`. Whole-build visual GREEN is not proven. Later weapon/world improvement attribution is secondary historical summary only.

### v10.2 `020117`
Genuine LIVE; direct user visual verdict unbound.

### v11 CADENCE_FASTPATH
Own arbiter said `REJECT_DO_NOT_CALL_FIXED`; visual verdict unresolved.

### v13 / v13.1
Genuine LIVE; visual verdicts unbound.

### v14
DualWorld v14.0.2/v14.0.3 package/family is VISUAL RED for black headset; exact raw-result timestamp binding remains partly open.

### v15.1 `NO_BINOCULAR`
Game-side dual-scene/eye-axis/FOV mechanics ran, but x64 host had:
`visual_projection_layers=0`
`submitted_frames=0`.

Classification:
`MECHANICAL_GREEN / VISUAL_NOT_TESTED`.

## HISTORICAL SINGLE-WINDOW BEHAVIOR PROFILE

18–19 Aug user oracle records:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- only hand/weapon visibly wrong.

Exact package/hash remains OPEN.

Do not guess it from temporal adjacency and do not invent a mythical old build containing every later independent success.

## CURRENT OPEN ITEMS

Must remain OPEN until direct evidence is recovered:
1. exact package/hash for historical last-good native single-window profile;
2. direct user verdicts for Z v6.2/v6.3/v6.4;
3. direct adjacent primary user message for v10 `034749`;
4. direct user verdict for v7.0.2 `001036`;
5. direct user verdicts for v13/v13.1;
6. exact raw-result binding for v14 black-headset reports;
7. exact package binding inside v11/v12 telescope/binocular family.

## NEXT

First reproduce exact physical v6.0.1 unchanged using its recovered historical runner to re-establish the known world-stability/no-flicker property.

Then treat camera ownership and true private L/R as separate axes:
- A1/single-source for camera;
- T1 v1.0.1 for private L/R.

Only one causal mutation after an unchanged reproduction.

Do not resume cadence K, final HEAD, weapon/NEAR, temporal or shadow work until a visual baseline is explicitly accepted again in headset.

## RETAIL TARGET / ANCHORS

Crysis2.exe:
- SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- direct RenderWorld seam `+0x005E2476`
- `C3DEngine::SetupCamera +0x0057A730`
- once/logical-frame camera lineage `+0x0057AC76`

CryRenderD3D11.dll:
- SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
- `EF_Scene3D +0x00101370`
- `EF_EndEf3D +0x001019A0`
- `RT_RenderScene +0x00107370`
- `ProcessScene +0x00123EA0`
- `Renderer::SetCamera +0x00148340`
- `RC_SetCamera +0x001C38F0`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`
- `RC_RenderScene +0x001C48D0`
- NEAR SetCamera return `+0x000FF456`

## PARKED

Until visual baseline recovery passes:
- cadence K;
- final HEAD composition;
- coordinate-sign LIVE experiments;
- weapon/NEAR integration;
- temporal-history isolation;
- second-eye shadow policy;
- release optimization.
