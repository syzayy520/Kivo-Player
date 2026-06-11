# P1-031 — Playback Timeline Public Snapshot Contract Skeleton Taskbook Seed

Status: `TASKBOOK_SEED_FOR_REVIEW`

This document is intentionally committed before implementation so the next assistant / Agent can see the intended P1-031 direction from the repository itself. It is not implementation approval by itself. The next assistant must first review this taskbook, check it against the actual repository state, and produce a standalone planning draft before writing code.

---

## 0. Current Safe Point

Previous accepted ticket:

```text
P1-030 Playback Timeline Public Read Model Skeleton
Classification: PASS_PUSHED_ACCEPTED
```

Safe base commit for the next implementation line:

```text
6f2f5b45570aa1b8d58ba76c095aa436c871709c
```

Previous branch:

```text
kivo-playback-timeline-public-read-model-p1-030
```

Recommended next planning / implementation branch:

```text
kivo-playback-timeline-public-snapshot-contract-p1-031
```

Taskbook seed branch:

```text
kivo-playback-taskbook-p1-031-public-snapshot-contract
```

This seed branch is documentation-only. Do not treat it as the implementation branch.

---

## 1. P1-031 Product Meaning

P1-031 defines a pure data contract for a public playback timeline snapshot.

A public snapshot is the next layer after the P1-030 public read model. P1-030 gives a public read model identity and public read model contract. P1-031 should define a stable snapshot contract that can later be read by API / IPC / UI layers, but P1-031 itself must not implement API / IPC / UI / runtime / builder behavior.

Strict definition:

```text
Public Snapshot is not UI.
Public Snapshot is not frontend.
Public Snapshot is not Tauri.
Public Snapshot is not IPC.
Public Snapshot is not API.
Public Snapshot is not an endpoint.
Public Snapshot is not a command.
Public Snapshot is not a renderer.
Public Snapshot is not a presenter.
Public Snapshot is not a view model.
Public Snapshot is not a builder.
Public Snapshot is not runtime.
Public Snapshot is not a state store.
Public Snapshot is not a polling or observer system.
Public Snapshot is only a pure C++ contract family.
```

---

## 2. Ticket Type

```text
planning-first / contract-only / skeleton-only / no-runtime / no-ui / no-ipc / no-api / no-builder / no-files-until-planning-approved
```

The next assistant must first output:

```text
P1-031 Planning Draft v1 — Playback Timeline Public Snapshot Contract Skeleton
```

Implementation is forbidden until that planning draft is reviewed and approved.

---

## 3. Required Gates Before Planning

### 3.1 Branch Gate

The next assistant must verify:

```text
Required base: 6f2f5b45570aa1b8d58ba76c095aa436c871709c
Expected implementation branch: kivo-playback-timeline-public-snapshot-contract-p1-031
```

Required raw commands:

```powershell
git branch --show-current
git rev-parse HEAD
git status --short
```

STOP if HEAD is not the accepted P1-030 commit:

```text
STOP_BASELINE_FAILED
```

### 3.2 Clean Workspace Gate

`git status --short` must be empty before planning or implementation.

STOP if non-empty:

```text
STOP_WORKSPACE_NOT_CLEAN
```

### 3.3 Inventory Gate

Do not rely on memory. The next assistant must inspect the real repository state.

Mandatory checks:

```text
src/playback/timeline_public_snapshot/
tests/playback/timeline_public_snapshot/
src/playback/timeline_public_read_model/identity/timeline_public_read_model_identity.h
src/playback/timeline_public_read_model/model/
src/playback/timeline_public_read_model/outcome/
CMakeLists.txt
```

Expected status before implementation:

```text
src/playback/timeline_public_snapshot/                  NOT_EXISTS
tests/playback/timeline_public_snapshot/                NOT_EXISTS
src/playback/timeline_public_read_model/identity/...     EXISTS
```

If public snapshot directories already exist, list them and STOP unless the task is explicitly converted into repair / continuation.

STOP:

```text
STOP_EXISTING_TIMELINE_PUBLIC_SNAPSHOT_FOUND
```

---

## 4. Dependency Direction

P1-031 may depend directly on P1-030 identity only:

```text
Allowed direct include:
playback/timeline_public_read_model/identity/timeline_public_read_model_identity.h
```

P1-031 must not directly include P1-030 model / record / envelope / outcome / classification types.

Forbidden direct includes:

```text
playback/timeline_public_read_model/anchor/**
playback/timeline_public_read_model/classification/**
playback/timeline_public_read_model/model/**
playback/timeline_public_read_model/outcome/**
```

Reason:

```text
P1-031 should anchor to the public read model identity, not clone or bind to the read model payload graph.
```

Forbidden dependency direction:

```text
P1-030 must not be modified to know P1-031.
P1-029 must not be modified to know P1-031.
P1-020 through P1-030 must remain read-only.
P0 contracts must remain read-only.
```

---

## 5. Proposed Family Tree

Recommended root:

```text
src/playback/timeline_public_snapshot/
```

Recommended subfamilies:

```text
src/playback/timeline_public_snapshot/
  identity/
  anchor/
  classification/
  snapshot/
  outcome/
  CMakeLists.txt
```

Recommended tests:

```text
tests/playback/timeline_public_snapshot/
  CMakeLists.txt
  timeline_public_snapshot_identity_tests.cpp
  timeline_public_snapshot_anchor_tests.cpp
  timeline_public_snapshot_classification_tests.cpp
  timeline_public_snapshot_snapshot_tests.cpp
  timeline_public_snapshot_outcome_tests.cpp
  timeline_public_snapshot_boundary_tests.cpp
```

Root direct children count:

```text
5 subfamilies + CMakeLists.txt = 6
```

Fan-out target:

```text
PASS if root direct children <= 7
```

---

## 6. Proposed Production Headers

Expected production headers: 18.

### 6.1 identity/ — 4 files

```text
identity/timeline_public_snapshot_id.h
identity/timeline_public_snapshot_sequence_id.h
identity/timeline_public_snapshot_generation.h
identity/timeline_public_snapshot_identity.h
```

Responsibilities:

```text
TimelinePublicSnapshotId: typed uint64_t wrapper only.
TimelinePublicSnapshotSequenceId: typed uint64_t wrapper only.
TimelinePublicSnapshotGeneration: typed uint64_t wrapper only.
TimelinePublicSnapshotIdentity: aggregate id + sequence + generation only.
```

### 6.2 anchor/ — 2 files

```text
anchor/timeline_public_read_model_snapshot_anchor.h
anchor/timeline_public_snapshot_anchor_set.h
```

Responsibilities:

```text
TimelinePublicReadModelSnapshotAnchor: holds TimelinePublicReadModelIdentity only.
TimelinePublicSnapshotAnchorSet: holds TimelinePublicReadModelSnapshotAnchor only.
```

This one-anchor set is intentional. It keeps the same genealogy pattern as previous families while leaving a safe extension point without introducing runtime behavior.

### 6.3 classification/ — 4 files

```text
classification/timeline_public_snapshot_availability.h
classification/timeline_public_snapshot_freshness.h
classification/timeline_public_snapshot_audience.h
classification/timeline_public_snapshot_classification.h
```

Responsibilities:

```text
TimelinePublicSnapshotAvailability: Available / Unavailable / Pending / Unknown.
TimelinePublicSnapshotFreshness: Fresh / Stale / Pending / Unknown.
TimelinePublicSnapshotAudience: Internal / UserVisible / DiagnosticSafe / Unknown.
TimelinePublicSnapshotClassification: aggregate availability + freshness + audience only.
```

### 6.4 snapshot/ — 4 files

```text
snapshot/timeline_public_snapshot_candidate.h
snapshot/playback_timeline_public_snapshot.h
snapshot/timeline_public_snapshot_envelope.h
snapshot/timeline_public_snapshot_record.h
```

Responsibilities:

```text
TimelinePublicSnapshotCandidate: identity + anchors + classification before acceptance.
PlaybackTimelinePublicSnapshot: accepted public snapshot payload contract.
TimelinePublicSnapshotEnvelope: lightweight envelope around identity + anchors + classification.
TimelinePublicSnapshotRecord: envelope + snapshot pair.
```

### 6.5 outcome/ — 4 files

```text
outcome/timeline_public_snapshot_status.h
outcome/timeline_public_snapshot_outcome.h
outcome/timeline_public_snapshot_rejection_reason.h
outcome/timeline_public_snapshot_drop_reason.h
```

Responsibilities:

```text
TimelinePublicSnapshotStatus: Recorded / Rejected / Dropped / Unknown.
TimelinePublicSnapshotOutcome: identity + status only.
TimelinePublicSnapshotRejectionReason: ReadModelAnchorMissing / ClassificationInvalid / SnapshotIdentityMissing / Unknown.
TimelinePublicSnapshotDropReason: Superseded / LowerPriority / Unknown.
```

---

## 7. Suggested Skeleton Contracts

All P1-031 production contracts should use:

```cpp
namespace kivo::playback::timeline_public_snapshot {
}
```

### 7.1 identity

```cpp
struct TimelinePublicSnapshotId {
    uint64_t value{0};
};

struct TimelinePublicSnapshotSequenceId {
    uint64_t value{0};
};

struct TimelinePublicSnapshotGeneration {
    uint64_t value{0};
};

struct TimelinePublicSnapshotIdentity {
    TimelinePublicSnapshotId snapshot_id{};
    TimelinePublicSnapshotSequenceId sequence_id{};
    TimelinePublicSnapshotGeneration generation{};
};
```

### 7.2 anchor

```cpp
struct TimelinePublicReadModelSnapshotAnchor {
    kivo::playback::timeline_public_read_model::TimelinePublicReadModelIdentity read_model_identity{};
};

struct TimelinePublicSnapshotAnchorSet {
    TimelinePublicReadModelSnapshotAnchor read_model_anchor{};
};
```

### 7.3 classification

```cpp
enum class TimelinePublicSnapshotAvailability {
    Available,
    Unavailable,
    Pending,
    Unknown
};

enum class TimelinePublicSnapshotFreshness {
    Fresh,
    Stale,
    Pending,
    Unknown
};

enum class TimelinePublicSnapshotAudience {
    Internal,
    UserVisible,
    DiagnosticSafe,
    Unknown
};

struct TimelinePublicSnapshotClassification {
    TimelinePublicSnapshotAvailability availability{TimelinePublicSnapshotAvailability::Unknown};
    TimelinePublicSnapshotFreshness freshness{TimelinePublicSnapshotFreshness::Unknown};
    TimelinePublicSnapshotAudience audience{TimelinePublicSnapshotAudience::Unknown};
};
```

### 7.4 snapshot

```cpp
struct TimelinePublicSnapshotCandidate {
    TimelinePublicSnapshotIdentity identity{};
    TimelinePublicSnapshotAnchorSet anchors{};
    TimelinePublicSnapshotClassification classification{};
};

struct PlaybackTimelinePublicSnapshot {
    TimelinePublicSnapshotIdentity identity{};
    TimelinePublicSnapshotAnchorSet anchors{};
    TimelinePublicSnapshotClassification classification{};
};

struct TimelinePublicSnapshotEnvelope {
    TimelinePublicSnapshotIdentity identity{};
    TimelinePublicSnapshotAnchorSet anchors{};
    TimelinePublicSnapshotClassification classification{};
};

struct TimelinePublicSnapshotRecord {
    TimelinePublicSnapshotEnvelope envelope{};
    PlaybackTimelinePublicSnapshot snapshot{};
};
```

### 7.5 outcome

```cpp
enum class TimelinePublicSnapshotStatus {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

enum class TimelinePublicSnapshotRejectionReason {
    ReadModelAnchorMissing,
    ClassificationInvalid,
    SnapshotIdentityMissing,
    Unknown
};

enum class TimelinePublicSnapshotDropReason {
    Superseded,
    LowerPriority,
    Unknown
};

struct TimelinePublicSnapshotOutcome {
    TimelinePublicSnapshotIdentity identity{};
    TimelinePublicSnapshotStatus status{TimelinePublicSnapshotStatus::Unknown};
};
```

---

## 8. Proposed Exact Allowlist

Expected create count:

```text
26 files
```

Expected modify count:

```text
1 file
```

Expected total touched:

```text
27 files
```

Allowed create:

```text
src/playback/timeline_public_snapshot/CMakeLists.txt

src/playback/timeline_public_snapshot/identity/timeline_public_snapshot_id.h
src/playback/timeline_public_snapshot/identity/timeline_public_snapshot_sequence_id.h
src/playback/timeline_public_snapshot/identity/timeline_public_snapshot_generation.h
src/playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h

src/playback/timeline_public_snapshot/anchor/timeline_public_read_model_snapshot_anchor.h
src/playback/timeline_public_snapshot/anchor/timeline_public_snapshot_anchor_set.h

src/playback/timeline_public_snapshot/classification/timeline_public_snapshot_availability.h
src/playback/timeline_public_snapshot/classification/timeline_public_snapshot_freshness.h
src/playback/timeline_public_snapshot/classification/timeline_public_snapshot_audience.h
src/playback/timeline_public_snapshot/classification/timeline_public_snapshot_classification.h

src/playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_candidate.h
src/playback/timeline_public_snapshot/snapshot/playback_timeline_public_snapshot.h
src/playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_envelope.h
src/playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_record.h

src/playback/timeline_public_snapshot/outcome/timeline_public_snapshot_status.h
src/playback/timeline_public_snapshot/outcome/timeline_public_snapshot_outcome.h
src/playback/timeline_public_snapshot/outcome/timeline_public_snapshot_rejection_reason.h
src/playback/timeline_public_snapshot/outcome/timeline_public_snapshot_drop_reason.h

tests/playback/timeline_public_snapshot/CMakeLists.txt
tests/playback/timeline_public_snapshot/timeline_public_snapshot_identity_tests.cpp
tests/playback/timeline_public_snapshot/timeline_public_snapshot_anchor_tests.cpp
tests/playback/timeline_public_snapshot/timeline_public_snapshot_classification_tests.cpp
tests/playback/timeline_public_snapshot/timeline_public_snapshot_snapshot_tests.cpp
tests/playback/timeline_public_snapshot/timeline_public_snapshot_outcome_tests.cpp
tests/playback/timeline_public_snapshot/timeline_public_snapshot_boundary_tests.cpp
```

Allowed modify:

```text
CMakeLists.txt
```

Root CMakeLists.txt may only add:

```cmake
add_subdirectory(src/playback/timeline_public_snapshot)
add_subdirectory(tests/playback/timeline_public_snapshot)
```

---

## 9. Forbidden Files

Implementation must not modify:

```text
src/playback/orchestration/**
src/playback/control/**
src/playback/timeline_request/**
src/playback/timeline_decision/**
src/playback/timeline_result/**
src/playback/timeline_snapshot_observation/**
src/playback/timeline_state_summary/**
src/playback/timeline_chain_integrity/**
src/playback/timeline_error_surface/**
src/playback/timeline_user_status_surface/**
src/playback/timeline_public_read_model/**
src/core/**
src/memory/**
src/format/**
src/capability/**
src/device/**
src/render/**
src/audio/**
src/subtitle/**
src/execution/**
src/diagnostics/**
src/scenario/**
src/demuxer/**
src/decoder/**
src/pipeline/**
scripts/**
docs/**
README.md
build.ps1
CMakePresets.json
```

Exception:

```text
This taskbook seed file exists under docs/** on a documentation-only branch.
The P1-031 implementation branch must not modify docs/**.
```

---

## 10. Tests

Expected new executable:

```text
kivo_playback_timeline_public_snapshot_tests
```

Expected CTest after implementation:

```text
34/34 PASS
```

Reason:

```text
P1-030 ended at 33/33 PASS.
P1-031 adds one test executable.
```

Test files:

```text
timeline_public_snapshot_identity_tests.cpp
timeline_public_snapshot_anchor_tests.cpp
timeline_public_snapshot_classification_tests.cpp
timeline_public_snapshot_snapshot_tests.cpp
timeline_public_snapshot_outcome_tests.cpp
timeline_public_snapshot_boundary_tests.cpp
```

Minimum test coverage:

```text
identity default zero values
anchor default read model identity values
classification default Unknown values
classification explicit values
candidate / snapshot / envelope / record field propagation
outcome default Unknown status
outcome explicit Recorded / Rejected / Dropped status
boundary construction with aggregate initialization
forbidden dependency boundary includes compile clean
```

---

## 11. Forbidden Token Scan Rules

Scan file contents only, not file paths.

Scan scope:

```text
src/playback/timeline_public_snapshot/**
tests/playback/timeline_public_snapshot/**
```

Forbidden boundary tokens:

```text
D3D11
DXGI
Vulkan
Metal
OpenGL
windows.h
HWND
HANDLE
void*
uintptr_t
AVFrame
AVPacket
AVBufferRef
FFmpeg
libav
swapchain
shader
WAVEFORMATEX
IMMDevice
IAudioClient
IAudioRenderClient
CoInitialize
WASAPI
Win32
COM
std::filesystem
std::ifstream
std::ofstream
socket
HTTP
HTTPS
TCP
UDP
```

Forbidden behavior tokens:

```text
UI
frontend
Tauri
IPC
API
endpoint
command
renderer
presenter
view model
builder
reporter
diagnostics
telemetry
trace
logger
logging
observer
monitor
watcher
poller
polling
validator
checker
verifier
runtime
engine
loop
callback
std::function
dispatcher
executor
scheduler
state machine
state manager
state reducer
state store
thread
queue
clock
timer
wait
sleep
decoder
demuxer
audio output
subtitle parser
```

Legal identifiers:

```text
TimelinePublicSnapshotId
TimelinePublicSnapshotSequenceId
TimelinePublicSnapshotGeneration
TimelinePublicSnapshotIdentity
TimelinePublicReadModelSnapshotAnchor
TimelinePublicSnapshotAnchorSet
TimelinePublicSnapshotAvailability
TimelinePublicSnapshotFreshness
TimelinePublicSnapshotAudience
TimelinePublicSnapshotClassification
TimelinePublicSnapshotCandidate
PlaybackTimelinePublicSnapshot
TimelinePublicSnapshotEnvelope
TimelinePublicSnapshotRecord
TimelinePublicSnapshotStatus
TimelinePublicSnapshotOutcome
TimelinePublicSnapshotRejectionReason
TimelinePublicSnapshotDropReason
TimelinePublicReadModelIdentity
Available
Unavailable
Pending
Unknown
Fresh
Stale
Internal
UserVisible
DiagnosticSafe
Recorded
Rejected
Dropped
ReadModelAnchorMissing
ClassificationInvalid
SnapshotIdentityMissing
Superseded
LowerPriority
```

Do not scan these legal substrings as standalone substring matches:

```text
public
snapshot
read
model
status
freshness
audience
anchor
identity
classification
record
outcome
availability
```

---

## 12. STOP Conditions

The next planning draft must include these STOP codes and may add more if inventory reveals more risk.

```text
STOP_BASELINE_FAILED
STOP_WORKSPACE_NOT_CLEAN
STOP_EXISTING_TIMELINE_PUBLIC_SNAPSHOT_FOUND
STOP_P1_PUBLIC_READ_MODEL_IDENTITY_MISSING
STOP_P1_PUBLIC_READ_MODEL_NON_IDENTITY_INCLUDE_ATTEMPTED
STOP_P1_020_ORCHESTRATION_CHANGE_REQUIRED
STOP_P1_021_CONTROL_CHANGE_REQUIRED
STOP_P1_022_TIMELINE_REQUEST_CHANGE_REQUIRED
STOP_P1_023_TIMELINE_DECISION_CHANGE_REQUIRED
STOP_P1_024_TIMELINE_RESULT_CHANGE_REQUIRED
STOP_P1_025_TIMELINE_SNAPSHOT_OBSERVATION_CHANGE_REQUIRED
STOP_P1_026_TIMELINE_STATE_SUMMARY_CHANGE_REQUIRED
STOP_P1_027_TIMELINE_CHAIN_INTEGRITY_CHANGE_REQUIRED
STOP_P1_028_TIMELINE_ERROR_SURFACE_CHANGE_REQUIRED
STOP_P1_029_TIMELINE_USER_STATUS_SURFACE_CHANGE_REQUIRED
STOP_P1_030_TIMELINE_PUBLIC_READ_MODEL_CHANGE_REQUIRED
STOP_P0_CONTRACT_CHANGE_REQUIRED
STOP_INCLUDE_PATH_MISSING
STOP_TYPE_NAME_MISMATCH
STOP_NAMESPACE_MISMATCH
STOP_ALLOWLIST_VIOLATION
STOP_CMAKELISTS_VIOLATION
STOP_FORBIDDEN_FILE_TOUCHED
STOP_FORBIDDEN_TOKEN_FOUND
STOP_FORBIDDEN_COMMENT_IN_SOURCE
STOP_UI_LEAK
STOP_FRONTEND_LEAK
STOP_TAURI_LEAK
STOP_IPC_LEAK
STOP_API_LEAK
STOP_ENDPOINT_LEAK
STOP_COMMAND_LEAK
STOP_RENDERER_LEAK
STOP_PRESENTER_LEAK
STOP_VIEW_MODEL_LEAK
STOP_BUILDER_LEAK
STOP_REPORTER_LEAK
STOP_DIAGNOSTICS_LEAK
STOP_TELEMETRY_LEAK
STOP_TRACE_LEAK
STOP_LOGGING_LEAK
STOP_OBSERVER_LEAK
STOP_MONITOR_LEAK
STOP_WATCHER_LEAK
STOP_POLLER_LEAK
STOP_POLLING_LEAK
STOP_VALIDATOR_LEAK
STOP_CHECKER_LEAK
STOP_VERIFIER_LEAK
STOP_RUNTIME_LEAK
STOP_ENGINE_LEAK
STOP_LOOP_LEAK
STOP_CALLBACK_LEAK
STOP_DISPATCHER_LEAK
STOP_EXECUTOR_LEAK
STOP_SCHEDULER_LEAK
STOP_STATE_MACHINE_LEAK
STOP_STATE_MANAGER_LEAK
STOP_STATE_REDUCER_LEAK
STOP_STATE_STORE_LEAK
STOP_THREAD_LEAK
STOP_QUEUE_LEAK
STOP_CLOCK_LEAK
STOP_TIMER_LEAK
STOP_WAIT_LEAK
STOP_SLEEP_LEAK
STOP_FILE_IO_LEAK
STOP_NETWORK_IO_LEAK
STOP_PLATFORM_API_LEAK
STOP_TESTS_NOT_ADDED
STOP_CTEST_NOT_34_OF_34
STOP_GOVERNANCE_NOT_4_OF_4
STOP_REMOTE_NOT_SYNCED
```

---

## 13. Planning Draft Acceptance Criteria

The next assistant's planning draft must be standalone.

It must include:

```text
Branch Gate
Clean Workspace Gate
Inventory Gate with fresh repository reads
P1 Continuity Gate
Dependency direction plan
Whole tree family plan
Folder fan-out proof
Single-file responsibility table
Suggested skeleton contracts
Exact allowlist
Forbidden files
Tests structure
Forbidden token scan rules
STOP conditions
Final report requirements
```

Do not accept a planning draft that uses:

```text
unchanged
same as above
as specified
remaining sections
no deviations
through
and so on
etc.
...
```

---

## 14. Implementation Acceptance Criteria

Implementation may be accepted only if:

```text
Created files: 26
Modified files: 1
Total touched files: 27
CTest: 34/34 PASS
Governance: 4/4 PASS
Standalone Forbidden Token Scan: PASS
Working tree: clean
Remote: synced
P1-020 through P1-030 untouched
P0 contracts untouched
Only TimelinePublicReadModelIdentity direct-consumed from P1-030
No P1-030 model / envelope / record / outcome direct include
No UI / IPC / API / runtime introduced
No builder / observer / state store introduced
```

The phrase `P1-020 through P1-030 untouched` above is only a summary in this seed file. The final planning draft must expand every protected family individually.

---

## 15. Required Final Report Raw Outputs

Implementation final report must include raw output:

```text
git status --short
git branch --show-current
git rev-parse HEAD
git show --stat --oneline --name-status -1
ctest --test-dir out/build/windows-msvc-debug --output-on-failure
Standalone Forbidden Token Scan raw output
git rev-parse origin/kivo-playback-timeline-public-snapshot-contract-p1-031
```

Final report must prove individually:

```text
Branch
HEAD
Remote HEAD
Working tree status
Push status
Created files: 26
Modified files: 1
CTest result: 34/34 PASS
Governance result: 4/4 PASS
Standalone Forbidden Token Scan result: PASS
P1-020 orchestration untouched
P1-021 control untouched
P1-022 timeline_request untouched
P1-023 timeline_decision untouched
P1-024 timeline_result untouched
P1-025 timeline_snapshot_observation untouched
P1-026 timeline_state_summary untouched
P1-027 timeline_chain_integrity untouched
P1-028 timeline_error_surface untouched
P1-029 timeline_user_status_surface untouched
P1-030 timeline_public_read_model untouched except direct identity consume
P0 contracts untouched
Only TimelinePublicReadModelIdentity direct-consumed
No heavy read model payload direct include
No UI introduced
No IPC introduced
No API introduced
No runtime introduced
No builder introduced
Namespace: kivo::playback::timeline_public_snapshot
Genealogy tree: 5 subfamilies, 18 production headers
```

---

## 16. Next Assistant Instruction

The next assistant must not implement directly from this seed.

Required next step:

```text
Review docs/taskbooks/P1-031_PLAYBACK_TIMELINE_PUBLIC_SNAPSHOT_CONTRACT_SKELETON.md
Inspect the actual repository at base 6f2f5b45570aa1b8d58ba76c095aa436c871709c
Produce P1-031 Planning Draft v1 as a standalone full document
Wait for review before implementation
```
