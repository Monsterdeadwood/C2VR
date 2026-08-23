#!/usr/bin/env python3
"""Verify the frozen C2VR P6 finalist representation.

CI mode:
    python tools/verify_c2vr_finalist_integrity.py

Full archive mode:
    python tools/verify_c2vr_finalist_integrity.py \
        CRYSIS2VR_RC33_TRUE_LR_WEAPON_v17.2.6_EXACT_BLOCK120_P6_ONECLICK.zip

CI proves repository metadata did not drift. Full archive mode additionally proves
that the physical package is the audited 42/42 P6 carrier.
"""

from __future__ import annotations

import hashlib
import re
import sys
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
P6 = ROOT / "runtime" / "finalists" / "v17.2.6_P6"
EXPECTED_ARCHIVE = "8385F6AAAD668E40058EB368E4593F53A3489CE7C24EFC19521C4C8DEB0ECA89"
# Correct canonical value, kept separately to make accidental typo obvious.
EXPECTED_ARCHIVE = "8385F6AAAD668E40058EB368E4593F53A3489CE7C24EF19521C4C8DEB0ECA89"
EXPECTED_ROWS = 42

EXPECTED_RUNTIME = {
    "src/exports.def": "1CC314940EDE7C74D57252B087F4F34D9397FCAE95A20F711AD88CDF7CAD6F1D",
    "src/t1_camera.cpp": "C71E6B52A6F326923A45E682392F79C96C84FFF1E1D66393769A821D9A5C42A1",
    "src/t1_dual_render.cpp": "397D0577D3F07B776A17395733AB6500BCD05C8928A51608CE3FDD8DEA415C77",
    "src/t1_game_api.h": "642AF56F086EE9EF8E674F495C2B610E9C38088FB0A2342B55CB0F53E2E52E02",
    "src/t1_host_x64.cpp": "EE58422BD20093D74F6165F528E38AE88D2BA6A613AAF20BEA8714D73E829E60",
    "src/t1_ipc.h": "DE00ABD099F5988BB930A6150FF16BA1A9E9AC1A55AE3EC5CC59DC7DEA54B931",
    "src/t1_proxy.cpp": "34097291EEC0C27F54D18ABC91FE34F94EC3CCF86F45C6F2FDA240ACCD570D60",
}

P5_HOST = "5CB608E35C83C1A06A084F23FA80D22B97A11663D31964DA01AE3E841FFDD14C"
ROW = re.compile(r"^([0-9A-Fa-f]{64})\s{2}(.+)$")


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest().upper()


def parse_manifest(text: str) -> dict[str, str]:
    out: dict[str, str] = {}
    for raw in text.splitlines():
        if not raw.strip():
            continue
        m = ROW.match(raw.strip())
        if not m:
            raise AssertionError(f"malformed manifest row: {raw!r}")
        digest = m.group(1).upper()
        rel = m.group(2).replace("\\", "/")
        if rel in out:
            raise AssertionError(f"duplicate manifest path: {rel}")
        out[rel] = digest
    return out


def verify_repo() -> dict[str, str]:
    readme = (P6 / "README.md").read_text(encoding="utf-8")
    manifest_text = (P6 / "PACKAGE_FILES_SHA256.txt").read_text(encoding="utf-8")
    preflight = (P6 / "PREFLIGHT.txt").read_text(encoding="utf-8")
    sync = (ROOT / "docs" / "SYNC.md").read_text(encoding="utf-8")

    assert EXPECTED_ARCHIVE in readme.upper(), "P6 archive SHA drift"
    assert "CURRENT UNTESTED LIVE FINALIST" in readme, "P6 status drift"
    assert P5_HOST in readme, "P5 parent host identity missing"

    rows = parse_manifest(manifest_text)
    assert len(rows) == EXPECTED_ROWS, f"manifest row count {len(rows)} != {EXPECTED_ROWS}"
    for rel, digest in EXPECTED_RUNTIME.items():
        assert rows.get(rel) == digest, f"runtime identity drift: {rel}"

    nonblank = [x.strip() for x in preflight.splitlines() if x.strip()]
    prefixes = [
        "MISSING FACT:",
        "WHY NOT COLD:",
        "PASS:",
        "FAIL:",
        "BASELINE MUST HOLD:",
    ]
    assert len(nonblank) == 5, f"PREFLIGHT must have exactly 5 nonblank lines, got {len(nonblank)}"
    for line, prefix in zip(nonblank, prefixes):
        assert line.startswith(prefix), f"PREFLIGHT order drift: expected {prefix}"

    assert "v17.2.6 EXACT_BLOCK120 P6" in sync, "P6 missing from STATE SYNC"
    assert "Run `v17.2.6 EXACT_BLOCK120 P6` unchanged." in sync, "NEXT gate drift"
    return rows


def verify_archive(path: Path, repo_rows: dict[str, str]) -> None:
    data = path.read_bytes()
    actual_archive = sha256(data)
    assert actual_archive == EXPECTED_ARCHIVE, (
        f"archive SHA mismatch: {actual_archive} != {EXPECTED_ARCHIVE}"
    )

    with zipfile.ZipFile(path, "r") as zf:
        bad = zf.testzip()
        assert bad is None, f"ZIP CRC failure: {bad}"
        names = zf.namelist()
        suffix = "/PACKAGE_FILES_SHA256.txt"
        hits = [n for n in names if n.endswith(suffix)]
        assert len(hits) == 1, f"expected one package manifest, got {len(hits)}"
        manifest_member = hits[0]
        root = manifest_member[: -len("PACKAGE_FILES_SHA256.txt")]
        package_rows = parse_manifest(zf.read(manifest_member).decode("utf-8-sig"))
        assert package_rows == repo_rows, "repository manifest differs from physical P6 manifest"
        for rel, expected in package_rows.items():
            member = root + rel
            assert member in names, f"missing archive member: {rel}"
            actual = sha256(zf.read(member))
            assert actual == expected, f"archive member hash mismatch: {rel}"

    print(f"P6_ARCHIVE_SHA256={actual_archive}")
    print(f"P6_PACKAGE_VERIFIED={len(repo_rows)}/{EXPECTED_ROWS}")


def main() -> int:
    try:
        rows = verify_repo()
        print(f"P6_REPO_MANIFEST={len(rows)}/{EXPECTED_ROWS} PASS")
        print("P6_NEXT_GATE=UNCHANGED PASS")
        if len(sys.argv) > 2:
            raise AssertionError("usage: verify_c2vr_finalist_integrity.py [P6.zip]")
        if len(sys.argv) == 2:
            archive = Path(sys.argv[1])
            assert archive.is_file(), f"archive not found: {archive}"
            verify_archive(archive, rows)
        return 0
    except (AssertionError, OSError, UnicodeDecodeError, zipfile.BadZipFile) as exc:
        print(f"FAIL: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
