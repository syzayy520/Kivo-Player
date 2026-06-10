// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/decode_result.h - Decode result types.
// Depends on: core/id, standard library.
// Does NOT depend on: pipeline, PlaybackResult, real decode.

#pragma once
#include "../../core/id/playback_id.h"
#include <cstdint>
#include <string>

namespace kivo::decoder::contracts {

// DecodeOutputKind - kind of decoded output.
enum class DecodeOutputKind {
    Unknown,
    VideoFrame,
    AudioSample,
    SubtitleSample,
    Empty,
};

// DecodeOutputEntry - single decoded output entry.
struct DecodeOutputEntry {
    DecodeOutputKind kind{DecodeOutputKind::Unknown};
    kivo::playback::TrackId track_id{};
    int64_t frame_index{0};
    int64_t pts{0};
};

// DecodeResultStatus - status of the overall decode result.
enum class DecodeResultStatus {
    Success,
    NeedMoreInput,
    OutputAvailable,
    Flushed,
    Drained,
    Reconfigured,
    Error,
};

// DecodeResult - result of a decode operation.
struct DecodeResult {
    DecodeResultStatus status{DecodeResultStatus::Success};
    DecodeOutputEntry entry{};
    std::string error_message{};
};

} // namespace kivo::decoder::contracts
