# Crysis 2 VR — GATES

## G0 — True two-eye renderer
**PASS.** `CUSTOM_DUAL_T1 v1.0.1` executed genuine non-duplicate private LEFT/RIGHT rendering. Do not rebuild stereo.

## G1 — PosePairContract
**PASS:** every submitted LEFT/RIGHT pair carries exactly one immutable current-frame OpenXR contract; both eye images and submission use the same ticket/predicted frame identity; stale or mismatched pairs are dropped, never relabeled.

Minimal build: T1 + PosePair rendezvous only.

Visual/behavior PASS:
- fused stereo
- real depth
- stationary head -> stationary world
- fast head turn -> no eye-time split
- no stale-eye behavior

**CURRENT GATE: G1**

## G2 — HEAD 1:1 + visibility envelope
After G1 freezes, add only the known HEAD/culling candidate.

PASS:
- yaw/pitch 1:1
- no doubled angle or continued world motion after head stops
- returning HMD returns world
- no accumulating translation
- no culling pop
- survives five minutes active head motion

Known direction: HEAD high before visibility/list selection; EYES low in the canonical per-eye transaction. Use v17.2 culling-union logic only as a narrow donor.

## G3 — Weapon / FOB_NEAREST
Known anchors:
- FOB_NEAREST owner region `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- restore return `+0x000FF4A3`
- object owner `+0x00102100`
- Renderer::SetCamera `+0x00148340`

PASS:
- head still -> weapon still
- controller only -> weapon moves, WORLD does not
- head only -> no weapon counter-motion
- no flicker
- both eyes coherent

## G4 — Temporal / shadow stability
Known later blocker: fast-head-turn temporal tearing / eye-state corruption.

Serial candidate order only after G1-G3 visual acceptance:
1. TAA/AA OFF control if not already off
2. LEFT-authoritative temporal / RIGHT isolated
3. separate eye histories if required
4. reset/freeze-restore only if required

For shadows, suppress only repeated RT-side second-eye shadow generation if needed. Never use `SHDF_ZPASS_ONLY` as the RIGHT scene policy.

## G5 — Regression
PASS all:
- normal mono launch
- stereo LEFT/RIGHT alive
- head 1:1
- weapon correct
- shadows both eyes
- HUD both eyes
- save/load
- menu -> gameplay
- cutscene transitions
- no accumulating drift/state corruption
- byte-exact d3d11 restore
- retail hashes unchanged

## G6 — Release candidate
At least 10 minutes actual gameplay with head motion, movement, weapon use and traversal, with no tearing, drift, eye divergence, black eye, crash or state corruption.

PASS -> STOP FORENSICS -> RELEASE CANDIDATE.
