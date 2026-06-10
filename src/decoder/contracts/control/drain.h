// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/control/drain.h - Decode drain contract.
// Depends on: core/id, standard library.
// Does NOT depend on: real decode, pipeline.

#pragma once
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::decoder::contracts::control {

// DrainMode - mode for drain operation.
enum class DrainMode {
    Unknown,
    BlockUntilEmpty,       // block until all pending work completes
    TimeoutMs,             // drain with timeout
    Immediate,             // immediate return, skip remaining
};

// DecodeDrainRequest - request to drain a decoder.
struct DecodeDrainRequest {
    kivo::playback::GenerationId generation{};
    kivo::playback::TrackId track_id{};
    DrainMode mode{DrainMode::BlockUntilEmpty};
    int64_t timeout_ms{0};
};

// DecodeDrainResult - result of a drain operation.
enum class DecodeDrainResult {
    Unknown,
    Drained,
    PartialTimeout,
    Rejected,
};

} // namespace kivo::decoder::contracts::control
