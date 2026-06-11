#pragma once

#include "playback/timeline_public_query_delta/identity/timeline_public_query_delta_identity.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseQueryDeltaAnchor {
    kivo::playback::timeline_public_query_delta::TimelinePublicQueryDeltaIdentity query_delta_identity{};
};

} // namespace kivo::playback::timeline_public_query_delta_response
