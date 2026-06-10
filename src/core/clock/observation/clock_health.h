// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/observation/clock_health.h - Clock health monitoring contract.
// Depends on: standard library only.
// Does NOT depend on: pipeline, runtime.

#pragma once
#include <cstdint>

namespace kivo::playback::clock {

// ClockHealth - health status of a clock.
enum class ClockHealth {
    Unknown,
    Healthy,
    Drifting,
    Lost,
    Recovered,
};

// ClockFallbackPolicy - policy when clock health is compromised.
enum class ClockFallbackPolicy {
    Unknown,
    UseSystemReference,
    HoldLastProjection,
    MarkProjectionInvalid,
    BestEffortProjection,
};

} // namespace kivo::playback::clock
