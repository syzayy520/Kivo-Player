#pragma once

#include "timeline_public_response_kind.h"
#include "timeline_public_response_scope.h"

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseClassification {
    TimelinePublicResponseKind kind{TimelinePublicResponseKind::Unknown};
    TimelinePublicResponseScope scope{TimelinePublicResponseScope::Unknown};

    bool operator==(const TimelinePublicResponseClassification& other) const = default;
};

} // namespace kivo::playback::timeline_public_response
