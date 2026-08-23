#!/usr/bin/env python3
"""Recover byte-exact C2VR v17.2.1 donor text files from the canonical master corpus.

Usage:
  python tools/extract_verified_v17_2_1.py \
      CRYSIS2VR_MASTER_CORPUS_ALL_EVIDENCE_20260821_100MB.md \
      runtime/donors/v17.2.1/recovered

The extractor admits a file only when BOTH recorded byte length and SHA-256 match.
It deliberately skips binary entries that were omitted from the Markdown corpus.
"""

from __future__ import annotations

import hashlib
import re
import sys
from pathlib import Path

PREFIX = "rc33_tool/CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.1_ARGV_FIX_ONECLICK/"

PATTERN = re.compile(
    r"## APPENDED SOURCE: `"
    + re.escape(PREFIX)
    + r"([^`]+)`\n\n"
      r"- bytes: (\d+)\n"
      r"- sha256: `([0-9A-Fa-f]{64})`\n\n"
      r"```(?:text|json|python|powershell|cpp|c|bat|cmd|md)?\n"
      r"(.*?)\n```",
    re.S,
)


def exact_bytes(body: str, expected_size: int, expected_sha: str) -> bytes | None:
    expected_sha = expected_sha.upper()
    for newline in ("\n", "\r\n"):
        for terminal_newline in (False, True):
            for bom in (False, True):
                s = body.replace("\n", newline)
                if terminal_newline:
                    s += newline
                data = s.encode("utf-8-sig" if bom else "utf-8")
                if len(data) != expected_size:
                    continue
                if hashlib.sha256(data).hexdigest().upper() == expected_sha:
                    return data
    return None


def main() -> int:
    if len(sys.argv) != 3:
        print(f"usage: {Path(sys.argv[0]).name} <master-corpus.md> <output-dir>", file=sys.stderr)
        return 2

    corpus = Path(sys.argv[1])
    out_root = Path(sys.argv[2])
    text = corpus.read_text(encoding="utf-8", errors="replace")

    found = 0
    written = 0
    failed: list[str] = []

    for match in PATTERN.finditer(text):
        found += 1
        rel = match.group(1)
        expected_size = int(match.group(2))
        expected_sha = match.group(3).upper()
        body = match.group(4)

        data = exact_bytes(body, expected_size, expected_sha)
        if data is None:
            failed.append(rel)
            print(f"FAIL  {rel}")
            continue

        dst = out_root / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_bytes(data)
        written += 1
        print(f"PASS  {expected_sha}  {expected_size:8d}  {rel}")

    print(f"\nfound={found} written={written} failed={len(failed)}")
    if failed:
        print("failed files:", file=sys.stderr)
        for rel in failed:
            print(f"  {rel}", file=sys.stderr)
        return 1
    if found == 0:
        print("no v17.2.1 embedded text sources found", file=sys.stderr)
        return 3
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
