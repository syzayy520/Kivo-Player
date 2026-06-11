#pragma once

#include <cstdint>

#include "playback/timeline_public_delta/identity/timeline_public_delta_identity.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaDeltaAnchor {
    kivo::playback::timeline_public_delta::TimelinePublicDeltaIdentity delta_identity{};
};

} // namespace kivo::playback::timeline_public_query_delta
