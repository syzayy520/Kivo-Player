// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/reset/timeline_reset.h - Timeline reset contract.
// TimelineResetReason is CANONICAL here -- do NOT redefine elsewhere.
// Does NOT depend on: pipeline, decoder, clock, runtime.

#pragma once
#include <cstdint>

namespace kivo::playback::timeline {

// TimelineResetReason - reason for timeline reset (CANONICAL).
enum class TimelineResetReason {
    Unknown,
    Seek,
    StreamSwitch,
    CodecChange,
    Recovery,
    UserDefined,
};

// TimelineResetScope - scope of a timeline reset.
enum class TimelineResetScope {
    Unknown,
    SingleStream,
    AllStreams,
    SessionScoped,
};

// TimelineResetAction - action to take on timeline reset.
enum class TimelineResetAction {
    Unknown,
    ClearSegments,
    PreserveHistory,
    ResetAndRescan,
};

} // namespace kivo::playback::timeline
