// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/timestamp/timebase.h - Timeline timebase definition.
// Depends on: standard library only.
// Does NOT depend on: pipeline, decoder, clock, runtime.

#pragma once
#include <cstdint>

namespace kivo::playback::timeline {

// Timebase - rational timebase (num/den seconds per tick).
struct Timebase {
    int num{1};
    int den{1};
};

// TimebaseValidity - validity of a timebase.
enum class TimebaseValidity {
    Valid,
    ZeroDenominator,
    Incompatible,
};

// TimebaseConversionRequest - request to convert between timebases (contract only).
struct TimebaseConversionRequest {
    Timebase src{};
    Timebase dst{};
    int64_t src_value{0};
};

// TimebaseConversionResult - result of timebase conversion (contract only).
struct TimebaseConversionResult {
    int64_t dst_value{0};
    bool exact{false};
    TimebaseValidity validity{TimebaseValidity::Valid};
};

} // namespace kivo::playback::timeline
