# Crysis 2 VR State

## CURRENT GATE — 2026-08-25

`VISIBLE PRIVATE L/R / STEREO CAUSAL MATRIX`

This supersedes the older `VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT` next-action text while preserving its parent-selection laws.

Authoritative read order:
1. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
2. `docs/HISTORICAL_AUDIT_PASS2_20260825.md`
3. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
4. `docs/FALSIFIED.md`
5. `experiments/R2_V102_VALIDATOR_SYNC_PREPARED_20260825.md`
6. `experiments/NEXT_EXPERIMENT.md`
7. `docs/NEXT.md`

Evidence law remains:
- `RESULT ZIP != LIVE`;
- bare `GREEN` is forbidden;
- package names do not establish acceptance;
- `VACUOUS_PASS` is invalid;
- user headset verdict outranks counters for visual acceptance.

## CURRENT NEXT RUNTIME

`R2 PRIVATE L/R PHASE MATRIX v1.0.2 VALIDATOR_SYNC`

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.2_VALIDATOR_SYNC_ONECLICK.zip`

Bytes:
`205935`

SHA256:
`2F751F869FC4B4AB8110FA6C893A77EA5B849457BEC21451E1C313D342852242`

Status:
`PREPARED / UNRUN`.

Validation:
- R2 generic static `67/67 PASS`;
- inherited v1.0.1 guardfix `43/43 PASS`;
- package hash manifest `81/81 PASS`;
- ZIP CRC PASS.

Compared with v1.0.1, runtime sources, BAT, PowerShell runner, recovery, analyzer, IPC ABI and phase matrix are byte-identical. v1.0.2 changes only the generic validator and package metadata/hash records.

## R1 STATUS — DO NOT REPEAT

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_175757.zip`
SHA256 `E737A348BD60CC479CAC6284023F94D3542D8923D09C04E8D0D822D66810F9BD`.

Mechanical evidence:
- hidden replay pairs `824`;
- L/R eye execution `824/824`;
- temporal snapshot/restore `824/824`;
- temporal leak `0`;
- pose mismatch `0`;
- hidden publication/shared copy/OpenXR submit `0/0/0`.

Classification:
`LIVE / MECHANICAL PASS / VISIBLE TRUE STEREO NOT TESTED`.

No phase-by-phase user visual PASS is backfilled.

## R2 v1.0.0 — NOT LIVE

Result:
`CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260825_194014.zip`.

It stopped before x86 compile/game launch on a stale PowerShell source-sanity guard expecting:
`custom_vr_transport=MONO_BACKBUFFER_TO_TWO_OPENXR_EYES`.

R2 runtime phases never executed. No stereo conclusion.

## R2 v1.0.1 — GUARDFIX, SUPERSEDED AS RUN PACKAGE

Package:
`CRYSIS2VR_V601_PRIVATE_LR_R2_v1.0.1_GUARDFIX_ONECLICK.zip`
SHA256 `42B7CF4E23C794F52912961631BC402E1B9273DA41AA23A32FF11AE2293422EB`.

Its dedicated guardfix validation is valid `43/43 PASS`, but the inherited generic validator still expected the obsolete v1.0.0 PowerShell SHA and printed `66/67 FAIL` on the intentional guardfix runner.

Use v1.0.2 instead. Runtime behavior is identical.

## R2 PHASE MATRIX

```text
0–10 s   MONO_A
10–22 s  PRIVATE_ZERO
22–36 s  PRIVATE_IPD
36–52 s  PRIVATE_FULL
52–64 s  PRIVATE_SWAP
64–74 s  MONO_B
>74 s    DONE
```

Causal interpretation:
- `MONO_A` bad -> baseline invalid, later phases uninterpretable;
- ZERO first bad -> replay/private publication/state path;
- ZERO good, IPD first bad -> eye translation/camera geometry;
- IPD good, FULL first bad -> asymmetric per-eye FOV/projection;
- FULL bad, SWAP better -> L/R order/sign mapping;
- PRIVATE_FULL stable, fused and nonduplicate -> true private stereo candidate, pending explicit user acceptance;
- MONO_B recovery after a private-phase failure is strong causal evidence.

## PRESERVED RECOVERY ANCHORS

### v6.0.1 world stability
`CRYSIS2VR_CUSTOM_VR_OWNER_v6.0.1_NO_FLICKER_FUSIONLOCK_PORTABLE.zip`
SHA256 `E113BF37B0D8B8377F8A08C03739D530059A814274505478A980D8E8BA5BBA96`.

Historical bounded property:
- flicker gone;
- shadows/textures/objects stable;
- binocular fusion failed.

Classification:
`COMPONENT_VISUAL_GREEN: WORLD_STABILITY_NO_FLICKER`.

### Camera ownership reference
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip` and single-source `Crysis2.exe+0x0057AC76` topology remain component references only.

### True private L/R authority
`CUSTOM_DUAL_T1 v1.0.1 / CRYSIS2VR_CUSTOM_DUAL_T1_RESULT_20260819_212003.zip` remains `MECHANICAL_GREEN: TRUE_PRIVATE_LR_RENDERER`, not automatic visual-parent authority.

## CURRENT HARD REDS

Do not derive visual descendants from:
- `C2VR_RC33_V1721_RESULT_20260825_063149.zip`;
- `CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip` SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`.

Both remain user visual RED.

## HISTORICAL OPEN ITEMS

Remain OPEN/UNBOUND unless direct evidence is recovered:
1. exact package/hash behind the old last-good native single-window behavior profile;
2. direct user verdicts for Z v6.2/v6.3/v6.4;
3. direct adjacent primary user message for v10 `034749`;
4. direct user verdict for v7.0.2 `001036`;
5. direct user verdicts for v13/v13.1;
6. exact raw-result binding for v14 black-headset reports;
7. exact package binding inside v11/v12 telescope/binocular family.

## PARKED UNTIL R2 CLOSES

- PosePair/K;
- final HEAD rewrite;
- A1 camera merge;
- weapon/NEAR integration;
- new temporal/shadow policy;
- release optimization.

## RETAIL IDENTITY

- Crysis2.exe SHA256 `5D1FF6B52278F853CA32A2AA1553FA55B4AC143A5BB4A35A1468BD859572D6FE`
- CryRenderD3D11.dll SHA256 `06BCCA733475A48A6BA8532336829FE0D9935073808CE8B84622C4119938693F`
