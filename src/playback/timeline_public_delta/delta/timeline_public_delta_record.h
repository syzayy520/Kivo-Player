#pragma once
#include "timeline_public_delta_envelope.h"
#include "playback_timeline_public_delta.h"
namespace kivo::playback::timeline_public_delta {
struct TimelinePublicDeltaRecord {
    TimelinePublicDeltaEnvelope envelope{};
    PlaybackTimelinePublicDelta delta{};
};
}
