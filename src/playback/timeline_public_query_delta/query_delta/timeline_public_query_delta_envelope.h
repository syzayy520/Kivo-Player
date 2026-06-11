#pragma once

#include "timeline_public_query_delta_candidate.h"
#include "timeline_public_query_delta_record.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaEnvelope {
    TimelinePublicQueryDeltaCandidate candidate{};
    TimelinePublicQueryDeltaRecord record{};
};

} // namespace kivo::playback::timeline_public_query_delta
