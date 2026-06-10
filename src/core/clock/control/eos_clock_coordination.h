// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/control/eos_clock_coordination.h - EOS clock coordination.
// Does NOT depend on: pipeline stage, decoder stage, renderer stage.
// Uses typed participant set, not bare bitmask.

#pragma once
#include <cstdint>

namespace kivo::playback::clock {

// EosClockParticipant - participants in EOS clock coordination.
enum class EosClockParticipant {
    Unknown,
    Timeline,
    MasterClock,
    ReferenceClock,
    Projection,
};

// EosClockParticipantSet - typed set of EOS clock participants.
struct EosClockParticipantSet {
    bool timeline{false};
    bool master_clock{false};
    bool reference_clock{false};
    bool projection{false};
};

// EosClockState - state of EOS clock coordination.
enum class EosClockState {
    Unknown,
    NotReached,
    Detected,
    Coordinating,
    Coordinated,
    Timeout,
};

// EosClockTimeoutPolicy - policy on EOS clock coordination timeout.
enum class EosClockTimeoutPolicy {
    Unknown,
    HoldLastProjection,
    MarkProjectionInvalid,
    BestEffortProjection,
};

// EosClockCoordination - EOS clock coordination state.
struct EosClockCoordination {
    EosClockState state{EosClockState::NotReached};
    EosClockParticipantSet participants{};
    int64_t timeout_us{0};
    EosClockTimeoutPolicy timeout_policy{EosClockTimeoutPolicy::HoldLastProjection};
};

} // namespace kivo::playback::clock
