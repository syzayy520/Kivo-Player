// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/clock_domains/clock_domain.h - Clock domain types.
// Depends on: standard library only.
// Does NOT depend on: pipeline, decoder, runtime

#pragma once
#include <cstdint>

namespace kivo::playback::clock {

// ClockDomain - identifies the clock domain.
enum class ClockDomain {
    Unknown,
    SystemMonotonic,
    PresentationReference,
    DeviceReference,
    UserDefinedReference,
};

// ClockDomainRelation - relationship between clock domains.
enum class ClockDomainRelation {
    Unknown,
    Master,
    Slave,
    Independent,
};

} // namespace kivo::playback::clock
