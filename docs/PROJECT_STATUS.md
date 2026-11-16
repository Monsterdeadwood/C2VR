# Crysis 2: VRevamp — project status

[← Project page](../README.md) · [Flat2VR testing & discussion](https://discord.gg/P4q9zt7ek)

Reviewed **14 November 2026**. Documented branch: **R8.2 campaign preview / R18 Rooftop Arsenal**.

## What has been checked

- The main HUD changes and supported retail/EA startup paths were checked in the actual game with XR Sim.
- R8.2 exercised the reported Battery Park transition with the supplied EA executable and DX11 renderer; retail startup with FSR was also checked.

## Follow-up tests reviewed 16 November 2026

The hand-ownership prototype used XR Sim packets and original game items. It exercised both pull/take directions, direct handoff, holster draw/stow, native support grip and two independently fired items. It uses button reloads. Recorded trigger cues cover the prototype route. Original host correlation and physical headset feel remain open. The campaign and Rooftop packages have their own handling and controls.

Verification records used for this section

- `C2VR_HANDS_BODY_HAPTICS_R5_20261115.json`

## Current limits

- This targets original Crysis 2; Crysis 2 Remastered is outside this package’s support.
- Physical-headset comfort, the Battery Park headset retest and full campaign coverage remain open.

## Separate experimental work

- R18 adds fitted sights, supporting-hand grip, supported manual magazine handling and a DSG1 4×/10× scope test on the rooftop. Its retail-game checks used XR Sim; physical comfort and Steam launch still need feedback.
- A separate independent weather experiment drives native time-of-day, sky, rain and wind controls. It is outside both documented test packages.

## Build access

Ask for the current complete test package in the game’s Flat2VR thread. A local build record does not by itself mean a file has been uploaded to this repository’s Releases.

## Documentation basis

This overview was reconciled against the project’s recorded package notes and validation records. The following names identify the records reviewed; they are not download links:

- `C2VR_OPENXR_PROPHET_FIX_20261112_R8_2/README_EN.txt`
- `C2VR_ROOFTOP_ARSENAL_R18/README_EN.txt`
- `C2VR_ROOFTOP_ARSENAL_R18/CONTROLS_EN.txt`
- `HUD_SOFT_R8_QUALIFICATION.json`
- `C2VR_INDEPENDENT_WEATHER_20261114.json`

Game execution, simulator validation and physical-headset feedback are reported separately above. Features from a separate experimental branch are identified explicitly.
