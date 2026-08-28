#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime as dt
import json
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
REQUIRED_PREFLIGHT = ["MISSING FACT:", "WHY NOT COLD:", "PASS:", "FAIL:", "BASELINE MUST HOLD:"]
EXPERIMENT_CODE_SUFFIXES = {".bat", ".cmd", ".ps1", ".py", ".c", ".cc", ".cpp", ".h", ".hpp", ".zig"}


def fail(msg, errors):
    errors.append(msg); print(f"ERROR: {msg}")


def warn(msg):
    print(f"WARN: {msg}")


def read_text(path):
    return path.read_text(encoding="utf-8", errors="replace")


def extract_date(text):
    m = re.search(r"(?<!\d)(20\d{2})[-_/](\d{2})[-_/](\d{2})(?!\d)", text) or re.search(r"(?<!\d)(20\d{2})(\d{2})(\d{2})(?!\d)", text)
    if not m: return None
    try: return dt.date(int(m.group(1)), int(m.group(2)), int(m.group(3)))
    except ValueError: return None


def git_changed_files(base):
    if not base or not re.fullmatch(r"[0-9a-fA-F]{7,40}", base) or set(base) == {"0"}: return []
    try:
        out = subprocess.check_output(["git", "diff", "--name-status", f"{base}...HEAD"], cwd=ROOT, text=True, stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        warn("could not compute changed files: " + e.output.strip()); return []
    rows=[]
    for line in out.splitlines():
        parts=line.split("\t")
        if len(parts)>=2: rows.append((parts[0], parts[-1]))
    return rows


def validate_preflight_file(path, errors):
    if not path.exists(): fail(f"new/changed LIVE-capable experiment lacks {path.relative_to(ROOT)}", errors); return
    lines=[ln.strip() for ln in read_text(path).splitlines() if ln.strip()]
    if len(lines)!=5: fail(f"{path.relative_to(ROOT)} must contain exactly 5 non-empty lines", errors); return
    for got,prefix in zip(lines, REQUIRED_PREFLIGHT):
        if not got.startswith(prefix) or not got[len(prefix):].strip(): fail(f"{path.relative_to(ROOT)} line must be non-empty and start with '{prefix}'", errors)


def main():
    ap=argparse.ArgumentParser(); ap.add_argument("--base", default=os.getenv("BASE_SHA")); args=ap.parse_args(); errors=[]
    contract_path=ROOT/"RESEARCH_CONTRACT.yaml"
    if not contract_path.exists(): fail("RESEARCH_CONTRACT.yaml missing", errors); return 1
    try: contract=json.loads(read_text(contract_path))
    except Exception as exc: fail(f"RESEARCH_CONTRACT.yaml must be JSON-compatible YAML: {exc}", errors); return 1
    if contract.get("schema_version")!=1: fail("unsupported schema_version; expected 1", errors)
    state_rel=contract.get("canonical_state")
    if not state_rel: fail("canonical_state is not declared", errors); return 1
    state_path=ROOT/state_rel
    if not state_path.exists(): fail(f"canonical state missing: {state_rel}", errors); return 1
    state=read_text(state_path); state_date=extract_date("\n".join(state.splitlines()[:120]))
    workflow_rel=contract.get("workflow")
    if workflow_rel and not (ROOT/workflow_rel).exists(): fail(f"workflow document missing: {workflow_rel}", errors)
    gate_anchor=contract.get("active_gate_anchor")
    if gate_anchor and gate_anchor.casefold() not in state.casefold(): fail(f"active gate anchor not found in {state_rel}: {gate_anchor}", errors)
    baseline_anchor=contract.get("protected_baseline_anchor")
    if baseline_anchor and baseline_anchor.casefold() not in state.casefold(): fail(f"protected baseline anchor not found in {state_rel}: {baseline_anchor}", errors)
    pending=set(contract.get("pending_evidence_refs", []))
    for rel in sorted(pending):
        if not (ROOT/rel).exists(): fail(f"pending evidence path missing: {rel}", errors)
    latest=None
    for pattern in contract.get("evidence_globs", []):
        for p in ROOT.glob(pattern):
            if not p.is_file(): continue
            d=extract_date(p.name) or extract_date("\n".join(read_text(p).splitlines()[:40]))
            if d and (latest is None or d>latest[0]): latest=(d,p)
    if latest and state_date and latest[0]>state_date:
        rel=latest[1].relative_to(ROOT).as_posix(); name=latest[1].name
        referenced=rel.casefold() in state.casefold() or name.casefold() in state.casefold()
        if not referenced:
            if rel in pending: warn(f"STATE_PENDING: {rel} is newer than canonical state and is explicitly queued for convergence")
            else: fail(f"STATE_STALE: newest dated evidence {rel} ({latest[0]}) is newer than canonical state snapshot ({state_date}) and is neither referenced nor declared pending", errors)
    for rel in contract.get("required_evidence_refs", []):
        p=ROOT/rel
        if not p.exists(): fail(f"required evidence path missing: {rel}", errors)
        elif rel.casefold() not in state.casefold() and p.name.casefold() not in state.casefold(): fail(f"canonical state does not reference required evidence: {rel}", errors)
    changed=git_changed_files(args.base); live_dirs=set()
    for _,rel in changed:
        p=Path(rel)
        if not p.parts or p.parts[0].lower()!="experiments" or p.suffix.lower() not in EXPERIMENT_CODE_SUFFIXES or "cold" in p.as_posix().casefold(): continue
        if len(p.parts)>=2: live_dirs.add(ROOT/p.parts[0]/p.parts[1])
    for exp_dir in sorted(live_dirs): validate_preflight_file(exp_dir/"PREFLIGHT_5_LINES.txt", errors)
    if live_dirs and pending and contract.get("block_live_when_pending", True): fail("LIVE_BLOCKED_BY_PENDING_EVIDENCE: converge or explicitly clear pending evidence before adding/changing LIVE-capable experiment code", errors)
    print(); print(f"PROJECT={contract.get('project','UNKNOWN')}"); print(f"CANONICAL_STATE={state_rel}"); print(f"STATE_DATE={state_date or 'UNKNOWN'}")
    if latest: print(f"LATEST_DATED_EVIDENCE={latest[1].relative_to(ROOT).as_posix()}@{latest[0]}")
    print(f"PENDING_EVIDENCE={len(pending)}"); print(f"CHANGED_FILES={len(changed)}"); print(f"LIVE_EXPERIMENT_DIRS_CHECKED={len(live_dirs)}"); print(f"ERRORS={len(errors)}"); print("VERDICT="+("PASS" if not errors else "FAIL"))
    return 0 if not errors else 1


if __name__=="__main__": raise SystemExit(main())
