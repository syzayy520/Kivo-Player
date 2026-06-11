#pragma once

#include "../identity/timeline_public_query_identity.h"
#include "timeline_public_query_status.h"

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQueryOutcome {
    TimelinePublicQueryIdentity identity{};
    TimelinePublicQueryStatus status{TimelinePublicQueryStatus::Unknown};

    bool operator==(const TimelinePublicQueryOutcome& other) const = default;
};

} // namespace kivo::playback::timeline_public_query
