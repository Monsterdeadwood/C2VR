# Crysis 2 VR — PROVEN

## True two-eye retail renderer
Main parent: `CUSTOM_DUAL_T1 v1.0.1`.

Canonical RESULT: `CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip`
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

**True private L/R execution is PROVEN. Do not rebuild stereo.**

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

## PosePair timing causality
`v17.2.5 WAIT45` is the latest recorded causal timing result:
- before this line: ~`92 exact / 776 miss` (~10.6%)
- WAIT45: `269 exact_pair_consumes`, `269 host_submits`, `53 misses`
- exact ratio `83.5404%`
- `pair_wait_ms_max = 47`
- completed/copies `354/354`
- visual flashes/dropouts remained

Changing only the bounded wait materially increased exact-pair acceptance (~7.9x). Therefore deadline/watchdog timing is a PROVEN contributor to projection-layer misses. This does **not** yet prove timely prediction or final visual stability.

`v17.2.6 EXACT_BLOCK120 P6` is statically verified but **not LIVE-proven**:
- only intended policy delta vs P5: watchdog ceiling `45 ms -> 120 ms`
- game-side camera/FOV/weapon/shadow/temporal/RC33 unchanged
- static `130/130 PASS`
- independent `98/98 PASS`
- package SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`

## Canonical render transaction
- one prepared render-list executes twice
- `RC_RenderScene` packages camera/thread state with the render-list snapshot
- render-item storage survives first eye; logical reset occurs at next top-level `EF_StartEf`
- `RT_RenderScene` contains shadows, HDR/deferred, ordered lists, temporal state and postprocess, not only draws
- RT transaction: `RC_PushRT +0x001C4190 -> eye render -> RC_PopRT +0x001C4200`

## Corrected retail anchors
Crysis2.exe:
- `CSystem::m_ViewCamera = +0x3F0`
- `C3DEngine::RenderWorld = +0x005E2360`
- `RenderInternal = +0x005DEF10`
- direct RenderWorld call seam `+0x005E2476`
- `SetupCamera candidate = +0x0057A730`
- once/frame camera propagation landmark `+0x0057AC76`

CryRenderD3D11.dll:
- NEAR owner region `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- NEAR restore `+0x000FF4A3`
- object-owner landmark `+0x00102100`
- `EF_RenderScene ~ +0x00101270`
- `EF_Scene3D = +0x00101370`
- `EF_EndEf3D = +0x001019A0`
- `RT_RenderScene = +0x00107370`
- `PrepareDepthMaps = +0x0011D390`
- `Renderer::SetCamera = +0x00148340`
- `RC_SetCamera = +0x001C38F0`
- `RC_PushRT = +0x001C4190`
- `RC_PopRT = +0x001C4200`
- `RC_RenderScene = +0x001C48D0`

## Camera / basis facts
- applying HMD transform at every `Renderer::SetCamera` creates cumulative feedback (`G -> G*HMD -> G*HMD^2 ...`)
- real game-owned CCamera + bounded mutation/restore preserved stereo better than fake partial CCamera shadows
- HEAD must be upstream of visibility; eye execution remains downstream
- the global rule `OpenXR +X -> Cry -X` is not valid authority; the primary proper right-handed basis is `(x,y,z) -> (+x,-z,+y)`. Historical `-X` behavior is path-specific evidence, not a universal basis rule
- per-eye LEFT/RIGHT must share one immutable contract identity

## Weapon / NEAR facts preserved for later gate
- `FOB_NEAREST` is a distinct camera-space/near family, not ordinary WORLD depth
- historical run `20260817_010329`: right controller visibly moved weapon/viewmodel; firing still followed monitor/game-center aim; image still flickered
- later historical GOLD `021239`: controller-driven gameplay aim servo + trigger produced user-confirmed firing following weapon/muzzle direction. This is a proven fallback behavior path, not proof of direct ballistic owner
- v10 / `20260818_034749`: synchronizing WORLD/NEAR projection removed the observed weapon counter-motion symptom, proving projection mismatch can masquerade as bad weapon pose
- current controller action family: RIGHT aim pose is canonical; grip is not a separate required pose-family hunt
- fholger donor architecture uses `WeaponWorld = ControllerWorld * InverseGrip`
- equivalent calibration candidate for C2: `G = inverse(C_bind) * W_bind`; then `W_now = C_now * G`
- source-level upstream topology is known: `CPlayer::PostUpdateView -> FPWeaponPos/Angles -> CItem::UpdateFPPosition -> weapon entity SetWorldTM`, followed by `CItem::UpdateFPCharacter` / skeleton preprocessing
- exact retail RVAs for those GameDll functions are not yet proven

## Retail identity
- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`

## Source/runtime trust
Retail Crysis 2 1.9 runtime/binary truth outranks source/SDK, CE lineage, beta/PDB and donor inference. Visual headset PASS outranks counters alone.
