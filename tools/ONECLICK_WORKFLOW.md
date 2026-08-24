# C2VR - canonical one-click workflow pattern

Purpose: preserve the runner/build/recovery engineering used by successful C2VR packages independently of old chat tabs.

This is tooling authority only. A prepared package is not runtime evidence.

## Front door
Use a tiny `.cmd`/`.bat` launcher that changes to its own directory and starts one PowerShell orchestrator. Keep experiment logic in the script, not in cmd syntax.

Current P6 examples:
- `RUN_C2VR_V17_TRUE_LR.cmd`
- `RECOVER_V17.cmd`
- `tools/Run-V17.ps1`
- `tools/Recover-V17.ps1`

## Strict orchestrator
Start with fail-closed PowerShell behavior:

```powershell
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version 2.0
```

Use explicit helper functions for SHA256, PE machine, process ownership, numeric status parsing and command timeouts.

## Frozen-target guard
Before build/install/run verify:
- exact `Crysis2.exe` SHA256;
- exact `CryRenderD3D11.dll` SHA256;
- expected retail root;
- correct x86 proxy and x64 host architecture;
- current OpenXR ActiveRuntime exists;
- no stale C2VR host/process transaction;
- no stale C2VR proxy already installed unless recovery semantics explicitly recognize it.

## Build contract
Prefer pinned/reproducible source and toolchain over copying opaque binaries.

C2 packages historically:
- discover Zig from known candidate paths and verify its version/argv transport;
- compile x86 in-process proxy and x64 OpenXR host separately;
- verify PE machine after build;
- record host/proxy SHA256 and ABI identity in the RESULT.

Source identity is the reproducibility lock. Object-file hash is not automatically a canonical identity unless determinism is independently proven.

## OpenXR before game mutation
Start the x64 OpenXR host first and wait for a real session/view-valid contract before installing or launching the game-side mutation.

Fail closed if:
- host exits early;
- session is not running;
- views are invalid;
- recommended eye size is absent/out of guard range.

This prevents Quest Link availability from being misclassified as game-renderer failure.

## Recovery transaction
Before touching `d3d11.dll` / `system.cfg`:
1. reject stale recovery state;
2. create recovery directory;
3. save existence flags and SHA256;
4. copy original bytes exactly;
5. write recovery state before experiment install;
6. install child only after recovery state is durable.

Recovery logic must distinguish:
- original file existed;
- file did not exist;
- recognized old C2VR wrapper;
- unknown modified file.

Unknown state must fail closed rather than overwrite it.

After restore, re-hash and emit `RESTORE_VERIFY=PASS/FAIL`.

## One gate per build
One C2VR version should correspond to one bounded policy change.

Examples:
- P5 WAIT45 changed exact-pair bounded wait policy;
- P6 changes the bounded wait ceiling `45 ms -> 120 ms` and adds passive timing telemetry, while keeping game-side camera/FOV/weapon/shadow policy unchanged.

Do not combine PosePair, HEAD, weapon and temporal changes in one child.

## Runtime GREEN gate
Do not start the human test window merely because processes are alive.

Require concrete counters, for example:
- LEFT/RIGHT render counts;
- direct pair copies;
- exact host hits/submits;
- pair MAE/non-black evidence where appropriate;
- desync counters remain zero.

Only after the mechanical gate is green should the runner beep/announce the user test window.

## RESULT packaging
Package:
- machine/retail hashes;
- build identity;
- host/game status snapshots;
- exact counters and waits;
- source/state files relevant to the one mutation;
- analyzer output;
- failure text if any;
- restore verification.

Large RenderDoc/TTD/PDB/corpora stay outside normal RESULT ZIP and Git history; preserve identity/provenance instead.

## Cleanup
Use `try/catch/finally` so restore runs after every code path. Stop only processes owned by the package/test contract and always attempt restore after a failure.

A failure to package after restore does not make the scientific target false. Preserve mechanical/scientific classifications separately.

## Historical pitfalls retained
- stale recovery directories must block a new mutation;
- stale C2VR proxy must be recognized or rejected, never silently replaced;
- PowerShell generated-script/parser defects are infrastructure failures;
- a timed-out downstream edge does not undo already-proven upstream ownership;
- no old pixels may be relabeled with a new pose to fake PosePair success;
- exact pair identity and display-time identity remain part of the acceptance contract.

## Evidence labels
Every package/result should explicitly distinguish:
- PREPARED / UNRUN
- STATIC-AUDITED / NOT LIVE-PROVEN
- MECHANICAL PASS
- SCIENTIFIC PASS
- INFRASTRUCTURE FAILURE
- FALSIFIED
- SUPERSEDED

A clean build/restore is not a visual scientific result.
