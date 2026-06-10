// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/timestamp/media_timestamp.h - Media timestamp types.
// Depends on: timebase.h, core/id, core/time, standard library.
// Does NOT depend on: pipeline, decoder, clock, runtime.

#pragma once
#include "timebase.h"
#include "../../id/playback_id.h"
#include "../../time/playback_time.h"
#include <cstdint>

namespace kivo::playback::timeline {

// MediaTimestamp - a timestamp with a timebase.
struct MediaTimestamp {
    Timebase timebase{};
    int64_t value{0};
};

// TrackTimestamp - stream-native timestamp.
struct TrackTimestamp {
    kivo::playback::TrackId track_id{};
    Timebase native_tb{};
    int64_t value{0};
};

// PacketTimestamp - packet-level timestamp.
struct PacketTimestamp {
    TrackTimestamp base{};
    bool is_keyframe{false};
};

// DecodedTimestamp - decoded frame/sample timestamp.
struct DecodedTimestamp {
    TrackTimestamp base{};
    int64_t presentation_offset{0};
};

// BestEffortTimestamp - estimated timestamp when real one is missing.
struct BestEffortTimestamp {
    int64_t value{0};
    bool is_estimated{true};
};

// TimestampValidity - validity status of a timestamp.
enum class TimestampValidity {
    Valid,
    Missing,
    Estimated,
    Invalid,
};

// TimestampOrigin - where a timestamp came from.
enum class TimestampOrigin {
    Unknown,
    ContainerDeclared,
    EncodedStreamDeclared,
    DecodedOutputDeclared,
    Estimated,
    UserDefined,
    UserAdjusted,
};

// TimestampRange - a range of media timestamps.
struct TimestampRange {
    MediaTimestamp start{};
    MediaTimestamp end{};
};

} // namespace kivo::playback::timeline
