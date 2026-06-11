#pragma once
#include "../identity/timeline_decision_route_identity.h"
#include "timeline_decision_route_status.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionRouteOutcome {
    TimelineDecisionRouteIdentity identity{};
    TimelineDecisionRouteStatus status{TimelineDecisionRouteStatus::Unknown};
};
}
