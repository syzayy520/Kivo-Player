#include <cassert>
#include <iostream>
#include "playback/timeline_decision/outcome/timeline_decision_route_status.h"
#include "playback/timeline_decision/outcome/timeline_decision_route_outcome.h"
#include "playback/timeline_decision/outcome/timeline_decision_rejection_reason.h"
#include "playback/timeline_decision/outcome/timeline_decision_drop_reason.h"
namespace kivo::playback::timeline_decision {
void run_timeline_decision_outcome_tests() {
    assert(static_cast<int>(TimelineDecisionRouteStatus::Routed) != static_cast<int>(TimelineDecisionRouteStatus::Rejected));
    assert(static_cast<int>(TimelineDecisionRouteStatus::Dropped) != static_cast<int>(TimelineDecisionRouteStatus::Unknown));
    assert(static_cast<int>(TimelineDecisionRejectionReason::InputInvalid) != static_cast<int>(TimelineDecisionRejectionReason::DecisionUnavailable));
    assert(static_cast<int>(TimelineDecisionRejectionReason::RoutePolicyInvalid) != static_cast<int>(TimelineDecisionRejectionReason::Unknown));
    assert(static_cast<int>(TimelineDecisionDropReason::Superseded) != static_cast<int>(TimelineDecisionDropReason::PriorityOverridden));
    assert(static_cast<int>(TimelineDecisionDropReason::Unknown) != static_cast<int>(TimelineDecisionDropReason::Superseded));
    TimelineDecisionRouteOutcome o1;
    assert(o1.status == TimelineDecisionRouteStatus::Unknown);
    assert(o1.identity.route_id.value == 0);
    TimelineDecisionRouteIdentity ident{.route_id{10}, .sequence_id{20}, .generation{30}};
    TimelineDecisionRouteOutcome o2{ident, TimelineDecisionRouteStatus::Routed};
    assert(o2.identity.route_id.value == 10);
    assert(o2.status == TimelineDecisionRouteStatus::Routed);
    std::cout << "  timeline_decision_outcome_tests: ALL PASSED\n";
}
}
