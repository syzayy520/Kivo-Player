#include <cassert>
#include <iostream>
#include "playback/timeline_decision/identity/timeline_decision_route_id.h"
#include "playback/timeline_decision/identity/timeline_decision_route_sequence_id.h"
#include "playback/timeline_decision/identity/timeline_decision_route_generation.h"
#include "playback/timeline_decision/identity/timeline_decision_route_identity.h"
namespace kivo::playback::timeline_decision {
void run_timeline_decision_identity_tests() {
    TimelineDecisionRouteId rid1; assert(rid1.value == 0); TimelineDecisionRouteId rid2{42}; assert(rid2.value == 42);
    TimelineDecisionRouteSequenceId sid1; assert(sid1.value == 0); TimelineDecisionRouteSequenceId sid2{7}; assert(sid2.value == 7);
    TimelineDecisionRouteGeneration g1; assert(g1.value == 0); TimelineDecisionRouteGeneration g2{3}; assert(g2.value == 3);
    TimelineDecisionRouteIdentity ident1;
    assert(ident1.route_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineDecisionRouteIdentity ident2{.route_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.route_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_decision_identity_tests: ALL PASSED\n";
}
void run_timeline_decision_source_tests();
void run_timeline_decision_input_tests();
void run_timeline_decision_policy_tests();
void run_timeline_decision_routing_tests();
void run_timeline_decision_outcome_tests();
}
int main() {
    using namespace kivo::playback::timeline_decision;
    run_timeline_decision_identity_tests(); run_timeline_decision_source_tests();
    run_timeline_decision_input_tests(); run_timeline_decision_policy_tests();
    run_timeline_decision_routing_tests(); run_timeline_decision_outcome_tests();
    std::cout << "  ALL timeline decision tests PASSED\n"; return 0;
}
