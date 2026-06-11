#pragma once

#include "timeline_public_query_kind.h"
#include "timeline_public_query_scope.h"

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQueryClassification {
    TimelinePublicQueryKind kind{TimelinePublicQueryKind::Unknown};
    TimelinePublicQueryScope scope{TimelinePublicQueryScope::Unknown};

    bool operator==(const TimelinePublicQueryClassification& other) const = default;
};

} // namespace kivo::playback::timeline_public_query
