# Crysis 2 VR — PROVEN

## EVIDENCE LANGUAGE

This file records proven facts, not whole-build visual acceptance unless explicitly stated.

Use:
- `MECHANICAL_GREEN` — mechanism proven;
- `COMPONENT_VISUAL_GREEN` — one user-visible property accepted;
- `FULL_USER_VISUAL_GREEN` — complete visual parent accepted;
- `VISUAL_RED` — user rejected headset result;
- `LIVE_VISUAL_UNBOUND` — runtime executed but direct visual verdict is not bound;
- `NOT_LIVE` — target runtime experiment did not execute.

A PASS with missing prerequisites is `VACUOUS_PASS_INVALID`.

See `docs/HISTORICAL_AUDIT_PASS2_20260825.md`.

---

# TRUE TWO-EYE RETAIL RENDERER PRIMITIVE

Main technical source authority:
`CUSTOM_DUAL_T1 v1.0.1`.

Canonical RESULT:
`CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`

- bytes `68,872,488`
- SHA256 `986A1B8FBFB32908E1D11580D90005A72851FEDAe1EDDB3596144D341CD53367`
- center HMD inject/restore `2296/2296`
- private LEFT `2295`
- private RIGHT `2295`
- direct eye copies `2229`
- OpenXR submits `2624`
- sampled L/R median MAE `35.9781`
- FramePairContract desync `0/0`
- PosePairContract acceptance failed

Classification:
`MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`.

**True private L/R retail execution is proven. Do not rebuild stereo from scratch.**

This is not automatic visual-parent authority after later user HARD RED descendants.

## Exact parent source authority

`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`

- bytes `83,442`
- SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`
- manifest `20/20 PASS`

Exact source identities:
- `t1_camera.cpp` `03D87C773DEA4FBA9D9C4828DCCB8BC50AD518E12B4E490B8C624CC26509F8BE`
- `t1_dual_render.cpp` `64F3B8FC3DEBB9976894DD1494406E4166B626BAF6B9AEB2F3D2CF846900C9F2`
- `t1_host_x64.cpp` `C88F9147D5C204B2D6E4C39FC271A34FDD5C3F9664431A2059306AE7C2468819`
- `t1_ipc.h` `4C98391543122FE9B3A9FFBBDAE76415568D51F7186D61DF1955A7BECBD2C90A`
- `t1_proxy.cpp` `4505003BE7574E0DFE7766FED603F41C7BC98FF882ED50E996A735A42C7F05CD`

Canonical binaries:
- x64 host `2F79B1D4C2233444E75BC895929FABEF41EF44734854E8448D158D151A87B028`
- x86 proxy `A11FC3E91669FBD472013E4882CEE721F09CB0A9C25FBD981AF222E87F92B279`

Repository authority:
- `runtime/main/CUSTOM_DUAL_T1_v1.0.1/`
- `tools/extract_verified_custom_dual_t1_v1_0_1.py`

---

# EXACT PHYSICAL WORLD-STABILITY CHECKPOINT

Recovered physical package:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`

- bytes `164221`
- SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`

Exact runner lineage:

`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Historical user-visible result:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`
`BINOCULAR_FUSION = FAIL`.

This is the strongest exact physical reproduction anchor currently recovered for world stability.

---

# CAMERA OWNERSHIP REFERENCE

`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

Historical user observation:
- head left/right drove the real in-game camera/world;
- the remaining dominant failure was flicker/two-screen behavior;
- state was described as close.

Classification:
`COMPONENT_VISUAL_GREEN: CAMERA_OWNERSHIP_REFERENCE`.

Related single-source topology reference:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_SINGLE_SOURCE_v1.0.4_OVERWRITE_LAB.zip`
SHA256 `6885E24A050A182E11996DE3CA6E9D6705FB2E8F09E3623CACF27E684A7C7385`.

Known topology:
HMD applied once at `Crysis2.exe+0x0057AC76`; downstream SetCamera calls pass through.

Do not inherit the surrounding native/NVIDIA final stereo.

---

# POSEPAIR / DEADLINE TIMING CAUSALITY

P4 exact-stale-drain baseline:
- `92` exact consumes
- `776` misses
- `386` stale drains
- exact ratio about `10.6%`

P5 `v17.2.5 WAIT45`:
- `269 exact_pair_consumes`
- `269 host_submits`
- `53 misses`
- exact ratio `83.5404%`
- `31` stale drains
- `pair_wait_ms_last=31`
- `pair_wait_ms_max=47`
- completed/copies `354/354`
- visible flashes/dropouts remained

Changing the bounded wait from the earlier P4 policy to the P5 WAIT45 policy materially increased exact-pair acceptance. Therefore deadline/watchdog timing is a **proven contributor** to projection-layer misses in that lineage.

This does not prove final visual stability or make cadence the current gate.

## Corrected P6 LIVE status

P6:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`

SHA256:
`8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`.

P6 is **not merely static**. It was executed.

Raw result:
`C2VR_RC33_V1721_RESULT_20260825_012454.zip`.

Observed:
- host published contracts through about `1533`;
- exact hits `0`;
- misses about `1409`;
- consumes/submits `0`;
- game `renderworld_calls≈900`;
- `scene_packets≈899`;
- pairs queued/completed/L/R `0`;
- fault `NO_LATCHED_RENDER_CONTRACT`;
- 120 ms wait policy was present;
- restore/hash checks passed.

Classification:
`LIVE_RUNTIME_RED_BEFORE_PAIR_PRODUCTION`.

Therefore:
- P6 does not prove a better cadence policy;
- increasing watchdog from 45 ms to 120 ms did not preserve the working P5 runtime path;
- P6 is not a canonical visual parent.

A later noncanonical latch-grace experiment proved pair production could be restored, but that run was then USER VISUAL HARD RED. It does not authorize returning to cadence K as current work.

---

# FRAME / PRESENTATION FACTS

- raw DXGI Present count is not logical game-frame count;
- `xrEndFrame` count is not equivalent to visible projection-layer submission count; `layerCount=0` may occur while XR remains active;
- game-side completed pair is not cross-process visible until publication/copy gate;
- a fresh game render is not fundamentally required for every XR submit, but cached pixels must retain the exact pose/FOV/metadata that rendered them;
- old pixels relabelled with a newer pose are forbidden;
- one fresh eye plus one stale eye is invalid;
- `RESULT ZIP` existence is not proof that the runtime experiment executed;
- analyzer PASS with absent prerequisites is invalid.

---

# HISTORICAL PACKET ATOMICITY AND CONTINUITY

Historical v6.0.0/v6.0.1 material proved a concrete publication race and cadence failure mode:
- releasing producer key `1` before publishing `eye_pair_packet_id` could pair frame N pixels with frame N-1 pose/FOV;
- fix: publish metadata while both producer mutexes are still owned, then MemoryBarrier, then release key `1`;
- host reads metadata only after acquiring both key `1` mutexes;
- Quest `xrWaitFrame` arriving before next Crysis Present plus zero projection layers created periodic blank XR frames;
- v6.0.1 cached/reused the last complete frame to remove that flicker.

Project law:
**complete L/R pixels and their render pose/FOV/contract metadata are one atomic publication unit.**

This does not authorize stale relabel.

Historical v11 cadence telemetry (`CRYSIS2VR_CADENCE_FASTPATH_RESULT_20260818_133603.zip`) measured real reuse, but its own arbiter said `STRUCTURAL_ARBITER=REJECT_DO_NOT_CALL_FIXED` and `VISUAL_ARBITER=UNRESOLVED_UNTIL_USER_HEADSET_TEST`.

Therefore v11 cadence is component evidence, not visual GREEN.

---

# CANONICAL RENDER TRANSACTION

Proven mechanical facts:
- one prepared render-list may execute twice;
- `RC_RenderScene` packages camera/thread state with the render-list snapshot;
- render-item storage survives first eye; logical reset occurs at next top-level `EF_StartEf`;
- `RT_RenderScene` contains shadows, HDR/deferred, ordered lists, temporal state and postprocess, not only draws;
- RT transaction: `RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`.

Canonical per-eye mechanical sequence:
`SetCamera(EYE) -> fill-side camera/view/projection/CameraZero -> RC_SetCamera 0x36 -> EF_Scene3D -> RC_RenderScene 0x33 -> render-thread eRC_SetCamera(EYE) -> eRC_RenderScene(TI_EYE, same RLD)`.

Do not infer visual acceptance from this topology alone.

---

# RENDER-THREAD SThreadInfo OVERWRITE LINEAGE

Public CryEngine lineage `MergHQ/CRYENGINE` commit `8b63f61c6bb186fbee254b793775856468df47c5` corroborates an already retail-observed ownership mechanism.

`SRenderThread::RC_RenderScene` transports a full `SThreadInfo` into the render command; RT processing reconstructs that state and `FX_ApplyThreadState` replaces process-thread render state.

`SThreadInfo` includes camera/view/projection state including:
- `m_matView`;
- `m_matProj`;
- `CCamera m_cam`;
- `CRenderCamera m_rcam`.

Implication:
standalone `RC_SetCamera` mutation can be superseded by the authoritative cmd33 `SThreadInfo` snapshot.

Trust boundary:
source lineage semantics do not replace retail offsets/layout proof.

---

# CORRECTED RETAIL ANCHORS

Crysis2.exe:
- `CSystem::GetViewCamera +0x0006AE50`
- `CSystem::m_ViewCamera +0x3F0`
- `CSystem::Render +0x00096A40`
- `C3DEngine::RenderWorld +0x005E2360`
- `RenderInternal +0x005DEF10`
- direct RenderWorld call seam `+0x005E2476`
- `C3DEngine::SetupCamera +0x0057A730`
- once/logical-frame camera propagation landmark `+0x0057AC76`

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
- SetCamera vslot `+0xB8`
- `Renderer::SetCamera +0x00148340`
- `RC_SetCamera +0x001C38F0`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`
- `RC_RenderScene +0x001C48D0`
- NEAR owner region `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- NEAR restore `+0x000FF4A3`
- near-enriched shader-camera path `+0x0007AEB0`
- late camera CB producer `+0x0006AE2A`
- temporal/previous-matrix anchor `+0x000F95A0`
- `RT_SetCameraInfo` candidate `+0x000FB2E0`
- `mfSetCamera` candidate `+0x0008AF30`

---

# CAMERA OWNERSHIP FACTS

- applying HMD at every `Renderer::SetCamera` creates cumulative feedback (`G -> G*HMD -> G*HMD^2...`);
- real game-owned CCamera + bounded mutation/restore preserved behavior better than fake partial shadows;
- HEAD belongs upstream of visibility/list selection;
- EYES belong downstream in the per-eye transaction;
- LEFT/RIGHT must share one immutable render-contract identity.

Current work must first recover a user-acceptable visual baseline before reopening final HEAD composition.

---

# COORDINATE BASIS — CONFLICT, NOT PROVEN

Do not cite either `XR +X -> Cry +X` or `XR +X -> Cry -X` as a closed global fact.

Historical `003329` and later retail/static/source-lineage evidence conflict.

Possible causes include:
- old stock-eye label reversal;
- row/column/basis interpretation error;
- later compensation elsewhere.

Resolve from exact writer/classifier or retail eye-transform helper only after visual baseline recovery.

See `research/COORDINATE_BASIS_CONFLICT_20260824.md`.

---

# WEAPON / NEAR FACTS PRESERVED FOR LATER

- `FOB_NEAREST` is a distinct camera-space/near family;
- `010329`: controller moved viewmodel, firing still followed monitor/game-center aim, image still flickered;
- `021239 / A1_HISTORY_FIX_175934`: controller-directed firing along weapon direction is a proven component donor, not proof of a good renderer;
- v10 `034749`: WorldCenter/Union/FOBNearest projection mechanics are structurally proven, but the user-visible counter-motion improvement is currently supported by a **secondary historical user-verdict summary**, not a recovered direct adjacent primary message;
- therefore do not state `034749` as whole-build visual GOLD or as primary-bound proof;
- RIGHT aim pose remains canonical; grip is not a required pose-family hunt;
- future rigid candidate remains `GripBind = inverse(C_bind) * W_bind`; `W_now = C_now * GripBind`;
- source-level upstream topology `CPlayer::PostUpdateView -> FPWeaponPos/Angles -> CItem::UpdateFPPosition -> weapon entity SetWorldTM` remains useful;
- exact retail RVAs for those GameDll functions are not yet proven.

---

# POSEPAIR PUBLICATION TOPOLOGY — SOURCE-PROVEN, NOT CURRENT VISUAL GATE

Verified donor source shows:
- matching LEFT/RIGHT serial required before publishing completed contract/serial;
- `publish_pair()` copies persistent eye RTs to keyed-mutex shared textures;
- `hkPresent()` calls `publish_pair()`;
- source has no explicit canonical-primary-swapchain or canonical-render-thread-ID guard around pair publication.

These are source facts, not proof of a retail wrong-thread race.

Do not add GPU fences or eye-RT rings without direct evidence.

See `research/POSEPAIR_PUBLICATION_OWNERSHIP_20260824.md`.

---

# EXISTING UPSTREAM HEAD MECHANISM IN T1

T1 mechanically executed an upstream center-HMD path:
- center HMD inject/restore `2296/2296`;
- union cull `2296/2296`;
- direct gameplay RenderWorld seam `Crysis2.exe+0x005E2476 -> RenderInternal+0x005DEF10`.

This proves mechanism execution only.

**HEAD visual 1:1 is not proven.**

Final HEAD work is parked until visual baseline recovery succeeds. Do not use “PosePair closes next” as current authorization.

---

# HISTORICAL SINGLE-WINDOW PROFILE

19-Aug user oracle records a useful behavior profile:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- headset image present;
- hand/weapon still wrong.

Exact physical package/hash remains OPEN.

Do not guess it and do not invent an old mythical build containing every later independent success.

---

# RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

Retail 1.9 runtime/binary truth outranks source/SDK/beta/donor inference.
For visual/playability claims, explicit headset acceptance outranks counters and technical topology.
