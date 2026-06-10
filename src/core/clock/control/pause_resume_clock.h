// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/control/pause_resume_clock.h - Pause/resume clock state.
// Depends on: core/timeline, standard library.
// Does NOT depend on: pipeline, runtime.

#pragma once
#include "../../timeline/timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::clock {

// PauseResumeClockState - state of the clock during pause/resume.
enum class PauseResumeClockState {
    Unknown,
    Running,
    Pausing,
    Paused,
    Resuming,
};

// PauseClockRecord - record of a pause event.
struct PauseClockRecord {
    kivo::playback::timeline::MediaTimestamp paused_at{{}, 0};
    int64_t accumulated_pause_us{0};
};

} // namespace kivo::playback::clock
