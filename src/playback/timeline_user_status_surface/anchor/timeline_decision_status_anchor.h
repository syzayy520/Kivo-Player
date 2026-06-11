#pragma once
#include "playback/timeline_decision/identity/timeline_decision_route_identity.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineDecisionStatusAnchor {
    kivo::playback::timeline_decision::TimelineDecisionRouteIdentity decision_route_identity{};
};
}
