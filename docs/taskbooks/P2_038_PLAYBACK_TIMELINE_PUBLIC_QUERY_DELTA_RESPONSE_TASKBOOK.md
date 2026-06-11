# P2-038 Planning Draft v1.0 — Playback Timeline Public Query Delta Response Contract Skeleton

Status: PLANNING_ONLY_TASKBOOK
Task type: planning-only / contract-skeleton-design / no-code-before-accepted
Repository: `syzayy520/Kivo-Player`

---

## 0. Baseline Verification

Accepted previous implementation:

```text
P2-037_IMPLEMENTED_PUSHED_TESTS_GATES_PASS_SYNCED
Branch: kivo-playback-timeline-public-query-delta-p2-037
HEAD: 138056cba131c341e64df8cedcbfd822b51607df
```

P2-038 taskbook branch:

```text
kivo-playback-p2-038-taskbook-query-delta-response
```

Future implementation branch:

```text
kivo-playback-timeline-public-query-delta-response-p2-038
```

---

## 1. Goal

Create a contract-only family that links the P2-037 `timeline_public_query_delta` seam to the existing `timeline_public_response` family and the P2 final audit identity.

The family must describe typed response binding data only:

```text
query-delta identity
response identity
final audit identity
classification
response binding record/envelope
outcome
```

No execution, dispatch, API, UI, cache, thread, or platform behavior is allowed.

---

## 2. Non-goals

Do not implement:

```text
response dispatch
query execution
delta calculation
public API endpoint
IPC command
UI binding
cache/persistence
threading/async behavior
platform/adapter/backend integration
```

---

## 3. Layer and Namespace

Production namespace:

```cpp
kivo::playback::timeline_public_query_delta_response
```

Production family root:

```text
src/playback/timeline_public_query_delta_response/
```

Test family root:

```text
tests/playback/timeline_public_query_delta_response/
```

Layer:

```text
contract-only / public timeline seam / no platform / no execution
```

---

## 4. Natural Family Tree

```text
src/playback/timeline_public_query_delta_response/
├── CMakeLists.txt
├── identity/
│   ├── timeline_public_query_delta_response_id.h
│   ├── timeline_public_query_delta_response_sequence_id.h
│   ├── timeline_public_query_delta_response_generation.h
│   └── timeline_public_query_delta_response_identity.h
├── anchor/
│   ├── timeline_public_query_delta_response_query_delta_anchor.h
│   ├── timeline_public_query_delta_response_response_anchor.h
│   ├── p2_public_surface_final_audit_query_delta_response_anchor.h
│   └── timeline_public_query_delta_response_anchor_set.h
├── classification/
│   ├── timeline_public_query_delta_response_kind.h
│   ├── timeline_public_query_delta_response_scope.h
│   └── timeline_public_query_delta_response_classification.h
├── response_binding/
│   ├── timeline_public_query_delta_response_candidate.h
│   ├── timeline_public_query_delta_response_record.h
│   ├── timeline_public_query_delta_response_envelope.h
│   └── playback_timeline_public_query_delta_response.h
└── outcome/
    ├── timeline_public_query_delta_response_status.h
    ├── timeline_public_query_delta_response_defer_reason.h
    ├── timeline_public_query_delta_response_rejection_reason.h
    └── timeline_public_query_delta_response_outcome.h
```

```text
tests/playback/timeline_public_query_delta_response/
├── CMakeLists.txt
├── timeline_public_query_delta_response_identity_tests.cpp
├── timeline_public_query_delta_response_anchor_tests.cpp
├── timeline_public_query_delta_response_classification_tests.cpp
├── timeline_public_query_delta_response_binding_tests.cpp
├── timeline_public_query_delta_response_outcome_tests.cpp
└── timeline_public_query_delta_response_boundary_tests.cpp
```

---

## 5. Single-file Responsibility Table

| File | Responsibility |
|---|---|
| `timeline_public_query_delta_response_id.h` | Typed id wrapper only. |
| `timeline_public_query_delta_response_sequence_id.h` | Typed sequence wrapper only. |
| `timeline_public_query_delta_response_generation.h` | Typed generation wrapper only. |
| `timeline_public_query_delta_response_identity.h` | Aggregates id, sequence, generation only. |
| `timeline_public_query_delta_response_query_delta_anchor.h` | Typed anchor to `TimelinePublicQueryDeltaIdentity`. |
| `timeline_public_query_delta_response_response_anchor.h` | Typed anchor to `TimelinePublicResponseIdentity`. |
| `p2_public_surface_final_audit_query_delta_response_anchor.h` | Typed anchor to `P2PublicSurfaceFinalAuditIdentity`. |
| `timeline_public_query_delta_response_anchor_set.h` | Aggregates the three typed anchors only. |
| `timeline_public_query_delta_response_kind.h` | Enum for binding kind only. |
| `timeline_public_query_delta_response_scope.h` | Enum for binding scope only. |
| `timeline_public_query_delta_response_classification.h` | Aggregates kind and scope only. |
| `timeline_public_query_delta_response_candidate.h` | Candidate aggregate before acceptance. |
| `timeline_public_query_delta_response_record.h` | Accepted record aggregate. |
| `timeline_public_query_delta_response_envelope.h` | Candidate + record envelope. |
| `playback_timeline_public_query_delta_response.h` | Top-level public contract aggregate. |
| `timeline_public_query_delta_response_status.h` | Status enum only. |
| `timeline_public_query_delta_response_defer_reason.h` | Defer reason enum only. |
| `timeline_public_query_delta_response_rejection_reason.h` | Rejection reason enum only. |
| `timeline_public_query_delta_response_outcome.h` | Aggregates status/defer/rejection only. |

---

## 6. Future Implementation Allowlist

Production files may be created only under:

```text
src/playback/timeline_public_query_delta_response/**
```

Test files may be created only under:

```text
tests/playback/timeline_public_query_delta_response/**
```

Existing file modification allowed:

```text
CMakeLists.txt
```

Root CMake may only add:

```cmake
add_subdirectory(src/playback/timeline_public_query_delta_response)
add_subdirectory(tests/playback/timeline_public_query_delta_response)
```

---

## 7. Forbidden Files

Implementation must not modify:

```text
docs/**
scripts/**
README.md
CMakePresets.json
build.ps1
src/playback/timeline_public_query_delta/**
src/playback/timeline_public_response/**
src/playback/p2_public_surface_final_audit/**
tests/playback/timeline_public_query_delta/**
tests/playback/timeline_public_response/**
tests/playback/p2_public_surface_final_audit/**
```

---

## 8. Dependency Direction

Allowed direct production includes:

```text
playback/timeline_public_query_delta/identity/timeline_public_query_delta_identity.h
playback/timeline_public_response/identity/timeline_public_response_identity.h
playback/p2_public_surface_final_audit/identity/p2_public_surface_final_audit_identity.h
```

Allowed standard library includes:

```text
<cstdint>
```

No non-identity upstream include is allowed without revising this taskbook.

---

## 9. Forbidden Tokens

Do not introduce these tokens in implementation files:

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
facade
Facade
bridge
Bridge
engine
Engine
runtime
Runtime
```

---

## 10. Test Plan

Create one CTest target with six focused source files:

```text
identity tests
anchor tests
classification tests
response binding tests
outcome tests
boundary compile surface tests
```

Expected CTest count after implementation:

```text
Current accepted total: 85/85 PASS
P2-038 adds one CTest target
Expected total: 86/86 PASS
```

---

## 11. STOP Conditions

```text
STOP_WRONG_BASE
STOP_WORKSPACE_NOT_CLEAN
STOP_FORBIDDEN_FILE_TOUCHED
STOP_DEPENDENCY_DIRECTION_VIOLATION
STOP_FORBIDDEN_TOKEN_FOUND
STOP_FAMILY_TREE_GOVERNANCE_VIOLATION
STOP_ROOT_CMAKE_UNRELATED_CHANGE
STOP_LOCAL_VERIFICATION_MISSING
STOP_PUSH_NOT_SYNCED
```

---

## 12. Acceptance Criteria

```text
1. Implementation starts from accepted taskbook HEAD.
2. File range is only root CMake + new src/test family.
3. New family follows identity/anchor/classification/response_binding/outcome tree.
4. Upstream references are typed identity only.
5. No token workaround appears.
6. Build PASS.
7. CTest PASS.
8. Governance gates PASS.
9. Source purity PASS.
10. git diff --check PASS.
11. Working tree clean.
12. Local HEAD == remote HEAD.
```

Final classification if all pass:

```text
P2-038_IMPLEMENTED_PUSHED_TESTS_GATES_PASS_SYNCED
```
