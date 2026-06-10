// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/mapping/rate_timestamp_mapping.h - Rate change timestamp mapping.
// Does NOT depend on: pipeline, decoder, clock, runtime.

#pragma once
#include "../timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::timeline {

// RateChangePoint - point in timeline where playback rate changes.
struct RateChangePoint {
    double old_rate{1.0};
    double new_rate{1.0};
    MediaTimestamp discontinuity_point{{}, 0};
};

// RateTimestampMappingRule - rule for mapping timestamps across rate change.
struct RateTimestampMappingRule {
    bool resample_timestamps{true};
    bool preserve_duration{false};
};

// RateTimestampMappingResult - result of rate timestamp mapping (contract only).
struct RateTimestampMappingResult {
    MediaTimestamp mapped_value{{}, 0};
    bool exact{true};
};

} // namespace kivo::playback::timeline
