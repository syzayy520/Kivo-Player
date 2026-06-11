#pragma once

#include "timeline_public_query_delta_response_candidate.h"
#include "timeline_public_query_delta_response_record.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseEnvelope {
    TimelinePublicQueryDeltaResponseCandidate candidate{};
    TimelinePublicQueryDeltaResponseRecord record{};
};

} // namespace kivo::playback::timeline_public_query_delta_response
