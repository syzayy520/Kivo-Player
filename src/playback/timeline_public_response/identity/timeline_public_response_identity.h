#pragma once

#include "timeline_public_response_id.h"
#include "timeline_public_response_sequence_id.h"
#include "timeline_public_response_generation.h"

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseIdentity {
    TimelinePublicResponseId response_id{};
    TimelinePublicResponseSequenceId sequence_id{};
    TimelinePublicResponseGeneration generation{};

    bool operator==(const TimelinePublicResponseIdentity& other) const = default;
};

} // namespace kivo::playback::timeline_public_response
