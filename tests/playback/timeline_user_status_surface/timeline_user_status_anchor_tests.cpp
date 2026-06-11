#include <cassert>
#include <iostream>
#include "playback/timeline_user_status_surface/anchor/timeline_request_status_anchor.h"
#include "playback/timeline_user_status_surface/anchor/timeline_decision_status_anchor.h"
#include "playback/timeline_user_status_surface/anchor/timeline_result_status_anchor.h"
#include "playback/timeline_user_status_surface/anchor/timeline_snapshot_status_anchor.h"
#include "playback/timeline_user_status_surface/anchor/timeline_state_summary_status_anchor.h"
#include "playback/timeline_user_status_surface/anchor/timeline_chain_integrity_status_anchor.h"
#include "playback/timeline_user_status_surface/anchor/timeline_error_surface_status_anchor.h"
#include "playback/timeline_user_status_surface/anchor/timeline_user_status_anchor_set.h"
namespace kivo::playback::timeline_user_status_surface {
void run_timeline_user_status_anchor_tests() {
    TimelineRequestStatusAnchor ra1; assert(ra1.request_identity.request_id.value == 0);
    TimelineDecisionStatusAnchor da1; assert(da1.decision_route_identity.route_id.value == 0);
    TimelineResultStatusAnchor rsa1; assert(rsa1.result_report_identity.report_id.value == 0);
    TimelineSnapshotStatusAnchor sa1; assert(sa1.snapshot_observation_identity.observation_id.value == 0);
    TimelineStateSummaryStatusAnchor ssa1; assert(ssa1.state_summary_identity.summary_id.value == 0);
    TimelineChainIntegrityStatusAnchor cia1; assert(cia1.chain_integrity_identity.integrity_id.value == 0);
    TimelineErrorSurfaceStatusAnchor esa1; assert(esa1.error_surface_identity.surface_id.value == 0);
    TimelineUserStatusAnchorSet set1;
    assert(set1.request_anchor.request_identity.request_id.value == 0);
    assert(set1.decision_anchor.decision_route_identity.route_id.value == 0);
    assert(set1.result_anchor.result_report_identity.report_id.value == 0);
    assert(set1.snapshot_anchor.snapshot_observation_identity.observation_id.value == 0);
    assert(set1.state_summary_anchor.state_summary_identity.summary_id.value == 0);
    assert(set1.chain_integrity_anchor.chain_integrity_identity.integrity_id.value == 0);
    assert(set1.error_surface_anchor.error_surface_identity.surface_id.value == 0);
    std::cout << "  timeline_user_status_anchor_tests: ALL PASSED\n";
}
}
