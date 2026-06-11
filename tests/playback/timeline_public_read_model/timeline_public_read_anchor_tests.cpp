#include <cassert>
#include <iostream>
#include "playback/timeline_public_read_model/anchor/timeline_request_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_decision_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_result_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_snapshot_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_state_summary_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_chain_integrity_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_error_surface_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_user_status_surface_read_anchor.h"
#include "playback/timeline_public_read_model/anchor/timeline_public_read_anchor_set.h"
namespace kivo::playback::timeline_public_read_model {
void run_timeline_public_read_anchor_tests() {
    TimelineRequestReadAnchor ra1; assert(ra1.request_identity.request_id.value == 0);
    TimelineDecisionReadAnchor da1; assert(da1.decision_route_identity.route_id.value == 0);
    TimelineResultReadAnchor rsa1; assert(rsa1.result_report_identity.report_id.value == 0);
    TimelineSnapshotReadAnchor sa1; assert(sa1.snapshot_observation_identity.observation_id.value == 0);
    TimelineStateSummaryReadAnchor ssa1; assert(ssa1.state_summary_identity.summary_id.value == 0);
    TimelineChainIntegrityReadAnchor cia1; assert(cia1.chain_integrity_identity.integrity_id.value == 0);
    TimelineErrorSurfaceReadAnchor esa1; assert(esa1.error_surface_identity.surface_id.value == 0);
    TimelineUserStatusSurfaceReadAnchor usa1; assert(usa1.user_status_surface_identity.surface_id.value == 0);
    TimelinePublicReadAnchorSet set1;
    assert(set1.request_anchor.request_identity.request_id.value == 0);
    assert(set1.decision_anchor.decision_route_identity.route_id.value == 0);
    assert(set1.result_anchor.result_report_identity.report_id.value == 0);
    assert(set1.snapshot_anchor.snapshot_observation_identity.observation_id.value == 0);
    assert(set1.state_summary_anchor.state_summary_identity.summary_id.value == 0);
    assert(set1.chain_integrity_anchor.chain_integrity_identity.integrity_id.value == 0);
    assert(set1.error_surface_anchor.error_surface_identity.surface_id.value == 0);
    assert(set1.user_status_surface_anchor.user_status_surface_identity.surface_id.value == 0);
    std::cout << "  timeline_public_read_anchor_tests: ALL PASSED\n";
}
}
