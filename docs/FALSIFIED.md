# Crysis 2 VR — FALSIFIED / STOPPED PATHS

Do not repeat these without new independent evidence.

## USER VISUAL HARD-RED GUARD

These stops are bound to recovered user headset verdicts, not only engineering inference. See `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md` and `docs/HISTORICAL_VISUAL_ORACLES_20260815_19.md` for chronology, evidence, and salvage checkpoints.

- **`CRYSIS2VR_CUSTOM_DUAL_T1_v1.0.2_POSEPAIR_ONLY_K0_ONECLICK.zip` as a visual parent** — HARD STOP. SHA256 `7A2F3B832A36D58DB66325B635896D485F78943CD8958D76FE6893ECBB8AD1B1`. User ran it on 2026-08-25 and reported it visually even worse than the already-rejected predecessor. No K=1/K=2/HEAD/weapon/temporal/shadow descendants from this package.
- **`C2VR_RC33_V1721_RESULT_20260825_063149.zip` lineage as a visual parent** — HARD STOP. Pair transport was alive but the user reported catastrophic camera/world instability and light/shadow motion. Do not convert counter PASS into visual PASS.
- **Native/NVIDIA/monitor-stereo as the final Crysis 2 VR renderer** — HARD STOP. User explicitly rejected this direction after repeated flashes/flicker. It remains archaeology/control evidence only.
- **Native stereo + real Quest IPD/XrView FOV as a final shortcut** — HARD STOP. `205430` user verdict: wrong stereo, flicker, shadows disappearing/changing. Saved L/R evidence showed lighting/shadow and near-geometry disagreement. Do not assume culling-only repair makes shared deferred/screen-space state binocularly correct.
- **STABLE_CAMERA v2.2.0 as proof that simplifying to one world-camera owner fixes the renderer** — FALSIFIED visually. `010329` still flickered badly; weapon motion did not establish real firing ownership.
- **All-SetCamera HMD injection** — HARD STOP with direct runtime/user evidence from `171947`: eyes collapsed toward equality and the camera accumulated the same HMD transform recursively. Keep only the single-upstream-owner lesson.
- **`CRYSIS2VR_REWRITE_v4.0.0_EXACT_XR_STEREO_GOLD_WEAPON_PORTABLE.zip` as visual GOLD** — HARD STOP. Result `CRYSIS2VR_BLACKBOX_ENGINE_TAP_RESULT_20260817_023510.zip` received immediate user rejection: image still wrong and hand rotation visibly broken. The `GOLD_WEAPON` filename is not evidence.
- **`A1_HISTORY_FIX_RESULT_20260817_175934` surrounding renderer as a parent** — HARD STOP. User explicitly said the only useful part was the crooked controller weapon that fired along weapon direction; the Nvidia/CryEngine two-image flickering renderer must be discarded. Preserve weapon-direction behavior only as a narrow donor.
- **v11/v12 telescope/binocular renderer family as a visual baseline** — HARD STOP. Recovered 2026-08-19 user verdicts explicitly reject the binocular/telescope geometry and severe misalignment. Exact individual package binding remains incomplete, so do not guess which neighboring v11/v12 ZIP is acceptable; recover exact identity first.
- **`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.2.zip` as a visual parent** — HARD STOP. Package SHA256 `A8BC46D31EE4A9FB9D34909D0EE5863CDA740A3710914D028C66974977A12F7F`; user reported completely black headset output. High-level DualWorld duplication is not a preferred final scheduler.
- **`CRYSIS2VR_DUALWORLD_CLEANROOM_v14.0.3_LAZY_GATE_HOTFIX.zip` as a visual parent** — HARD STOP. User again reported OpenXR startup signaling followed by completely black headset output. Do not keep patching a black-headset lineage forward; revert to a visible baseline first.
- **A package name containing `GOLD`, `CLEAN`, `MAIN`, `NO_BINOCULAR`, or a technically authoritative source label as sufficient visual-parent evidence** — REJECTED. User headset verdict and captures outrank naming and counters.
- **Guessing a package identity for an old user visual failure when the exact result/package was not recovered** — STOP. Preserve it as `UNBOUND_VISUAL_RED` or family-bound evidence until exact identity is recovered.

## EARLY / SEMANTIC FAILURES THAT MUST NEVER RETURN

- **Mouse-look / SendInput as VR HEAD camera** — FALSIFIED as final solution. It has no true roll/6DoF and mixes HMD with body/game aim. Early MVP use is bring-up evidence only.
- **Black headset + moving/working monitor as VR camera proof** — FALSIFIED. `C2VR_NATIVE_MVP_v0.1.2` proved host/session/pose/injection bring-up while the headset was black. Visible headset output is an independent gate.
- **Two eye textures / two images as VR acceptance** — FALSIFIED. Early user verdict: “two screens in two eyes”; horizon did not remain world-locked. Non-duplicate eye images are not enough.
- **Submitting current HMD pose for pixels not rendered from current HMD pose** — HARD STOP. Early v1.0.4 produced a flat/screen-glued image while Crysis camera was not HMD-driven but OpenXR projection-view pose used current HMD pose. Pixels + render pose + FOV + ticket must stay atomic.
- **Old pixels relabelled with a new/current pose** — FALSIFIED generally. If last-good fallback is used, the pixels retain the exact pose/FOV/metadata that rendered them.
- **One fresh eye + one stale eye** — FALSIFIED as a valid stereo submission policy.
- **Present as authoritative eye owner** — FALSIFIED. Historical no-Cry-stereo temporal work scheduled logical eye renders but Present did not preserve eye identity 1:1 (`417/417` planned versus `396/264` captured in one control). Do not classify rendered eye from a global/main-thread flag and expect Present to preserve it.
- **Global/main-thread active-eye variable as `FOB_NEAREST` owner** — FALSIFIED. Render-thread owner truth showed the old near-left/right asymmetry was a cross-thread classification artifact. Use a render-thread-local/transaction-bound identity if this seam is revisited.
- **Treating `near_left=55 / near_right=6634` as real eye asymmetry** — FALSIFIED by `FOB_NEAREST OWNER TRUTH`; balanced ownership was later measured around `5148/5161` with the same dominant caller `+0x000FF456`.
- **Calling `FOB_NEAREST OWNER TRUTH` visually successful** — FORBIDDEN. Owner/timing evidence is KEEP; user judged the visual result completely wrong/broken.
- **Calling `NATIVE_NEAR_PASSTHROUGH` a visual baseline because numeric reverse-control checks passed** — FORBIDDEN. It is a causal reverse-control only.
- **Unsafe `CopyResource/Flush` from the old RC callback path** — HARD STOP. `181936` reached a first pair, then crashed `0xC0000005` after RC copy #3 and copied near-black data. Route reachability is not thread/context safety.
- **Eye-axis dot + asymmetric-FOV numeric match as binocular-fusion proof** — REJECTED. A later `NO_BINOCULAR`-style path could make those metrics effectively exact while historical binocular/telescope complaints were not thereby globally closed. Headset fusion remains mandatory.
- **Downstream GPU/constant-buffer camera mutation as final gameplay-camera ownership** — STOP. It is useful as a verifier/causal probe, but CPU-side culling, shadows, sky, NEAR/viewmodel, and gameplay systems may already have consumed a different camera upstream.

## RENDER / SCHEDULING DEAD ENDS

- **Rebuild stereo from scratch** — STOP. `CUSTOM_DUAL_T1 v1.0.1` already proves true private L/R retail rendering. This is a technical primitive, not automatic visual-parent approval.
- **Second top-level `RenderWorld` / second `EF_StartEf`** — forbidden. One prepared render-list executes twice.
- **Apply HMD transform at every `Renderer::SetCamera`** — FALSIFIED by cumulative feedback (`G -> G*HMD -> G*HMD^2 ...`).
- **Fake/partial CCamera as authoritative camera object** — unsafe; earlier partial shadow broke native stereo semantics. Use a real full CCamera or a fully verified shadow with exact lifetime/layout.
- **Standalone `RC_SetCamera` mutation as final eye ownership** — rejected because later RT-side state can supersede it.
- **Native Cry SBS / DisplayStereo / CopyToStereo as final VR transport** — rejected.
- **Mono RGB+depth/Z reprojection as final renderer** — visually and architecturally FALSIFIED; v15 late-sink line is not the shipping path.
- **High-level duplicate DualWorld as preferred final scheduler** — STOP. Historical v14 black-headset runs and later renderer closure favor one prepared scene/list with private eye executions rather than two unrelated high-level worlds.
- **`camera-0x3E8 == CSystem`** — FALSIFIED.
- **GPU constant-buffer hits as gameplay detector** — rejected.
- **Counters alone as visual proof** — rejected.
- **`SHDF_ZPASS_ONLY` as normal RIGHT-eye shadow policy** — rejected because it suppresses normal scene body too.
- **Wholesale v17.2 integration** — STOP. It mixes PosePair, HEAD/culling, weapon/NEAR, temporal and shadow mutations and destroys causal attribution.
- **Treating raw Present as logical game frame** — FALSIFIED by cadence evidence (~18901 Present vs ~1880 RenderWorld vs ~1241 successful producer frames in historical harvest).
- **P3 latest-pair stale submit / stale relabel** — FALSIFIED. It produced live output but `1738` pair-contract/pose mismatches and severe jitter/blur/one-eye asymmetry. Never relabel a stale pair as the current XR contract.

## CAMERA / WEAPON / TEMPORAL STOPS

- **Universal `OpenXR +X -> Cry -X` rule as settled global truth** — STOP. Historical `003329` supports it locally, but retail/static and later v10 evidence conflict with that interpretation.
- **Universal `OpenXR +X -> Cry +X` rule as settled global truth** — also STOP until the `003329` conflict is closed. Do not silently promote either sign.
- **Random weapon XYZ/muzzle offset grids before rigid-transform closure** — STOP. They confound pivot, basis and ownership.
- **Head position as weapon rotation pivot** — STOP for final weapon math. Historical v7 object transform rotated around head position and mixes poorly with camera-space `FOB_NEAREST` semantics.
- **Independent position and rotation correction as assumed final weapon SE(3)** — STOP. Current v17-style decomposition is a bug candidate because translation/pivot coupling is missing. Prefer one rigid bind transform.
- **Automatic squeeze/grip-edge rebaseline as default weapon policy** — STOP. It can create discontinuous weapon snaps; next weapon proof must use fixed bind except explicit recenter/equip/rebind.
- **AIM-vs-GRIP pose-family hunt** — STOP unless new evidence appears. AIM is canonical; GRIP is only a low-priority control.
- **Gameplay aim/ballistics work during visual weapon gate** — STOP. Historical controller-directed firing is preserved as a donor fact, but ballistics remains a later blocker.
- **Broad weapon reverse now** — STOP while visual baseline recovery is current gate.
- **Broad HEAD/camera archaeology now** — STOP while visual baseline recovery is current gate. Recover and reproduce the nearest user-positive camera/world-stability checkpoints first.
- **Temporal/shadow mutation now** — STOP until a stable visual baseline is recovered and later serial gates explicitly open it.
- **New broad symbol/corpus census for weapon functions** — STOP. When weapon gate opens, do a narrow `CryGameCrysis2.pdb/source -> retail` bridge for only `PostUpdateView`, `UpdateFPPosition`, `UpdateFPCharacter` (and ballistic symbols only if later required).
- **Repeating the old broad WAVE3 cadence gate instrumentation before visual baseline recovery** — STOP. Cadence K is no longer the next gate after the 2026-08-25 user HARD REDs.
- **Increasing wait beyond P6 after timeout starvation is closed** — STOP. A larger watchdog cannot repair a visually wrong camera/world renderer.
- **Full GPU fence / synchronous GPU wait as the first fix for persistent eye-RT overwrite** — STOP. Source review does not prove a canonical-path overwrite race; close publication ownership only if a future visually valid baseline reaches that blocker.
- **Double/triple-buffering or ring-buffering engine eye RTs before publication ownership is closed** — STOP. It expands renderer mutation surface and can mask the actual owner. See `research/POSEPAIR_PUBLICATION_OWNERSHIP_20260824.md`.

## IMPORTANT PARTIAL GREEN THAT MUST NOT BE LOST

`v6.0.1` behavior is a preserved component checkpoint:
- flicker gone;
- shadows/textures/objects stable;
- eyes still did not fuse.

This is `WORLD_STABILITY_NO_FLICKER_REFERENCE`, not final stereo.
Do not throw away this property when recovering a visual baseline.
The exact physical v6.0.1 carrier/hash remains an archival recovery task; do not invent it from the v6.0.2 descendant.

The 18–19 Aug user visual oracle also records a `last good native single-window branch` with:
- one window;
- native OpenXR dual eye;
- good world scale;
- stable head movement;
- visible headset image;
- only hand/weapon visibly wrong.

Its exact package/hash was already recorded as a blind zone at the time. Recover it before replacing the renderer again.

Historical resource `20500` / 320-byte per-view carrier work remains supporting archaeology, not authorization to restart broad GPU/resource searches.

Coordinate-basis conflict provenance is in `research/COORDINATE_BASIS_CONFLICT_20260824.md`.
Publication-ownership provenance is in `research/POSEPAIR_PUBLICATION_OWNERSHIP_20260824.md`.
User visual precedence and parent-selection policy are in `docs/USER_VISUAL_ACCEPTANCE_LEDGER.md`.
Historical reconstructed headset verdicts are in `docs/HISTORICAL_VISUAL_ORACLES_20260815_19.md`.
