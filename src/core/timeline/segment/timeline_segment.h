// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/segment/timeline_segment.h - Timeline segment & discontinuity.
// TimelineDiscontinuityType is canonical here -- do NOT redefine elsewhere.
// Does NOT depend on: pipeline, clock, runtime.

#pragma once
#include "../timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::timeline {

// TimelineDiscontinuityType - type of timeline discontinuity (CANONICAL).
enum class TimelineDiscontinuityType {
    Unknown,
    Gap,
    Overlap,
    Reset,
    TimebaseChange,
    SegmentBoundary,
};

// TimelineSegment - a segment within the media timeline.
struct TimelineSegment {
    TimestampRange range{};
    Timebase timebase{};
    int segment_index{0};
};

// TimelineDiscontinuity - a discontinuity between timeline segments.
struct TimelineDiscontinuity {
    TimelineDiscontinuityType type{TimelineDiscontinuityType::Unknown};
    TimelineSegment old_segment{};
    TimelineSegment new_segment{};
};

// TimelineMapping - maps between container/stream/unified media timelines.
// Does NOT map to: wall time, QPC, system clock, presentation clock, audio clock.
struct TimelineMapping {
    int container_timeline_id{0};
    int stream_timeline_id{0};
    int unified_timeline_id{0};
    TimestampRange container_range{};
    TimestampRange unified_range{};
};

} // namespace kivo::playback::timeline
