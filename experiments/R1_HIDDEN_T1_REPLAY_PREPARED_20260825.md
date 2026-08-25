# C2VR R1 — HIDDEN T1 REPLAY — PREPARED / UNRUN — 2026-08-25

## STATUS

`PREPARED / UNRUN`

No runtime PASS is claimed.

Static validation:
`R1_STATIC=PASS (70/70)`.

Final package:
`CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`

Bytes:
`191925`

SHA256:
`330382153381C01CDE23FA15D777A6F54796F761D8DEC3F0A2BC2D07AC78EC79`.

## LINEAGE

BASE_PACKAGE:
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

T1 DONOR:
`CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip`
SHA256 `9271A002F8DE7875EDDD72AC2C2C307748A922883365F05FEFFC18FA05D2EECF`.

Exact v6 launch/build/restore chain remains byte-identical:
`20_RUN_C2VR_FULL_VR.bat -> RUN_FULL_VR.bat -> tools/Build-Run-EngineTap.ps1`.

Exact x64 host, host client and IPC ABI remain byte-identical.

## CAUSAL QUESTION

Can proven T1 private-eye replay execute underneath the historically stable v6 world owner without perturbing the visible v6 camera/world/shadow/temporal state?

The headset continues to receive only the inherited v6.0.1 mono Present/cache output.

Hidden private eyes are never:
- published to IPC;
- copied to shared eye textures;
- submitted to OpenXR.

## AUTOMATIC SCHEDULE

The run contains its own baseline control, so a separate R0 launch is not required before interpreting R1:

```text
0–10 s   OFF_A             baseline control
10–25 s  SPARSE_1_OF_10    hidden replay low duty
25–45 s  FULL              hidden replay every eligible scene packet
45–55 s  OFF_B             recovery control
>55 s    DONE
```

If OFF_A is already visually bad, classify the entire run `R1_INVALID_BASELINE` and stop interpreting replay phases.

Audio cues:
- 1 short beep = SPARSE starts;
- 2 short beeps = FULL starts;
- 3 short beeps = OFF_B starts;
- 1 long beep = DONE.

## ONLY RUNTIME DELTA

Modified inherited files:
- `src/engine_tap.cpp` — read-only v6 center camera/packet snapshot; hidden worker bootstrap/shutdown; textual hidden module include.
- `src/engine_tap.h` — passive Present observer declaration.
- `src/porous_proxy.cpp` — inherited `C2VR_HOST_OnPresent` remains first; hidden observer only reads swapchain dimensions afterward.
- `analysis/analyze_result.py` — reports hidden counters and refuses automatic visual promotion.

New runtime file:
- `src/hidden_t1_replay.cpp` — adapted exact T1 RC/RT replay seams into private RTs only.

No files removed.

## ISOLATION CONTRACT

`visible_output_owner=V601_MONO_PRESENT_CACHE_UNCHANGED`

Required:
```text
private_eye_publication=0
private_eye_shared_copy=0
private_eye_openxr_submit=0
```

Hidden module contains no `CopyResource`, shared-handle, keyed-mutex publication or OpenXR composition submission path.

## RUNTIME EVIDENCE

`HIDDEN_T1_STATUS.txt` reports:
- installed / ever_installed;
- ready;
- phase / max_phase / experiment_done;
- top-level and eligible scene packets;
- replay attempts/pairs;
- sparse/full pairs;
- L/R eye build counts;
- RT push and RT scene counts;
- temporal snapshot/restore and leak count;
- private shadow-skip counts;
- center restore commands;
- replay microseconds;
- fault.

Analyzer ends with:
`VISUAL_RESULT=NOT_AUTOMATED__USER_HEADSET_VERDICT_REQUIRED`.

## VERDICT TREE

### R1_INVALID_BASELINE
OFF_A is already catastrophically unstable.
Do not interpret later phases.

### R1_REPLAY_POISONS_STATE
OFF_A stable; SPARSE or FULL makes visible v6 world/camera/shadows unstable; OFF_B recovers or clearly changes again.

Next: bisect T1 renderer-state restore inside x86 only. No PosePair/K/submission work.

### R1_FULL_RATE_ONLY_BAD
OFF_A + SPARSE stable; FULL becomes unstable.

Next: replay scheduling/cadence/cost ownership before submission.

### R1_REPLAY_VISUALLY_INERT
OFF_A, SPARSE, FULL and OFF_B remain visually stable and hidden counters prove real replay execution.

Next authorized experiment becomes R2: expose already-rendered private L/R while preserving the game-owned v6 world contract. Still no host-driven PosePair/K/HEAD/weapon policy.

## FORBIDDEN INTERPRETATION

A static PASS or hidden mechanical replay PASS is not a visual PASS.
Only the user's phase-by-phase headset verdict closes R1.
