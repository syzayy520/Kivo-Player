#pragma once

#include "timeline_public_query_delta_kind.h"
#include "timeline_public_query_delta_scope.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaClassification {
    TimelinePublicQueryDeltaKind kind{TimelinePublicQueryDeltaKind::Unspecified};
    TimelinePublicQueryDeltaScope scope{TimelinePublicQueryDeltaScope::Unspecified};
};

} // namespace kivo::playback::timeline_public_query_delta
