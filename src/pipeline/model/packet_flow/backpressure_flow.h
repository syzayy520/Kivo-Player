// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/packet_flow/bpresssure_flow.h - Backpressure propagation flow.
// Depends on: pipeline/contracts/flow/backpressure.h, standard library.
// Does NOT depend on: real demux, real decode, real output, runtime engine.

#pragma once
#include "../../contracts/flow/backpressure.h"
#include <cstdint>

namespace kivo::pipeline::model::packet_flow {

// BackpressureSource - source of backpressure (pipeline-neutral).
// Does NOT bind to decoder/render/output semantics.
enum class BackpressureSource {
    Unknown,
    QueueHighWatermark,      // queue watermark exceeded
    ProducerBurst,           // burst of incoming packets
    ConsumerLag,             // downstream consumption slower
    DownstreamBacklog,       // downstream stage backlogged
    PipelinePaused,          // pipeline intentionally paused
};

// BackpressureDirection - direction of backpressure propagation.
enum class BackpressureDirection {
    None,
    Upstream,
    Downstream,
    Bidirectional,
};

// BackpressureFlowAction - action to take under backpressure.
enum class BackpressureFlowAction {
    Throttle,
    DropNonKey,
    PauseAdmission,
    Resume,
};

// BackpressureFlowRule - maps source level to action.
struct BackpressureFlowRule {
    kivo::pipeline::flow::backpressure::BackpressureLevel level{};
    BackpressureFlowAction action{BackpressureFlowAction::Throttle};
    BackpressureDirection direction{BackpressureDirection::Upstream};
};

} // namespace kivo::pipeline::model::packet_flow
