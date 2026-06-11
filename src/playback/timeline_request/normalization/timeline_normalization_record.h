#pragma once
#include "../identity/timeline_request_identity.h"
#include "../source/timeline_request_source.h"
#include "../target/timeline_request_target.h"
#include "../policy/timeline_request_policy.h"
#include "timeline_normalization_policy.h"
#include "normalized_timeline_request.h"
namespace kivo::playback::timeline_request {
struct TimelineNormalizationRecord {
    TimelineRequestIdentity identity{};
    TimelineRequestSource source{};
    TimelineRequestTarget target{};
    TimelineRequestPolicy policy{};
    TimelineNormalizationPolicy normalization_policy{TimelineNormalizationPolicy::Unknown};
    NormalizedTimelineRequest normalized_request{};
};
}
