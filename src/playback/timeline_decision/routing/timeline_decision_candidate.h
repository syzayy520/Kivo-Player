#pragma once
#include "../identity/timeline_decision_route_identity.h"
#include "playback/orchestration/timeline/playback_timeline_decision.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionCandidate {
    TimelineDecisionRouteIdentity identity{};
    kivo::playback::orchestration::PlaybackTimelineDecision decision{};
};
}
