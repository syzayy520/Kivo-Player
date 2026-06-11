#include <cassert>
#include <iostream>
#include "playback/timeline_decision/input/timeline_decision_input_kind.h"
#include "playback/timeline_decision/input/timeline_normalized_request_input.h"
#include "playback/timeline_decision/input/timeline_request_envelope_input.h"
#include "playback/timeline_decision/input/timeline_decision_input.h"
namespace kivo::playback::timeline_decision {
void run_timeline_decision_input_tests() {
    assert(static_cast<int>(TimelineDecisionInputKind::NormalizedRequest) != static_cast<int>(TimelineDecisionInputKind::RequestEnvelope));
    assert(static_cast<int>(TimelineDecisionInputKind::Unknown) != static_cast<int>(TimelineDecisionInputKind::NormalizedRequest));
    TimelineNormalizedRequestInput nri1; assert(nri1.request.identity.request_id.value == 0);
    TimelineRequestEnvelopeInput rei1; assert(rei1.envelope.identity.request_id.value == 0);
    kivo::playback::timeline_request::TimelineRequestIdentity ident{.request_id{1}, .sequence_id{2}, .generation{3}};
    kivo::playback::timeline_request::TimelineRequestEnvelope env{ident};
    TimelineRequestEnvelopeInput rei2{env}; assert(rei2.envelope.identity.request_id.value == 1);
    TimelineDecisionInput inp1;
    assert(inp1.kind == TimelineDecisionInputKind::Unknown);
    TimelineDecisionInput inp2{TimelineDecisionInputKind::RequestEnvelope, {}, rei2};
    assert(inp2.kind == TimelineDecisionInputKind::RequestEnvelope);
    assert(inp2.request_envelope.envelope.identity.request_id.value == 1);
    std::cout << "  timeline_decision_input_tests: ALL PASSED\n";
}
}
