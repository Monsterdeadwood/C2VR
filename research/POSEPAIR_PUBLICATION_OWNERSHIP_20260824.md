# C2VR — PosePair publication ownership / persistent eye-RT overwrite risk

Date: 2026-08-24
Role: cross-branch handoff only; no new LIVE performed here.

## Cross-branch position
Remote `main` already advanced beyond the original BUILD-P planning stage.

Current active gate remains:
**G1 — PosePair / projection-layer exact-pair cadence gating.**

Latest LIVE result imported from the concurrent branch:
- `v17.2.5 WAIT45`
- exact consumes `269`
- host submits `269`
- misses `53`
- exact ratio `83.5404%`
- `pair_wait_ms_max=47`
- completed/copies `354/354`
- headset flashes/dropouts remained

Authorized NEXT remains the already-built, unmodified:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip`
SHA256 `8385f6aaad668e40058eb368e4593f53a3489ce7c24ef19521c4c8deb0eca89e`.

This note does **not** replace P6. It preserves a narrower source-level ownership risk to use only if P6 leaves presentation instability unresolved.

## Question examined in this branch
Could the persistent engine eye render targets be overwritten by the next render-thread pair before Present copies the previous completed pair into the shared transport?

## SOURCE-PROVEN donor behavior
Proven from the verified v17.2.1 donor source already stored under `runtime/donors/v17.2.1/`.

### Completion point — `src/t1_dual_render.cpp`
RIGHT completion is published after the real RIGHT `RT_RenderScene` returns and matching LEFT serial state is present:

```cpp
if (InterlockedCompareExchange(&g_leftCompletedSerial,0,0)==t->serial
    && leftSerial==t->serial) {
    InterlockedIncrement(&g_completedSeq);
    MemoryBarrier();
    g_completedContract=t->fc;
    MemoryBarrier();
    InterlockedIncrement(&g_completedSeq);
    InterlockedExchange(&g_completedSerial,t->serial);
}
```

Interpretation:
- this is render-thread / CPU-side semantic completion;
- it is not an explicit GPU fence proving all prior raster work has physically retired;
- that distinction alone is not evidence of a pixel race.

### Pair publication — `src/t1_proxy.cpp::publish_pair()`
The donor:
1. reads the latest completed pair serial + contract;
2. acquires both keyed mutexes for producer key `0`;
3. gets persistent engine eye textures `T1_DualEyeTexture(0/1)`;
4. queues `CopyResource(sharedL, eyeL)` and `CopyResource(sharedR, eyeR)` on `g_ctx`;
5. calls `g_ctx->Flush()`;
6. publishes `pair_contract`, then increments `pair_seq` / `direct_pair_copies`;
7. releases both keyed mutexes to key `1`;
8. sets `g_lastCopiedSerial=serial`.

`Flush()` is not a GPU-completion fence. Correctness on the normal path therefore depends on command-stream ordering and the ownership of the immediate context/publication seam.

### Present hook ownership — `src/t1_proxy.cpp`
The verified donor contains:

```cpp
static HRESULT STDMETHODCALLTYPE hkPresent(IDXGISwapChain* s,UINT sync,UINT flags) {
    T1_IPC();
    T1_DualOnPresent(s);
    int pub=publish_pair();
    if(pub)mirror_left(s);
    ...
    return oPresent?oPresent(s,sync,flags):E_FAIL;
}
```

The factory hook installs the Present hook on every successfully created swapchain:

```cpp
if(SUCCEEDED(hr)&&out&&*out) {
    adopt_device(dev);
    if(!g_swap){g_swap=*out;g_swap->AddRef();}
    install_present(*out);
}
```

There is no explicit:
- `s == canonical_primary_swapchain` publication guard;
- canonical render-thread ID guard around `publish_pair()`;
- `current_ticket()==NULL` / outside-eye-transaction publication guard.

These are source facts. They do **not** prove that retail Crysis 2 actually calls an auxiliary Present concurrently on the failing runtime path.

## Current interpretation
### Normal canonical path
If:
- RIGHT `RT_RenderScene(N)`;
- engine EndFrame;
- primary render-thread Present;
- `CopyResource(shared, persistentEyeRT)`

all execute through the same intended D3D11 immediate-context lineage, then the copy command is ordered after pair-N draw/post commands and before later writes to the same persistent eye resource. A separate CPU/GPU fence is not the first justified fix.

Therefore the simple model:
`N completes -> N+1 overwrites persistent eye RT -> primary Present copies N+1 while metadata still says N`

is **not currently proven** and is not the leading first fix on the canonical path.

### Narrow ownership risk
If an auxiliary/wrong-thread Present can reach `publish_pair()` while the renderer is still using the same immediate context, the intended ordering/ownership assumption can fail.

Possible failure class:
- completed metadata says pair `N`;
- an early/noncanonical Present publishes from persistent eye textures at the wrong point;
- `g_lastCopiedSerial` becomes `N`;
- the later true primary Present skips `N` because it now appears already copied.

This would create an image/metadata ownership error without requiring the host exact-contract checks themselves to be wrong.

Classification:
**SOURCE-SUPPORTED RISK, RUNTIME UNRESOLVED.**

## Prior project evidence that strengthens the ownership concern
Historical result:
`CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_012736.zip`

It proved a different but analogous cross-thread ownership failure:
- global/main-thread `g_activeNativeEye` was not a reliable eye owner;
- render-thread boundary ownership recovered `10309/10309` predicted events;
- `BoundaryThread` was coherent with zero mismatch in that test;
- verdict: `GLOBAL_ACTIVE_EYE_RACE_CONFIRMED`.

This does not prove the Present race, but it reinforces the project rule:
**use the concrete render-thread transaction owner, not a process-global or loosely timed proxy for ownership.**

## Minimal passive ownership closure if P6 still needs it
Do not mutate HEAD/weapon/temporal/shadow for this question.

Preferred publication authority:

```text
RIGHT pair completion
 -> leave eye transaction
 -> canonical render-thread EndFrame
 -> PRIMARY Present only
 -> snapshot completed serial/contract
 -> Copy L/R to shared
 -> verify serial/contract unchanged
 -> publish exact metadata
 -> release BOTH producer mutexes to key 1
 -> READY / host consume
```

Recommended passive guards:
- `primary_present_wrong_thread == 0`
- `aux_present_publish == 0`
- `publish_inside_eye == 0`
- `completed_serial_changed_during_copy == 0`
- `resource_epoch_changed == 0`

### Cheap serial sandwich
Before copy:
`S0 = completedSerial`, `C0 = completedContract`.

After both copies have been queued:
`S1 = completedSerial`, `C1 = completedContract`.

Required for a valid publication:
`S0 == S1 && C0 == C1`.

On the intended same-thread canonical path, a change across this window should not occur. If it does, ownership assumptions are wrong and the publication must fail closed.

## STOP / do not overreact
Do not make these the first response while P6 is still untested:
- full GPU fence after every RIGHT eye;
- synchronous CPU wait for GPU completion;
- double/triple-buffering engine eye RTs;
- new RT ring architecture;
- broad Present/cadence analyzer;
- wholesale v17.2 rewrite.

Those add mutation surface and can hide the real owner. First close primary Present + render-thread publication ownership if P6 leaves this class active.

## Relation to CURRENT GATE
This research does not close G1 and does not authorize a new build before P6.

Decision:
- `KEEP` exact immutable PosePair architecture;
- `KEEP` P6 as NEXT;
- `ADAPT` future post-P6 diagnostics to include publication-owner identity if flashes/misses remain inconsistent with exact-pair timing;
- `STOP` premature heavy synchronization/ring-buffer fixes.

## Provenance
- verified donor source: `runtime/donors/v17.2.1/src/t1_dual_render.cpp`
- verified donor source: `runtime/donors/v17.2.1/src/t1_proxy.cpp`
- transplant map: `runtime/donors/v17.2.1/POSEPAIR_TRANSPLANT.md`
- canonical cross-branch state: `docs/SYNC.md`
- historical ownership result: `CRYSIS2VR_FOB_NEAREST_OWNER_TRUTH_RESULT_20260819_012736.zip`

## Unresolved
1. Does P6 close timeout starvation and visual flashes without any publication-owner change?
2. Is every pair-publication call on the same canonical render thread that executes `RT_RenderScene` / `RT_EndFrame`?
3. Can any auxiliary swapchain Present reach `publish_pair()` in the actual retail runtime?
4. Can `completedSerial/Contract` advance across the publication-copy window?
5. If publication ownership is clean and exact ratio is high, the remaining problem moves to timely prediction / pipeline lead, not persistent-RT lifetime.
