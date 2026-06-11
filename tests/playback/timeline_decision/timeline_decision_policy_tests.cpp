#include <cassert>
#include <iostream>
#include "playback/timeline_decision/policy/timeline_decision_route_kind.h"
#include "playback/timeline_decision/policy/timeline_decision_fallback_policy.h"
#include "playback/timeline_decision/policy/timeline_decision_priority.h"
#include "playback/timeline_decision/policy/timeline_decision_route_policy.h"
namespace kivo::playback::timeline_decision {
void run_timeline_decision_policy_tests() {
    assert(static_cast<int>(TimelineDecisionRouteKind::Direct) != static_cast<int>(TimelineDecisionRouteKind::Drop));
    assert(static_cast<int>(TimelineDecisionRouteKind::Unknown) != static_cast<int>(TimelineDecisionRouteKind::Hold));
    assert(static_cast<int>(TimelineDecisionFallbackPolicy::PreserveUnknown) != static_cast<int>(TimelineDecisionFallbackPolicy::PreferDrop));
    assert(static_cast<int>(TimelineDecisionFallbackPolicy::Unknown) != static_cast<int>(TimelineDecisionFallbackPolicy::PreferHold));
    assert(static_cast<int>(TimelineDecisionPriority::Low) != static_cast<int>(TimelineDecisionPriority::High));
    assert(static_cast<int>(TimelineDecisionPriority::Unknown) != static_cast<int>(TimelineDecisionPriority::Normal));
    TimelineDecisionRoutePolicy p1;
    assert(p1.route_kind == TimelineDecisionRouteKind::Unknown);
    assert(p1.fallback_policy == TimelineDecisionFallbackPolicy::Unknown);
    assert(p1.priority == TimelineDecisionPriority::Unknown);
    TimelineDecisionRoutePolicy p2{TimelineDecisionRouteKind::Direct, TimelineDecisionFallbackPolicy::PreferHold, TimelineDecisionPriority::High};
    assert(p2.route_kind == TimelineDecisionRouteKind::Direct);
    assert(p2.fallback_policy == TimelineDecisionFallbackPolicy::PreferHold);
    assert(p2.priority == TimelineDecisionPriority::High);
    std::cout << "  timeline_decision_policy_tests: ALL PASSED\n";
}
}
