#pragma once
#include "timeline_decision_route_kind.h"
#include "timeline_decision_fallback_policy.h"
#include "timeline_decision_priority.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionRoutePolicy {
    TimelineDecisionRouteKind route_kind{TimelineDecisionRouteKind::Unknown};
    TimelineDecisionFallbackPolicy fallback_policy{TimelineDecisionFallbackPolicy::Unknown};
    TimelineDecisionPriority priority{TimelineDecisionPriority::Unknown};
};
}
