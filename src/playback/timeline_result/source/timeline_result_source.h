#pragma once
#include "timeline_result_source_kind.h"
#include "timeline_decision_route_identity_source_ref.h"
#include "routed_timeline_decision_source_ref.h"
namespace kivo::playback::timeline_result {
struct TimelineResultSource {
    TimelineResultSourceKind kind{TimelineResultSourceKind::Unknown};
    TimelineDecisionRouteIdentitySourceRef identity_source{};
    RoutedTimelineDecisionSourceRef routed_source{};
};
}
