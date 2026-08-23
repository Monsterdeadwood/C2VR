# Crysis 2 VR — NEXT EXPERIMENT

## Decision
**KEEP architecture, ADAPT only the frame-pair contract.** True stereo is already proven. Broad renderer/scheduler research is stopped.

## Primary question
Can `CUSTOM_DUAL_T1 v1.0.1` submit only LEFT/RIGHT images that belong to exactly the same immutable current OpenXR frame ticket, eliminating stale-eye / eye-time split without changing the proven render primitive?

## PREFLIGHT — exactly 5 lines
**MISSING FACT:** whether exact immutable current-frame ticket identity across LEFT production, RIGHT production and host submission is sufficient to close the observed `PosePairContract` failure on the existing true-L/R renderer.
**WHY NOT COLD:** the contract logic can be built from known v17.2/Khronos semantics, but only LIVE fast-head-turn behavior can prove stale/mismatched eye presentation is gone while the renderer remains visually fused.
**PASS:** both eyes submit from one exact ticket; mismatches drop the layer instead of relabeling; fused real depth remains; stationary head gives stationary world; fast head turns show no eye-time split/stale-eye behavior.
**FAIL:** stale/relabelled eye is still presented, pair identity diverges, true L/R renderer regresses, one eye goes black unexpectedly, or the host submits a pair whose images/pose belong to different XR frame identities.
**BASELINE MUST HOLD:** `CUSTOM_DUAL_T1 v1.0.1` true private L/R primitive, one prepared render-list executed twice, exact retail hashes, and no second top-level RenderWorld/EF_StartEf.

## Minimal mutation surface
Transplant from v17.2 only the rendezvous/contract pieces required for BUILD P:
1. packed immutable current-XR-frame ticket / ABI-equivalent `T1FrameContract`;
2. host publishes the current ticket once for the frame;
3. pair producer copies the exact ticket into LEFT and RIGHT production state;
4. completed pair becomes publishable only after RIGHT render-target completion;
5. host waits within a bounded window;
6. host accepts only exact ticket identity;
7. any mismatch/stale condition => `layerCount=0` for that frame.

## Forbidden in this build
Do not add:
- HEAD/culling union changes beyond T1 baseline
- RIGHT Touch / FOB_NEAREST weapon mutation
- temporal history isolation
- second-eye shadow suppression
- new resource/CB archaeology

Those are later serial gates.

## Required telemetry
Log per XR frame:
- ticket sequence/id
- predictedDisplayTime or exact time identity used by the contract
- LEFT produced ticket id
- RIGHT produced ticket id
- RIGHT completion marker
- completed-pair ticket id
- host-consumed ticket id
- accepted/rejected reason
- submitted layerCount
- stale/mismatch/drop counters

Do not use counters alone as visual proof; they are contract evidence plus headset behavior.

## Visual test
Use a scene with real depth and perform:
- stationary head hold
- slow yaw
- repeated fast yaw reversals
- pitch/yaw combination
- stop head abruptly after fast turn

PASS requires:
- no eye-time split
- no stale-eye catch-up
- no persistent world motion after head stops caused by pair mismatch
- real depth remains
- both eyes remain distinct/alive

## Rollback rule
Any regression of the true-L/R renderer or canonical eye transaction => immediate rollback. Do not compensate by adding another mutation.

## After PASS
Freeze BUILD P. Next authorized build is HEAD 1:1 + conservative visibility envelope only.
