# Crysis 2 VR — ROADMAP

Main build remains `CUSTOM_DUAL_T1 v1.0.1`. True private L/R rendering is already proven. Do not replace the main build wholesale with v17.2; v17.2 is a donor corpus for later serial gates.

## BUILD P — PosePair rendezvous — CURRENT
T1 + PosePair only.

Import only:
- immutable current-XR-frame contract
- host ticket publication
- exact ticket carried through LEFT+RIGHT
- completed-pair publication only after RIGHT RT completion
- bounded host wait
- exact identity acceptance
- mismatch => zero layers

PASS:
- fused stereo
- real depth
- stationary head -> stationary world
- fast turn -> no eye-time split
- no stale-eye behavior

Then FREEZE.

## BUILD H — HEAD 1:1 + culling envelope
Add only HEAD/cull candidate after BUILD P passes.

Architecture:
- HEAD high before visibility/list selection
- EYES low in per-eye raster transaction
- apply HMD center transform once to one frozen center-camera snapshot
- conservative union envelope only for list preparation
- exact per-eye XrView projection stays separate for raster cameras

PASS:
- yaw/pitch 1:1
- no double rotation/drift
- no culling pop
- five minutes active head motion

Then FREEZE.

## BUILD W — WEAPON / NEAR
Use existing retail anchors, do not reopen weapon subsystem broadly:
- FOB_NEAREST `+0x000FF340`
- NEAR SetCamera return `+0x000FF456`
- restore return `+0x000FF4A3`
- owner `+0x00102100`
- Renderer::SetCamera `+0x00148340`

Canonical donor transaction:
- clone temporary eye camera
- recompute current-eye asymmetry at LIVE NEAR near plane
- apply RIGHT Touch transform relative to HMD center
- call original SetCamera with clone
- never persistently overwrite original camera

PASS:
- head still -> weapon still
- controller only -> weapon moves, WORLD does not
- head only -> no counter-motion
- no flicker
- both eyes coherent

Then FREEZE.

## BUILD T — TEMPORAL / SHADOW STABILITY
Only after P/H/W pass visually.

Known blocker: fast-head-turn temporal tearing / eye-state corruption.

Serial policy:
1. TAA/AA OFF control if applicable
2. LEFT-authoritative temporal history / RIGHT isolated
3. separate history per eye only if required
4. minimal reset/freeze/restore only if required

Shadows:
- list prepared once
- shadow generation occurs later RT-side
- suppress only repeated second-eye RT shadow generation if needed
- never use `SHDF_ZPASS_ONLY` as a RIGHT scene policy

Then FREEZE.

## BUILD R — REGRESSION
Required:
- normal mono launch
- true LEFT/RIGHT
- HEAD 1:1
- weapon correct
- shadows both eyes
- HUD both eyes
- save/load
- menu -> gameplay
- cutscene transitions
- no accumulating drift
- no state corruption
- byte-exact restore
- retail hashes unchanged

Any failure => rollback immediately.

## RELEASE CANDIDATE
At least 10 minutes of actual gameplay with head motion, movement, weapon use and traversal with no tearing, drift, eye divergence, black eye, crash or state corruption.

PASS => STOP FORENSICS => RELEASE CANDIDATE.
