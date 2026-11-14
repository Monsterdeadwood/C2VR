# Crysis 2 VR — project status

[← Project page](../README.md) · [Flat2VR testing & discussion](https://discord.gg/P4q9zt7ek)

Reviewed **14 November 2026**. Documented branch: **R8.2 community preview**.

## What has been checked

- The main HUD changes and supported retail/EA startup paths were checked in the actual game with XR Sim.
- R8.2 exercised the reported Battery Park transition with the supplied EA executable and DX11 renderer; retail startup with FSR was also checked.

## Current limits

- This targets original Crysis 2; Crysis 2 Remastered is outside this package’s support.
- Physical-headset comfort, the Battery Park headset retest and full campaign coverage remain open.

## Separate experimental work

- Separate rooftop/loadout and independent weather branches are under development. The weather experiment drives native time-of-day, sky, rain and wind controls; it is separate from R8.2.

## Build access

Ask for the current complete test package in the game’s Flat2VR thread. A local build record does not by itself mean a file has been uploaded to this repository’s Releases.

## Documentation basis

This overview was reconciled against the project’s recorded package notes and validation records. The following names identify the records reviewed; they are not download links:

- `C2VR_OPENXR_PROPHET_FIX_20261112_R8_2/README_EN.txt`
- `HUD_SOFT_R8_QUALIFICATION.json`
- `C2VR_INDEPENDENT_WEATHER_20261114.json`

Game execution, simulator validation and physical-headset feedback are reported separately above. Features from a separate experimental branch are identified explicitly.

## Кратко по-русски

Оригинальная Crysis 2 в VR: обзор шлемом, оружие от контроллеров, физический ближний бой и взаимодействие с предметами. Общественная ветка развивает читаемый HUD, пространственные экраны видео и переходы кампании.

- Эта сборка рассчитана на оригинальную Crysis 2; Remastered ею не поддерживается.
- Удобство в физическом шлеме, повтор перехода Battery Park в шлеме и вся кампания ещё требуют проверки.
