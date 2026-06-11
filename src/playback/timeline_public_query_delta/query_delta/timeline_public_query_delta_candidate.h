#pragma once

#include "../identity/timeline_public_query_delta_identity.h"
#include "../anchor/timeline_public_query_delta_anchor_set.h"
#include "../classification/timeline_public_query_delta_classification.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaCandidate {
    TimelinePublicQueryDeltaIdentity identity{};
    TimelinePublicQueryDeltaAnchorSet anchors{};
    TimelinePublicQueryDeltaClassification classification{};
};

} // namespace kivo::playback::timeline_public_query_delta
