#pragma once
#include "timeline_decision_route_envelope.h"
#include "routed_timeline_decision.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionRouteRecord {
    TimelineDecisionRouteEnvelope envelope{};
    RoutedTimelineDecision routed_decision{};
};
}
