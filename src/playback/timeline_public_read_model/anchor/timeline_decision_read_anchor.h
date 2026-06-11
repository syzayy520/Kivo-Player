#pragma once
#include "playback/timeline_decision/identity/timeline_decision_route_identity.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelineDecisionReadAnchor {
    kivo::playback::timeline_decision::TimelineDecisionRouteIdentity decision_route_identity{};
};
}
