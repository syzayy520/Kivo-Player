# P1-031 to P1-045 — Playback Timeline Future Taskbook Pack

Status: `TASKBOOK_PACK_SEED_FOR_REVIEW`

This file exists because one isolated P1-031 seed is not enough for handoff continuity. It gives the next assistants a full forward queue for the remaining playback timeline public-surface contract line.

This pack is not implementation approval. Every ticket below must still begin with a standalone Planning Draft, real repository inventory, clean workspace gate, branch gate, family tree gate, allowlist gate, forbidden token scan plan, STOP conditions, and final report requirements.

Current accepted base:

```text
P1-030 Playback Timeline Public Read Model Skeleton
Commit: 6f2f5b45570aa1b8d58ba76c095aa436c871709c
Classification: PASS_PUSHED_ACCEPTED
```

Taskbook seed branch:

```text
kivo-playback-taskbook-p1-031-public-snapshot-contract
```

Implementation branches must be created from the accepted base of the immediately previous implemented ticket, not from this docs-only seed branch.

---

## Global Rules For Every Ticket In This Pack

### Always planning first

Each ticket must first output a standalone Planning Draft.

Forbidden before planning approval:

```text
code changes
src file creation
test file creation
CMakeLists modification
commit
push
```

### Required gates

Every Planning Draft and every Implementation Final Report must cover:

```text
Branch Gate
Clean Workspace Gate
Inventory Gate
Family Tree Gate
Allowlist Gate
Forbidden Files Gate
Forbidden Token Scan Gate
P0/P1 Continuity Gate
CTest expectation
Governance expectation
Final Report raw-output requirement
STOP Conditions
```

### Family law

```text
folder = functional family
subfolder = subfamily
single file = minimum responsibility
```

Forbidden design smells:

```text
flat helper bucket
manager catch-all
mixed responsibility file
runtime hidden inside contract family
state store hidden inside snapshot family
builder hidden inside contract ticket
observer hidden inside public surface ticket
poller hidden inside status ticket
```

### Protected previous families

Unless a later approved repair explicitly says otherwise, every future ticket must treat these as read-only:

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
```

Later tickets may direct-consume explicitly named identity headers only when the ticket says so.

### Universal forbidden runtime/UI/API tokens

Every contract-only ticket must forbid file contents containing:

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
std::filesystem
std::ifstream
std::ofstream
socket
HTTP
HTTPS
TCP
UDP
D3D11
DXGI
Vulkan
Metal
OpenGL
Win32
COM
WASAPI
FFmpeg
libav
AVFrame
AVPacket
```

The scan must check file contents only, not path substrings.

---

# Phase A — Public Timeline Surface Closure

These tickets finish the public timeline data surface without implementing UI, IPC, API, runtime, or builders.

---

## P1-031 — Playback Timeline Public Snapshot Contract Skeleton

Branch:

```text
kivo-playback-timeline-public-snapshot-contract-p1-031
```

Purpose:

```text
Define a public snapshot contract that anchors to TimelinePublicReadModelIdentity only.
```

Allowed direct dependency:

```text
playback/timeline_public_read_model/identity/timeline_public_read_model_identity.h
```

Forbidden direct dependency:

```text
playback/timeline_public_read_model/anchor/**
playback/timeline_public_read_model/classification/**
playback/timeline_public_read_model/model/**
playback/timeline_public_read_model/outcome/**
```

Root family:

```text
src/playback/timeline_public_snapshot/
```

Subfamilies:

```text
identity/
anchor/
classification/
snapshot/
outcome/
```

Production headers:

```text
identity/timeline_public_snapshot_id.h
identity/timeline_public_snapshot_sequence_id.h
identity/timeline_public_snapshot_generation.h
identity/timeline_public_snapshot_identity.h
anchor/timeline_public_read_model_snapshot_anchor.h
anchor/timeline_public_snapshot_anchor_set.h
classification/timeline_public_snapshot_availability.h
classification/timeline_public_snapshot_freshness.h
classification/timeline_public_snapshot_audience.h
classification/timeline_public_snapshot_classification.h
snapshot/timeline_public_snapshot_candidate.h
snapshot/playback_timeline_public_snapshot.h
snapshot/timeline_public_snapshot_envelope.h
snapshot/timeline_public_snapshot_record.h
outcome/timeline_public_snapshot_status.h
outcome/timeline_public_snapshot_outcome.h
outcome/timeline_public_snapshot_rejection_reason.h
outcome/timeline_public_snapshot_drop_reason.h
```

Expected test executable:

```text
kivo_playback_timeline_public_snapshot_tests
```

Expected CTest after implementation:

```text
34/34 PASS
```

---

## P1-032 — Playback Timeline Public Delta Contract Skeleton

Branch:

```text
kivo-playback-timeline-public-delta-contract-p1-032
```

Purpose:

```text
Define a public delta contract that can describe differences between public snapshots without implementing comparison logic.
```

Allowed direct dependencies:

```text
playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h
```

Forbidden direct dependencies:

```text
playback/timeline_public_snapshot/snapshot/**
playback/timeline_public_snapshot/outcome/**
playback/timeline_public_read_model/model/**
```

Root family:

```text
src/playback/timeline_public_delta/
```

Subfamilies:

```text
identity/
anchor/
classification/
delta/
outcome/
```

Production headers:

```text
identity/timeline_public_delta_id.h
identity/timeline_public_delta_sequence_id.h
identity/timeline_public_delta_generation.h
identity/timeline_public_delta_identity.h
anchor/timeline_public_snapshot_delta_anchor.h
anchor/timeline_public_delta_anchor_set.h
classification/timeline_public_delta_kind.h
classification/timeline_public_delta_scope.h
classification/timeline_public_delta_classification.h
delta/timeline_public_delta_candidate.h
delta/playback_timeline_public_delta.h
delta/timeline_public_delta_envelope.h
delta/timeline_public_delta_record.h
outcome/timeline_public_delta_status.h
outcome/timeline_public_delta_outcome.h
outcome/timeline_public_delta_rejection_reason.h
outcome/timeline_public_delta_drop_reason.h
```

Expected test executable:

```text
kivo_playback_timeline_public_delta_tests
```

Expected CTest:

```text
35/35 PASS
```

---

## P1-033 — Playback Timeline Public Query Contract Skeleton

Branch:

```text
kivo-playback-timeline-public-query-contract-p1-033
```

Purpose:

```text
Define contract-only public query intent types for requesting public timeline data later. No query execution, no API, no IPC, no command.
```

Allowed direct dependencies:

```text
playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h
playback/timeline_public_delta/identity/timeline_public_delta_identity.h
```

Root family:

```text
src/playback/timeline_public_query/
```

Subfamilies:

```text
identity/
target/
classification/
query/
outcome/
```

Production headers:

```text
identity/timeline_public_query_id.h
identity/timeline_public_query_sequence_id.h
identity/timeline_public_query_generation.h
identity/timeline_public_query_identity.h
target/timeline_public_snapshot_query_target.h
target/timeline_public_delta_query_target.h
target/timeline_public_query_target_set.h
classification/timeline_public_query_kind.h
classification/timeline_public_query_scope.h
classification/timeline_public_query_classification.h
query/timeline_public_query_candidate.h
query/playback_timeline_public_query.h
query/timeline_public_query_envelope.h
query/timeline_public_query_record.h
outcome/timeline_public_query_status.h
outcome/timeline_public_query_outcome.h
outcome/timeline_public_query_rejection_reason.h
outcome/timeline_public_query_drop_reason.h
```

Expected test executable:

```text
kivo_playback_timeline_public_query_tests
```

Expected CTest:

```text
36/36 PASS
```

---

## P1-034 — Playback Timeline Public Response Contract Skeleton

Branch:

```text
kivo-playback-timeline-public-response-contract-p1-034
```

Purpose:

```text
Define a contract-only response envelope for future public query results. No execution. No transport. No API. No IPC.
```

Allowed direct dependencies:

```text
playback/timeline_public_query/identity/timeline_public_query_identity.h
playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h
playback/timeline_public_delta/identity/timeline_public_delta_identity.h
```

Root family:

```text
src/playback/timeline_public_response/
```

Subfamilies:

```text
identity/
anchor/
classification/
response/
outcome/
```

Production headers:

```text
identity/timeline_public_response_id.h
identity/timeline_public_response_sequence_id.h
identity/timeline_public_response_generation.h
identity/timeline_public_response_identity.h
anchor/timeline_public_query_response_anchor.h
anchor/timeline_public_snapshot_response_anchor.h
anchor/timeline_public_delta_response_anchor.h
anchor/timeline_public_response_anchor_set.h
classification/timeline_public_response_kind.h
classification/timeline_public_response_status_class.h
classification/timeline_public_response_classification.h
response/timeline_public_response_candidate.h
response/playback_timeline_public_response.h
response/timeline_public_response_envelope.h
response/timeline_public_response_record.h
outcome/timeline_public_response_status.h
outcome/timeline_public_response_outcome.h
outcome/timeline_public_response_rejection_reason.h
outcome/timeline_public_response_drop_reason.h
```

Expected test executable:

```text
kivo_playback_timeline_public_response_tests
```

Expected CTest:

```text
37/37 PASS
```

---

## P1-035 — Playback Timeline Public Surface Boundary Contract Skeleton

Branch:

```text
kivo-playback-timeline-public-surface-boundary-contract-p1-035
```

Purpose:

```text
Create a pure boundary index contract that ties public snapshot, delta, query, and response identities together. No transport. No endpoint. No runtime boundary object.
```

Allowed direct dependencies:

```text
playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h
playback/timeline_public_delta/identity/timeline_public_delta_identity.h
playback/timeline_public_query/identity/timeline_public_query_identity.h
playback/timeline_public_response/identity/timeline_public_response_identity.h
```

Root family:

```text
src/playback/timeline_public_surface_boundary/
```

Subfamilies:

```text
identity/
anchor/
classification/
boundary/
outcome/
```

Production headers:

```text
identity/timeline_public_surface_boundary_id.h
identity/timeline_public_surface_boundary_sequence_id.h
identity/timeline_public_surface_boundary_generation.h
identity/timeline_public_surface_boundary_identity.h
anchor/timeline_public_snapshot_boundary_anchor.h
anchor/timeline_public_delta_boundary_anchor.h
anchor/timeline_public_query_boundary_anchor.h
anchor/timeline_public_response_boundary_anchor.h
anchor/timeline_public_surface_boundary_anchor_set.h
classification/timeline_public_surface_boundary_scope.h
classification/timeline_public_surface_boundary_stability.h
classification/timeline_public_surface_boundary_classification.h
boundary/timeline_public_surface_boundary_candidate.h
boundary/playback_timeline_public_surface_boundary.h
boundary/timeline_public_surface_boundary_envelope.h
boundary/timeline_public_surface_boundary_record.h
outcome/timeline_public_surface_boundary_status.h
outcome/timeline_public_surface_boundary_outcome.h
outcome/timeline_public_surface_boundary_rejection_reason.h
outcome/timeline_public_surface_boundary_drop_reason.h
```

Expected test executable:

```text
kivo_playback_timeline_public_surface_boundary_tests
```

Expected CTest:

```text
38/38 PASS
```

---

# Phase B — Playback Lifecycle Contract Line

These tickets prepare the next non-runtime lifecycle surface. They still do not implement actual playback runtime.

---

## P1-036 — Playback Lifecycle Phase Contract Skeleton

Branch:

```text
kivo-playback-lifecycle-phase-contract-p1-036
```

Purpose:

```text
Define pure lifecycle phase contracts for playback session progression. No engine. No loop. No state machine.
```

Allowed direct dependency:

```text
playback/timeline_public_surface_boundary/identity/timeline_public_surface_boundary_identity.h
```

Root family:

```text
src/playback/lifecycle_phase/
```

Subfamilies:

```text
identity/
anchor/
classification/
phase/
outcome/
```

Core production names:

```text
LifecyclePhaseIdentity
TimelinePublicSurfaceBoundaryLifecycleAnchor
LifecyclePhaseKind
LifecyclePhaseReadiness
PlaybackLifecyclePhase
LifecyclePhaseEnvelope
LifecyclePhaseRecord
LifecyclePhaseOutcome
```

Expected CTest:

```text
39/39 PASS
```

---

## P1-037 — Playback Session Public Contract Skeleton

Branch:

```text
kivo-playback-session-public-contract-p1-037
```

Purpose:

```text
Define public playback session identity and contract shell. No session manager. No store. No runtime lifecycle engine.
```

Allowed direct dependency:

```text
playback/lifecycle_phase/identity/lifecycle_phase_identity.h
```

Root family:

```text
src/playback/session_public_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
session/
outcome/
```

Core production names:

```text
PlaybackSessionPublicIdentity
LifecyclePhaseSessionAnchor
PlaybackSessionPublicMode
PlaybackSessionPublicVisibility
PlaybackSessionPublicContract
PlaybackSessionPublicEnvelope
PlaybackSessionPublicRecord
PlaybackSessionPublicOutcome
```

Expected CTest:

```text
40/40 PASS
```

---

## P1-038 — Media Open Public Contract Skeleton

Branch:

```text
kivo-playback-media-open-public-contract-p1-038
```

Purpose:

```text
Define media-open public request/record shell. No file I/O. No decoder. No demuxer. No path scanning.
```

Allowed direct dependency:

```text
playback/session_public_contract/identity/playback_session_public_identity.h
```

Root family:

```text
src/playback/media_open_public_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
open/
outcome/
```

Core production names:

```text
MediaOpenPublicIdentity
PlaybackSessionMediaOpenAnchor
MediaOpenPublicKind
MediaOpenPublicTrustLevel
MediaOpenPublicContract
MediaOpenPublicEnvelope
MediaOpenPublicRecord
MediaOpenPublicOutcome
```

Expected CTest:

```text
41/41 PASS
```

---

## P1-039 — Stream Selection Public Contract Skeleton

Branch:

```text
kivo-playback-stream-selection-public-contract-p1-039
```

Purpose:

```text
Define stream selection public contracts for audio/video/subtitle stream identity choices. No decoder. No demuxer. No track probing.
```

Allowed direct dependency:

```text
playback/media_open_public_contract/identity/media_open_public_identity.h
```

Root family:

```text
src/playback/stream_selection_public_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
selection/
outcome/
```

Core production names:

```text
StreamSelectionPublicIdentity
MediaOpenStreamSelectionAnchor
StreamSelectionPublicKind
StreamSelectionPublicPreference
StreamSelectionPublicContract
StreamSelectionPublicEnvelope
StreamSelectionPublicRecord
StreamSelectionPublicOutcome
```

Expected CTest:

```text
42/42 PASS
```

---

## P1-040 — Seek Public Contract Skeleton

Branch:

```text
kivo-playback-seek-public-contract-p1-040
```

Purpose:

```text
Define public seek contracts. No time source. No clock. No scheduler. No runtime seek execution.
```

Allowed direct dependency:

```text
playback/stream_selection_public_contract/identity/stream_selection_public_identity.h
```

Root family:

```text
src/playback/seek_public_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
seek/
outcome/
```

Core production names:

```text
SeekPublicIdentity
StreamSelectionSeekAnchor
SeekPublicKind
SeekPublicPrecision
SeekPublicContract
SeekPublicEnvelope
SeekPublicRecord
SeekPublicOutcome
```

Expected CTest:

```text
43/43 PASS
```

---

## P1-041 — Playback Buffering Public Contract Skeleton

Branch:

```text
kivo-playback-buffering-public-contract-p1-041
```

Purpose:

```text
Define public buffering status contracts. No buffering engine. No queue. No thread. No timers.
```

Allowed direct dependency:

```text
playback/seek_public_contract/identity/seek_public_identity.h
```

Root family:

```text
src/playback/buffering_public_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
buffering/
outcome/
```

Core production names:

```text
BufferingPublicIdentity
SeekBufferingAnchor
BufferingPublicLevel
BufferingPublicPressure
BufferingPublicContract
BufferingPublicEnvelope
BufferingPublicRecord
BufferingPublicOutcome
```

Expected CTest:

```text
44/44 PASS
```

---

## P1-042 — Track Transition Public Contract Skeleton

Branch:

```text
kivo-playback-track-transition-public-contract-p1-042
```

Purpose:

```text
Define public track transition contracts. No playlist engine. No queue runtime. No file or metadata scan.
```

Allowed direct dependency:

```text
playback/buffering_public_contract/identity/buffering_public_identity.h
```

Root family:

```text
src/playback/track_transition_public_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
transition/
outcome/
```

Core production names:

```text
TrackTransitionPublicIdentity
BufferingTrackTransitionAnchor
TrackTransitionPublicKind
TrackTransitionPublicReason
TrackTransitionPublicContract
TrackTransitionPublicEnvelope
TrackTransitionPublicRecord
TrackTransitionPublicOutcome
```

Expected CTest:

```text
45/45 PASS
```

---

## P1-043 — End Of Stream Public Contract Skeleton

Branch:

```text
kivo-playback-end-of-stream-public-contract-p1-043
```

Purpose:

```text
Define public end-of-stream contracts. No playback loop. No automatic next-track execution. No queue mutation.
```

Allowed direct dependency:

```text
playback/track_transition_public_contract/identity/track_transition_public_identity.h
```

Root family:

```text
src/playback/end_of_stream_public_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
end_of_stream/
outcome/
```

Core production names:

```text
EndOfStreamPublicIdentity
TrackTransitionEndOfStreamAnchor
EndOfStreamPublicKind
EndOfStreamPublicReason
EndOfStreamPublicContract
EndOfStreamPublicEnvelope
EndOfStreamPublicRecord
EndOfStreamPublicOutcome
```

Expected CTest:

```text
46/46 PASS
```

---

## P1-044 — Playback Public Error Recovery Contract Skeleton

Branch:

```text
kivo-playback-public-error-recovery-contract-p1-044
```

Purpose:

```text
Define public error recovery contract types. No recovery runtime. No retry loop. No platform reset.
```

Allowed direct dependencies:

```text
playback/end_of_stream_public_contract/identity/end_of_stream_public_identity.h
playback/timeline_error_surface/identity/timeline_error_surface_identity.h
```

Root family:

```text
src/playback/public_error_recovery_contract/
```

Subfamilies:

```text
identity/
anchor/
classification/
recovery/
outcome/
```

Core production names:

```text
PublicErrorRecoveryIdentity
EndOfStreamPublicErrorRecoveryAnchor
TimelineErrorSurfaceRecoveryAnchor
PublicErrorRecoveryKind
PublicErrorRecoveryDisposition
PublicErrorRecoveryContract
PublicErrorRecoveryEnvelope
PublicErrorRecoveryRecord
PublicErrorRecoveryOutcome
```

Expected CTest:

```text
47/47 PASS
```

---

## P1-045 — P1 Public Playback Surface Closure Audit

Branch:

```text
kivo-playback-p1-public-surface-closure-audit-p1-045
```

Purpose:

```text
Run a planning-only and then audit-only closure over P1-020 through P1-044. This ticket should not add production contracts unless the audit explicitly finds a missing contract family and is converted into a new task.
```

Primary output:

```text
P1 Closure Audit Report
```

Expected checks:

```text
all P1 families have CMake registration
all P1 test executables are registered
all contract-only families contain no forbidden runtime/UI/API tokens
all root families obey folder fan-out policy
all family dependencies point forward only through allowed identity anchors
no P0 contracts were modified during P1 public surface line
no docs/taskbooks implementation branch leaked into production branch
```

Expected CTest after audit:

```text
47/47 PASS
```

If a code fix is needed, STOP and create a separate repair ticket. Do not silently fix in the audit ticket.

---

## Required Final-Handoff Behavior

When a future assistant opens this pack, it must not implement from this pack directly. It must:

```text
1. Pick the next unimplemented ticket.
2. Read this pack and any per-ticket seed file.
3. Inspect the actual repository.
4. Produce a standalone Planning Draft.
5. Wait for review.
6. Implement only after explicit approval.
7. Commit and push only after tests/gates/scan pass.
8. Submit raw final report outputs.
```

This pack intentionally avoids writing the exact final allowlist for every later ticket because each later planning draft must re-inventory the real repository after previous tickets land. However, each ticket above defines its root family, subfamily tree, dependency direction, expected CTest count, and core production names so the next assistant can expand it into a formal standalone taskbook without guessing the architecture direction.
