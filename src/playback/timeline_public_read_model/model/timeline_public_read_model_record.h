#pragma once
#include "timeline_public_read_model_envelope.h"
#include "playback_timeline_public_read_model.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelinePublicReadModelRecord {
    TimelinePublicReadModelEnvelope envelope{};
    PlaybackTimelinePublicReadModel model{};
};
}
