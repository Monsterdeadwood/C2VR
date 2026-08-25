# Crysis 2 VR — NEXT

## CURRENT GATE

`220427 V6.0.1 LIVE -> BIND USER HEADSET VERDICT`

The exact Z-reprojection v6.0.1 PRIVATE_RTV recovery has now executed. Do not rerun it merely because older STATE/NEXT text called it the next runtime.

Read first:
1. `docs/LATEST_OVERRIDE_20260825_V601_220427_LIVE.md`
2. `experiments/Z_REPROJECTION_V601_RESULT_20260825_220427.md`
3. `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`
4. `docs/VISUAL_BASELINE_RECOVERY_MATRIX.md`
5. `docs/FALSIFIED.md`

## LATEST RESULT

`CRYSIS2VR_Z_REPROJECTION_RESULT_20260825_220427.zip`

SHA256:
`483D8B2E96E4BFF766CE7252D888A629738896233D20683CF7DD08CDDB8E92A4`

Mechanical result:
- XR session ran;
- 4691 submits;
- private eye staging active;
- 9382 eye-stage copies;
- 9382 depth-reprojection draws;
- 33 XR pair captures;
- raw restore PASS.

This closes the narrow old `XR_RTV_CREATE_FAIL` blocker.

## IMPORTANT LIMIT

The fresh output is synthetic stereo from one center color+depth source, not true independent L/R scene rendering.

Therefore:

```text
PRIVATE_RTV_XR_BRIDGE          = KEEP / MECHANICAL_GREEN
MONO_DEPTH_SYNTHETIC_LR_OUTPUT = MECHANICAL_GREEN
FINAL_RENDERER                 = NOT PROVEN
USER_HEADSET_VERDICT           = UNBOUND
```

Do not turn a transport success into a visual-GOLD claim.

## ANALYZER NOTE

Generated `Z_REPROJECTION_VERDICT.txt` contains false-negative summary fields for XR transport, eye-stage copies and restore. Raw logs/status are authoritative for those executed facts.

Analyzer repair is a later isolated tooling task, not a reason to rerun or redesign the renderer now.

## NEXT ACTION

Bind the direct headset verdict for the already executed 220427 run.

Needed visual fields:

```text
WORLD_STABILITY       = ?
CAMERA_WORLD_LOCK     = ?
BINOCULAR_FUSION      = ?
WORLD_SCALE           = ?
SHADOW_LIGHT_STABLE   = ?
RIGHT_EYE_QUALITY     = ?
WEAPON_VISIBLE_STATE  = ?
USER_HEADSET_VERDICT  = ACCEPT / RED
```

No new code is required to answer this gate.

## DECISION TREE

### If ACCEPT

Freeze 220427 as a component visual/control baseline and preserve the proven private-RTV XR bridge unchanged.

Next scientific gate:
`TRUE L/R SOURCE GEOMETRY WITHOUT LOSING ACCEPTED WORLD/CAMERA OUTPUT`.

That future child must be one mutation category only. It must not simultaneously rewrite HEAD, weapon, NEAR, temporal, shadow and cadence.

### If RED

Mark v6.0.1 whole visual parent `VISUAL_RED`.

Keep only:
`PRIVATE_RTV_XR_BRIDGE`.

Then continue exact archival recovery of the historical user-accepted single-window behavior profile rather than tuning Z-reprojection or resurrecting rejected parents.

## DO NOT DO NOW

- no GOODLINE descendant;
- no R2/T1 visible descendant;
- no v17 whole-build descendant;
- no K/PosePair;
- no later Z v6.1/v6.2/v6.3/v6.4 jump;
- no arbitrary IPD/FOV/convergence tuning;
- no weapon/NEAR merge;
- no temporal/shadow mutation;
- no broad reverse.

One executed LIVE is already on the table. Bind what the user actually saw before touching the machine again.
