// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/lifecycle/seek.h - Seek contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, core/time, standard library.
// Does NOT depend on: real seek implementation, thread, mutex.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include "../../../core/time/playback_time.h"
#include <cstdint>

namespace kivo::pipeline::lifecycle::seek {

// SeekRequest - request to seek to target position.
struct SeekRequest {
    kivo::playback::GenerationId generation{};
    kivo::playback::MediaTime target{};
    bool accurate{false};
    bool flush_pipeline{true};
};

// SeekStatus - status of seek operation (contract only).
struct SeekStatus {
    bool completed{false};
    kivo::playback::MediaTime actual_position{};
};

// seek_pipeline - contract for seek operation (no implementation here).
// Returns PipelineResult<SeekStatus> or PipelineError.
struct SeekContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::lifecycle::seek
