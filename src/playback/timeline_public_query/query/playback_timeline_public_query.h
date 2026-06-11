#pragma once

#include "../identity/timeline_public_query_identity.h"
#include "../anchor/timeline_public_query_anchor_set.h"
#include "../classification/timeline_public_query_classification.h"

namespace kivo::playback::timeline_public_query {

struct PlaybackTimelinePublicQuery {
    TimelinePublicQueryIdentity identity{};
    TimelinePublicQueryAnchorSet anchors{};
    TimelinePublicQueryClassification classification{};
};

} // namespace kivo::playback::timeline_public_query
