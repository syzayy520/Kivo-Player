// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/observation/clock_projection.h - Clock projection contract.
// Depends on: core/timeline, standard library.
// Does NOT depend on: pipeline, runtime

#pragma once
#include "../../timeline/timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::clock {

// ProjectionConfidence - confidence level of a clock projection.
enum class ProjectionConfidence {
    Unknown,
    Exact,
    Estimated,
    Drifting,
    Invalid,
};

// ClockProjection - projects a clock snapshot to a media timestamp.
struct ClockProjection {
    kivo::playback::timeline::MediaTimestamp projected{{}, 0};
    ProjectionConfidence confidence{ProjectionConfidence::Invalid};
};

} // namespace kivo::playback::clock
