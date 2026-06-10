// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/snapshot/system_clock_snapshot.h - System clock snapshot.
// Does NOT depend on: pipeline

#pragma once
#include <cstdint>

namespace kivo::playback::clock {

// SystemClockSnapshot - snapshot of the system monotonic clock.
struct SystemClockSnapshot {
    int64_t monotonic_ticks{0};
    int64_t tick_frequency{0};
    int capture_generation{0};
    bool valid{false};
};

} // namespace kivo::playback::clock
