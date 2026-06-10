// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/lifecycle/cancellation.h - Cancellation contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real cancellation implementation, thread, mutex.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::pipeline::lifecycle::cancellation {

// CancellationToken - token to cancel ongoing operation.
struct CancellationToken {
    kivo::playback::GenerationId generation{};
    bool is_cancelled{false};
};

// CancellationRequest - request to cancel operation.
struct CancellationRequest {
    kivo::playback::GenerationId generation{};
    std::string reason{};
};

// cancel_operation - contract for cancellation (no implementation here).
// Returns PipelineResult<void> or PipelineError.
struct CancelContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::lifecycle::cancellation
