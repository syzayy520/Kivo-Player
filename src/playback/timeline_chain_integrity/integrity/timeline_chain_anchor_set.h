#pragma once
#include "../anchor/timeline_request_chain_anchor.h"
#include "../anchor/timeline_decision_chain_anchor.h"
#include "../anchor/timeline_result_chain_anchor.h"
#include "../anchor/timeline_snapshot_chain_anchor.h"
#include "../anchor/timeline_state_summary_chain_anchor.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineChainAnchorSet { TimelineRequestChainAnchor request_anchor{}; TimelineDecisionChainAnchor decision_anchor{}; TimelineResultChainAnchor result_anchor{}; TimelineSnapshotChainAnchor snapshot_anchor{}; TimelineStateSummaryChainAnchor state_summary_anchor{}; };
}
