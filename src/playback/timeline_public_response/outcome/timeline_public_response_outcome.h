#pragma once

#include "../identity/timeline_public_response_identity.h"
#include "timeline_public_response_status.h"

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseOutcome {
    TimelinePublicResponseIdentity identity{};
    TimelinePublicResponseStatus status{TimelinePublicResponseStatus::Unknown};

    bool operator==(const TimelinePublicResponseOutcome& other) const = default;
};

} // namespace kivo::playback::timeline_public_response
