# C2VR — Public CryENGINE lineage enrichment — 2026-08-24

Purpose: preserve high-value public CryENGINE documentation and Crytek presentation evidence that can reduce future C2VR reverse-engineering work. This is lineage/candidate evidence only unless independently closed against retail Crysis 2.

## Evidence rule
- Public CryENGINE 3 documentation is stronger than generic donor intuition, but it is not automatically retail Crysis 2 proof.
- Later CRYENGINE VR documentation is architectural lineage evidence, not proof that the 2011 retail binary contains the same implementation.
- Do not replace current retail offsets/causal results with these documents. Use them to choose and interpret narrow retail experiments.

## 1. CCamera coordinate and Matrix34 semantics
Official CryENGINE 3 CCamera documentation states:
- CryENGINE uses a right-handed coordinate system;
- +X points right;
- +Y points away from the viewer / forward;
- +Z points up;
- camera 6DoF is stored in a Matrix34;
- the 3x3 portion stores orientation;
- the translation vector stores position;
- GetMatrix/SetMatrix are the intended 6DoF accessors;
- the renderer performs API-space conversion.

Source:
https://www.cryengine.com/docs/static/engines/cryengine-3/categories/17399809/pages/17074542

### C2VR impact
This is important COLD evidence for the open OpenXR<->Cry local-X conflict. It supports interpreting native Cry camera local +X as camera-right and makes a silent "global reflected X" rule less plausible unless the historical logger/classifier or a later conversion stage introduced the reflection.

It does NOT by itself resolve RESULT 20260817_003329. The exact historical writer/classifier and retail eye-transform helper still outrank this lineage documentation.

## 2. Native CryENGINE 3 stereo model
Official CryENGINE stereo documentation describes two modes:
- Dual Rendering: render the scene twice for LEFT/RIGHT using an asymmetric/off-center frustum. Preferred for PC / quality.
- Post Stereo / SSRS: synthesize the second eye from depth.

Source:
https://www.cryengine.com/docs/static/engines/cryengine-5/categories/23756816/pages/44959253

Relevant CVars include r_StereoMode, r_StereoOutput, r_StereoDevice and r_StereoEyeDist.

### C2VR impact
This independently supports the architecture already proven by retail work:
- true two-pass rendering is a native CryENGINE design, not an alien graft;
- per-eye asymmetry belongs in the camera/frustum contract;
- mono depth reprojection is a distinct lower-quality path and should remain FALSIFIED as the final C2VR renderer.

Do not revive native SBS transport as the final OpenXR transport. Use this only as eye/camera lineage evidence.

## 3. Renderer camera ownership
Official IRenderer documentation exposes:
- IRenderer::SetCamera(const CCamera&);
- IRenderer::GetIStereoRenderer();
- IRenderer::IsStereoEnabled();
- stereo-aware 2D placement through stereoDepth.

Source:
https://www.cryengine.com/docs/static/engines/cryengine-3/categories/17399809/pages/17074926

### C2VR impact
This strengthens the interpretation that SetCamera is a central renderer contract, but does not override the retail finding that mutating every SetCamera causes feedback/corruption. The useful conclusion is ownership hierarchy, not authorization for a global hook.

## 4. RenderWorld culling camera semantics
CryENGINE 3 API documentation for I3DEngine::GetRenderingCamera says that during RenderWorld this is the camera that should be used for all engine-side culling. It also exposes GetRenderingPassCamera and SRenderingPassInfo camera-bearing constructors.

Source:
https://www.cryengine.com/docs/static/engines/cryengine-3/categories/17399809/pages/17075356

### C2VR impact
This is high-value lineage evidence for the parked HEAD gate:
- visibility/culling wants a coherent upstream rendering camera;
- the existing T1 RenderWorld-seam center-HMD owner and union cull are directionally aligned with engine design;
- final HEAD work should converge the upstream center camera before inventing another late renderer-only owner.

Retail T1 evidence remains the authority.

## 5. Later CryENGINE VR late-stage camera injection
Later official CRYENGINE camera documentation explicitly describes late-stage / asynchronous HMD camera injection to reduce tracking-to-render latency. IHmdDevice::IAsyncCameraCallback is called from the render thread and composes the latest HMD pose with a game camera matrix.

Sources:
https://www.cryengine.com/docs/static/engines/cryengine-5/categories/23756813/pages/26871553
https://www.cryengine.com/docs/static/engines/cryengine-5/categories/28704770/pages/29797340

The documented composition example is conceptually:
`outputCameraMatrix = gameCameraMatrix * HMDrelativeMatrix`

IHmdDevice also exposes asymmetric per-eye setup and most-recent tracking state.

Source:
https://www.cryengine.com/docs/static/engines/cryengine-5/categories/28704770/pages/29797339

### C2VR impact
This is architectural lineage support for two future ideas already in the project:
1. HEAD composition should be relative to an immutable game/body camera rather than repeatedly feeding HMD output back into SetCamera.
2. A late/timely HMD sample near render/presentation is an engine-proven VR latency pattern.

Do NOT jump to a new late-injection mutation while PosePair P6 is current gate. This becomes useful after exact-pair cadence closes.

## 6. CryENGINE 3 Oculus-era VR configuration
Official CryENGINE 3 Oculus documentation contains:
- r_stereomode=1 for dual rendering;
- r_minimizeLatency=1;
- r_motionblur=0 recommendation;
- HMD stereo output and render-resolution configuration.

Source:
https://www.cryengine.com/docs/static/engines/cryengine-3/categories/1638401/pages/21267378

### C2VR impact
Treat this as historical evidence that CryEngine VR evolved around dual-render + latency minimization, not as a direct Crysis 2 retail capability claim.

## 7. Weapon firing ownership contract
Official CryENGINE 3 IWeapon documentation exposes:
- GetFiringPos(probableHit);
- GetFiringDir(probableHit, firingPos);
- GetFiringLocator();
- SetFiringLocator(IWeaponFiringLocator*);
- OnShoot / RequestShoot / StartFire.

Source:
https://www.cryengine.com/docs/static/engines/cryengine-3/categories/17399809/pages/17075029

The documentation explicitly notes that the firing position must be supplied to obtain an accurate firing direction.

### C2VR impact
This strongly validates the current future GameDll target family:
- CWeapon::SetFiringLocator;
- fire-mode GetProbableHit / GetFiringPos / GetFiringDir.

After HEAD closes, source/PDB-to-retail mapping should prioritize this chain rather than relying on a mouse-servo fallback if exact functions can be closed.

## 8. First-person weapon lineage
CryENGINE 3.4 documentation describes a dedicated first-person weapon rig/mesh path using character arms as the base and weapon-specific animation/attachments.

Sources:
https://www.cryengine.com/docs/static/engines/cryengine-3/categories/1114113/pages/1310920
https://www.cryengine.com/docs/static/engines/cryengine-3/categories/1114113/pages/1310783

### C2VR impact
This supports treating the visual first-person weapon as a distinct ownership family from WORLD camera and from gameplay firing direction. That is consistent with the current separation:
- WORLD/HEAD;
- per-eye NEAR projection;
- rigid controller->weapon visual bind;
- gameplay firing locator/direction.

## 9. Crytek Crysis 2 stereo presentation lineage
Crytek/GDC material documents a dedicated CryENGINE 3 real-time stereo effort for Crysis 2, and later Crytek rendering material explicitly covers stereoscopic rendering and shadowing techniques.

Sources:
https://www.gdcvault.com/play/1013803/CryENGINE-3-Real-time-Stereo
https://advances.realtimerendering.com/s2011/

Historical Crytek/Crysis 2 discussion also describes special handling for close first-person weapon stereo depth and HUD occlusion/depth conflicts. This is useful context for why weapon/NEAR should remain a separate gate from WORLD stereo.

## 10. Current actionable deductions
### For current G1 PosePair
No gate change. Public lineage does not supersede P6. Run P6 unchanged first.

### For G2 HEAD after PosePair
Prioritize:
1. existing T1 upstream center camera at RenderWorld;
2. immutable game/body camera composed with HMD-relative rotation;
3. coherent rendering/culling camera;
4. only then consider later/async pose refinement;
5. resolve local-X conflict COLD before final positional mapping.

### For G3 weapon/NEAR
Prioritize:
1. fixed rigid visual bind for FP weapon;
2. independent per-eye NEAR projection;
3. exact retail mapping of IWeapon firing-locator chain;
4. servo fallback only if exact owner remains unavailable.

### For G4 temporal/shadows
The SIGGRAPH/GDC Crytek rendering material is worth mining next for exact stereo shadow reuse and camera-dependent history policy before creating any new LIVE.

## Next public-source harvest targets
1. Extract specific stereo/shadow slides from Crytek SIGGRAPH 2011 materials.
2. Find publicly accessible CRYENGINE source/tag lineage around stereo camera generation, SRenderingPassInfo and shadow reuse.
3. Find the closest public GameSDK source lineage for Item/Weapon update order and firing-locator implementation.
4. Compare later async-HMD composition ordering against retail CCamera Matrix34 semantics.
5. Preserve exact source URLs, version/date, symbol names and retail relevance in this repository.
