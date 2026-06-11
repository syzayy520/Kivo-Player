#pragma once

#include "timeline_public_query_envelope.h"
#include "playback_timeline_public_query.h"

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQueryRecord {
    TimelinePublicQueryEnvelope envelope{};
    PlaybackTimelinePublicQuery query{};
};

} // namespace kivo::playback::timeline_public_query
