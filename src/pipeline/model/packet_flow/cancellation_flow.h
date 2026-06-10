// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/packet_flow/cancellation_flow.h - Cancellation propagation flow.
// Depends on: pipeline/contracts/lifecycle/cancellation.h, standard library.
// Does NOT depend on: real demux, runtime engine.

#pragma once
#include "../../contracts/lifecycle/cancellation.h"
#include <cstdint>

namespace kivo::pipeline::model::packet_flow {

// CancellationScope - scope of a cancellation request.
enum class CancellationScope {
    Unknown,
    StreamScoped,        // cancel one stream only
    SessionScoped,       // cancel all streams in session
    PipelineScoped,      // cancel entire pipeline
};

// CancellationStage - stage of cancellation propagation.
enum class CancellationStage {
    Requested,           // cancellation requested
    Propagating,         // propagating to pipeline stages
    Draining,            // draining remaining work
    Completed,           // fully cancelled
    Aborted,             // cancellation aborted
};

// CancellationFlowRule - behavior rule when cancellation reaches a stage.
enum class CancellationFlowRule {
    Unknown,
    DrainCompletion,     // complete drain before stopping
    ImmediateStop,       // stop immediately
    CleanShutdown,       // clean shutdown with flush
};

// CancellationFlowResult - result of cancellation propagation.
enum class CancellationFlowResult {
    Cancelled,
    PartiallyCancelled,
    RejectedOnCritical,
};

} // namespace kivo::pipeline::model::packet_flow
