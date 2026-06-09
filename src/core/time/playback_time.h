// src/core/time/playback_time.h - Core time types.
// Depends on: standard library only.
#pragma once
#include <cstdint>
#include <limits>

namespace kivo::playback {

using MediaTime = std::int64_t;   // microseconds
using MediaDuration = std::int64_t; // microseconds, -1 = unknown

struct MediaTimeRange {
    MediaTime start{0};
    MediaTime end{std::numeric_limits<MediaTime>::max()};
};

struct PlaybackRate {
    double value{1.0};
    constexpr PlaybackRate() = default;
    constexpr explicit PlaybackRate(double v) : value(v) {}
    constexpr auto operator==(PlaybackRate const&) const noexcept -> bool = default;
};

} // namespace kivo::playback
