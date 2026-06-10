// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/mapping/track_offset.h - Track offset adjustment contract.
// Does NOT depend on: pipeline, decoder, clock, runtime.

#pragma once
#include "../../id/playback_id.h"
#include <cstdint>

namespace kivo::playback::timeline {

// TrackOffsetDirection - direction of track offset adjustment.
enum class TrackOffsetDirection {
    Unknown,
    Advance,
    Delay,
};

// TrackOffsetAdjustment - offset adjustment for a track.
struct TrackOffsetAdjustment {
    kivo::playback::TrackId track_id{};
    int64_t offset_us{0};
    TrackOffsetDirection direction{TrackOffsetDirection::Unknown};
};

// OffsetApplicationRule - when to apply offset.
struct OffsetApplicationRule {
    bool apply_before_seek{true};
    bool apply_after_seek{true};
};

} // namespace kivo::playback::timeline
