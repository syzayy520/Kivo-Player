// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/control/seek_clock_reset.h - Seek clock reset contract.
// Depends on: core/timeline, standard library.
// Does NOT depend on: pipeline, runtime.
// DOES NOT redefine TimelineResetReason -- consumes P0-006 canonical.

#pragma once
#include "../../timeline/timestamp/media_timestamp.h"
#include "../../timeline/reset/timeline_reset.h"
#include <cstdint>

namespace kivo::playback::clock {

// SeekClockReset - clock state reset caused by a seek.
struct SeekClockReset {
    kivo::playback::timeline::MediaTimestamp old_time{{}, 0};
    kivo::playback::timeline::MediaTimestamp new_time{{}, 0};
    kivo::playback::timeline::TimelineResetReason reset_reason{};
};

// SeekResetAction - action to take on the clock after seek.
enum class SeekResetAction {
    Unknown,
    FlushObservations,
    PreserveRate,
    FullReset,
};

} // namespace kivo::playback::clock
