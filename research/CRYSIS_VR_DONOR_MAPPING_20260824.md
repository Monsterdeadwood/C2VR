# C2VR — Crysis VR donor mapping harvest — 2026-08-24

Purpose: preserve high-value source-lineage evidence mined from the already-saved public `02_CRYENGINE_VR_AND_STEREO_DONORS.zip`. This is DONOR/COLD evidence, not retail Crysis 2 proof.

## Corpus identity
Local persistent donor archive:
`02_CRYENGINE_VR_AND_STEREO_DONORS.zip`

SHA256 observed during this harvest:
`8134EAA87951232FD50AD68960E970DD58634E959DC6841E26CD6D3677E7F823`

Most valuable subtree:
`Crysis-VR-fholger/`

Upstream public project:
`https://github.com/fholger/crysis_vrmod`

Project description identifies it as the Crysis 2007 VR mod using OpenXR with full 6DoF and motion controller support. Its source is under the CryENGINE 2 Mod SDK license. Treat it as older CryEngine/GameDLL lineage and VR architecture donor, not as a binary-equivalent Crysis 2 source tree.

## Key donor file identities
- `Code/ItemView.cpp` SHA256 `BB3D8AED85BA362A7F948294526952794A38B37BD04AA27796F573D87D11093C`
- `Code/Player.cpp` SHA256 `47AB74BDB1CC89206E52DC2A1CAED48E71A3901684F432D17E08789F8508A886`
- `Code/Weapon.cpp` SHA256 `3D830A2B02475A93666B28C35B913E2011C24E45E1754068A44E80EACF1A4723`
- `Code/Single.cpp` SHA256 `4D3C94E6C1E8C46E441F2E482F922D5789F07ECCFD46A57D03BB3143956D1351`
- `Code/VR/VRManager.cpp` SHA256 `110EC3DF79A5685B69D6D9741C77BE4763B796D6BF4F04A512CF3AF376B07AFD`
- `Code/VR/VRRenderer.cpp` SHA256 `F3FD2B9F2726F8C865FEEE04D753D4033AE87AF0741A47D4B2165BBFF37ABA54`
- `Code/CryEngine/CryCommon/Cry_Camera.h` SHA256 `8545AFB8853A996FFC320BC8947804C380091D48C11D48308579ACD69B970E49`

## 1. Exact FP weapon update order exists in donor
`CItem::UpdateFPView` performs, when valid first-person/mounted conditions hold:
1. view-state checks;
2. `UpdateFPPosition(frameTime)`;
3. `UpdateFPCharacter(frameTime)`.

`CItem::UpdateFPPosition` builds a Matrix34 from `FPWeaponAngles`, applies optional local right/front/up offsets along matrix columns, sets translation from `FPWeaponPos`, then writes the weapon entity world transform.

`CItem::UpdateFPCharacter` then explicitly updates first-person character/skeleton state using the current weapon/entity transform and current view camera, followed by local-bounds invalidation.

### C2VR impact
This strongly supports the existing parked retail target pair:
`CItem::UpdateFPPosition -> CItem::UpdateFPCharacter`.

The clean VR mutation seam is likely between the pose writer and the explicit FP character/skeleton update, because that is where a changed rigid weapon transform can still propagate into first-person geometry before character rendering.

This is a candidate mapping rule, not permission to patch retail before HEAD/PosePair ordering allows it.

## 2. Player PostUpdateView is a weapon-pose producer
In the donor, `CPlayer::PostUpdateView` derives:
- `FPWeaponPos` from `viewParams.position` plus weapon offsets/shake;
- `FPWeaponAngles` from `viewParams.rotation` plus offsets/shake;
- then invokes the VR-specific weapon-position modifier before later FP-item update/render propagation.

### C2VR impact
This elevates `CPlayer::PostUpdateView` from a generic candidate to a high-value upstream writer family for retail Crysis 2 mapping.

Future GameDLL static mapping should therefore establish the chain:
`PostUpdateView -> FPWeaponPos/Angles writer -> UpdateFPPosition -> weapon entity WorldTM -> UpdateFPCharacter`.

If retail lineage preserves this structure, it gives a cleaner controller bind seam than late `FOB_NEAREST` render-object mutation.

## 3. Real CryEngine VR weapon bind matches the planned rigid-bind architecture
The Crysis VR donor computes a controller-driven weapon transform by:
- obtaining a world-space controller/weapon transform;
- obtaining an inverse weapon grip transform;
- multiplying them into a tracked weapon transform;
- assigning resulting translation/orientation to weapon position/angles.

Conceptually:
`W_now = C_now * inverse(Grip_local)`

The grip transform comes from the weapon skeleton/hand anchor and optional grip correction. Special weapons can override the anchor source.

### C2VR impact
This is independent donor convergence with the current C2VR fixed-bind SE(3) finalist:
`GripBind = inverse(C_bind) * W_bind`
`W_now = C_now * GripBind`.

The exact algebra differs only by where the bind is represented. The architecture is the same family: one immutable rigid controller-to-weapon bind, not ad-hoc XYZ offsets and not automatic per-frame rebind.

Promotion:
**SUPPORTED DONOR ARCHITECTURE for G3.**
Still requires retail owner closure and headset causal proof.

## 4. Firing chain is explicitly closed in donor source
The donor contains exactly the function family already listed as unclosed retail C2VR targets:
- `CWeapon::SetFiringLocator`
- `CWeapon::GetFiringLocator`
- `CWeapon::GetFiringPos`
- `CWeapon::GetFiringDir`
- fire-mode `GetProbableHit`
- fire-mode `GetFiringPos`
- fire-mode `GetFiringDir`

Important control flow:
1. fire mode asks the weapon for an optional `IWeaponFiringLocator`;
2. locator gets first refusal for probable hit / firing position / firing direction;
3. fallback uses movement-controller weaponPosition/fireDirection and weapon helpers;
4. weapon-level `GetFiringPos/GetFiringDir` delegate to the active fire mode.

Official CryENGINE 3 `IWeapon` / `IWeaponFiringLocator` documentation independently exposes the same API family, including `GetActualWeaponDir`, projectile position and probable-hit hooks.

### C2VR impact
This turns `SetFiringLocator` into a particularly attractive future ballistics seam: a custom controller-aware locator could override firing origin/direction without rewriting the entire fire mode, while preserving downstream weapon/ammo behavior.

Priority retail mapping after HEAD:
1. identify `CWeapon::SetFiringLocator` / `m_pFiringLocator` lineage;
2. map active fire-mode `GetProbableHit`, `GetFiringPos`, `GetFiringDir`;
3. prove whether a locator override reaches projectile spawn and hit direction in retail;
4. keep historical mouse-servo aim only as fallback.

## 5. Donor contains a stronger VR firing implementation
The VR-modified donor adds a direct local-player path that derives firing origin/direction from the weapon itself:
- origin from a first-person `weapon_term` helper;
- direction from the weapon entity WorldTM forward column;
- a small forward origin adjustment avoids immediate self-collision.

The same direct weapon transform is used for local-player fire direction when not mounted.

### C2VR impact
This provides a concrete reference architecture for the desired behavior:
**visual weapon rigid transform and projectile direction share the same weapon-space authority.**

Do not copy the exact helper name/offset blindly into Crysis 2 retail. Instead use it to generate retail hypotheses:
- look for muzzle/weapon helper access near fire-mode origin code;
- correlate projectile spawn position with FP weapon entity/helper transforms;
- prefer controller-aware firing locator over input emulation if mapping closes.

## 6. Donor HEAD/stereo/culling architecture
The donor VR renderer:
- saves the original game view camera;
- waits for XR frame timing;
- renders LEFT and RIGHT separately;
- builds each eye from the original camera plus eye/HMD transform;
- restores the original view camera afterward;
- uses asymmetric-FOV-derived frustum-plane adjustments to improve culling.

Its camera helper explicitly updates frustum planes from raw per-eye tangents while preserving Cry camera orientation/position semantics.

### C2VR impact
The donor is not directly transplantable because C2 retail work has already FALSIFIED a second top-level RenderWorld as the final architecture. However, three lower-level principles converge with current C2VR:
1. derive each eye from one immutable original/center camera;
2. do not feed eye/HMD output back recursively into the source camera;
3. culling/frustum state must be coherent with the actual eye/head visibility envelope.

## 7. Second-eye shadow suppression has a real CryEngine VR precedent
The donor hooks the Cry renderer shadow-generation function and executes it only for the first eye when a shadow-optimization option is enabled. Its own comment states that shadow maps do not need regeneration for the second eye.

### C2VR impact
This is highly relevant to parked G4.

Current C2VR policy already says: suppress only repeated RT-side second-eye shadow generation if required; never suppress the RIGHT scene itself.

The Crysis VR donor independently validates exactly that class of optimization:
**reuse first-eye shadow maps; still render full second-eye scene.**

This does NOT prove which Crysis 2 DX11 shadow function/command should be gated. Retail `PrepareDepthMaps`, shadow pass state and the current RC33 eye transaction remain the authority.

## 8. Second-eye non-view simulation work can be selectively suppressed
The donor also avoids redundant particle-system update work on the second eye while preserving rendering.

### C2VR impact
Future G4 instrumentation should distinguish:
- render state that must be eye-specific;
- simulation/update work that should occur once per logical frame;
- history/state that must either be LEFT-authoritative or separately indexed per eye.

This is a useful classification framework for temporal corruption hunting.

## 9. Crysis2Coop corpus status — already possessed, not a new acquisition target
The project had already acquired and processed the public `Crysis 2 Co-op` / Crysis 2 ModSDK-lineage material before this harvest. Therefore **do not redownload or treat it as a newly discovered dependency**.

Public package identity remains useful provenance:
- `Crysis 2 Co-op - Source Files`
- filename `Crysis2Coop.rar`
- published Apr 18 2012
- size `11,133,614` bytes
- MD5 `dc640394f1534084baf4ac7c7e04c34c`

The correct next action is a **targeted re-harvest of the already-held corpus**, not acquisition:
- `CPlayer::PostUpdateView`
- `CItem::UpdateFPPosition`
- `CItem::UpdateFPCharacter`
- `CWeapon::SetFiringLocator`
- fire-mode `GetProbableHit`
- `GetFiringPos`
- `GetFiringDir`
- first-person weapon helpers / muzzle helpers / skeleton update order
- stereo/near-geometry CVars and any Crysis 2-specific handling

Classify every useful hit by exact file/version/provenance and then triangulate against local beta/PDB and retail. Do not repeat the earlier broad corpus pass unless a specific missing fact requires it.

## 10. Gate consequences
No runtime gate change.

Current order remains:
`P6 PosePair -> HEAD 1:1 -> WEAPON/NEAR -> TEMPORAL/SHADOW -> REGRESSION -> RELEASE`.

But future work is narrower now:

### G2 HEAD
Use donor only for composition/culling principles. Retail T1 remains primary.

### G3 WEAPON/NEAR
Preferred static sequence after HEAD:
`CPlayer::PostUpdateView -> FP weapon pose writers -> CItem::UpdateFPPosition -> weapon WorldTM -> CItem::UpdateFPCharacter -> firing locator/fire-mode chain`.

### G4 TEMPORAL/SHADOW
First shadow candidate remains first-eye-authoritative shadow generation with full RIGHT scene rendering. Passive proof must identify the exact retail shadow command/function before mutation.

## Classification
- `CItem::UpdateFPPosition -> UpdateFPCharacter` order: **DONOR PROVEN / RETAIL UNMAPPED**
- `PostUpdateView` as upstream FP weapon pose producer: **DONOR PROVEN / RETAIL UNMAPPED**
- rigid controller * inverse-grip weapon bind: **DONOR PROVEN / RETAIL UNPROVEN**
- firing-locator override architecture: **DONOR + OFFICIAL API SUPPORTED / RETAIL UNMAPPED**
- weapon-derived projectile origin/direction: **VR DONOR PROVEN / RETAIL UNPROVEN**
- first-eye-only shadow generation: **VR DONOR PROVEN / RETAIL UNPROVEN**
- second top-level render: **DONOR METHOD, C2VR FINAL ARCHITECTURE FALSIFIED**

Do not promote donor findings to retail `PROVEN` until version mapping or causal retail evidence closes them.
