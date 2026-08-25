# Crysis 2 VR — NEXT EXPERIMENT

## Decision
**ADAPT at the first missing edge. Run the minimal P6 latch-wait child.**

Do not run pipeline-lead K, HEAD, weapon/NEAR, temporal or shadow experiments until this recovery edge is green.

Detailed evidence:
`research/P6_STARTUP_LATCH_RACE_20260825.md`

Corrected state:
`docs/STATE_OVERRIDE_20260825_P6_RED.md`

## CURRENT GATE
`MASTER 2 regression recovery / contract-latch rendezvous`

## FIRST MISSING EDGE
The executed P6 run reaches private eye target readiness before the first valid local RenderWorld camera/contract snapshot after OpenXR session re-entry. The inherited `dRC` path turns that transient condition into global `T1_Fault("NO_LATCHED_RENDER_CONTRACT")`, and `T1_HostRunning()` then remains false because `faulted=1`.

Raw P6 ordering:
- game `ENGINE_EYES_READY` `01:25:48.700`
- game `FAULT NO_LATCHED_RENDER_CONTRACT` `01:25:48.700`
- host `XR_STATE 4/5` `01:25:48.858`
- result: zero queued pairs, zero LEFT/RIGHT, zero completes, zero exact consumes/submits

## WORKING ANCESTOR
Exact physical package recovered:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.5_EXACT_WAIT45_P5_ONECLICK.zip`
SHA256 `D0C7B94A0DB56DCB7974FC20EC9D1017DA790ADFF80B64B177275F5B1BDC9737`

Exact raw RESULT recovered:
`C2VR_RC33_V1721_RESULT_20260823_170445.zip`
SHA256 `7B1CF8E0CBBF87930CE8FE8D810341527804C3AEC8C9C90999251F3186724DD2`

Known-good P5:
- `354/354` completed/copies
- `269` exact consumes
- `269` host submits
- exact hit ratio `0.835404`
- `53` misses
- `31` stale drains
- wait last/max `31/47 ms`

`SCRIPT_LINEAGE_GAP = CLOSED`.

## P6 INTERMEDIATE
Executed P6 package:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89E`

P5 -> P6:
- all game/in-process runtime source byte-identical;
- only first-party runtime source change is x64 host 45 -> 120 ms exact watchdog plus passive wait telemetry;
- exact-only submit/stale-drain architecture unchanged.

## NEXT CHILD
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.7_P6_LATCH_WAIT_ONECLICK.zip`

BASE_PACKAGE = P5 exact working package above
BASE_SCRIPT = `RUN_C2VR_V17_TRUE_LR.cmd -> tools\Run-V17.ps1`
KNOWN_GOOD_RESULT = P5 RESULT above
WHAT_IS_REUSED = P5 launcher/build/restore/logging/packaging plus already-executed P6 host 120 ms/watch telemetry
ONLY DELTA = relative to P6, `src/t1_dual_render.cpp` only
UNCHANGED LAUNCH PATH = byte-identical
UNCHANGED BUILD PATH = byte-identical
UNCHANGED RESTORE PATH = byte-identical
EXPECTED NEW RESULT = optional early WAIT marker, no global latch fault, then center latch -> queue -> LEFT -> RIGHT -> completion -> host exact consume/submit

Exact launcher/recovery hashes remain:
- RUN cmd `9CF526A7F08B19A2974B4FA454C23966768D7CC4C782CE46EF14ECA86353DCD4`
- Run-V17.ps1 `AD6B3D7614700E2117F550AEB626D8432C88F9513924FEBA4524FA623237F6F5`
- RECOVER cmd `53EF1565B315AB737176112E76DE31A329C9645184BB2B3C406D3C372D87B659`
- Recover-V17.ps1 `CD020C2D50ACCE0818D487373E009DEF0477F23F53966D543596A500D5DF6C5F`

## ONLY RUNTIME MUTATION
Old P6:
```cpp
if(!T1_GetCenterCamera(center,sizeof(center),&cc)||!T1_GetSnapshotContract(&fc)){
    T1_Fault("NO_LATCHED_RENDER_CONTRACT");
    return;
}
```

P7:
```cpp
if(!T1_GetCenterCamera(center,sizeof(center),&cc)||!T1_GetSnapshotContract(&fc)){
    if(InterlockedCompareExchange(&g_latchWaitLogged,1,0)==0)
        T1_Log("WAIT_LATCHED_RENDER_CONTRACT fail_closed=1 fault=0");
    return;
}
```

No eye pair is rendered/submitted on the missing-latch call. No stale pair is relabelled. No mono fallback is introduced. The next valid RenderWorld can publish the snapshot normally.

## COLD VALIDATION
- static `130/130 PASS`
- independent `98/98 PASS`
- IPC ABI `T1FrameContract=196`, `T1Shared=1084`
- P6 120ms host policy unchanged
- exact-only/stale-drain unchanged
- HEAD/weapon/temporal/shadow unchanged

## PREFLIGHT — exactly 5 lines
**MISSING FACT:** does removing only the premature global latch fault allow P6 to recover pair production after OpenXR session re-entry?
**WHY NOT K:** P6 produced zero queued pairs and zero submits; cadence K is downstream of this first missing edge.
**PASS:** no global latch fault, then center inject/restore >0, queued pairs >0, LEFT/RIGHT >0, completed pairs >0, exact consumes/submits >0.
**FAIL:** no latch/pair after host session+views are valid, or renderer/transport regression; package first missing edge and STOP.
**BASELINE MUST HOLD:** exact P5/P6 launcher/build/restore/IPC/RC33/OpenXR architecture, 120 ms watchdog and all downstream policies remain unchanged.

## RUN
Use the inherited one-click only:
`RUN_C2VR_V17_TRUE_LR.cmd`

Return the generated `C2VR_RC33_V1721_RESULT_*.zip`. The inherited filename prefix remains intentional lineage and is not build identity; `BUILD_COMMANDS.log` and `BUILD_IDENTITY.txt` determine the actual child.

## AFTER PASS
If pair production/submission is restored, inspect the same run's unchanged P6 120 ms timing telemetry. Then return to MASTER 3 transport cadence with fixed watchdog and serial K testing. HEAD remains blocked until exact hit ratio, visual stability, L/R non-duplicate proof, hashes and restore satisfy MASTER 3 acceptance.