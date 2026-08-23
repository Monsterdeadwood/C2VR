# C2VR MASTER3 — WEAPON / FOB_NEAREST parked state

Status: **PARKED until PosePair and HEAD gates pass.** This file preserves the branch so it can resume without replaying old chat/research.

## PRIMARY BLOCKER when this gate opens
Weapon must:
- follow RIGHT Touch/controller
- have no counter-motion
- not flicker
- not alter WORLD
- remain coherent in both eyes

WORLD is immutable in MASTER3. Ballistics/firing direction is a later blocker.

## PROVEN RETAIL NEAR SEAMS
CryRenderD3D11.dll:
- NEAR owner region `+0x000FF340`
- NEAR `SetCamera` return `+0x000FF456`
- NEAR restore `+0x000FF4A3`
- object-owner landmark `+0x00102100`
- renderer `SetCamera +0x00148340`
- `RC_RenderScene +0x001C48D0`
- `RT_RenderScene +0x00107370`
- `RC_PushRT +0x001C4190`
- `RC_PopRT +0x001C4200`

Late 320-byte carrier evidence:
- separate WORLD and NEAR semantic families
- remembered carrier `3FD0B134`: ~48,736 WORLD, ~5,543 NEAR
- NEAR stack `+0x0006AE2A -> +0x0007AEB0` ~84.5% vs WORLD ~1.29%
- earlier `41932D74`: WORLD near/far about `0.12/2000`, NEAR about `0.03/40`, NEAR projection term around `-0.030023`
- `3604/4303` NEAR writes via `CryRenderD3D11+0x7AEB0`
- `deferred_contexts=0`, `ExecuteCommandList=0`
- path `Map -> write -> Unmap -> slot3 bind`

Carrier is a passive raster witness, not gameplay/lifecycle detector.

## HISTORICAL VISUAL EVIDENCE
### 20260817_010329
- right controller visibly moved weapon/viewmodel
- firing still followed monitor/game-center aim
- global image still flickered

Conclusion: controller tracking and visual weapon movement existed; missing piece was ownership/lifetime/coherence, not absence of Touch pose.

### historical 021239 GOLD
- RIGHT controller -> gameplay aim via closed-loop retail input/mouse-response servo
- trigger -> retail fire
- user-confirmed bullets followed weapon/muzzle direction

Keep as later fallback donor. It does not prove direct ballistic ABI/owner.

### 20260818_034749 v10
WORLD/FOB_NEAREST projection coherence removed the observed counter-motion symptom (weapon no longer went right when head looked left).

Conclusion: projection mismatch can look like bad weapon transform. Do not judge controller math while NEAR projection is known-wrong.

## CURRENT v17 HAND PATH — WHAT IT DOES
Current family intercepts the NEAR `SetCamera` callsite (`return RVA +0x000FF456`) during eye transaction:
- copy temporary ~0x230 CCamera
- start from exact current-eye Matrix34
- apply eye-specific near asymmetry/FOV
- apply controller transform
- call original SetCamera with temporary camera
- do not persistently overwrite original camera

Controller contract:
- RIGHT `aim` pose canonical
- `right_pos_head_m`
- `right_q_head`
- trigger
- grip/squeeze input

Current correct primary coordinate bridge:
OpenXR `(x,y,z)` -> Cry local `(+x,-z,+y)`.
Do not resurrect universal `-X` reflection without local causal proof.

## HIGH-PRIORITY BUG CANDIDATE IN CURRENT v17 MATH
Current pattern decomposes position and rotation:
- `handPos = p_current - p_base`
- `handQ = q_current * inverse(q_base)`
- translation applied independently in near-camera basis
- inverse rotation applied separately to camera basis

This is not a guaranteed complete rigid relative transform. Rotation and translation/pivot are coupled in SE(3). Likely symptoms:
- wrist rotation creates arcs
- counter-motion
- weapon runs away when rotated while translated
- combined position+rotation worse than pure controls

Do not solve this with broad XYZ coefficient sweeps.

## HISTORICAL v7 OBJECT TRANSFORM — USEFUL BUT NOT FINAL
v7 improved ownership by temporarily modifying the actual `FOB_NEAREST` render-object Matrix34 and restoring it exactly after draw.

But its transform used head position as rotation pivot and treated late NEAR state too much like ordinary world space. `FOB_NEAREST` is camera-space semantics in CryEngine, so mixing world head pivot + controller world transform + late NEAR object can create residual counter-motion/arcs.

Do not copy v7 formula unchanged.

## PRIMARY RIGID FORMULA FOR NEXT WEAPON GATE
Use a fixed bind transform instead of independent position/rotation hacks.

At bind:
```text
C_bind = ControllerWorld
W_bind = stock WeaponWorld
GripBind = inverse(C_bind) * W_bind
```

Each frame:
```text
W_now = C_now * GripBind
```

Equivalent:
```text
W_now = C_now * inverse(C_bind) * W_bind
```

This naturally contains model orientation, grip offset and pivot.

Requirements:
- baseline fixed after activation/equip/recenter
- no automatic squeeze/grip-edge rebaseline
- one controller contract/pose for both LEFT and RIGHT
- gameplay aim servo OFF during visual weapon proof to avoid double ownership
- keep NEAR eye projection separate from weapon root pose

## CONTROLLER WORLD INVARIANT
Current contract stores controller relative to head. Reconstruct consistently:
```text
ControllerWorld = BodyWorld * HMD * ControllerRelativeToHMD
```

Because `ControllerRelativeToHMD = inverse(HMD) * ControllerAbsolute`, head motion cancels for a physically stationary controller.

Diagnostic oracle during head-only movement:
`Delta ControllerWorld ~= 0`.

If ControllerWorld is stable while weapon moves, the bug is below tracking: bind/weapon/render representation.

## CLEAN UPSTREAM FINAL ARCHITECTURE
C2 source topology:
```text
CPlayer::PostUpdateView
 -> FPWeaponPos / FPWeaponAngles
 -> CItem::UpdateFPPosition
 -> weapon entity SetWorldTM
 -> CItem::UpdateFPCharacter
 -> skeleton preprocessing / attachments
 -> normal FOB_NEAREST rendering
```

Best upstream seam if renderer-side shim cannot become perfect:
**after stock `UpdateFPPosition` has produced WeaponWorld, before `UpdateFPCharacter` consumes it.**

Then replace weapon entity WorldTM with fixed-bind VR pose and let CryEngine update skeleton/attachments and generate near render objects normally.

Do not immediately duplicate skeleton preprocessing per eye. First prove weapon root. If root is correct but arms/bones deform or drift, then investigate `UpdateFPCharacter/SkeletonPreProcess` camera ownership.

## EXACT RETAIL WEAPON SYMBOLS STILL UNRESOLVED
Do not pretend these are mapped:
- `CPlayer::PostUpdateView`
- `CItem::UpdateFPPosition`
- `CItem::UpdateFPCharacter`
- `CWeapon::SetFiringLocator`
- fire-mode `GetProbableHit`
- `GetFiringPos`
- `GetFiringDir`

Preferred closure when gate opens:
- beta `CryGameCrysis2.pdb` + matching beta DLL/source
- extract only the three visual weapon functions first
- derive beta RVA/size/calls/fingerprint
- map narrowly to retail Crysis2.exe
- no broad whole-game archaeology

Observed beta PDB size: `82,045,952` bytes. Older symbol census stopped at `80,000` hits, so absence of these names in that census is not negative evidence.

## NEXT WEAPON CAUSAL FUNNEL AFTER ITS GATE OPENS
1. CONTROL: hand off, exact current NEAR eye/projection.
2. Fixed-bind full SE(3), no grip rebind.
3. Same rigid transform on actual weapon entity/upstream seam if exact mapping is available.
4. Only if geometry is correct but latency remains: same pose pair with later weapon-only latch, never resample independently per eye.
5. Only if root is correct but skeleton is wrong: `UpdateFPCharacter/SkeletonPreProcess` branch.

PASS:
- head still -> weapon still
- controller only -> weapon moves, WORLD does not
- head only -> no counter-motion/drift
- wrist rotation -> weapon rotates around natural grip, no head-radius arc
- both eyes coherent
- no flicker

On reproducible visual PASS: `KEEP -> INTEGRATE -> STOP weapon reverse`.
