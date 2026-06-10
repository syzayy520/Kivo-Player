// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/packet_flow/eos_flow.h - EOS propagation flow.
// Depends on: pipeline/contracts/flow/end_of_stream.h, standard library.
// Does NOT depend on: real demux, runtime engine.

#pragma once
#include "../../contracts/flow/end_of_stream.h"
#include <cstdint>

namespace kivo::pipeline::model::packet_flow {

// EosPipelineStage - pipeline stage where EOS is detected.
enum class EosPipelineStage {
    Unknown,
    DemuxEnd,       // demuxer reached end of input
    DecodeEnd,      // decoder flushed all frames
    OutputEnd,      // output consumed all frames
};

// EosPropagationState - propagation state of EOS through the pipeline.
enum class EosPropagationState {
    Unknown,
    NotStarted,
    Propagating,
    Arrived,
    Consumed,
};

// EosFlowPolicy - policy for handling EOS at a stage.
enum class EosFlowPolicy {
    Unknown,
    StopAtEos,       // stop processing immediately at EOS
    DrainThenStop,   // drain remaining work then stop
    Ignore,          // forward EOS to next stage
};

// EosFlowValidationResult - result of EOS flow validation (contract only).
enum class EosFlowValidationResult {
    Valid,
    PastEos,
    StageUnreachable,
};

} // namespace kivo::pipeline::model::packet_flow
