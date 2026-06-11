#pragma once
#include "playback/timeline_request/normalization/normalized_timeline_request.h"
namespace kivo::playback::timeline_decision {
struct TimelineNormalizedRequestInput {
    kivo::playback::timeline_request::NormalizedTimelineRequest request{};
};
}
