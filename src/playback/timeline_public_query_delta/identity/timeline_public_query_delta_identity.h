#pragma once

#include "timeline_public_query_delta_id.h"
#include "timeline_public_query_delta_sequence_id.h"
#include "timeline_public_query_delta_generation.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaIdentity {
    TimelinePublicQueryDeltaId query_delta_id{};
    TimelinePublicQueryDeltaSequenceId sequence_id{};
    TimelinePublicQueryDeltaGeneration generation{};

    bool operator==(const TimelinePublicQueryDeltaIdentity& other) const = default;
};

} // namespace kivo::playback::timeline_public_query_delta
