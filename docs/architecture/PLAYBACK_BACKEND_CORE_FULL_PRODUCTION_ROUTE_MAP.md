# Playback Backend Core Full Production Route Map

Status: ACTIVE_SOURCE_OF_TRUTH
Task type: architecture-doc / full-route-map / no-code / no-src / no-tests / no-cmake
Repository: `syzayy520/Kivo-Player`

---

## 0. Purpose

This document replaces short-term ticket guessing with a full backend playback core production route.

The goal is not to keep adding small contract leaves forever. The goal is to build a commercial-grade desktop playback backend in controlled layers:

```text
contract foundation
-> public surface closure
-> route map and naming ledger
-> orchestration seam
-> media source and demux planning
-> decode pipeline planning
-> clock and sync planning
-> video/audio/subtitle render boundary planning
-> runtime backend implementation
-> API integration
-> stress/compatibility/quality gates
-> release hardening
```

This route is the source of truth for what to do after P2-039.

---

## 1. Current Accepted Baseline

Latest accepted implementation:

```text
P2-038 — Playback Timeline Public Query Delta Response Contract Skeleton
Branch: kivo-playback-timeline-public-query-delta-response-p2-038
HEAD: cd8d1cdad12a5e287aa2240c38a98a30d5668421
Build: PASS
CTest: 86/86 PASS
Governance: PASS
Source purity: PASS
```

Latest audit:

```text
P2-039 — Playback P2 Public Surface Architecture Audit and Route Map
Branch: kivo-playback-p2-public-surface-architecture-audit-p2-039
HEAD: e32c1e64a1679c8fbc113a5e47d166a5d99aaea1
Classification: PASS_WITH_CONCERNS
Decision: keep P2-037/P2-038, pause ordinary leaf growth
```

---

## 2. Hard Governance Rules

Every future task must obey:

```text
Folder = feature family
Subfolder = sub-feature family
Single file = smallest responsibility
```

Forbidden patterns:

```text
manager
helper
facade
bridge
engine as a dumping bucket
runtime mixed into contracts
types.h / defs.h buckets
wide mod files carrying logic
platform code inside core contracts
UI / IPC / API mixed into backend core contracts
```

Every implementation task must start with:

```text
1. Branch Gate
2. Clean Workspace Gate
3. Inventory Gate
4. Family Tree Gate
5. Allowlist Gate
6. Dependency Direction Gate
7. Forbidden Token Gate
8. Static Structure Self-check
9. Build / CTest / Governance Gates
10. Local HEAD == Remote HEAD proof
```

---

## 3. Route Overview

```text
P0: Contract foundation and domain contracts
P1: Playback orchestration and timeline skeletons
P2: Public surface contract closure and audit
P3: Backend core architecture map and seam consolidation
P4: Media source / demux / decode / frame pipeline implementation route
P5: Clock / sync / scheduling route
P6: Video render backend route
P7: Audio render backend route
P8: Subtitle / overlay route
P9: Runtime playback backend integration
P10: API boundary and application integration
P11: Stress, compatibility, diagnostics, quality gates
P12: Release hardening and commercial readiness
```

P0-P2 are mostly contract-first foundation. P3 starts the transition from scattered contract leaves to a coherent implementation route. No real runtime backend should be started before P3 route consolidation is accepted.

---

## 4. P0 — Contract Foundation

Status:

```text
Mostly complete based on current repository state.
```

Purpose:

```text
Define domain contracts for pipeline, probe, packet flow, decode, timeline, clock, presentation, memory, demuxer, format, capability, device, renderer, audio, subtitle, execution, diagnostics, and scenarios.
```

Deliverables:

```text
src/pipeline/contracts/**
src/pipeline/model/**
src/decoder/contracts/**
src/core/timeline/**
src/core/clock/**
src/core/presentation/**
src/memory/**
src/demuxer/contracts/**
src/format/contracts/**
src/capability/contracts/**
src/device/contracts/**
src/render/contracts/**
src/audio/contracts/**
src/subtitle/contracts/**
src/execution/contracts/**
src/diagnostics/contracts/**
src/scenario/contracts/**
```

Exit criteria:

```text
All P0 contract families compile.
All tests pass.
No runtime implementation mixed into contract families.
```

---

## 5. P1 — Playback Orchestration and Timeline Skeletons

Status:

```text
Mostly complete based on current repository state.
```

Purpose:

```text
Create typed orchestration/control/timeline skeletons without platform runtime.
```

Families:

```text
playback/orchestration
playback/control
playback/timeline_request
playback/timeline_decision
playback/timeline_result
playback/timeline_snapshot_observation
playback/timeline_state_summary
playback/timeline_chain_integrity
playback/timeline_error_surface
playback/timeline_user_status_surface
```

Exit criteria:

```text
Playback timeline command/request/decision/result chain is typed.
No real media IO or renderer backend is present.
```

---

## 6. P2 — Public Surface Contract Closure

Status:

```text
P2-037/P2-038 accepted.
P2-039 audit recommends pausing ordinary leaf growth.
```

Purpose:

```text
Define the public playback state/query/response surface and closure audits.
```

Current risk:

```text
P2 has many public-surface view/audit leaf families.
Continuing to add leaf contracts without a map risks over-fragmentation.
```

Required before any new P2 leaf:

```text
P2 public surface route map
P2 naming ledger
Keep / Freeze / Merge decision table
Public query extension chain map
```

Decision:

```text
Do not continue ordinary P2 leaf implementation until P3/P2-map consolidation is complete.
```

---

## 7. P3 — Architecture Consolidation Layer

Purpose:

```text
Convert P0-P2 contract forest into an explainable backend implementation route.
```

P3 must produce documents only at first.

Recommended P3 tasks:

```text
P3-001 — Playback Public Surface Route Map and Naming Ledger
P3-002 — Playback Backend Core Family Map
P3-003 — Playback Runtime Boundary Map
P3-004 — Playback Implementation Readiness Audit
P3-005 — Contract-to-Implementation Trace Matrix
```

Allowed files:

```text
docs/architecture/P2_PUBLIC_SURFACE_ROUTE_MAP.md
docs/architecture/P2_PUBLIC_SURFACE_NAMING_LEDGER.md
docs/architecture/PLAYBACK_BACKEND_CORE_FAMILY_MAP.md
docs/architecture/PLAYBACK_RUNTIME_BOUNDARY_MAP.md
docs/audits/PLAYBACK_IMPLEMENTATION_READINESS_AUDIT.md
docs/traceability/PLAYBACK_CONTRACT_TO_IMPLEMENTATION_TRACE_MATRIX.md
```

Forbidden files:

```text
src/**
tests/**
CMakeLists.txt
scripts/**
```

Exit criteria:

```text
Every existing contract family has a role.
Every future implementation family has an owner.
No duplicate or near-synonym family continues without classification.
Runtime boundary is clear.
```

---

## 8. P4 — Media Source, Demux, Decode, and Frame Pipeline Route

Purpose:

```text
Plan and then implement the real media ingestion path in isolated stages.
```

Subroutes:

```text
P4-A Media source boundary
P4-B Demux session boundary
P4-C Stream selection and format negotiation
P4-D Decode packet queue
P4-E Video frame output boundary
P4-F Audio sample output boundary
P4-G Error and recovery propagation
```

Implementation family direction:

```text
src/playback_backend/media_source/**
src/playback_backend/demux_session/**
src/playback_backend/decode_session/**
src/playback_backend/frame_pipeline/**
```

Important rule:

```text
Do not put FFmpeg types into public playback contracts.
If FFmpeg is used, it must live behind a backend adapter boundary.
```

Exit criteria:

```text
Open local file.
Probe streams.
Select streams.
Demux packets.
Decode frames into internal neutral frame contracts.
No renderer dependency yet.
```

---

## 9. P5 — Clock, Timeline, Sync, and Scheduling Route

Purpose:

```text
Turn typed timeline/clock contracts into a real playback timing core.
```

Subroutes:

```text
P5-A Master clock policy
P5-B Audio clock feedback seam
P5-C Video presentation scheduler
P5-D Pause/resume/seek timebase
P5-E Drift detection and correction
P5-F Backpressure and underrun signaling
P5-G Timeline reset and recovery behavior
```

Implementation family direction:

```text
src/playback_backend/clock_runtime/**
src/playback_backend/timeline_runtime/**
src/playback_backend/scheduler/**
src/playback_backend/sync_control/**
```

Exit criteria:

```text
Paused and playing timelines behave predictably.
Seek and flush update timebase cleanly.
Audio/video drift has observable policy.
```

---

## 10. P6 — Video Render Backend Route

Purpose:

```text
Implement the video output path behind a renderer boundary.
```

Subroutes:

```text
P6-A Renderer abstraction boundary
P6-B Surface lifecycle and pool runtime
P6-C GPU upload / hardware frame handling policy
P6-D Presentation queue runtime
P6-E HDR/color metadata propagation
P6-F Resize/display mode transition policy
P6-G Renderer diagnostics and recovery
```

Implementation family direction:

```text
src/playback_backend/video_render/**
src/playback_backend/surface_pool/**
src/playback_backend/presentation_queue/**
```

Platform rule:

```text
D3D11/DXGI may appear only inside explicit platform backend folders after a platform-boundary task allows them.
They must never leak into core public contracts.
```

Exit criteria:

```text
Decoded video frames can be scheduled and presented.
Renderer failure is classified and recoverable.
No UI ownership leaks into backend core.
```

---

## 11. P7 — Audio Render Backend Route

Purpose:

```text
Implement the audio output path with a real endpoint/backend seam.
```

Subroutes:

```text
P7-A Audio endpoint selection boundary
P7-B Format negotiation and shared/exclusive mode policy
P7-C Audio buffer writer runtime
P7-D Audio clock feedback
P7-E Underrun/glitch telemetry
P7-F Device lost and fallback policy
P7-G Passthrough policy if supported
```

Implementation family direction:

```text
src/playback_backend/audio_endpoint/**
src/playback_backend/audio_render/**
src/playback_backend/audio_clock_feedback/**
```

Platform rule:

```text
WASAPI/COM/HRESULT may appear only in explicit Windows audio backend folders after a platform-boundary task allows them.
They must never appear in contract-only or public surface folders.
```

Exit criteria:

```text
Audio plays through selected endpoint.
Audio clock feedback drives sync.
Underrun/device-lost paths are observable.
```

---

## 12. P8 — Subtitle and Overlay Route

Purpose:

```text
Implement subtitle and overlay handling behind contract boundaries.
```

Subroutes:

```text
P8-A Subtitle stream decode boundary
P8-B Text subtitle timing model
P8-C Bitmap subtitle timing model
P8-D Overlay composition boundary
P8-E Font/style/layout policy
P8-F Subtitle delay and sync adjustment
```

Implementation family direction:

```text
src/playback_backend/subtitle_runtime/**
src/playback_backend/overlay_runtime/**
```

Exit criteria:

```text
Subtitle events can be scheduled against playback timeline.
Overlay composition is isolated from UI.
```

---

## 13. P9 — Runtime Playback Backend Integration

Purpose:

```text
Assemble media source, demux, decode, clock, scheduler, video, audio, subtitle into a backend runtime.
```

Subroutes:

```text
P9-A Runtime session lifecycle
P9-B Open/play/pause/seek/stop/close command flow
P9-C Queue and track transition runtime
P9-D Flush/drop/ack runtime behavior
P9-E Error recovery and fallback runtime
P9-F Diagnostics event emission
P9-G Controlled shutdown and resource release
```

Implementation family direction:

```text
src/playback_backend/session_runtime/**
src/playback_backend/command_runtime/**
src/playback_backend/recovery_runtime/**
src/playback_backend/diagnostics_runtime/**
```

Exit criteria:

```text
One local file can open, decode, play, pause, seek, stop, and close.
Failure paths are classified.
No UI coupling is introduced.
```

---

## 14. P10 — API Boundary and Application Integration

Purpose:

```text
Expose backend playback capabilities to application layer without leaking backend internals.
```

Subroutes:

```text
P10-A Public backend command API
P10-B Public state/query API
P10-C Event subscription boundary
P10-D Thread ownership and call boundary
P10-E UI-safe state projection
P10-F Error reporting contract
```

Implementation family direction:

```text
src/playback_api/**
src/playback_app_boundary/**
```

Rule:

```text
API must consume stable public contracts, not backend-private FFmpeg/D3D/WASAPI/platform details.
```

Exit criteria:

```text
Application can drive backend through typed API.
Application can observe playback state without owning runtime internals.
```

---

## 15. P11 — Stress, Compatibility, and Quality Gates

Purpose:

```text
Prove the backend behaves under real-world media and failure pressure.
```

Test lanes:

```text
1. Short clips
2. Long duration files
3. High bitrate video
4. Variable frame rate video
5. Multi-audio stream media
6. Subtitle-heavy media
7. Seek storm
8. Pause/resume storm
9. Device lost and recovery
10. Corrupt media
11. Unsupported codec/format
12. Rapid open/close
13. Memory pressure
14. Renderer reset
15. Audio underrun
```

Required tooling:

```text
stress test harness
scenario media manifest
diagnostics trace capture
performance baseline report
regression gate script
```

Exit criteria:

```text
No crash in core scenarios.
No resource leak in repeated open/close.
Seek/pause/play are stable.
Diagnostics explain failures.
```

---

## 16. P12 — Release Hardening and Commercial Readiness

Purpose:

```text
Prepare backend playback core for commercial desktop product integration.
```

Subroutes:

```text
P12-A Crash resilience
P12-B Logging and telemetry policy
P12-C Feature capability reporting
P12-D Runtime configuration policy
P12-E Installer/runtime dependency audit
P12-F User-visible error translation
P12-G Performance and startup budget
P12-H Maintenance and regression policy
```

Exit criteria:

```text
Backend core is stable enough for product UI integration and wider media testing.
```

---

## 17. Ticket Granularity Rule

No future task may be created as an isolated leaf without being assigned to a route:

```text
P3 architecture consolidation
P4 media/decode pipeline
P5 clock/sync
P6 video render
P7 audio render
P8 subtitle/overlay
P9 runtime integration
P10 API integration
P11 QA/stress
P12 release hardening
```

Every ticket title must include:

```text
route id
family name
task type
allowed files
forbidden files
verification gates
```

---

## 18. Next Immediate Work

Recommended next task:

```text
P3-001 — Playback Public Surface Route Map and Naming Ledger
```

Why this comes next:

```text
P2-039 found that P2 public surface has too many view/audit leaf families.
Before runtime implementation starts, we must classify existing P2 families and lock naming rules.
```

Allowed files:

```text
docs/architecture/P2_PUBLIC_SURFACE_ROUTE_MAP.md
docs/architecture/P2_PUBLIC_SURFACE_NAMING_LEDGER.md
```

Forbidden files:

```text
src/**
tests/**
CMakeLists.txt
scripts/**
README.md
CMakePresets.json
build.ps1
```

Expected outcome:

```text
P2 family keep/freeze/merge table
Id vs Key naming ledger
public query chain map
explicit stop rule for near-synonym leaf growth
next implementation gate
```

---

## 19. Final Decision

```text
FULL_BACKEND_ROUTE_MAP_CREATED
P2 leaf growth: PAUSED
P3 architecture consolidation: NEXT
Runtime implementation: NOT_ALLOWED_YET
Reason: contract foundation must be mapped before real backend runtime begins
```
