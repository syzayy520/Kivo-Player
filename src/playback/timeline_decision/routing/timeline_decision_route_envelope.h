#pragma once
#include "../identity/timeline_decision_route_identity.h"
#include "../source/timeline_decision_source.h"
#include "../input/timeline_decision_input.h"
#include "../policy/timeline_decision_route_policy.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionRouteEnvelope {
    TimelineDecisionRouteIdentity identity{};
    TimelineDecisionSource source{};
    TimelineDecisionInput input{};
    TimelineDecisionRoutePolicy policy{};
};
}
