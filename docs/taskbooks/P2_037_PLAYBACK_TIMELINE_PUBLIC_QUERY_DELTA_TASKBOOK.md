# P2-037 Planning Draft v1.0 — Playback Timeline Public Query Delta Contract Skeleton

Status: PLANNING_ONLY_TASKBOOK_REBUILT
Task type: planning-only / contract-skeleton-design / no-code / no-src / no-tests / no-cmake-change
Repository: `syzayy520/Kivo-Player`

---

## 0. Source-of-truth Recovery Note

The previous P2-037 planning handoff was not recoverable.

Canonical facts for this rebuilt planning draft:

```text
Latest accepted / repair accepted HEAD:
fd11671ee2d5aeeadd70c468481b3f51acce498c

Closed predecessor:
P2-036 — P2 Public Surface Final Audit Repair

This taskbook branch:
kivo-playback-taskbook-p2-037-public-query-delta

Future implementation branch:
kivo-playback-timeline-public-query-delta-p2-037
```

Hard rule:

```text
Do not use 5559ff2e7dd79c45ad85c5ac36cdc26af5edb337 as the P2-037 base.
That SHA belongs to an older P1 line and is not the current P2 source of truth.
```

---

## 1. Planning Branch Gate

Planning branch must be:

```text
kivo-playback-taskbook-p2-037-public-query-delta
```

Planning base must be:

```text
fd11671ee2d5aeeadd70c468481b3f51acce498c
```

Planning-only allowed file:

```text
docs/taskbooks/P2_037_PLAYBACK_TIMELINE_PUBLIC_QUERY_DELTA_TASKBOOK.md
```

Planning-only forbidden changes:

```text
src/**
tests/**
scripts/**
README.md
CMakeLists.txt
CMakePresets.json
build.ps1
```

STOP condition:

```text
STOP_PLANNING_BRANCH_OR_BASE_MISMATCH
```

---

## 2. Future Implementation Branch Gate

Future implementation branch must be created only after this Planning Draft is accepted.

Implementation branch:

```text
kivo-playback-timeline-public-query-delta-p2-037
```

Implementation base must be the accepted taskbook HEAD, not the older P2-036 base alone and never the older P1-032 SHA.

Required initial commands for the future implementation agent:

```powershell
git branch --show-current
git rev-parse HEAD
git status --short
git rev-parse origin/kivo-playback-taskbook-p2-037-public-query-delta
```

Required result:

```text
branch == kivo-playback-timeline-public-query-delta-p2-037
working tree clean
implementation base includes accepted taskbook commit
```

STOP condition:

```text
STOP_IMPLEMENTATION_BASE_NOT_TASKBOOK_HEAD
```

---

## 3. Clean Workspace Gate

Before any implementation file is created or modified:

```powershell
git status --short
```

Required result:

```text
(empty output)
```

STOP condition:

```text
STOP_WORKSPACE_NOT_CLEAN
```

---

## 4. Inventory Gate

The implementation agent must inventory existing upstream families before writing code.

Required checks:

```powershell
Test-Path src/playback/timeline_public_query
Test-Path src/playback/timeline_public_delta
Test-Path src/playback/p2_public_surface_final_audit
Test-Path tests/playback/timeline_public_query
Test-Path tests/playback/timeline_public_delta
Test-Path tests/playback/p2_public_surface_final_audit
```

Required source inventory:

```powershell
Get-ChildItem src/playback/timeline_public_query -Recurse -File | Select-Object FullName
Get-ChildItem src/playback/timeline_public_delta -Recurse -File | Select-Object FullName
Get-ChildItem src/playback/p2_public_surface_final_audit -Recurse -File | Select-Object FullName
```

Required CMake inventory:

```powershell
Select-String -Path CMakeLists.txt -Pattern "timeline_public_query"
Select-String -Path CMakeLists.txt -Pattern "timeline_public_delta"
Select-String -Path CMakeLists.txt -Pattern "p2_public_surface_final_audit"
```

STOP condition:

```text
STOP_UPSTREAM_FAMILY_MISSING_OR_UNVERIFIED
```

---

## 5. Goal

Create a contract-only skeleton family for Playback Timeline Public Query Delta.

The family models a public contract seam where a consumer can describe a typed relationship between:

```text
TimelinePublicQuery identity
TimelinePublicDelta identity
P2PublicSurfaceFinalAudit identity
```

The skeleton must provide:

```text
identity types
anchor types
classification types
query-delta record/candidate/envelope types
outcome/status/rejection/defer types
compile tests
boundary isolation tests
```

This task only defines typed contract data. It does not implement runtime query execution, delta calculation, cache, dispatch, IPC, UI, or playback behavior.

---

## 6. Non-goals

Do not implement:

```text
runtime query engine
delta computation algorithm
public API endpoint
IPC command
UI binding
cache or persistence
threading / queues / async runtime
builder / factory / manager
file IO / network IO
real playback integration
scheduler integration
```

Do not modify completed upstream families.

Do not add docs beyond this accepted taskbook unless a later task explicitly allows it.

---

## 7. Layer and Namespace

Production namespace:

```cpp
kivo::playback::timeline_public_query_delta
```

Production family root:

```text
src/playback/timeline_public_query_delta/
```

Test family root:

```text
tests/playback/timeline_public_query_delta/
```

Layer classification:

```text
contract-only / public timeline seam / no runtime / no platform
```

---

## 8. Natural Family Tree

The implementation must use this tree exactly unless the Planning Draft is revised before implementation.

```text
src/playback/timeline_public_query_delta/
├── CMakeLists.txt
├── identity/
│   ├── timeline_public_query_delta_id.h
│   ├── timeline_public_query_delta_sequence_id.h
│   ├── timeline_public_query_delta_generation.h
│   └── timeline_public_query_delta_identity.h
├── anchor/
│   ├── timeline_public_query_delta_query_anchor.h
│   ├── timeline_public_query_delta_delta_anchor.h
│   ├── p2_public_surface_final_audit_query_delta_anchor.h
│   └── timeline_public_query_delta_anchor_set.h
├── classification/
│   ├── timeline_public_query_delta_kind.h
│   ├── timeline_public_query_delta_scope.h
│   └── timeline_public_query_delta_classification.h
├── query_delta/
│   ├── timeline_public_query_delta_candidate.h
│   ├── timeline_public_query_delta_record.h
│   ├── timeline_public_query_delta_envelope.h
│   └── playback_timeline_public_query_delta.h
└── outcome/
    ├── timeline_public_query_delta_status.h
    ├── timeline_public_query_delta_defer_reason.h
    ├── timeline_public_query_delta_rejection_reason.h
    └── timeline_public_query_delta_outcome.h
```

```text
tests/playback/timeline_public_query_delta/
├── CMakeLists.txt
├── timeline_public_query_delta_identity_tests.cpp
├── timeline_public_query_delta_anchor_tests.cpp
├── timeline_public_query_delta_classification_tests.cpp
├── timeline_public_query_delta_query_delta_tests.cpp
├── timeline_public_query_delta_outcome_tests.cpp
└── timeline_public_query_delta_boundary_tests.cpp
```

---

## 9. Folder to Subfamily to Single-file Responsibility Table

| Family path | Subfamily | File | Single responsibility |
|---|---|---|---|
| `identity/` | identity | `timeline_public_query_delta_id.h` | Minimal typed id wrapper for one query-delta contract instance. |
| `identity/` | identity | `timeline_public_query_delta_sequence_id.h` | Minimal monotonic sequence wrapper for query-delta ordering. |
| `identity/` | identity | `timeline_public_query_delta_generation.h` | Minimal generation wrapper for invalidation/version semantics. |
| `identity/` | identity | `timeline_public_query_delta_identity.h` | Aggregates id, sequence id, and generation only. |
| `anchor/` | query anchor | `timeline_public_query_delta_query_anchor.h` | Direct typed anchor to upstream `TimelinePublicQueryIdentity`. |
| `anchor/` | delta anchor | `timeline_public_query_delta_delta_anchor.h` | Direct typed anchor to upstream `TimelinePublicDeltaIdentity`. |
| `anchor/` | audit anchor | `p2_public_surface_final_audit_query_delta_anchor.h` | Direct typed anchor to upstream `P2PublicSurfaceFinalAuditIdentity`. |
| `anchor/` | anchor set | `timeline_public_query_delta_anchor_set.h` | Aggregates query, delta, and final-audit anchors only. |
| `classification/` | kind | `timeline_public_query_delta_kind.h` | Enum for query-delta contract kind. |
| `classification/` | scope | `timeline_public_query_delta_scope.h` | Enum for query-delta public surface scope. |
| `classification/` | classification | `timeline_public_query_delta_classification.h` | Aggregates kind and scope only. |
| `query_delta/` | candidate | `timeline_public_query_delta_candidate.h` | Candidate relationship before admission/result. |
| `query_delta/` | record | `timeline_public_query_delta_record.h` | Accepted typed query-delta record. |
| `query_delta/` | envelope | `timeline_public_query_delta_envelope.h` | Envelope for identity + anchors + classification + record. |
| `query_delta/` | public aggregate | `playback_timeline_public_query_delta.h` | Top-level public contract aggregate only. |
| `outcome/` | status | `timeline_public_query_delta_status.h` | Enum for query-delta outcome status. |
| `outcome/` | defer reason | `timeline_public_query_delta_defer_reason.h` | Enum for deferrable query-delta reasons. |
| `outcome/` | rejection reason | `timeline_public_query_delta_rejection_reason.h` | Enum for rejected query-delta reasons. |
| `outcome/` | outcome | `timeline_public_query_delta_outcome.h` | Aggregates status + defer/rejection reason only. |

---

## 10. Future Implementation Allowlist

The future implementation may create only these production files:

```text
src/playback/timeline_public_query_delta/CMakeLists.txt
src/playback/timeline_public_query_delta/identity/timeline_public_query_delta_id.h
src/playback/timeline_public_query_delta/identity/timeline_public_query_delta_sequence_id.h
src/playback/timeline_public_query_delta/identity/timeline_public_query_delta_generation.h
src/playback/timeline_public_query_delta/identity/timeline_public_query_delta_identity.h
src/playback/timeline_public_query_delta/anchor/timeline_public_query_delta_query_anchor.h
src/playback/timeline_public_query_delta/anchor/timeline_public_query_delta_delta_anchor.h
src/playback/timeline_public_query_delta/anchor/p2_public_surface_final_audit_query_delta_anchor.h
src/playback/timeline_public_query_delta/anchor/timeline_public_query_delta_anchor_set.h
src/playback/timeline_public_query_delta/classification/timeline_public_query_delta_kind.h
src/playback/timeline_public_query_delta/classification/timeline_public_query_delta_scope.h
src/playback/timeline_public_query_delta/classification/timeline_public_query_delta_classification.h
src/playback/timeline_public_query_delta/query_delta/timeline_public_query_delta_candidate.h
src/playback/timeline_public_query_delta/query_delta/timeline_public_query_delta_record.h
src/playback/timeline_public_query_delta/query_delta/timeline_public_query_delta_envelope.h
src/playback/timeline_public_query_delta/query_delta/playback_timeline_public_query_delta.h
src/playback/timeline_public_query_delta/outcome/timeline_public_query_delta_status.h
src/playback/timeline_public_query_delta/outcome/timeline_public_query_delta_defer_reason.h
src/playback/timeline_public_query_delta/outcome/timeline_public_query_delta_rejection_reason.h
src/playback/timeline_public_query_delta/outcome/timeline_public_query_delta_outcome.h
```

The future implementation may create only these test files:

```text
tests/playback/timeline_public_query_delta/CMakeLists.txt
tests/playback/timeline_public_query_delta/timeline_public_query_delta_identity_tests.cpp
tests/playback/timeline_public_query_delta/timeline_public_query_delta_anchor_tests.cpp
tests/playback/timeline_public_query_delta/timeline_public_query_delta_classification_tests.cpp
tests/playback/timeline_public_query_delta/timeline_public_query_delta_query_delta_tests.cpp
tests/playback/timeline_public_query_delta/timeline_public_query_delta_outcome_tests.cpp
tests/playback/timeline_public_query_delta/timeline_public_query_delta_boundary_tests.cpp
```

The future implementation may modify only this existing file:

```text
CMakeLists.txt
```

Root `CMakeLists.txt` may only add:

```cmake
add_subdirectory(src/playback/timeline_public_query_delta)
add_subdirectory(tests/playback/timeline_public_query_delta)
```

---

## 11. Forbidden Files

The future implementation must not modify:

```text
docs/**
scripts/**
README.md
CMakePresets.json
build.ps1
src/playback/timeline_public_query/**
src/playback/timeline_public_delta/**
src/playback/p2_public_surface_final_audit/**
tests/playback/timeline_public_query/**
tests/playback/timeline_public_delta/**
tests/playback/p2_public_surface_final_audit/**
```

The only exception is this taskbook itself during the planning phase. Implementation must not change it unless the user explicitly requests a Planning Draft revision.

STOP condition:

```text
STOP_FORBIDDEN_FILE_TOUCHED
```

---

## 12. Dependency Direction Matrix

Allowed direct production includes:

```text
playback/timeline_public_query/identity/timeline_public_query_identity.h
playback/timeline_public_delta/identity/timeline_public_delta_identity.h
playback/p2_public_surface_final_audit/identity/p2_public_surface_final_audit_identity.h
```

Allowed standard library includes:

```text
<cstdint>
```

No other upstream headers may be included without a Planning Draft revision.

Dependency direction:

```text
timeline_public_query_delta -> timeline_public_query identity only
timeline_public_query_delta -> timeline_public_delta identity only
timeline_public_query_delta -> p2_public_surface_final_audit identity only
```

Forbidden dependency direction:

```text
timeline_public_query_delta -> runtime implementation
timeline_public_query_delta -> adapter/backend/platform
timeline_public_query_delta -> UI/IPC/API
timeline_public_query_delta -> unfinished P2/P3 modules
timeline_public_query_delta -> non-identity outcome/classification from upstream families
```

STOP condition:

```text
STOP_DEPENDENCY_DIRECTION_VIOLATION
```

---

## 13. Forbidden Token Scan Rules

The future implementation must not introduce these tokens in production files or tests except as literal text inside this taskbook:

```text
FFmpeg
AVPacket
AVFrame
AVStream
D3D11
DXGI
WASAPI
COM
IUnknown
HRESULT
HWND
std::thread
std::mutex
condition_variable
CreateFile
ReadFile
WriteFile
source_identity_token
void*
manager
Manager
helper
Helper
helpers
Helpers
facade
Facade
bridge
Bridge
engine
Engine
runtime
Runtime
```

`source_identity_token` is explicitly forbidden because P2-036 already required a typed identity anchor repair. P2-037 must not reintroduce token workaround patterns.

---

## 14. CMake Integration Plan

Production CMake file:

```text
src/playback/timeline_public_query_delta/CMakeLists.txt
```

Test CMake file:

```text
tests/playback/timeline_public_query_delta/CMakeLists.txt
```

Root CMake allowed additions only:

```cmake
add_subdirectory(src/playback/timeline_public_query_delta)
add_subdirectory(tests/playback/timeline_public_query_delta)
```

The implementation must not reorder unrelated existing CMake sections.

---

## 15. Test Plan

The future implementation must add six focused test files:

```text
timeline_public_query_delta_identity_tests.cpp
timeline_public_query_delta_anchor_tests.cpp
timeline_public_query_delta_classification_tests.cpp
timeline_public_query_delta_query_delta_tests.cpp
timeline_public_query_delta_outcome_tests.cpp
timeline_public_query_delta_boundary_tests.cpp
```

Required coverage:

```text
identity default construction
anchor typed upstream identity construction
classification default and enum construction
query_delta candidate/record/envelope aggregate construction
outcome default and enum construction
boundary isolation: no platform/runtime/API/IPC token dependency
```

Expected CTest count:

```text
Base accepted P2-036 repair reported 84/84 PASS.
P2-037 is expected to add 6 focused CTest entries.
Expected total after implementation: 90/90 PASS.
```

If the local baseline count differs, the implementation final report must disclose the actual baseline and actual total. It must not claim stale `36/36` without current local evidence.

---

## 16. Whole Tree Family Governance Precheck

The new family is valid because:

```text
Folder = timeline_public_query_delta feature family
Subfolder = identity / anchor / classification / query_delta / outcome subfamily
Single file = one smallest contract responsibility
```

Rejected structures:

```text
src/playback/timeline_public_query_delta/types.h
src/playback/timeline_public_query_delta/helpers.h
src/playback/timeline_public_query_delta/manager.h
src/playback/timeline_public_query_delta/facade.h
src/playback/timeline_public_query_delta/bridge.h
src/playback/timeline_public_query_delta/runtime.h
src/playback/timeline_public_query_delta/engine.h
```

STOP condition:

```text
STOP_FAMILY_TREE_GOVERNANCE_VIOLATION
```

---

## 17. Static Structure Self-check Required Before Build

The future implementation agent must run a static file-range self-check before build:

```powershell
git diff --name-status <IMPLEMENTATION_BASE>..HEAD
```

Allowed result shape:

```text
M  CMakeLists.txt
A  src/playback/timeline_public_query_delta/**
A  tests/playback/timeline_public_query_delta/**
```

No other paths are allowed.

Forbidden path scan:

```powershell
git diff --name-only <IMPLEMENTATION_BASE>..HEAD | Select-String "^(docs/|scripts/|README.md|CMakePresets.json|build.ps1)"
```

Required result:

```text
(empty output)
```

---

## 18. Required Local Verification Commands

Future implementation final report must paste raw output for:

```powershell
git branch --show-current
git rev-parse HEAD
git status --short
git rev-parse @{u}
git log -1 --oneline
git diff --name-status <IMPLEMENTATION_BASE>..HEAD
git show --stat --oneline --name-status -1
.\build.ps1
ctest --test-dir out/build/windows-msvc-debug --output-on-failure -C Debug
.\scripts\run-foundation-gates.ps1
.\scripts\check-playback-core-source-purity.ps1
git diff --check <IMPLEMENTATION_BASE>..HEAD
```

Required final state:

```text
working tree clean
local HEAD == remote HEAD
build PASS
CTest PASS
governance gates PASS
forbidden token scan PASS
```

---

## 19. Acceptance Criteria

P2-037 implementation may be accepted only if all are true:

```text
1. Implementation branch starts from accepted taskbook HEAD.
2. Exactly one new production family exists: src/playback/timeline_public_query_delta/**.
3. Exactly one new test family exists: tests/playback/timeline_public_query_delta/**.
4. Root CMake adds only the two allowed add_subdirectory lines.
5. No docs/scripts/README/build/CMakePresets changes in implementation.
6. All production files are header-only contract skeletons.
7. No runtime, manager, helper, facade, bridge, platform, adapter, UI, IPC, API, or builder code appears.
8. All upstream consumption is typed identity only.
9. No source_identity_token or raw token workaround appears.
10. Test family compiles and validates identity, anchor, classification, query_delta, outcome, and boundary isolation.
11. Build PASS.
12. CTest PASS.
13. Governance gates PASS.
14. Forbidden token scan PASS.
15. Working tree clean.
16. Local HEAD == remote HEAD.
```

---

## 20. STOP Conditions Summary

```text
STOP_PLANNING_BRANCH_OR_BASE_MISMATCH
STOP_IMPLEMENTATION_BASE_NOT_TASKBOOK_HEAD
STOP_WORKSPACE_NOT_CLEAN
STOP_UPSTREAM_FAMILY_MISSING_OR_UNVERIFIED
STOP_FORBIDDEN_FILE_TOUCHED
STOP_DEPENDENCY_DIRECTION_VIOLATION
STOP_FAMILY_TREE_GOVERNANCE_VIOLATION
STOP_FORBIDDEN_TOKEN_FOUND
STOP_ROOT_CMAKE_UNRELATED_CHANGE
STOP_TEST_COUNT_UNPROVEN
STOP_LOCAL_VERIFICATION_NOT_ON_CURRENT_HEAD
STOP_PUSH_NOT_SYNCED
```

---

## 21. Final Report Required Classification

If future implementation passes all required checks:

```text
P2-037_IMPLEMENTED_PUSHED_TESTS_GATES_PASS_SYNCED
```

If implementation only passes remote compare but lacks local build/test/gate raw output:

```text
P2-037_REMOTE_SCOPE_PASS_LOCAL_VERIFICATION_MISSING
```

If implementation reintroduces token workaround or starts from the wrong base:

```text
P2-037_REJECTED_WRONG_BASE_OR_TOKEN_WORKAROUND
```

---

## 22. Open Questions

No open product questions.

Implementation must not begin until this taskbook is reviewed and accepted.
