#include <cassert>
#include <iostream>
#include "playback/timeline_chain_integrity/integrity/timeline_chain_anchor_set.h"
namespace kivo::playback::timeline_chain_integrity {
void run_timeline_chain_boundary_tests() {
    TimelineChainAnchorSet anchors;
    assert(anchors.request_anchor.request_identity.request_id.value == 0);
    assert(anchors.request_anchor.request_identity.sequence_id.value == 0);
    assert(anchors.request_anchor.request_identity.generation.value == 0);
    assert(anchors.decision_anchor.decision_route_identity.route_id.value == 0);
    assert(anchors.result_anchor.result_report_identity.report_id.value == 0);
    assert(anchors.snapshot_anchor.snapshot_observation_identity.observation_id.value == 0);
    assert(anchors.state_summary_anchor.state_summary_identity.summary_id.value == 0);
    std::cout << "  timeline_chain_boundary_tests: ALL PASSED\n";
}
}
