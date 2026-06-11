#include <cassert>
#include <iostream>
#include "playback/timeline_decision/source/timeline_decision_source_kind.h"
#include "playback/timeline_decision/source/timeline_request_identity_source_ref.h"
#include "playback/timeline_decision/source/timeline_normalized_request_source_ref.h"
#include "playback/timeline_decision/source/timeline_decision_source.h"
namespace kivo::playback::timeline_decision {
void run_timeline_decision_source_tests() {
    assert(static_cast<int>(TimelineDecisionSourceKind::RequestIdentity) != static_cast<int>(TimelineDecisionSourceKind::NormalizedRequest));
    assert(static_cast<int>(TimelineDecisionSourceKind::Unknown) != static_cast<int>(TimelineDecisionSourceKind::Synthetic));
    TimelineRequestIdentitySourceRef ir1; assert(ir1.request_identity.request_id.value == 0);
    kivo::playback::timeline_request::TimelineRequestIdentity ident{.request_id{5}, .sequence_id{6}, .generation{7}};
    TimelineRequestIdentitySourceRef ir2{ident}; assert(ir2.request_identity.request_id.value == 5);
    TimelineNormalizedRequestSourceRef nr1; assert(nr1.normalized_request.identity.request_id.value == 0);
    TimelineDecisionSource src1;
    assert(src1.kind == TimelineDecisionSourceKind::Unknown);
    TimelineDecisionSource src2{TimelineDecisionSourceKind::RequestIdentity, ir2, {}};
    assert(src2.kind == TimelineDecisionSourceKind::RequestIdentity);
    assert(src2.identity_source.request_identity.request_id.value == 5);
    std::cout << "  timeline_decision_source_tests: ALL PASSED\n";
}
}
