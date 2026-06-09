// src/core/clock/playback_clock.h - Playback clock contract.
#pragma once
#include "../time/playback_time.h"

namespace kivo::playback {
struct IPlaybackClock {
    virtual ~IPlaybackClock() = default;
    virtual auto current_position() const -> MediaTime = 0;
};
} // namespace kivo::playback
