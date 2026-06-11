#pragma once

#include "timeline_public_query_id.h"
#include "timeline_public_query_sequence_id.h"
#include "timeline_public_query_generation.h"

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQueryIdentity {
    TimelinePublicQueryId query_id{};
    TimelinePublicQuerySequenceId sequence_id{};
    TimelinePublicQueryGeneration generation{};

    bool operator==(const TimelinePublicQueryIdentity& other) const = default;
};

} // namespace kivo::playback::timeline_public_query
