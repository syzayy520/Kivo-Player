#include <cassert>
#include <iostream>
#include "playback/timeline_error_surface/anchor/timeline_request_error_anchor.h"
#include "playback/timeline_error_surface/anchor/timeline_decision_error_anchor.h"
#include "playback/timeline_error_surface/anchor/timeline_result_error_anchor.h"
#include "playback/timeline_error_surface/anchor/timeline_snapshot_error_anchor.h"
#include "playback/timeline_error_surface/anchor/timeline_state_summary_error_anchor.h"
#include "playback/timeline_error_surface/anchor/timeline_chain_integrity_error_anchor.h"
#include "playback/timeline_error_surface/anchor/timeline_error_anchor_set.h"
namespace kivo::playback::timeline_error_surface {
void run_timeline_error_anchor_tests() {
    TimelineRequestErrorAnchor ra1; assert(ra1.request_identity.request_id.value == 0);
    TimelineDecisionErrorAnchor da1; assert(da1.decision_route_identity.route_id.value == 0);
    TimelineResultErrorAnchor rsa1; assert(rsa1.result_report_identity.report_id.value == 0);
    TimelineSnapshotErrorAnchor sa1; assert(sa1.snapshot_observation_identity.observation_id.value == 0);
    TimelineStateSummaryErrorAnchor ssa1; assert(ssa1.state_summary_identity.summary_id.value == 0);
    TimelineChainIntegrityErrorAnchor cia1; assert(cia1.chain_integrity_identity.integrity_id.value == 0);
    TimelineErrorAnchorSet set1;
    assert(set1.request_anchor.request_identity.request_id.value == 0);
    assert(set1.decision_anchor.decision_route_identity.route_id.value == 0);
    assert(set1.result_anchor.result_report_identity.report_id.value == 0);
    assert(set1.snapshot_anchor.snapshot_observation_identity.observation_id.value == 0);
    assert(set1.state_summary_anchor.state_summary_identity.summary_id.value == 0);
    assert(set1.chain_integrity_anchor.chain_integrity_identity.integrity_id.value == 0);
    std::cout << "  timeline_error_anchor_tests: ALL PASSED\n";
}
}
