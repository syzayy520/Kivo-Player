// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/subtitle/subtitle_sample.h - Subtitle decoded sample model.
// Depends on: core/time, standard library.
// Does NOT depend on: style model, layout, render, overlay, ASS/SSA, font.
// Note: full subtitle contracts are in P0-009.

#pragma once
#include "../../../core/time/playback_time.h"
#include <string>
#include <cstdint>

namespace kivo::decoder::contracts::subtitle {

// SubtitleSampleKind - kind of decoded subtitle sample.
enum class SubtitleSampleKind {
    Unknown,
    Text,
    Bitmap,
};

// SubtitleTimingInfo - timing of a subtitle sample.
struct SubtitleTimingInfo {
    kivo::playback::MediaTime start_pts{0};
    kivo::playback::MediaTime end_pts{0};
};

// SubtitleDecodedSample - decoded subtitle sample (contract only, no style).
struct SubtitleDecodedSample {
    SubtitleSampleKind kind{SubtitleSampleKind::Unknown};
    SubtitleTimingInfo timing{};
    std::string payload_kind{};
    std::string text_hint{};
};

} // namespace kivo::decoder::contracts::subtitle
