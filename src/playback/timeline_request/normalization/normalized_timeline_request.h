#pragma once
#include "../identity/timeline_request_identity.h"
#include "playback/orchestration/timeline/playback_timeline_request.h"
namespace kivo::playback::timeline_request {
struct NormalizedTimelineRequest {
    TimelineRequestIdentity identity{};
    kivo::playback::orchestration::PlaybackTimelineRequest request{};
};
}
