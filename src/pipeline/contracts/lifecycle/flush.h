// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/lifecycle/flush.h - Flush contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real flush implementation, thread, mutex.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::pipeline::lifecycle::flush {

// FlushRequest - request to flush pipeline (discard pending data).
struct FlushRequest {
    kivo::playback::GenerationId generation{};
    bool discard_packets{true};
    bool reset_decoder{false};
};

// FlushStatus - status of flush operation (contract only).
struct FlushStatus {
    bool completed{false};
    int64_t packets_discarded{0};
};

// flush_pipeline - contract for flush operation (no implementation here).
// Returns PipelineResult<FlushStatus> or PipelineError.
struct FlushContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::lifecycle::flush
