// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/control/flush.h - Decode flush contract.
// Depends on: core/id, standard library.
// Does NOT depend on: real decode, pipeline.

#pragma once
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::decoder::contracts::control {

// FlushStrategy - strategy for flush operation.
enum class FlushStrategy {
    Unknown,
    DiscardAll,          // discard all pending decode work
    ProduceRemaining,    // produce remaining frames then stop
    SoftReset,           // soft reset, keep state
};

// DecodeFlushRequest - request to flush a decoder.
struct DecodeFlushRequest {
    kivo::playback::GenerationId generation{};
    kivo::playback::TrackId track_id{};
    FlushStrategy strategy{FlushStrategy::DiscardAll};
};

// DecodeFlushResult - result of a flush operation.
enum class DecodeFlushResult {
    Unknown,
    Flushed,
    Partial,
    Rejected,
};

} // namespace kivo::decoder::contracts::control
