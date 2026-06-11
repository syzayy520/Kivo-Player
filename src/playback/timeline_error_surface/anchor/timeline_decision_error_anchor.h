#pragma once
#include "playback/timeline_decision/identity/timeline_decision_route_identity.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineDecisionErrorAnchor {
    kivo::playback::timeline_decision::TimelineDecisionRouteIdentity decision_route_identity{};
};
}
