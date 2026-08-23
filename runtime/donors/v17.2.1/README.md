# C2VR v17.2.1 — VERIFIED DONOR SOURCE

**DONOR ONLY. NOT THE MAIN BUILD.**

Main build remains `CUSTOM_DUAL_T1 v1.0.1`.

This directory contains byte-verified source recovered from the embedded package tree:
`CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.1_ARGV_FIX_ONECLICK`.

Recovery source:
`CRYSIS2VR_MASTER_CORPUS_ALL_EVIDENCE_20260821_100MB.md`.

Recovery rule:
- source block extracted from the corpus;
- original newline/BOM convention reconstructed where required;
- byte length verified;
- SHA-256 verified against the corpus metadata;
- only exact matches are admitted here.

## Why this donor exists
v17.2.1 mixes several future gates in one package: PosePair rendezvous, HEAD/culling, weapon/NEAR, temporal and shadow logic. Installing it wholesale would destroy causal attribution.

For the current G1 build, import **only** the PosePair contract/rendezvous pieces into `CUSTOM_DUAL_T1 v1.0.1`.

See:
- `POSEPAIR_TRANSPLANT.md`
- `SOURCE_SHA256.txt`
- `src/t1_ipc.h`
- `src/t1_host_x64.cpp`
- `src/t1_dual_render.cpp`

Do not treat runtime claims made by the donor as accepted main-build results unless independently promoted in `docs/PROVEN.md`.
