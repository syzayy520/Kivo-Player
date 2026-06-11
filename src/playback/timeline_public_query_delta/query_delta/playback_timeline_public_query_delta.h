#pragma once

#include "../identity/timeline_public_query_delta_identity.h"
#include "../anchor/timeline_public_query_delta_anchor_set.h"
#include "../classification/timeline_public_query_delta_classification.h"
#include "timeline_public_query_delta_envelope.h"

namespace kivo::playback::timeline_public_query_delta {

struct PlaybackTimelinePublicQueryDelta {
    TimelinePublicQueryDeltaIdentity identity{};
    TimelinePublicQueryDeltaAnchorSet anchors{};
    TimelinePublicQueryDeltaClassification classification{};
    TimelinePublicQueryDeltaEnvelope envelope{};
};

} // namespace kivo::playback::timeline_public_query_delta
