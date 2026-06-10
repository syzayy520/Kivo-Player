// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/mapping/track_delay_compensation.h - Track delay compensation.
// Does NOT depend on: pipeline, decoder, clock, runtime.

#pragma once
#include "../../id/playback_id.h"
#include <cstdint>

namespace kivo::playback::timeline {

// CompensationSource - source of delay compensation value.
enum class CompensationSource {
    Unknown,
    UserConfigured,
    Measured,
    Declared,
};

// CompensationMode - mode of delay compensation.
enum class CompensationMode {
    Unknown,
    TrackAheadOfReference,
    ReferenceAheadOfTrack,
    Automatic,
};

// TrackDelayCompensation - delay compensation for a track.
struct TrackDelayCompensation {
    kivo::playback::TrackId track_id{};
    int64_t delay_us{0};
    CompensationSource source{CompensationSource::Unknown};
    CompensationMode mode{CompensationMode::Automatic};
};

} // namespace kivo::playback::timeline
