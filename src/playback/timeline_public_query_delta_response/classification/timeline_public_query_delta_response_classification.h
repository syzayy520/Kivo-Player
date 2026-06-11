#pragma once

#include "timeline_public_query_delta_response_kind.h"
#include "timeline_public_query_delta_response_scope.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseClassification {
    TimelinePublicQueryDeltaResponseKind kind{TimelinePublicQueryDeltaResponseKind::Unspecified};
    TimelinePublicQueryDeltaResponseScope scope{TimelinePublicQueryDeltaResponseScope::Unspecified};
};

} // namespace kivo::playback::timeline_public_query_delta_response
