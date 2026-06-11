# P2 Continuation Route After P2-037

Status: ACTIVE_ROUTE_SOURCE_OF_TRUTH
Base accepted HEAD: `138056cba131c341e64df8cedcbfd822b51607df`
Closed latest task: P2-037 — Playback Timeline Public Query Delta Contract Skeleton

---

## Purpose

This route file prevents oral-only handoff drift. Every next P2 task must first create a taskbook, then implementation, then remote static self-check, then local cumulative verification.

---

## Execution Mode

```text
planning design
-> natural family tree
-> implementation
-> remote static structure self-check
-> cumulative local verification after a batch
```

Each task must have:

```text
1. Branch Gate
2. Clean Workspace Gate
3. Inventory Gate
4. Goal / Non-goals
5. Natural Family Tree
6. Folder to subfamily to single-file responsibility table
7. Exact allowlist
8. Forbidden files
9. Dependency direction
10. Forbidden token scan rules
11. Test plan
12. Acceptance criteria
13. STOP conditions
14. Final report requirements
```

No task may rely on memory or an assistant handoff without a repository taskbook.

---

## Next Route

### P2-038 — Playback Timeline Public Query Delta Response Contract Skeleton

Branch plan:

```text
Taskbook branch:
kivo-playback-taskbook-p2-038-query-delta-response

Implementation branch:
kivo-playback-timeline-public-query-delta-response-p2-038
```

Purpose:

```text
Create a contract-only seam connecting the already typed P2-037 query-delta family with timeline_public_response identity.
```

Natural family root:

```text
src/playback/timeline_public_query_delta_response/
tests/playback/timeline_public_query_delta_response/
```

Allowed direct upstream identity anchors:

```text
playback/timeline_public_query_delta/identity/timeline_public_query_delta_identity.h
playback/timeline_public_response/identity/timeline_public_response_identity.h
playback/p2_public_surface_final_audit/identity/p2_public_surface_final_audit_identity.h
```

Forbidden:

```text
runtime query execution
response dispatch
IPC/API/UI binding
cache/persistence
threading/async
platform/adapter/backend
source_identity_token
manager/helper/facade/bridge/engine/runtime
```

### P2-039 — Reserved

Purpose must be decided only after P2-038 is closed and verified.

---

## Current Required Local Verification Batch

After P2-038 implementation, run one cumulative verification over HEAD:

```powershell
git status --short
git branch --show-current
git rev-parse HEAD
git rev-parse @{u}
.\build.ps1
ctest --test-dir out/build/windows-msvc-debug --output-on-failure -C Debug
.\scripts\run-foundation-gates.ps1
.\scripts\check-playback-core-source-purity.ps1
git diff --check <BATCH_BASE>..HEAD
```
