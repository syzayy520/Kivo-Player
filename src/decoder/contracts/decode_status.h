// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/decode_status.h - Decode status and state.
// Depends on: standard library only.
// Does NOT depend on: pipeline, real decode, hardware backends.

#pragma once
#include <cstdint>

namespace kivo::decoder::contracts {

// DecoderStage - current stage in decoder lifecycle.
enum class DecoderStage {
    Unknown,
    Idle,
    Active,
    Flushing,
    Draining,
    Reconfiguring,
    Error,
    Stopped,
};

// DecodeProgress - progress statistics (contract only, no runtime tracking).
struct DecodeProgress {
    int64_t inputs_consumed{0};
    int64_t outputs_produced{0};
    int64_t errors_encountered{0};
};

} // namespace kivo::decoder::contracts
