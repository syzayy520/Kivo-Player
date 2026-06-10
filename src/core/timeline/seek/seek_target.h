// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/seek/seek_target.h - Seek target contract.
// Does NOT depend on: pipeline, decoder, runtime.

#pragma once
#include "../timestamp/media_timestamp.h"

namespace kivo::playback::timeline {

// SeekMode - mode for seek operation.
enum class SeekMode {
    Unknown,
    KeyframeOnly,
    Accurate,
    Fast,
    Preview,
};

// SeekAccuracyHint - accuracy hint for seek target.
enum class SeekAccuracyHint {
    Unknown,
    Exact,
    NearestKeyframe,
    BeforeTarget,
    AfterTarget,
};

// SeekTarget - target position for seek.
struct SeekTarget {
    MediaTimestamp position{};
    SeekMode mode{SeekMode::KeyframeOnly};
    SeekAccuracyHint accuracy{SeekAccuracyHint::NearestKeyframe};
};

} // namespace kivo::playback::timeline
