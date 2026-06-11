#pragma once

#include "timeline_public_query_response_anchor.h"

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseAnchorSet {
    TimelinePublicQueryResponseAnchor query_anchor{};
};

} // namespace kivo::playback::timeline_public_response
