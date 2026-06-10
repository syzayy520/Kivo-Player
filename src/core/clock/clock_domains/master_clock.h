// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/clock_domains/master_clock.h - Master clock contract.
// Depends on: clock_domain.h, standard library.
// Does NOT depend on: pipeline, runtime

#pragma once
#include "clock_domain.h"
#include <cstdint>

namespace kivo::playback::clock {

// MasterClockSource - source of the master clock.
enum class MasterClockSource {
    Unknown,
    SystemMonotonic,
    DeviceDerived,
    UserDefined,
};

// MasterClock - master clock definition.
struct MasterClock {
    ClockDomain domain{ClockDomain::SystemMonotonic};
    MasterClockSource source{MasterClockSource::SystemMonotonic};
    int64_t resolution_hz{0};
    int timeline_ref_id{0};
};

} // namespace kivo::playback::clock
