#pragma once

#include "../identity/timeline_public_query_delta_response_identity.h"
#include "../anchor/timeline_public_query_delta_response_anchor_set.h"
#include "../classification/timeline_public_query_delta_response_classification.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseRecord {
    TimelinePublicQueryDeltaResponseIdentity identity{};
    TimelinePublicQueryDeltaResponseAnchorSet anchors{};
    TimelinePublicQueryDeltaResponseClassification classification{};
};

} // namespace kivo::playback::timeline_public_query_delta_response
