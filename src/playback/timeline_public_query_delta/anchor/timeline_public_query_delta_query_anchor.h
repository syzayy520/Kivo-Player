#pragma once

#include "playback/timeline_public_query/identity/timeline_public_query_identity.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaQueryAnchor {
    kivo::playback::timeline_public_query::TimelinePublicQueryIdentity query_identity{};
};

} // namespace kivo::playback::timeline_public_query_delta
