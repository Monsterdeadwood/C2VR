# C2VR A1 `173053` binding correction — 2026-08-25

## PRECEDENCE

This correction supersedes any older ledger/state wording that classifies
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`
as a user-positive camera/world visual checkpoint.

## EXACT PHYSICAL IDENTITY

Package:
`CRYSIS2VR_A1_NATIVE_REPAIR_v5.0.0.zip`

SHA256:
`1A361450ED9806CF8B25CDC90CC8DC37D946578A71484A6B6D47DFA066D21DE3`

Raw result:
`CRYSIS2VR_A1_NATIVE_REPAIR_RESULT_20260817_173053.zip`

SHA256:
`B54502DFF5C6E953353605615166AD7B3A3475F7B802E3F476A10D225E6234ED`

Exact runner exists inside the package:
`RUN_C2VR_A1_NATIVE_REPAIR_v5.0.0.bat -> tools/Run-C2VR5.ps1`.

## RAW RESULT VERDICT

`C2VR5_VERDICT.txt` proves:
- `InProcessA1Architecture=FAIL`
- `OpenXRSessionAndSubmit=FAIL submits=0`
- `Head6DoFBeforeRenderWorld=FAIL count=0`
- `NativeEyeCameraOverride=FAIL L/R=0/0`
- `DirectNativeEyeToXR=FAIL engineL/R=0/0`
- `PRIMARY_RESULT=PIPELINE_NOT_FULLY_ACTIVE`

`PROCESS_EXIT.txt` records process exit `0xC0000005`.

Restore completed successfully, but the VR experiment itself did not execute far enough to establish a headset camera/world property.

Architecture reason recovered from the historical discussion:
v5.0.0 regressed to trying OpenXR inside x86 `Crysis2.exe`, the already-known dead path that had previously motivated the x86-game + x64-host split.

## USER-VERDICT BINDING CORRECTION

Immediately after this result, the user said in substance that **before this** the project had already reached a state where left/right head movement changed the camera and only flicker/two-screen behavior remained.

The key phrase is retrospective: `до этого мы уже дошли`.

Therefore that positive camera/world statement must NOT be bound to `173053`.

Correct classification for `173053`:

`NOT_VALID_VISUAL_BASELINE`
`RUNTIME_RED: PIPELINE_NOT_FULLY_ACTIVE`
`RESTORE_PASS`

Do not use `173053` as a visual parent or as proof that v5.0.0 had working HMD camera ownership.

## FOLLOW-UP v5.1.0 ALSO NOT A VISUAL PARENT

Package:
`CRYSIS2VR_A1_GOLD_HISTORY_SPLIT_v5.1.0.zip`
SHA256 `BD50EABC3AE2F75139B5DADFF309D92848E3090DE843138F37581994587A3797`.

Raw result:
`CRYSIS2VR_A1_HISTORY_FIX_RESULT_20260817_175934.zip`
SHA256 `BE4E54FCBA854A137B1E96287188EA3ECAC0A72580FFF2211FBC645FE1C4D98A`.

This run did execute the x64 OpenXR path and produced live counters, but the direct user verdict rejected the surrounding renderer as the same bad two-image flickering Nvidia/Cry stereo and explicitly requested that architecture be discarded.

Keep only narrow component evidence such as controller-directed firing where independently supported.

Classification:
`VISUAL_RED: SURROUNDING_NATIVE/NVIDIA_STEREO`
`COMPONENT_ONLY: NARROW DONORS`

## CURRENT NEXT IS UNCHANGED

This correction does not invalidate the prepared current experiment:
`CRYSIS2VR_V601_HIDDEN_T1_R1_v1.0.0_ONECLICK.zip`.

R1 is based on the independently recovered v6.0.1 world-stability property plus hidden T1 replay, not on A1 `173053`.

Current gate remains:
`VISUAL BASELINE RECOVERY / CAMERA-WORLD OWNERSHIP BISECT`.
