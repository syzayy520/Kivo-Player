#include <cassert>
#include <iostream>
#include "playback/timeline_state_summary/input/timeline_state_input_kind.h"
#include "playback/timeline_state_summary/input/timeline_decision_route_identity_input.h"
#include "playback/timeline_state_summary/input/timeline_result_report_identity_input.h"
#include "playback/timeline_state_summary/input/timeline_state_input.h"
namespace kivo::playback::timeline_state_summary {
void run_timeline_state_input_tests() {
    assert(static_cast<int>(TimelineStateInputKind::DecisionRouteIdentity) != static_cast<int>(TimelineStateInputKind::ResultReportIdentity));
    assert(static_cast<int>(TimelineStateInputKind::Unknown) != static_cast<int>(TimelineStateInputKind::DecisionRouteIdentity));
    TimelineDecisionRouteIdentityInput di1; assert(di1.decision_route_identity.route_id.value == 0);
    kivo::playback::timeline_decision::TimelineDecisionRouteIdentity drid{.route_id{1}, .sequence_id{2}, .generation{3}};
    TimelineDecisionRouteIdentityInput di2{drid}; assert(di2.decision_route_identity.route_id.value == 1);
    TimelineResultReportIdentityInput ri1; assert(ri1.result_report_identity.report_id.value == 0);
    kivo::playback::timeline_result::TimelineResultReportIdentity rrid{.report_id{5}, .sequence_id{6}, .generation{7}};
    TimelineResultReportIdentityInput ri2{rrid}; assert(ri2.result_report_identity.report_id.value == 5);
    TimelineStateInput inp1; assert(inp1.kind == TimelineStateInputKind::Unknown);
    TimelineStateInput inp2{TimelineStateInputKind::DecisionRouteIdentity, di2, {}}; assert(inp2.decision_input.decision_route_identity.route_id.value == 1);
    std::cout << "  timeline_state_input_tests: ALL PASSED\n";
}
}
