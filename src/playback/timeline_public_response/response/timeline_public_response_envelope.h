#pragma once

#include "../identity/timeline_public_response_identity.h"
#include "../anchor/timeline_public_response_anchor_set.h"
#include "../classification/timeline_public_response_classification.h"

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseEnvelope {
    TimelinePublicResponseIdentity identity{};
    TimelinePublicResponseAnchorSet anchors{};
    TimelinePublicResponseClassification classification{};
};

} // namespace kivo::playback::timeline_public_response
