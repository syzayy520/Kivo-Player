// src/core/timeline/playback_timeline.h - Timeline contract.
#pragma once
#include "../time/playback_time.h"

namespace kivo::playback {
struct PlaybackTimeline {
    MediaTime position{0};
    MediaDuration duration{-1};
    double rate{1.0};
};
} // namespace kivo::playback
