#pragma once
#include "timeline_decision_route_id.h"
#include "timeline_decision_route_sequence_id.h"
#include "timeline_decision_route_generation.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionRouteIdentity {
    TimelineDecisionRouteId route_id{};
    TimelineDecisionRouteSequenceId sequence_id{};
    TimelineDecisionRouteGeneration generation{};
};
}
