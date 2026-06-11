#pragma once
#include "../identity/timeline_request_identity.h"
#include "timeline_normalization_status.h"
namespace kivo::playback::timeline_request {
struct TimelineNormalizationOutcome {
    TimelineRequestIdentity identity{};
    TimelineNormalizationStatus status{TimelineNormalizationStatus::Unknown};
};
}
