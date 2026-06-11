#include <cassert>
#include <iostream>
#include "playback/timeline_result/source/timeline_result_source_kind.h"
#include "playback/timeline_result/source/timeline_decision_route_identity_source_ref.h"
#include "playback/timeline_result/source/routed_timeline_decision_source_ref.h"
#include "playback/timeline_result/source/timeline_result_source.h"
namespace kivo::playback::timeline_result {
void run_timeline_result_source_tests() {
    assert(static_cast<int>(TimelineResultSourceKind::DecisionRouteIdentity) != static_cast<int>(TimelineResultSourceKind::RoutedDecision));
    assert(static_cast<int>(TimelineResultSourceKind::Unknown) != static_cast<int>(TimelineResultSourceKind::Synthetic));
    TimelineDecisionRouteIdentitySourceRef ir1; assert(ir1.route_identity.route_id.value == 0);
    kivo::playback::timeline_decision::TimelineDecisionRouteIdentity ident{.route_id{5}, .sequence_id{6}, .generation{7}};
    TimelineDecisionRouteIdentitySourceRef ir2{ident}; assert(ir2.route_identity.route_id.value == 5);
    RoutedTimelineDecisionSourceRef rr1; assert(rr1.routed_decision.identity.route_id.value == 0);
    TimelineResultSource src1;
    assert(src1.kind == TimelineResultSourceKind::Unknown);
    TimelineResultSource src2{TimelineResultSourceKind::DecisionRouteIdentity, ir2, {}};
    assert(src2.kind == TimelineResultSourceKind::DecisionRouteIdentity);
    assert(src2.identity_source.route_identity.route_id.value == 5);
    std::cout << "  timeline_result_source_tests: ALL PASSED\n";
}
}
