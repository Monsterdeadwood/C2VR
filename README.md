> [!IMPORTANT]
> **[TEST BUILDS & DISCUSSION · FLAT2VR DISCORD](https://discord.gg/P4q9zt7ek)**
> Testing, build requests, feedback and discussion happen in the **Flat2VR Modding Discord**. Join the server and find the **Crysis 2 VR** thread.

![Crysis 2 VR — Monsterdeadwood VR mods](assets/vr-banner.svg)

# Crysis 2 VR

[English](README.md) · [Русский](README_RU.md) · [Flat2VR Discord](https://discord.gg/P4q9zt7ek) · [All projects](PORTFOLIO.md)

![Project status](assets/vr-status.svg)

Experience the original Crysis 2 in VR with tracked viewing, controller-directed weapons, physical melee and object interaction. The current community branch focuses on a readable HUD, spatial movie screens and reliable campaign transitions.

**Current documented branch: R8.2 community preview.**

## Installation

1. Get the current **Crysis 2 OpenXR** package in the Crysis 2 thread on Flat2VR. Use the **original PC game with its supported DX11 renderer**.
2. Extract the complete mod folder into the game directory, beside **bin32**.
3. Connect PC VR and select your OpenXR runtime, then open **RUN.bat** inside the mod folder.
4. Choose New Campaign or Load Game in the normal menu. Keep the launcher open. If detection needs help, set game_path in config/settings.json.

Current test-package availability is coordinated in Discord. Use the complete package for your supported game build; this project page is separate from a release download.

## What this project brings to VR

- Stereo VR viewing, tracked weapons and the existing motion-controller gameplay.
- Physical melee and native object pulling, holding and throwing in the existing gameplay branch.
- A compact translucent HUD with subtle delayed motion and preserved binocular depth.
- A spatial movie screen you can look away from; tap Left Menu to recenter it.
- FSR 1 image scaling and startup fixes for the supported retail and reported EA renderer families.
- R8.2 addresses the reported Battery Park crash after the Prophet cinematic.

<details>
<summary><b>Controller quick reference</b></summary>

| Input | Action |
| --- | --- |
| Left Menu tap / hold | Recenter / pause after 0.65 seconds |
| Left stick in menus | Navigate |
| A / right trigger in menus | Confirm |
| B in menus | Back |
| CONTROLS_EN.txt in the package | Full gameplay action map |

The complete package control sheet takes precedence for its version and interaction profile.

</details>

## Current status

**Experimental preview.** The main HUD changes and supported retail/EA startup paths were checked in the actual game with XR Sim.

- This targets original Crysis 2; Crysis 2 Remastered is outside this package’s support.
- Physical-headset comfort, the Battery Park headset retest and full campaign coverage remain open.

Separate rooftop/loadout and independent weather branches are under development. The weather experiment drives native time-of-day, sky, rain and wind controls; it is separate from R8.2.

[Detailed status and validation scope](docs/PROJECT_STATUS.md)

## Testing & feedback

Post in the game’s [Flat2VR thread](https://discord.gg/P4q9zt7ek) with your **mod version, game/store version, headset, OpenXR runtime, GPU, reproduction steps and the package’s diagnostic ZIP**. A short video is helpful for visual or handling problems.

## Other VR mods by Monsterdeadwood

| Game / project | Focus | Visibility |
| --- | --- | --- |
| [Battlefield 3 VR](https://github.com/Monsterdeadwood/BF3VR) | Campaign, tracked weapons and hands | Private |
| [Assassin’s Creed VR](https://github.com/Monsterdeadwood/AC1VR) | First-person exploration, climbing and sword interaction | Private |
| [NOVA · CS:GO Legacy VR](https://github.com/Monsterdeadwood/CSGOVR) | CS:GO Legacy local matches with motion controls | Private |
| [TimeShift VR](https://github.com/Monsterdeadwood/TimeShiftVR) | Time powers, nine weapons and roomscale posture | Private |
| [You Are Empty: Absolute Edition VR](https://github.com/Monsterdeadwood/YouAreEmptyAEVR) | Absolute Edition VR, weapons and hand interaction | Public |
| [Alone in the Dark 2008 VR](https://github.com/Monsterdeadwood/AloneInTheDark2008VR) | Survival-horror VR and held-item interaction | Public |
| [Rainbow Six Siege VR](https://github.com/Monsterdeadwood/SiegeVR) | Legacy Siege stereo and tracked weapon handling | Public |
| [Burnout Paradise Remastered VR](https://github.com/Monsterdeadwood/BUrnOutPvr) | Stereo driving, vehicle menus and native effects | Private |
| [Titanfall 1 VR](https://github.com/Monsterdeadwood/Titanfall1VR) | Pilot combat and Titan cockpit VR | Private |
| [Metro 2033 VR](https://github.com/Monsterdeadwood/Metro2033VR) | Original Metro VR and native physics experiments | Public |
| [Insurgency VR](https://github.com/Monsterdeadwood/InsurgencyVR) | Early VR integration research | Private |
| [Counter-Strike: Source VR](https://github.com/Monsterdeadwood/CSSVR) | Counter-Strike: Source VR development | Private |

Private repository links are available to invited collaborators. Public project pages are marked above.

## Credits & development notes

Project maintained by [Monsterdeadwood](https://github.com/Monsterdeadwood). This is an independent fan VR project; you need your own supported copy of the original game.

[Previous repository overview, preserved as history](README_RESEARCH_ARCHIVE.md).

Documentation reviewed: **14 November 2026**.
