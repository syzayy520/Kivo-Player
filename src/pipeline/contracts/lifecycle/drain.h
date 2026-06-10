// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/lifecycle/drain.h - Drain contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real drain implementation, thread, mutex.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::pipeline::lifecycle::drain {

// DrainRequest - request to drain pipeline (process all pending data).
struct DrainRequest {
    kivo::playback::GenerationId generation{};
    bool wait_for_completion{false};
};

// DrainStatus - status of drain operation (contract only).
struct DrainStatus {
    bool completed{false};
    int64_t packets_processed{0};
};

// drain_pipeline - contract for drain operation (no implementation here).
// Returns PipelineResult<DrainStatus> or PipelineError.
struct DrainContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::lifecycle::drain
