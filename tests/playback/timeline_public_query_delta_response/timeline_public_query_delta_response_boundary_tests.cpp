#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta_response/response_binding/playback_timeline_public_query_delta_response.h"
#include "playback/timeline_public_query_delta_response/outcome/timeline_public_query_delta_response_outcome.h"

using namespace kivo::playback::timeline_public_query_delta_response;

void test_query_delta_response_boundary_compile_surface() {
    PlaybackTimelinePublicQueryDeltaResponse aggregate{};
    TimelinePublicQueryDeltaResponseOutcome outcome{};

    assert(aggregate.identity.query_delta_response_key.value == 0);
    assert(aggregate.anchors.query_delta_anchor.query_delta_identity.query_delta_id.value == 0);
    assert(aggregate.anchors.response_anchor.response_identity.response_id.value == 0);
    assert(aggregate.anchors.final_audit_anchor.final_audit_identity.audit_id.value == 0);
    assert(outcome.status == TimelinePublicQueryDeltaResponseStatus::Pending);

    std::cout << "PASS: test_query_delta_response_boundary_compile_surface" << std::endl;
}
