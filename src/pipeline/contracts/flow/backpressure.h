// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/flow/backpressure.h - Backpressure contract (canonical BackpressureLevel).
// Depends on: pipeline_result.h, pipeline_error.h, standard library.
// Does NOT depend on: queue implementation, mutex, thread.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include <cstdint>

namespace kivo::pipeline::flow::backpressure {

// BackpressureLevel - backpressure level (CANONICAL DEFINITION).
// Do NOT redefine this in queue/contract.h. Queue should reference this or define queue-specific status.
enum class BackpressureLevel {
    None,      // queue below low watermark
    Soft,      // queue between low and high watermark
    Hard,      // queue above high watermark
    Overflow,   // queue at capacity
};

// BackpressureSignal - signal indicating backpressure state change.
struct BackpressureSignal {
    BackpressureLevel level{BackpressureLevel::None};
    int64_t current_packets{0};
    int64_t current_bytes{0};
};

// backpressure_detected - contract for backpressure detection (no implementation here).
// Returns PipelineResult<BackpressureSignal> or PipelineError.
struct BackpressureContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::flow::backpressure
