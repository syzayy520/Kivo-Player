#include <cassert>
#include <iostream>
#include "playback/timeline_chain_integrity/anchor/timeline_request_chain_anchor.h"
#include "playback/timeline_chain_integrity/anchor/timeline_decision_chain_anchor.h"
#include "playback/timeline_chain_integrity/anchor/timeline_result_chain_anchor.h"
#include "playback/timeline_chain_integrity/anchor/timeline_snapshot_chain_anchor.h"
#include "playback/timeline_chain_integrity/anchor/timeline_state_summary_chain_anchor.h"
namespace kivo::playback::timeline_chain_integrity {
void run_timeline_chain_anchor_tests() {
    TimelineRequestChainAnchor ra1; assert(ra1.request_identity.request_id.value == 0);
    kivo::playback::timeline_request::TimelineRequestIdentity rid{.request_id{1}, .sequence_id{2}, .generation{3}};
    TimelineRequestChainAnchor ra2{rid}; assert(ra2.request_identity.request_id.value == 1);
    TimelineDecisionChainAnchor da1; assert(da1.decision_route_identity.route_id.value == 0);
    TimelineResultChainAnchor ra3; assert(ra3.result_report_identity.report_id.value == 0);
    TimelineSnapshotChainAnchor sa1; assert(sa1.snapshot_observation_identity.observation_id.value == 0);
    TimelineStateSummaryChainAnchor ssa1; assert(ssa1.state_summary_identity.summary_id.value == 0);
    std::cout << "  timeline_chain_anchor_tests: ALL PASSED\n";
}
}
