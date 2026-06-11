#include <cassert>
#include <iostream>
#include "playback/timeline_decision/routing/timeline_decision_candidate.h"
#include "playback/timeline_decision/routing/routed_timeline_decision.h"
#include "playback/timeline_decision/routing/timeline_decision_route_envelope.h"
#include "playback/timeline_decision/routing/timeline_decision_route_record.h"
namespace kivo::playback::timeline_decision {
void run_timeline_decision_routing_tests() {
    TimelineDecisionRouteIdentity ident{.route_id{1}, .sequence_id{2}, .generation{3}};
    TimelineDecisionCandidate c1;
    assert(c1.identity.route_id.value == 0);
    assert(c1.decision.session_id.value == 0);
    assert(static_cast<int>(c1.decision.decision) == static_cast<int>(kivo::playback::presentation::PresentationDecision::Unknown));
    kivo::playback::orchestration::PlaybackTimelineDecision d1;
    d1.decision = kivo::playback::presentation::PresentationDecision::Present;
    TimelineDecisionCandidate c2{ident, d1};
    assert(c2.identity.route_id.value == 1);
    assert(c2.decision.decision == kivo::playback::presentation::PresentationDecision::Present);
    RoutedTimelineDecision r1;
    assert(r1.identity.route_id.value == 0);
    RoutedTimelineDecision r2{ident, d1};
    assert(r2.decision.decision == kivo::playback::presentation::PresentationDecision::Present);
    TimelineDecisionRouteEnvelope env1;
    assert(env1.identity.route_id.value == 0);
    TimelineDecisionRouteEnvelope env2{ident};
    assert(env2.identity.route_id.value == 1);
    TimelineDecisionRouteRecord rec1;
    assert(rec1.envelope.identity.route_id.value == 0);
    assert(rec1.routed_decision.identity.route_id.value == 0);
    TimelineDecisionRouteRecord rec2{env2, r2};
    assert(rec2.envelope.identity.route_id.value == 1);
    assert(rec2.routed_decision.decision.decision == kivo::playback::presentation::PresentationDecision::Present);
    std::cout << "  timeline_decision_routing_tests: ALL PASSED\n";
}
}
