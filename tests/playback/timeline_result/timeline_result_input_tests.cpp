#include <cassert>
#include <iostream>
#include "playback/timeline_result/input/timeline_result_input_kind.h"
#include "playback/timeline_result/input/timeline_decision_route_record_input.h"
#include "playback/timeline_result/input/playback_timeline_result_input.h"
#include "playback/timeline_result/input/timeline_result_input.h"
namespace kivo::playback::timeline_result {
void run_timeline_result_input_tests() {
    assert(static_cast<int>(TimelineResultInputKind::DecisionRouteRecord) != static_cast<int>(TimelineResultInputKind::TimelineResult));
    assert(static_cast<int>(TimelineResultInputKind::Unknown) != static_cast<int>(TimelineResultInputKind::DecisionRouteRecord));
    TimelineDecisionRouteRecordInput rri1; assert(rri1.route_record.envelope.identity.route_id.value == 0);
    PlaybackTimelineResultInput pri1; assert(pri1.result.session_id.value == 0);
    assert(static_cast<int>(pri1.result.decision.decision) == static_cast<int>(kivo::playback::presentation::PresentationDecision::Unknown));
    TimelineResultInput inp1;
    assert(inp1.kind == TimelineResultInputKind::Unknown);
    kivo::playback::orchestration::PlaybackTimelineResult res;
    res.decision.decision = kivo::playback::presentation::PresentationDecision::Present;
    PlaybackTimelineResultInput pri2{res};
    TimelineResultInput inp2{TimelineResultInputKind::TimelineResult, {}, pri2};
    assert(inp2.kind == TimelineResultInputKind::TimelineResult);
    assert(inp2.timeline_result.result.decision.decision == kivo::playback::presentation::PresentationDecision::Present);
    std::cout << "  timeline_result_input_tests: ALL PASSED\n";
}
}
