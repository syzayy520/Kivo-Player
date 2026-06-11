#pragma once

#include "timeline_public_response_envelope.h"
#include "playback_timeline_public_response.h"

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseRecord {
    TimelinePublicResponseEnvelope envelope{};
    PlaybackTimelinePublicResponse response{};
};

} // namespace kivo::playback::timeline_public_response
