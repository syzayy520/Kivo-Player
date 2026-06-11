#pragma once

#include "timeline_public_delta_query_anchor.h"

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQueryAnchorSet {
    TimelinePublicDeltaQueryAnchor delta_anchor{};
};

} // namespace kivo::playback::timeline_public_query
