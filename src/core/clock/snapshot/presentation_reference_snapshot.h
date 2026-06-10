// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/snapshot/presentation_reference_snapshot.h - Presentation reference snapshot.
// Does NOT depend on: pipeline, runtime.

#pragma once
#include <cstdint>

namespace kivo::playback::clock {

// PresentationReferenceSnapshot - snapshot of the presentation reference.
struct PresentationReferenceSnapshot {
    int64_t presentation_position{0};
    int64_t presentation_interval_hint{0};
    int source_generation{0};
    bool valid{false};
};

} // namespace kivo::playback::clock
