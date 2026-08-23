#!/usr/bin/env python3
"""Recover exact CUSTOM_DUAL_T1 v1.0.1 source from its original package.

Canonical source carrier:
  CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip

Usage:
  python tools/extract_verified_custom_dual_t1_v1_0_1.py \
      CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1_HOSTFIX.zip \
      runtime/main/CUSTOM_DUAL_T1_v1.0.1/recovered

No output is promoted until all 20 original package-manifest entries pass SHA-256.
"""

from __future__ import annotations

import hashlib
import os
import re
import shutil
import sys
import tempfile
import zipfile
from pathlib import Path, PurePosixPath

PACKAGE_DIR = "CRYSIS2VR_CUSTOM_DUAL_RENDER_TEST_T1_v1.0.1"
MANIFEST = "PACKAGE_FILES_SHA256.txt"
EXPECTED_ROWS = 20
ROW_RE = re.compile(r"^([0-9A-Fa-f]{64})\s{2}(.+)$")


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest().upper()


def find_root(names: list[str]) -> str:
    target = f"{PACKAGE_DIR}/{MANIFEST}"
    hits = [n for n in names if n == target or n.endswith("/" + target)]
    if len(hits) != 1:
        raise RuntimeError(f"expected one {target}, found {len(hits)}")
    return hits[0][: -len(MANIFEST)]


def parse_manifest(data: bytes) -> list[tuple[str, str]]:
    text = data.decode("utf-8-sig")
    rows: list[tuple[str, str]] = []
    seen: set[str] = set()
    for raw in text.splitlines():
        line = raw.strip()
        if not line:
            continue
        m = ROW_RE.match(line)
        if not m:
            raise RuntimeError(f"malformed manifest row: {raw!r}")
        expected = m.group(1).upper()
        rel = m.group(2).replace("\\", "/")
        pure = PurePosixPath(rel)
        if pure.is_absolute() or ".." in pure.parts:
            raise RuntimeError(f"unsafe manifest path: {rel}")
        if rel in seen:
            raise RuntimeError(f"duplicate manifest path: {rel}")
        seen.add(rel)
        rows.append((rel, expected))
    if len(rows) != EXPECTED_ROWS:
        raise RuntimeError(
            f"manifest row-count mismatch: expected {EXPECTED_ROWS}, got {len(rows)}"
        )
    return rows


def verify(
    zf: zipfile.ZipFile, root: str, rows: list[tuple[str, str]]
) -> list[tuple[str, str, bytes]]:
    names = set(zf.namelist())
    verified: list[tuple[str, str, bytes]] = []
    errors: list[str] = []
    for rel, expected in rows:
        member = root + rel
        if member not in names:
            errors.append(f"MISSING {rel}")
            continue
        data = zf.read(member)
        actual = sha256(data)
        if actual != expected:
            errors.append(f"HASH_FAIL {rel} expected={expected} actual={actual}")
            continue
        verified.append((rel, expected, data))
        print(f"PASS  {expected}  {len(data):8d}  {rel}")
    if errors:
        raise RuntimeError("verification failed:\n  " + "\n  ".join(errors))
    if len(verified) != EXPECTED_ROWS:
        raise RuntimeError(f"verified count mismatch: {len(verified)}")
    return verified


def promote(files: list[tuple[str, str, bytes]], output: Path) -> None:
    parent = output.parent.resolve()
    parent.mkdir(parents=True, exist_ok=True)
    stage = Path(tempfile.mkdtemp(prefix="c2vr_t1_v101_", dir=str(parent)))
    try:
        for rel, _expected, data in files:
            dst = stage / Path(*PurePosixPath(rel).parts)
            dst.parent.mkdir(parents=True, exist_ok=True)
            dst.write_bytes(data)
        for rel, expected, _data in files:
            staged = stage / Path(*PurePosixPath(rel).parts)
            if sha256(staged.read_bytes()) != expected:
                raise RuntimeError(f"staged hash mismatch: {rel}")
        if output.exists():
            if not output.is_dir():
                raise RuntimeError(f"output exists and is not a directory: {output}")
            shutil.rmtree(output)
        os.replace(stage, output)
    except Exception:
        shutil.rmtree(stage, ignore_errors=True)
        raise


def main() -> int:
    if len(sys.argv) != 3:
        print(f"usage: {Path(sys.argv[0]).name} <T1-v1.0.1.zip> <output-dir>", file=sys.stderr)
        return 2
    archive = Path(sys.argv[1])
    output = Path(sys.argv[2])
    if not archive.is_file():
        print(f"archive not found: {archive}", file=sys.stderr)
        return 3
    try:
        archive_hash = sha256(archive.read_bytes())
        with zipfile.ZipFile(archive, "r") as zf:
            bad = zf.testzip()
            if bad:
                raise RuntimeError(f"ZIP CRC failure: {bad}")
            root = find_root(zf.namelist())
            rows = parse_manifest(zf.read(root + MANIFEST))
            files = verify(zf, root, rows)
        promote(files, output)
        print()
        print(f"ARCHIVE_SHA256={archive_hash}")
        print(f"SOURCE_PACKAGE_VERIFIED={len(files)}/{EXPECTED_ROWS}")
        print(f"OUTPUT={output.resolve()}")
        return 0
    except (OSError, UnicodeDecodeError, zipfile.BadZipFile, RuntimeError) as exc:
        print(f"FAIL: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
