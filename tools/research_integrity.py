#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime as dt
import difflib
import json
import os
from pathlib import Path
import re
import subprocess
import urllib.error
import urllib.request

ROOT = Path(__file__).resolve().parents[1]
PREFLIGHT = ["MISSING FACT:", "WHY NOT COLD:", "PASS:", "FAIL:", "BASELINE MUST HOLD:"]
MUTATION_EXT = {".bat", ".cmd", ".ps1", ".py", ".c", ".cc", ".cpp", ".h", ".hpp", ".zig", ".ini", ".cfg", ".json", ".yaml", ".yml", ".toml"}
CLAIM_STATUSES = {"ACTIVE", "PENDING", "QUEUED", "PARKED", "PROVEN", "FALSIFIED", "SUPERSEDED"}
CLOSED_CLAIM_STATUSES = {"PROVEN", "FALSIFIED", "SUPERSEDED"}
EXPERIMENT_CLASSES = {"COLD", "PASSIVE_LIVE", "CAUSAL_LIVE", "BUILD_LIVE"}
LIVE_CLASSES = EXPERIMENT_CLASSES - {"COLD"}
STOP = {"the", "a", "an", "and", "or", "of", "to", "for", "in", "on", "at", "by", "with", "from", "current", "exact", "runtime", "project", "gate", "path", "vr", "result", "proof", "owner", "ownership"}

def fail(msg, errors): errors.append(msg); print("ERROR:", msg)
def warn(msg): print("WARN:", msg)
def read(path): return path.read_text(encoding="utf-8", errors="replace")
def load_json(path, label, errors):
    try: return json.loads(read(path))
    except Exception as exc: fail(f"{label} must be JSON-compatible: {exc}", errors); return None

def dateof(text):
    m = re.search(r"(?<!\d)(20\d{2})[-_/](\d{2})[-_/](\d{2})(?!\d)", text) or re.search(r"(?<!\d)(20\d{2})(\d{2})(\d{2})(?!\d)", text)
    if not m: return None
    try: return dt.date(*map(int, m.groups()))
    except ValueError: return None

def changed(base):
    if not base or not re.fullmatch(r"[0-9a-fA-F]{7,40}", base) or set(base) == {"0"}: return []
    try: out = subprocess.check_output(["git", "diff", "--name-status", f"{base}...HEAD"], cwd=ROOT, text=True, stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as exc: warn("git diff failed: " + exc.output.strip()); return []
    rows=[]
    for line in out.splitlines():
        parts=line.split("\t")
        if len(parts)>=2: rows.append((parts[0],parts[-1]))
    return rows

def norm(text): return " ".join(token for token in re.findall(r"[a-z0-9]+", str(text).casefold()) if len(token)>1 and token not in STOP)

def graph_check(contract, errors):
    rel=contract.get("claim_graph","CLAIM_GRAPH.json"); path=ROOT/rel
    if not path.exists(): fail(f"claim graph missing: {rel}",errors); return {},{}
    graph=load_json(path,rel,errors)
    if not isinstance(graph,dict): return {},{}
    if graph.get("schema_version")!=1: fail(f"{rel}: schema_version must be 1",errors)
    if graph.get("project")!=contract.get("project"): fail(f"{rel}: project mismatch",errors)
    claims={}; evidence={}
    for row in graph.get("claims",[]):
        cid=str(row.get("id","")).strip()
        if not cid or cid in claims: fail(f"{rel}: missing/duplicate claim id {cid!r}",errors); continue
        if row.get("status") not in CLAIM_STATUSES: fail(f"{cid}: invalid status {row.get('status')!r}",errors)
        if not str(row.get("summary","")).strip(): fail(f"{cid}: missing summary",errors)
        claims[cid]=row
    for row in graph.get("evidence",[]):
        eid=str(row.get("id","")).strip()
        if not eid or eid in evidence: fail(f"{rel}: missing/duplicate evidence id {eid!r}",errors); continue
        if not str(row.get("ref","")).strip(): fail(f"{eid}: missing ref",errors)
        if row.get("repo_path") and not (ROOT/row["repo_path"]).exists(): fail(f"{eid}: missing repo_path {row['repo_path']}",errors)
        evidence[eid]=row
    for cid,row in claims.items():
        for eid in row.get("evidence_ids",[]):
            if eid not in evidence: fail(f"{cid}: unknown evidence {eid}",errors)
        for key in ("blocks","supersedes","allow_similarity_with"):
            for other in row.get(key,[]):
                if other not in claims: fail(f"{cid}: {key} unknown claim {other}",errors)
        if row.get("status") in CLOSED_CLAIM_STATUSES and not row.get("evidence_ids"): warn(f"CLOSED_CLAIM_WITHOUT_EVIDENCE: {cid} status={row.get('status')}")
    fingerprints={}
    for cid,row in claims.items():
        for source in [row.get("summary","")]+row.get("aliases",[])+row.get("fingerprints",[]):
            normalized=norm(source)
            if not normalized: continue
            if normalized in fingerprints and fingerprints[normalized]!=cid and fingerprints[normalized] not in row.get("allow_similarity_with",[]) and cid not in claims[fingerprints[normalized]].get("allow_similarity_with",[]): fail(f"DUPLICATE_CLAIM_FINGERPRINT: {cid} ~ {fingerprints[normalized]} => {normalized}",errors)
            fingerprints.setdefault(normalized,cid)
    items=list(claims.items())
    for i,(a,ra) in enumerate(items):
        for b,rb in items[i+1:]:
            if b in ra.get("allow_similarity_with",[]) or a in rb.get("allow_similarity_with",[]): continue
            na,nb=norm(ra.get("summary","")),norm(rb.get("summary",""))
            if not na or not nb: continue
            ta,tb=set(na.split()),set(nb.split()); union=ta|tb; j=len(ta&tb)/len(union) if union else 0.0; sequence=difflib.SequenceMatcher(None,na,nb).ratio()
            if j>=0.82 and sequence>=0.92: fail(f"POSSIBLE_DUPLICATE_CLAIM: {a} ~ {b} token={j:.2f} text={sequence:.2f}",errors)
            elif j>=0.72 and sequence>=0.86: warn(f"CLAIM_SIMILARITY_REVIEW: {a} ~ {b} token={j:.2f} text={sequence:.2f}")
    active=contract.get("active_claim_ids",[])
    if not active: fail("active_claim_ids is empty",errors)
    for cid in active:
        if cid not in claims: fail(f"active_claim_ids unknown claim {cid}",errors)
        elif claims[cid].get("status") not in {"ACTIVE","PENDING"}: fail(f"active claim {cid} status is {claims[cid].get('status')}",errors)
    pending_refs=set(contract.get("pending_evidence_refs",[])); pending_claims={cid:row for cid,row in claims.items() if row.get("status")=="PENDING"}
    if bool(pending_refs)!=bool(pending_claims): fail("PENDING_MISMATCH: pending_evidence_refs and PENDING claim set must both be empty or both be non-empty",errors)
    for relpath in sorted(pending_refs):
        matching_eids={eid for eid,row in evidence.items() if row.get("repo_path")==relpath}
        if not matching_eids: fail(f"PENDING_EVIDENCE_UNREGISTERED: {relpath}",errors); continue
        if not any(matching_eids.intersection(set(row.get("evidence_ids",[]))) for row in pending_claims.values()): fail(f"PENDING_EVIDENCE_UNLINKED: {relpath}",errors)
    return claims,evidence

def read_single_marker(path,label,errors,allowed=None,prefix=None):
    if not path.exists(): fail(f"{path.relative_to(ROOT)} missing",errors); return None
    rows=[line.strip() for line in read(path).splitlines() if line.strip() and not line.lstrip().startswith("#")]
    if len(rows)!=1: fail(f"{path.relative_to(ROOT)} must contain exactly one non-empty value",errors); return None
    value=rows[0]
    if prefix:
        if not value.startswith(prefix) or not value[len(prefix):].strip(): fail(f"{path.relative_to(ROOT)} must be one non-empty line starting with '{prefix}'",errors); return None
        value=value[len(prefix):].strip()
    if allowed and value not in allowed: fail(f"{path.relative_to(ROOT)} invalid {label} {value!r}; allowed={sorted(allowed)}",errors); return None
    return value

def validate_reopen_rationale(exp_dir,cid,errors):
    path=exp_dir/"REOPEN_RATIONALE.md"
    if not path.exists(): fail(f"CLAIM_CLOSED: {cid} requires REOPEN_RATIONALE.md or a new claim",errors); return
    rows=[line.strip() for line in read(path).splitlines() if line.strip()]
    found={}
    for prefix in ("WHY_REOPEN:","NEW_EVIDENCE:"):
        for row in rows:
            if row.startswith(prefix): found[prefix]=row[len(prefix):].strip(); break
        if not found.get(prefix): fail(f"{path.relative_to(ROOT)} requires non-empty '{prefix}'",errors)
        elif len(found[prefix])<12: fail(f"{path.relative_to(ROOT)} '{prefix}' is too weak; provide a concrete reason",errors)

def experiment_metadata(exp_dir,claims,errors):
    cid=read_single_marker(exp_dir/"CLAIM_ID.txt","CLAIM_ID",errors)
    exp_class=read_single_marker(exp_dir/"EXPERIMENT_CLASS.txt","experiment class",errors,allowed=EXPERIMENT_CLASSES)
    read_single_marker(exp_dir/"PRIMARY_FACT.txt","primary fact",errors,prefix="PRIMARY_FACT:")
    if cid:
        if cid not in claims: fail(f"{(exp_dir/'CLAIM_ID.txt').relative_to(ROOT)} unknown claim {cid}",errors)
        elif claims[cid].get("status") in CLOSED_CLAIM_STATUSES: validate_reopen_rationale(exp_dir,cid,errors)
    return cid,exp_class

def validate_preflight(exp_dir,errors):
    path=exp_dir/"PREFLIGHT_5_LINES.txt"
    if not path.exists(): fail(f"{path.relative_to(ROOT)} missing",errors); return
    rows=[line.strip() for line in read(path).splitlines() if line.strip()]
    if len(rows)!=5: fail(f"{path.relative_to(ROOT)} must contain exactly 5 non-empty lines",errors); return
    for got,required in zip(rows,PREFLIGHT):
        if not got.startswith(required) or not got[len(required):].strip(): fail(f"{path.relative_to(ROOT)} bad line: expected {required}",errors)

def evidence_delta_path(rel):
    path=Path(rel); name=path.name.casefold()
    return path.suffix.casefold()==".md" and path.parts and path.parts[0].casefold() in {"research","docs","experiments"} and ("result_delta" in name or "evidence_delta" in name)

def validate_delta_headers(path,evidence,claims,errors):
    head="\n".join(read(path).splitlines()[:100]); me=re.search(r"(?im)^\s*EVIDENCE_ID:\s*(\S+)\s*$",head); mc=re.search(r"(?im)^\s*CLAIM_ID:\s*(\S+)\s*$",head)
    if not me or not mc: fail(f"{path.relative_to(ROOT)} must declare EVIDENCE_ID and CLAIM_ID in first 100 lines",errors); return
    eid,cid=me.group(1),mc.group(1)
    if eid not in evidence: fail(f"{path.relative_to(ROOT)} unregistered EVIDENCE_ID {eid}",errors)
    if cid not in claims: fail(f"{path.relative_to(ROOT)} unregistered CLAIM_ID {cid}",errors)
    elif eid in evidence and eid not in claims[cid].get("evidence_ids",[]): fail(f"{eid} is not linked from claim {cid}",errors)

def github_get_json(url,token):
    req=urllib.request.Request(url,headers={"Accept":"application/vnd.github+json","Authorization":f"Bearer {token}","X-GitHub-Api-Version":"2022-11-28","User-Agent":"research-integrity-v2"})
    with urllib.request.urlopen(req,timeout=20) as response: return json.loads(response.read().decode("utf-8"))

def issue_sync(contract,claims,errors):
    issue_number=contract.get("current_issue_number")
    if not issue_number: fail("current_issue_number is not declared",errors); return
    token=os.getenv("GITHUB_TOKEN","").strip(); repo=os.getenv("GITHUB_REPOSITORY","").strip()
    if not token or not repo: warn("ISSUE_SYNC_SKIPPED: GITHUB_TOKEN/GITHUB_REPOSITORY unavailable outside CI"); return
    base=f"https://api.github.com/repos/{repo}"
    try: issue=github_get_json(f"{base}/issues/{issue_number}",token); open_items=github_get_json(f"{base}/issues?state=open&per_page=100",token)
    except (urllib.error.URLError,urllib.error.HTTPError,TimeoutError,json.JSONDecodeError) as exc: fail(f"ISSUE_SYNC_API_ERROR: {exc}",errors); return
    if issue.get("pull_request"): fail(f"current_issue_number {issue_number} resolves to a pull request",errors); return
    if issue.get("state")!="open": fail(f"CURRENT_ISSUE_CLOSED: #{issue_number}",errors)
    title=str(issue.get("title","")); body=str(issue.get("body") or "")
    if not title.casefold().startswith("current:"): fail(f"CURRENT_ISSUE_TITLE: #{issue_number} must start with 'CURRENT:'",errors)
    state_rel=str(contract.get("canonical_state",""))
    if state_rel and state_rel not in body: fail(f"CURRENT_ISSUE_STATE_LINK: #{issue_number} does not mention {state_rel}",errors)
    for cid in contract.get("active_claim_ids",[]):
        if cid not in body: fail(f"CURRENT_ISSUE_CLAIM_MISSING: #{issue_number} does not mention active claim {cid}",errors)
    current_issues=[row for row in open_items if "pull_request" not in row and str(row.get("title","")).casefold().startswith("current:")]
    current_numbers=sorted(int(row.get("number",0)) for row in current_issues)
    if current_numbers!=[int(issue_number)]: fail(f"CURRENT_ISSUE_CARDINALITY: expected only #{issue_number}, found {current_numbers}",errors)

def main():
    parser=argparse.ArgumentParser(); parser.add_argument("--base",default=os.getenv("BASE_SHA")); args=parser.parse_args(); errors=[]
    contract_path=ROOT/"RESEARCH_CONTRACT.yaml"
    if not contract_path.exists(): fail("RESEARCH_CONTRACT.yaml missing",errors); return 1
    contract=load_json(contract_path,"RESEARCH_CONTRACT.yaml",errors)
    if not isinstance(contract,dict): return 1
    if contract.get("schema_version")!=2: fail("unsupported RESEARCH_CONTRACT schema_version; expected 2",errors)
    state_rel=contract.get("canonical_state")
    if not state_rel or not (ROOT/state_rel).exists(): fail(f"canonical state missing: {state_rel}",errors); return 1
    state=read(ROOT/state_rel); state_date=dateof("\n".join(state.splitlines()[:120]))
    workflow_rel=contract.get("workflow")
    if workflow_rel and not (ROOT/workflow_rel).exists(): fail(f"workflow missing: {workflow_rel}",errors)
    gate_anchor=contract.get("active_gate_anchor")
    if gate_anchor and gate_anchor.casefold() not in state.casefold(): fail("active gate anchor missing from canonical state",errors)
    baseline_anchor=contract.get("protected_baseline_anchor")
    if baseline_anchor and baseline_anchor.casefold() not in state.casefold(): fail("protected baseline anchor missing from canonical state",errors)
    claims,evidence=graph_check(contract,errors); pending=set(contract.get("pending_evidence_refs",[]))
    for rel in pending:
        if not (ROOT/rel).exists(): fail(f"pending evidence missing: {rel}",errors)
    latest=None
    for pattern in contract.get("evidence_globs",[]):
        for path in ROOT.glob(pattern):
            if path.is_file():
                d=dateof(path.name) or dateof("\n".join(read(path).splitlines()[:40]))
                if d and (latest is None or d>latest[0]): latest=(d,path)
    if latest and state_date and latest[0]>state_date:
        rel=latest[1].relative_to(ROOT).as_posix(); name=latest[1].name
        if rel.casefold() not in state.casefold() and name.casefold() not in state.casefold():
            if rel in pending: warn(f"STATE_PENDING: {rel} newer than STATE and queued for convergence")
            else: fail(f"STATE_STALE: {rel}@{latest[0]} newer than STATE@{state_date}",errors)
    changes=changed(args.base); experiment_dirs=set()
    for status,rel in changes:
        path=Path(rel)
        if path.parts and path.parts[0].casefold()=="experiments" and path.suffix.casefold() in MUTATION_EXT and len(path.parts)>=2: experiment_dirs.add(ROOT/path.parts[0]/path.parts[1])
        if contract.get("require_headers_for_changed_evidence_delta",True) and not status.startswith("D") and evidence_delta_path(rel) and (ROOT/path).exists(): validate_delta_headers(ROOT/path,evidence,claims,errors)
    live_dirs=set()
    for exp_dir in sorted(experiment_dirs):
        _,exp_class=experiment_metadata(exp_dir,claims,errors)
        if exp_class in LIVE_CLASSES: live_dirs.add(exp_dir); validate_preflight(exp_dir,errors)
    if live_dirs and pending and contract.get("block_live_when_pending",True): fail("LIVE_BLOCKED_BY_PENDING_EVIDENCE",errors)
    issue_sync(contract,claims,errors)
    print(); print("PROJECT="+str(contract.get("project","UNKNOWN"))); print("CANONICAL_STATE="+str(state_rel)); print("STATE_DATE="+str(state_date or "UNKNOWN")); print("CLAIMS="+str(len(claims))); print("EVIDENCE_IDS="+str(len(evidence))); print("ACTIVE_CLAIMS="+",".join(contract.get("active_claim_ids",[]))); print("PENDING_EVIDENCE="+str(len(pending))); print("CHANGED_FILES="+str(len(changes))); print("EXPERIMENT_DIRS_CHECKED="+str(len(experiment_dirs))); print("LIVE_EXPERIMENT_DIRS_CHECKED="+str(len(live_dirs))); print("ERRORS="+str(len(errors))); print("VERDICT="+("PASS" if not errors else "FAIL")); return 0 if not errors else 1

if __name__=="__main__": raise SystemExit(main())
