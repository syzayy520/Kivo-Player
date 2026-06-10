// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/decode_error.h - Decode error classification.
// Depends on: standard library only.
// Does NOT depend on: hardware backends, platform-specific types.
// Does NOT contain: HardwareError, platform-specific types.

#pragma once
#include <string>
#include <cstdint>

namespace kivo::decoder::contracts {

// DecodeErrorCategory - classification of decode errors.
enum class DecodeErrorCategory {
    Unknown,
    InvalidInput,             // packet data invalid
    UnsupportedCodec,         // codec not supported
    CorruptedData,            // bitstream corruption
    ConfigurationRejected,    // decoder rejected codec config
    ResourceUnavailable,      // resource temporarily unavailable
    Timeout,                  // decode timed out
    Internal,                 // internal decoder error
};

// DecodeErrorInfo - detailed decode error information.
struct DecodeErrorInfo {
    DecodeErrorCategory category{DecodeErrorCategory::Unknown};
    std::string message{};
    int64_t input_index{0};
    bool recoverable{true};
};

} // namespace kivo::decoder::contracts
