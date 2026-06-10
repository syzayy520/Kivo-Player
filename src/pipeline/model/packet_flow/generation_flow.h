// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/packet_flow/generation_flow.h - Generation guard & validation flow.
// Depends on: pipeline/contracts/flow/generation.h, standard library.
// Does NOT depend on: real demux, real decode, runtime engine.

#pragma once
#include "../../contracts/flow/generation.h"
#include <cstdint>

namespace kivo::pipeline::model::packet_flow {

// GenerationFlowState - state of a generation in the pipeline.
enum class GenerationFlowState {
    Unknown,
    Current,        // active generation
    Superseded,     // replaced by newer generation
};

// GenerationFlowCheckpoint - safe checkpoint for generation switch.
enum class GenerationFlowCheckpoint {
    Unknown,
    AfterFlush,     // switch after pipeline flush
    AfterDrain,     // switch after pipeline drain
    AfterEos,       // switch after end-of-stream
};

// GenerationFlowRule - when to allow switch and reject stale.
struct GenerationFlowRule {
    GenerationFlowCheckpoint checkpoint{GenerationFlowCheckpoint::Unknown};
    bool reject_stale{true};
    bool reject_future{false};
};

// GenerationFlowValidationResult - result of generation validation.
enum class GenerationFlowValidationResult {
    Accepted,
    RejectedStale,
    RejectedFuture,
    Mismatch,
};

} // namespace kivo::pipeline::model::packet_flow
