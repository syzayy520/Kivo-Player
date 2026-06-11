#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta/query_delta/playback_timeline_public_query_delta.h"
#include "playback/timeline_public_query_delta/outcome/timeline_public_query_delta_outcome.h"

using namespace kivo::playback::timeline_public_query_delta;

void test_timeline_public_query_delta_boundary_compile_surface() {
    PlaybackTimelinePublicQueryDelta aggregate{};
    TimelinePublicQueryDeltaOutcome outcome{};

    assert(aggregate.identity.query_delta_id.value == 0);
    assert(aggregate.anchors.query_anchor.query_identity.query_id.value == 0);
    assert(aggregate.anchors.delta_anchor.delta_identity.delta_id.value == 0);
    assert(aggregate.anchors.final_audit_anchor.final_audit_identity.audit_id.value == 0);
    assert(outcome.status == TimelinePublicQueryDeltaStatus::Pending);

    std::cout << "PASS: test_timeline_public_query_delta_boundary_compile_surface" << std::endl;
}
