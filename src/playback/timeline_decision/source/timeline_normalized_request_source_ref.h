#pragma once
#include "playback/timeline_request/normalization/normalized_timeline_request.h"
namespace kivo::playback::timeline_decision {
struct TimelineNormalizedRequestSourceRef {
    kivo::playback::timeline_request::NormalizedTimelineRequest normalized_request{};
};
}
