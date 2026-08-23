# PosePair transplant map — v17.2.1 donor -> CUSTOM_DUAL_T1 v1.0.1

## Scope
Current G1 allows **only** the host/game rendezvous mutation. Do not transplant the donor's HEAD/culling, RIGHT Touch/NEAR, temporal-history or second-eye-shadow policy in the same build.

Main build remains `CUSTOM_DUAL_T1 v1.0.1`.

## Verified donor parents
- `src/t1_ipc.h` — SHA256 `DE00ABD099F5988BB930A6150FF16BA1A9E9AC1A55AE3EC5CC59DC7DEA54B931`
- `src/t1_host_x64.cpp` — SHA256 `A349AA6BC2781C4DCD1AF20E5EF5B571656B84BF005E2193637C3591F8D21C51`
- `src/t1_dual_render.cpp` — SHA256 `397D0577D3F07B776A17395733AB6500BCD05C8928A51608CE3FDD8DEA415C77`
- `src/t1_proxy.cpp` — SHA256 `1CF91E61999A600C7A39E992EF610FFDF259ABD9B8D0E32373A13996DD8FC22C`

All hashes were reconstructed and checked against the canonical corpus before this map was written.

# 1. ABI to preserve
Use the packed `T1FrameContract` from `src/t1_ipc.h` or an ABI-equivalent minimal contract.

Fields required by the current gate:
- `contract_id`
- `predicted_display_time`
- both eye poses
- both eye FOVs
- view-validity state in the surrounding IPC protocol

The donor also carries HEAD and RIGHT-controller data. Those fields may remain ABI-compatible, but they are **not authorized mutation behavior** in BUILD P.

The donor's full ABI guards are:
```cpp
static_assert(sizeof(T1FrameContract)==196, "T1FrameContract ABI mismatch");
static_assert(sizeof(T1Shared)==1084, "T1Shared ABI mismatch");
```

# 2. Host owns the XR frame ticket
The host flow must remain:

```text
xrWaitFrame(N)
 -> xrBeginFrame(N)
 -> xrLocateViews(predictedDisplayTime N, BOTH eyes once)
 -> validate POSITION + ORIENTATION for both views
 -> publish immutable contract N
 -> wait bounded time for completed game pair N
 -> exact identity check
 -> copy LEFT + RIGHT
 -> xrEndFrame(predictedDisplayTime N)
```

If the pair is missing, stale, invalid or mismatched, submit **zero projection layers** for that XR frame.

Never relabel old pixels as the current ticket.

# 3. Exact donor host logic to preserve semantically
The verified host publishes a monotonically increasing contract and stores the same predicted display time used by `xrLocateViews`:

```cpp
c.contract_id = ++g_contractId;
c.predicted_display_time = (uint64_t)displayTime;
...
InterlockedIncrement(&g_ipc->contract_seq);
MemoryBarrier();
g_ipc->contract = c;
MemoryBarrier();
InterlockedIncrement(&g_ipc->contract_seq);
```

The pair consumer accepts only an exact contract id before copying the pair:

```cpp
if (peek.contract_id != requested) {
    InterlockedIncrement(&g_ipc->pair_contract_mismatch);
    return false;
}
...
if (!contractOk || lockedPair != p || fc.contract_id != requested) {
    ...
    InterlockedIncrement(&g_ipc->pair_contract_mismatch);
    return false;
}
```

After copying, submission metadata is taken from the exact contract that produced those pixels:

```cpp
g_submitDisplayTime = fc.predicted_display_time;
g_submitContractId = fc.contract_id;
g_haveSubmit = true;
```

The host wait is bounded. The v17.2.1 donor derives a budget from the XR frame period and clamps it to 12..28 ms. That exact budget is a donor implementation detail, not an immutable project law; the **bounded wait + fail-closed behavior** is the invariant.

# 4. Game pair becomes complete only after RIGHT finishes
The verified dual-render donor records completion only on the RIGHT RT path after LEFT completion for the same serial:

```cpp
if (InterlockedCompareExchange(&g_leftCompletedSerial,0,0) == t->serial
    && leftSerial == t->serial) {
    InterlockedIncrement(&g_completedSeq);
    MemoryBarrier();
    g_completedContract = t->fc;
    MemoryBarrier();
    InterlockedIncrement(&g_completedSeq);
    InterlockedExchange(&g_completedSerial,t->serial);
}
```

For BUILD P, keep only the **completion ordering/identity concept**. Do not import the surrounding v17.2 temporal-history behavior yet.

The donor's render queue also refuses to queue a second pair for the same immutable contract:

```cpp
if (fc.contract_id == g_queuedPoseId) {
    InterlockedIncrement(&sh->host_frame_gate_skips);
    return;
}
```

# 5. Pair publication to shared transport
The verified proxy copies both completed private-eye textures under keyed mutexes, then publishes the exact completed contract with a seqlock-style update before incrementing `pair_seq`:

```cpp
InterlockedIncrement(&p->pair_contract_seq);
MemoryBarrier();
p->pair_contract = fc;
MemoryBarrier();
InterlockedIncrement(&p->pair_contract_seq);
MemoryBarrier();
InterlockedIncrement(&p->pair_seq);
```

The host re-reads `pair_contract` before and after locking/copying. Keep this anti-tearing identity discipline or an equivalent stronger synchronization scheme.

# 6. Final exact acceptance gate
BUILD P accepts a projection layer only when:

```text
completed.contract_id == requested.contract_id
AND completed.predictedDisplayTime == requested.predictedDisplayTime
AND LEFT valid
AND RIGHT valid
AND both images were copied from the completed pair belonging to that contract
```

A contract-id hit with a display-time mismatch is **not** accepted.

# 7. Explicit STOP list for BUILD P
Do not import from v17.2.1 yet:
- `apply_center_6dof`
- culling-union policy
- RIGHT Touch / hand-to-NEAR transforms
- LEFT-authoritative / RIGHT-isolated temporal policy
- second-eye `PrepareDepthMaps` suppression
- any new WORLD/NEAR mutation

Those belong to later frozen gates only after PosePair passes visually.

# 8. Required telemetry in the T1 child build
At minimum record:
- requested contract id
- requested `predictedDisplayTime`
- LEFT produced contract id
- RIGHT produced contract id
- completed contract id
- completed display time
- pair serial
- exact hit count
- mismatch count
- timeout/drop count
- submitted layer count

Counters are contract evidence, not visual acceptance by themselves.

# 9. Visual acceptance
PASS requires in-headset:
- fused stereo
- real depth
- stationary head -> stationary world
- fast yaw/reversal -> no eye-time split or stale smear
- no one-eye stale behavior
- true L/R T1 renderer remains intact

On PASS: freeze PosePair and move to HEAD 1:1. On FAIL: identify which contract component is late/mismatched; do not reopen stereo discovery.
