// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/snapshot/device_reference_snapshot.h - Device reference snapshot.
// Does NOT depend on: pipeline, runtime.
// Abstract device reference only -- adapters map platform types later.

#pragma once
#include <cstdint>

namespace kivo::playback::clock {

// DeviceReferenceSnapshot - snapshot of an abstract device reference clock.
struct DeviceReferenceSnapshot {
    int64_t reference_position{0};
    int64_t reference_frequency{0};
    int source_generation{0};
    bool valid{false};
};

} // namespace kivo::playback::clock
