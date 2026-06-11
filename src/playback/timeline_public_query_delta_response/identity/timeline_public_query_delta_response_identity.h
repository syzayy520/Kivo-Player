#pragma once

#include "timeline_public_query_delta_response_key.h"
#include "timeline_public_query_delta_response_sequence_id.h"
#include "timeline_public_query_delta_response_generation.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseIdentity {
    TimelinePublicQueryDeltaResponseKey query_delta_response_key{};
    TimelinePublicQueryDeltaResponseSequenceId sequence_id{};
    TimelinePublicQueryDeltaResponseGeneration generation{};

    bool operator==(const TimelinePublicQueryDeltaResponseIdentity& other) const = default;
};

} // namespace kivo::playback::timeline_public_query_delta_response
