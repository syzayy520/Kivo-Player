// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/pipeline_event.h - Pipeline event model.
// Depends on: core/id, core/time, pipeline_error.h, standard library.

#pragma once
#include "../../core/id/playback_id.h"
#include "../../core/time/playback_time.h"
#include "pipeline_error.h"
#include <variant>

namespace kivo::pipeline {

// PipelineEvProbeCompleted - probe finished, basic info available.
struct PipelineEvProbeCompleted {
    kivo::playback::SessionId session_id{};
};

// PipelineEvDemuxReady - demux initialized, streams available.
struct PipelineEvDemuxReady {
    kivo::playback::SessionId session_id{};
};

// PipelineEvPacketReady - a packet is available for decoding.
struct PipelineEvPacketReady {};

// PipelineEvQueueFull - packet queue is full, backpressure signal.
struct PipelineEvQueueFull {};

// PipelineEvFlushCompleted - flush operation finished.
struct PipelineEvFlushCompleted {};

// PipelineEvDrainCompleted - drain operation finished.
struct PipelineEvDrainCompleted {};

// PipelineEvSeekCompleted - seek operation finished.
struct PipelineEvSeekCompleted {
    kivo::playback::MediaTime position{};
};

// PipelineEvError - pipeline error occurred.
struct PipelineEvError {
    PipelineError error{};
};

// PipelineEvEndOfStream - end of stream reached.
struct PipelineEvEndOfStream {};

// PipelineEvDiscontinuity - discontinuity detected (timestamp jump).
struct PipelineEvDiscontinuity {
    kivo::playback::MediaTime new_time{};
};

// PipelineEvBackpressure - backpressure signal (queue watermark exceeded).
struct PipelineEvBackpressure {
    int queue_depth{0};
};

using PipelineEvent = std::variant<
    PipelineEvProbeCompleted,
    PipelineEvDemuxReady,
    PipelineEvPacketReady,
    PipelineEvQueueFull,
    PipelineEvFlushCompleted,
    PipelineEvDrainCompleted,
    PipelineEvSeekCompleted,
    PipelineEvError,
    PipelineEvEndOfStream,
    PipelineEvDiscontinuity,
    PipelineEvBackpressure
>;

} // namespace kivo::pipeline
