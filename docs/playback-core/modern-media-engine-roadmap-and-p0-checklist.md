# Kivo Playback Core — Modern Media Engine Roadmap & P0 Master Checklist

Status: ROADMAP_V1_POLISHED  
Scope: Kivo Video / Windows desktop local video player / self-owned playback core  
Purpose: This document is the project-level route map and execution checklist for the playback core. It must be stored in the repository and used as the source of truth for P0 planning.  
Rule: Do not rely on memory. Every future P0 ticket must check this roadmap before planning.

---

## 0. Executive Decision

Kivo playback core is not a normal wrapper-player route. It is a modern professional/commercial media engine route.

The current route is correct:

- C++23 + CMake + MSVC + Ninja
- Win32 native window
- DirectComposition + Direct2D / DirectWrite
- self-owned Kivo UI Runtime
- self-owned Playback Engine / Pipeline / State Machine
- FFmpeg/libav as adapter-only
- D3D11 / DXGI / DXVA / D3D11VA planned as backend adapters
- WASAPI shared/exclusive and future HDMI bitstream passthrough
- HDR / Dolby / Atmos enter through capability and negotiation, not marketing claims
- libmpv is reference lane only
- madVR is visual benchmark only

The current implementation has completed the correct foundation:

- P0-001 Core Foundation
- P0-002 Pipeline Contracts
- P0-003 Media Probe Model
- P0-004 Packet Flow Contracts
- P0-005 Decode Contracts

The route now requires an upgrade before continuing Clock/A-V Sync:

> P0-006 must become Timeline / Timestamp / Segment Contracts.  
> Clock comes after Timeline.  
> Presentation comes after Clock.  
> Renderer executes Presentation decisions; Renderer must not own global timing policy.

---

## 1. Non-Negotiable Engineering Principles

### 1.1 Whole Tree Family Governance

Every change must obey:

```text
Folder = feature family
Subfolder = sub-feature family
Single file = smallest responsibility
```

Required behavior:

- Put related concepts into their natural family.
- Create a new folder only when a real new family appears.
- Do not flatten everything into one bloated directory.
- Do not create bucket directories: common, helper, helpers, utils, types, stubs, domain, misc, shared.
- Do not merge unrelated responsibilities to pass fan-out.
- Do not mechanically split files when there is no natural family reason.
- Upper layer manages only its direct children; no cross-family command/control.

### 1.2 Dependency Direction

Clean dependency direction is mandatory.

```text
core must not depend on pipeline
core must not depend on decoder
core must not depend on render
core must not depend on audio
core must not depend on adapters

pipeline contracts must not depend on pipeline model
contracts must not depend on implementation
decoder contracts must not depend on pipeline
renderer contracts must not depend on FFmpeg
audio contracts must not expose WASAPI
core contracts must not expose D3D11/DXGI/WASAPI/FFmpeg types
```

Adapters translate platform/library reality into Kivo contracts:

```text
FFmpeg adapter -> demux/decode contracts
D3D11 adapter -> graphics/surface/render contracts
DXGI adapter -> presentation/display timing contracts
WASAPI adapter -> audio endpoint/audio clock contracts
DirectComposition adapter -> composition/render contracts
```

### 1.3 Contracts First, Runtime Later

P0 phase is contract/model/skeleton only.

P0 must not implement:

- real FFmpeg probe/demux/decode
- real D3D11/DXGI renderer
- real WASAPI output
- real clock runtime
- real scheduler runtime
- real thread pool
- real queue runtime
- real file IO or network IO
- real playback loop

P0 defines enum, struct, policy, status, validation result, state contract, mapping rule, capability model, and diagnostic contract.

### 1.4 One Objective Branch Mode

Each P0 branch must complete one natural feature family goal.

The branch itself must handle inventory, baseline verification, planning, architecture design, allowed files gate, implementation, self-review, repair, final verification, local commit, and final report.

Do not create micro repair branches for small issues discovered inside the same branch. Fix them inside the current objective branch.

---

## 2. Current Completed Safety Points

### P0-001 Core Foundation

Purpose:
- Core foundation
- basic playback state machine
- engine submit
- governance gates

Status: closed, PASS_COMMITTED

### P0-002 Pipeline Contracts

Purpose:
- packet / queue / lifecycle / flow contracts
- backpressure
- generation
- cancellation
- EOS / discontinuity

Status: closed, PASS_COMMITTED

Important repair:
- `BackpressureLevel` canonicalized.
- Only one canonical definition allowed.

### P0-003 Media Probe Model

Purpose:
- formal media probe model
- container / stream / codec / probe result
- no FFmpeg
- no real probe
- no file IO

Status: closed, PASS_COMMITTED

Important rule:
- `source_hint`, not `source_url`.
- `chapter_count` only, no full chapter model.

### P0-004 Packet Flow Contracts

Purpose:
- packet sequence
- EOS propagation
- discontinuity
- lifecycle interaction
- backpressure propagation
- generation guard
- cancellation flow

Status: closed, PASS_COMMITTED

Important rule:
- no real queue
- no push/pop/enqueue/dequeue
- neutral backpressure source naming only

### P0-005 Decode Contracts

Purpose:
- decoder contracts in `src/decoder/contracts/`
- video/audio/subtitle decoded sample boundaries
- decode result/status/error
- flush/drain/reconfigure
- no FFmpeg
- no D3D11/WASAPI
- no pipeline dependency

Status: closed, PASS_COMMITTED

Important rule:
- decode contracts belong to decoder family, not pipeline/model.
- decode result is decoder-specific.
- `EncodedPacketView` has no `eos_flag`.
- video plane layout has no real data pointer.

---

## 3. Final Route Upgrade

The previous P0-006 Clock/A-V Sync plan must be paused.

Reason:

```text
Timeline answers: what is media time?
Clock answers: where should playback be now?
Presentation answers: should this frame/sample be shown, waited, repeated, dropped, or resynced?
Renderer answers: how to execute the presentation decision on the device.
```

Therefore the correct order is:

```text
Timeline
-> Clock Domain
-> Presentation Decision
-> Surface / Memory Lifetime
-> Demuxer
-> Format / Color / HDR
-> Capability / Negotiation
-> Device / Recovery
-> Renderer / Audio
-> Subtitle
-> Execution
-> Diagnostics
-> Stress Test
```

---

## 4. P0 Master Roadmap

### P0-006 — Timeline / Timestamp / Segment Contracts

Recommended branch:

```text
kivo-playback-timeline-timestamp-segment-contracts-p0-006
```

Recommended family:

```text
src/core/timeline/
tests/core/timeline/
```

Goal:
- Define media time and timestamp semantics before clock/sync.

Contracts to define:

```text
Timebase
MediaTimestamp
StreamTimestamp
PacketTimestamp
DecodedTimestamp
BestEffortTimestamp
TimestampValidity
TimestampOrigin
TimestampRange
TimelineSegment
TimelineDiscontinuity
TimelineMapping
SeekTarget
SeekMode
PrerollPolicy
TimelineResetReason
ExternalSubtitleOffset
AudioDelayCompensation
RateChangeTimestampMapping
```

Must not do:

```text
FFmpeg / AVPacket / AVFrame / AVStream
D3D11 / DXGI / WASAPI
decoder/render/audio/pipeline runtime
real seek implementation
real scheduler
file IO / network IO
thread / queue runtime
```

Acceptance:
- timeline contracts are self-contained core contracts
- no pipeline/decoder/render/audio dependency
- compile tests
- semantic tests for timestamp validity, discontinuity, seek target, reset reason
- all governance gates pass

---

### P0-007 — Clock Domain / A-V Sync Contracts

Recommended family:

```text
src/core/clock/
tests/core/clock/
```

Goal:
- Define clock domains and sync observation after Timeline exists.

Contracts to define:

```text
ClockDomain
MasterClock
MediaClock
SystemClockSnapshot
AudioDeviceClockSnapshot
PresentationClockSnapshot
ClockProjection
ClockHealth
ClockFallbackPolicy
DriftObservation
DriftSeverity
SyncCorrectionPolicy
PauseResumeClockState
SeekClockReset
EosClockCoordination
```

Rules:
- Clock does not depend on renderer.
- Clock does not depend on WASAPI.
- Clock does not expose `IAudioClock`.
- Clock uses abstract snapshots; adapter maps platform clock sources later.

Important:
- Audio device clock can be lost, interrupted, or drifting.
- System monotonic clock is fallback.
- Soft resync is required when audio clock returns.

---

### P0-008 — Presentation Decision / Queue Policy / Scheduler Contracts

Recommended family:

```text
src/core/presentation/
tests/core/presentation/
```

Goal:
- Define the decision layer between Clock and Renderer.

Contracts to define:

```text
PresentationDecision
PresentationDeadline
PresentationReadiness
PresentationTimingVerdict
FrameLateness
DropReason
RepeatReason
FramePacingPolicy
PresentationQueuePolicy
PresentationWatermark
QueueAdmissionDecision
VsyncEstimate
EosPresentationPolicy
TrickplayPresentationPolicy
```

Rules:
- Presentation is not Renderer.
- Presentation does not call D3D11/DXGI.
- Presentation only decides frame/sample fate.

Queue model:
- bounded dynamic watermark, not fixed-only and not unbounded dynamic.

Policy:

```text
Normal playback: video queue 2-4 frames
Seek/scrub: 1-2 frames, old generation discarded
Pause: keep current frame, do not grow queue
4K/HDR/slow decoder: may raise watermark within memory budget
Device recovery: freeze admission, invalidate old surfaces
Audio clock lost: fallback clock + soft resync
```

---

### P0-009 — Memory / Surface / Opaque Handle / Pool Lifetime Contracts

Recommended family:

```text
src/memory/buffer/
src/memory/surface_lifetime/
tests/memory/
```

Goal:
- Make zero-copy and adapter-owned memory possible without leaking D3D11/FFmpeg types into core.

Contracts to define:

```text
BufferHandle
SurfaceHandle
MemoryDomain
BackendTag
LifetimeToken
ReleaseDelegate
PoolLease
PoolBudget
PoolPressure
AllocationPolicy
BackpressureByAllocation
SurfaceInvalidationReason
OpaquePayloadEnvelope
```

Rules:
- Do not expose `ID3D11Texture2D`.
- Do not expose `AVBufferRef`.
- Do not use raw `void*` as public contract.
- Use typed opaque handle + backend tag + lifetime token + release delegate.
- Only adapter/backend may unwrap real platform objects.

---

### P0-010 — Demuxer / Media Source Contracts

Recommended family:

```text
src/demux/contracts/
tests/demux/contracts/
```

Goal:
- Fill the missing layer between static probe model and dynamic packet flow.

Contracts to define:

```text
MediaSource
MediaSourceIdentity
DemuxerSession
StreamSelector
StreamSelectionResult
DemuxSeekRequest
DemuxSeekResult
KeyframeSeek
AccurateSeek
FastSeek
PacketReadResult
SparseStreamPolicy
AttachmentPolicy
ChapterPolicy
MultiProgramPolicy
DamagedMediaPolicy
TruncatedMediaPolicy
```

Rules:
- FFmpeg adapter implements demuxer contracts later.
- demuxer contracts do not expose libavformat types.
- no real file IO in P0.

---

### P0-011 — Media Format / Color / HDR Metadata Contracts

Recommended family:

```text
src/media/format/
src/media/color/
src/media/hdr/
tests/media/
```

Goal:
- Make color/HDR/format facts flow through the engine without renderer guessing.

Contracts to define:

```text
CodecIdentity
ProfileLevelTier
PixelFormat
BitDepth
ChromaSubsampling
CodedSize
VisibleRect
CropRect
SampleAspectRatio
Rotation
InterlaceMode
FieldOrder
ColorPrimaries
TransferFunction
MatrixCoefficients
ColorRange
MasteringDisplayMetadata
ContentLightMetadata
DynamicHdrMetadataEnvelope
DolbyVisionPrivatePayloadEnvelope
HdrMetadataConfidence
```

Rules:
- Do not expose DXGI color types in core model.
- DXGI adapter maps Kivo color model to DXGI later.
- Keep opaque private payload for Dolby Vision / HDR10+ / official SDK paths.

---

### P0-012 — Capability / Negotiation Contracts

Recommended family:

```text
src/media/capability/
src/media/negotiation/
tests/media/capability/
```

Goal:
- Make HDR, Dolby, Atmos, DXVA, WASAPI, passthrough, fallback honest and testable.

Contracts to define:

```text
Capability
CapabilityKind
CapabilityConfidence
CapabilitySource
NegotiationRequest
NegotiationResult
FallbackReason
UnsupportedReason
DegradationPolicy
HardwareAccelerationMode
OutputMode
DisplayCapability
AudioEndpointCapability
PassthroughEligibility
AuthorizationRequirement
PlatformRequirement
UserSettingRequirement
```

Must distinguish:

```text
container support
codec parse support
software decode support
hardware decode support
surface support
renderer support
display HDR support
audio endpoint support
passthrough support
license/platform/user-setting support
```

Rule:
- UI badge must be based on verified capability, not detected codec string.

---

### P0-013 — Device / Surface / Recovery Contracts

Recommended family:

```text
src/graphics/device/
src/graphics/recovery/
src/audio/recovery/
src/recovery/playback/
tests/recovery/
```

Goal:
- Make device loss and recovery a first-class engine concept.

Contracts to define:

```text
DeviceLost
DeviceRemoved
DisplayChanged
HdrStateChanged
SwapchainInvalidated
AudioEndpointChanged
AudioEndpointRemoved
ExclusiveModeLost
DecoderDeviceInvalidated
SurfacePoolInvalidated
RecoveryAction
RecoveryScope
GenerationBumpPolicy
SessionRecreatePolicy
ResourceRebuildOrder
```

Rules:
- No D3D11/DXGI/WASAPI types in contracts.
- Adapter maps real device loss events later.

---

### P0-014 — Video Renderer Contracts

Recommended family:

```text
src/render/video/
tests/render/video/
```

Goal:
- Define video renderer boundary after presentation and memory/surface contracts exist.

Contracts to define:

```text
VideoRendererContract
VideoOutputDevice
VideoFrameView
VideoFramePool
PresentationQueue
RendererAdmission
RendererPresentResult
ScalingPolicy
ToneMapPolicy
OutputColorSpace
RenderIntent
OverlayCompositionPolicy
DisplayTimingObservation
```

Rules:
- Renderer executes presentation decisions.
- Renderer does not own global sync.
- Renderer does not expose D3D11 directly to core.

---

### P0-015 — Audio Endpoint / Audio Renderer / Audio Clock / Passthrough Contracts

Recommended family:

```text
src/audio/endpoint/
src/audio/render/
src/audio/clock/
src/audio/passthrough/
tests/audio/
```

Goal:
- Make PCM path, bitstream path, endpoint negotiation, and audio clock explicit.

Contracts to define:

```text
AudioEndpoint
AudioEndpointState
AudioRenderMode
SharedMode
ExclusiveMode
AudioFormat
SampleFormat
ChannelLayout
ChannelMask
AudioClockSnapshot
AudioDriftSnapshot
AudioBufferLevel
EndpointNegotiationRequest
EndpointNegotiationResult
PassthroughFormat
BitstreamEligibility
BitstreamPayloadKind
VolumePolicy
MutePolicy
DrainPolicy
EndpointRecoveryPolicy
```

Rules:
- PCM path and bitstream path are separate contracts.
- Passthrough must not be a boolean in audio renderer.
- Do not expose WASAPI types in contracts.

---

### P0-016 — Subtitle / Overlay Contracts

Recommended family:

```text
src/subtitle/contracts/
src/subtitle/overlay/
tests/subtitle/
```

Goal:
- Make text/bitmap/ASS/PGS subtitle paths possible without polluting video renderer.

Contracts to define:

```text
SubtitleTrack
SubtitleSample
TextSubtitlePayload
BitmapSubtitlePayload
AssSubtitlePayloadEnvelope
SubtitleTiming
SubtitleClockPolicy
SubtitleOverlay
OverlayRegion
OverlayCompositionMode
ForcedSubtitlePolicy
ExternalSubtitleOffset
SubtitleAttachmentPolicy
```

Rules:
- Text and bitmap subtitles are separate paths.
- ASS/SSA can be adapter-backed later.
- Subtitle renderer/overlay must not become video renderer internals.

---

### P0-017 — Execution / Concurrency / Task Contracts

Recommended family:

```text
src/execution/contracts/
tests/execution/
```

Goal:
- Define concurrency contracts before implementing real threading.

Contracts to define:

```text
ExecutionDomain
TaskPriority
RealtimePriorityHint
ThreadAffinityPolicy
MessageEnvelope
ActorMailboxPolicy
CancellationPropagation
FlushBarrier
DrainBarrier
SeekBarrier
GenerationBarrier
ShutdownBarrier
```

Rules:
- No real thread pool in P0.
- No mutex/thread/condition_variable runtime.
- Contracts only.

---

### P0-018 — Diagnostics / Telemetry / Trace Contracts

Recommended family:

```text
src/diagnostics/
tests/diagnostics/
```

Goal:
- Make the player able to explain behavior.

Contracts to define:

```text
PlaybackTraceEvent
PipelineTraceEvent
SyncTraceEvent
RenderTraceEvent
AudioTraceEvent
DropCounter
RepeatCounter
DriftSnapshot
QueueDepthSnapshot
BufferLevelSnapshot
RecoveryCounter
FallbackReasonTrace
CapabilityDecisionTrace
SeekTrace
FlushTrace
GenerationTrace
```

Required future observability:

```text
packet queue depth
decoded frame queue depth
audio buffer level
video lateness
drop count
repeat count
clock drift
seek generation
flush generation
decoder reconfigure count
device recovery count
format fallback reason
HDR path decision
audio endpoint decision
```

---

### P0-019 — Media Case / Stress Test Scenario Contracts

Recommended family:

```text
tests/media_cases/
tests/playback_scenarios/
tests/chaos/
```

Goal:
- Make stability measurable.

Scenarios:

```text
4K HDR long playback
23.976 / 29.97 / 59.94 frame pacing
seek storm
pause/resume storm
bad files
missing PTS
PTS rollback
non-monotonic DTS/PTS
B-frame content
variable frame rate
missing HDR metadata
audio delay
external subtitle delay
device hotplug
D3D device lost
WASAPI endpoint changed
hardware decode fallback
truncated file tail
oversized packet
long GOP
multiple audio tracks
multiple subtitle tracks
cancel open
cancel seek
```

---

## 5. P1 Minimal Real Playback Loop

After P0 contracts are complete, do not keep writing contracts forever.

Move to P1 minimal playback:

```text
P1-020 FFmpeg Probe + Demux Adapter
P1-021 Software Decode Adapter
P1-022 Timeline + Clock Runtime Minimal
P1-023 Presentation Decision Runtime Minimal
P1-024 WASAPI Shared PCM Output Minimal
P1-025 D3D11 Video Presentation Minimal
P1-026 Local File Playback MVP
P1-027 Seek / Pause / Resume / EOS Integration
P1-028 Diagnostics Overlay / Log Snapshot
```

P1 goal:

```text
ordinary local video plays reliably
seek does not corrupt state
pause/resume does not corrupt state
EOS is correct
bad files do not crash
basic A/V sync is explainable
diagnostics show queue/drift/drop/fallback
```

Do not chase HDR/Dolby/Atmos in P1.

---

## 6. P2 Advanced Capability Route

After P1 is stable:

```text
D3D11VA / DXVA hardware decode
zero-copy surface path
HDR10 metadata path
SDR/HDR display negotiation
tone mapping policy
WASAPI exclusive
HDMI bitstream passthrough
Dolby / DTS capability classification
Subtitle ASS / PGS / VobSub
device lost recovery
multi-monitor HDR/SDR switching
stress test corpus expansion
```

---

## 7. P0-006 Immediate Instruction

The immediate next branch must be:

```text
KIVO-PLAYBACK-TIMELINE-TIMESTAMP-SEGMENT-CONTRACTS-P0-006
```

The previous Clock/A-V Sync P0-006 planning is paused and must not be implemented yet.

Required first response from the Agent:

```text
P0-006 Timeline Planning Draft v1
```

No code. No file changes. No commit until planning is approved.

Required Planning sections:

```text
1. Inventory Gate
2. Branch evidence
3. Baseline result
4. Goal
5. Non-goals
6. Layer touched
7. Timeline contract boundary
8. Folder family structure
9. Allowed files
10. Forbidden files
11. CMake integration
12. Dependency direction matrix
13. Source purity rules
14. Whole Tree Family Governance Precheck
15. STOP conditions
16. Acceptance criteria
17. Open questions requiring user confirmation
```

---

## 8. Repository Storage Requirement

This roadmap must be committed into the repository.

Recommended location:

```text
docs/playback-core/modern-media-engine-roadmap-and-p0-checklist.md
```

If `docs/playback-core/` does not exist, it is allowed to create it as the natural documentation family for playback core strategy.

Allowed repository write for this roadmap task:

```text
Create:
docs/playback-core/modern-media-engine-roadmap-and-p0-checklist.md

Modify:
docs/20-ticket-index.md
```

Only modify `docs/README.md` if the repository already requires every new docs family to be indexed there.

Forbidden:

```text
src/**
tests/**
build.ps1
scripts/**
root report file
memory file
temp file
random markdown at repo root
```

Commit message:

```text
docs: add playback core modern media engine roadmap
```

Final report must include:

```text
created files
modified files
branch
HEAD
commit
working tree clean
push status: not pushed by design
```

---

## 9. Final Positioning

Kivo playback core route can be described as:

```text
A top-tier playback core architecture route with professional/commercial media engine potential.
Not a completed top-tier player yet.
The route becomes truly strong only if Timeline, Clock, Presentation, Surface, Capability, Recovery, Renderer, Audio, Diagnostics, and Stress Test are implemented as first-class families.
```

The next correct engineering action is:

```text
Write this roadmap into the repository.
Then start P0-006 Timeline Planning.
```
