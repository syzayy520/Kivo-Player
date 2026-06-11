# P2-001 to P2-020 — Playback In-Memory Runtime Readiness Taskbook Pack

Status: `TASKBOOK_PACK_SEED_FOR_REVIEW`

This pack starts after the P1 public playback surface line is closed. P2 is the deterministic in-memory runtime-readiness phase. It is not the real platform phase.

P2 may introduce pure reducers, projectors, composers, in-memory shells, and fake-only integration surfaces. P2 must not introduce real audio devices, real video devices, real file readers, real decoders, real demuxers, real graphics APIs, real OS handles, UI, IPC, or public API commands.

Prerequisite:

```text
P1-045 P1 Public Playback Surface Closure Audit
Classification: PASS_PUSHED_ACCEPTED
```

Implementation branches must be created from the accepted commit of the immediately previous implemented ticket, not from this docs-only seed branch.

---

## Global P2 Rules

Every P2 ticket must begin with a standalone Planning Draft.

No implementation before planning approval:

```text
no src creation
no tests creation
no CMakeLists modification
no commit
no push
```

Required gates for every P2 ticket:

```text
Branch Gate
Clean Workspace Gate
Inventory Gate
Family Tree Gate
Allowlist Gate
Dependency Direction Gate
Forbidden Files Gate
Forbidden Token Scan Gate
CTest expectation
Governance expectation
STOP Conditions
Final Report raw-output requirement
```

Family rule:

```text
folder = functional family
subfolder = subfamily
single file = minimum responsibility
```

P2 forbidden implementation categories:

```text
real platform integration
real device open
real decoder library
real demuxer library
real file input
real network input
real UI
real IPC
real API command
real async runtime
real thread runtime
real timer runtime
```

P2 allowed implementation categories:

```text
pure data reducers
pure projectors
pure composers
in-memory deterministic shell
manual step function for tests
fake-only graph contract
compile-only integration
single-process deterministic tests
```

---

## P2-001 — Playback Runtime Readiness Inventory Audit

Branch:

```text
kivo-playback-runtime-readiness-inventory-audit-p2-001
```

Purpose:

```text
Audit P1-020 through P1-045 and produce the exact dependency map needed before any runtime-readiness code is written.
```

Type:

```text
planning-only / audit-only / no-code / no-files-unless-report
```

Required output:

```text
P2 Runtime Readiness Inventory Report
```

Must verify:

```text
all P1 families exist
all P1 CMake registrations exist
all P1 tests pass
all P1 roots obey family tree structure
all dependencies are identity-anchor oriented
all P1 public surface families are contract-only
```

Expected CTest:

```text
same count as P1-045
```

---

## P2-002 — Timeline Public Snapshot Projector Pure Skeleton

Branch:

```text
kivo-playback-timeline-public-snapshot-projector-p2-002
```

Purpose:

```text
Introduce a pure projector skeleton that maps accepted public read model identities to public snapshot candidate records without runtime behavior.
```

Allowed direct dependencies:

```text
playback/timeline_public_read_model/identity/timeline_public_read_model_identity.h
playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h
playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_candidate.h
```

Root family:

```text
src/playback/timeline_public_snapshot_projector/
```

Subfamilies:

```text
identity/
input/
classification/
projection/
outcome/
```

Forbidden:

```text
state store
observer
builder runtime
callback
thread
timer
```

---

## P2-003 — Timeline Public Delta Projector Pure Skeleton

Branch:

```text
kivo-playback-timeline-public-delta-projector-p2-003
```

Purpose:

```text
Introduce a pure projector skeleton that describes public delta candidate projection from snapshot identities. No diff algorithm yet.
```

Root family:

```text
src/playback/timeline_public_delta_projector/
```

Allowed direct dependencies:

```text
playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h
playback/timeline_public_delta/identity/timeline_public_delta_identity.h
```

---

## P2-004 — Timeline Public Query Resolver Pure Skeleton

Branch:

```text
kivo-playback-timeline-public-query-resolver-p2-004
```

Purpose:

```text
Introduce pure resolver contract skeleton for mapping query identities to response candidate identities. No API, no IPC, no execution.
```

Root family:

```text
src/playback/timeline_public_query_resolver/
```

Allowed direct dependencies:

```text
playback/timeline_public_query/identity/timeline_public_query_identity.h
playback/timeline_public_response/identity/timeline_public_response_identity.h
```

---

## P2-005 — Timeline Public Response Composer Pure Skeleton

Branch:

```text
kivo-playback-timeline-public-response-composer-p2-005
```

Purpose:

```text
Introduce pure composer skeleton for response records. No transport, no endpoint, no serialization.
```

Root family:

```text
src/playback/timeline_public_response_composer/
```

Allowed direct dependencies:

```text
playback/timeline_public_response/identity/timeline_public_response_identity.h
playback/timeline_public_response/response/playback_timeline_public_response.h
```

---

## P2-006 — Lifecycle Phase Reducer Pure Skeleton

Branch:

```text
kivo-playback-lifecycle-phase-reducer-p2-006
```

Purpose:

```text
Introduce a pure reducer skeleton for lifecycle phase records. No state machine runtime.
```

Root family:

```text
src/playback/lifecycle_phase_reducer/
```

Allowed direct dependency:

```text
playback/lifecycle_phase/identity/lifecycle_phase_identity.h
```

---

## P2-007 — Session Public Reducer Pure Skeleton

Branch:

```text
kivo-playback-session-public-reducer-p2-007
```

Purpose:

```text
Introduce a pure reducer skeleton for public session contract records. No session manager and no store.
```

Root family:

```text
src/playback/session_public_reducer/
```

Allowed direct dependency:

```text
playback/session_public_contract/identity/playback_session_public_identity.h
```

---

## P2-008 — Media Open Intent Adapter Pure Skeleton

Branch:

```text
kivo-playback-media-open-intent-adapter-p2-008
```

Purpose:

```text
Map public session identity to media-open candidate identity in memory. No file reading.
```

Root family:

```text
src/playback/media_open_intent_adapter/
```

---

## P2-009 — Stream Selection Intent Adapter Pure Skeleton

Branch:

```text
kivo-playback-stream-selection-intent-adapter-p2-009
```

Purpose:

```text
Map media-open identity to stream-selection candidate identity in memory. No stream probing.
```

Root family:

```text
src/playback/stream_selection_intent_adapter/
```

---

## P2-010 — Seek Intent Adapter Pure Skeleton

Branch:

```text
kivo-playback-seek-intent-adapter-p2-010
```

Purpose:

```text
Map stream-selection identity to seek candidate identity. No seek execution.
```

Root family:

```text
src/playback/seek_intent_adapter/
```

---

## P2-011 — Buffering Public Projector Pure Skeleton

Branch:

```text
kivo-playback-buffering-public-projector-p2-011
```

Purpose:

```text
Project buffering public contract identities into deterministic public status records. No buffering engine.
```

Root family:

```text
src/playback/buffering_public_projector/
```

---

## P2-012 — Track Transition Public Projector Pure Skeleton

Branch:

```text
kivo-playback-track-transition-public-projector-p2-012
```

Purpose:

```text
Project track transition public contract identities. No playlist or queue runtime.
```

Root family:

```text
src/playback/track_transition_public_projector/
```

---

## P2-013 — End Of Stream Public Projector Pure Skeleton

Branch:

```text
kivo-playback-end-of-stream-public-projector-p2-013
```

Purpose:

```text
Project end-of-stream public contract identities. No automatic next-track behavior.
```

Root family:

```text
src/playback/end_of_stream_public_projector/
```

---

## P2-014 — Public Error Recovery Projector Pure Skeleton

Branch:

```text
kivo-playback-public-error-recovery-projector-p2-014
```

Purpose:

```text
Project public error recovery contract identities. No retry runtime.
```

Root family:

```text
src/playback/public_error_recovery_projector/
```

---

## P2-015 — In-Memory Playback Public Surface Store Contract Skeleton

Branch:

```text
kivo-playback-in-memory-public-surface-store-contract-p2-015
```

Purpose:

```text
Define a deterministic in-memory store contract shell for public surface records. No global singleton. No persistence. No file I/O.
```

Root family:

```text
src/playback/in_memory_public_surface_store_contract/
```

Required planning caution:

```text
This ticket may introduce store contract types, but not a runtime store implementation.
```

---

## P2-016 — Deterministic Playback Step Contract Skeleton

Branch:

```text
kivo-playback-deterministic-step-contract-p2-016
```

Purpose:

```text
Define manual step input/output contracts for in-memory tests. No scheduler. No loop. No timers.
```

Root family:

```text
src/playback/deterministic_step_contract/
```

---

## P2-017 — Deterministic Playback Shell Skeleton

Branch:

```text
kivo-playback-deterministic-shell-skeleton-p2-017
```

Purpose:

```text
Introduce an in-memory deterministic shell that wires pure projectors and reducers through explicit step records. No threads, no callbacks, no async.
```

Root family:

```text
src/playback/deterministic_playback_shell/
```

Required planning caution:

```text
This is the first P2 shell ticket. It must have a narrow allowlist and must not mutate previous families.
```

---

## P2-018 — Deterministic Playback Scenario Tests Skeleton

Branch:

```text
kivo-playback-deterministic-scenario-tests-p2-018
```

Purpose:

```text
Add deterministic scenario tests over fake step records and public surface outputs. No real media.
```

Root family:

```text
tests/playback/deterministic_playback_scenarios/
```

Production code allowed:

```text
none unless planning finds a missing pure test fixture family
```

---

## P2-019 — P2 Performance Shape Audit

Branch:

```text
kivo-playback-p2-performance-shape-audit-p2-019
```

Purpose:

```text
Audit deterministic shell and public-surface projectors for structural performance risks. No benchmark harness required unless planning approves it.
```

Checks:

```text
no O(N) hidden scan in step shell
no global mutable singleton
no unbounded vector growth contract
no per-step heap-heavy ownership pattern unless explicit contract says so
```

---

## P2-020 — P2 In-Memory Runtime Readiness Closure Audit

Branch:

```text
kivo-playback-p2-in-memory-runtime-readiness-closure-audit-p2-020
```

Purpose:

```text
Close P2. Audit P2-001 through P2-019 for deterministic, fake-free, platform-free in-memory readiness.
```

Audit must prove:

```text
all P2 families registered correctly
all P2 tests registered correctly
all P2 families obey family tree law
all P2 dependencies are allowed
all P2 projectors/reducers remain pure
no real platform API introduced
no UI or IPC introduced
CTest all pass
forbidden token scan pass
```

If the audit finds an issue, STOP and open a dedicated repair ticket.

---

## Required Final-Handoff Behavior

A future assistant reading this pack must:

```text
1. Confirm P1-045 is accepted.
2. Pick the next unimplemented P2 ticket.
3. Inspect the actual repository.
4. Produce a standalone Planning Draft.
5. Wait for review.
6. Implement only after explicit approval.
7. Run build, CTest, governance, and token scan.
8. Commit and push only after all verification passes.
9. Submit raw final report outputs.
```
