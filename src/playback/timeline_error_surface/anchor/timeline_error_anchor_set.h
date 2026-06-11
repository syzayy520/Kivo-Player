#pragma once
#include "timeline_request_error_anchor.h"
#include "timeline_decision_error_anchor.h"
#include "timeline_result_error_anchor.h"
#include "timeline_snapshot_error_anchor.h"
#include "timeline_state_summary_error_anchor.h"
#include "timeline_chain_integrity_error_anchor.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineErrorAnchorSet {
    TimelineRequestErrorAnchor request_anchor{};
    TimelineDecisionErrorAnchor decision_anchor{};
    TimelineResultErrorAnchor result_anchor{};
    TimelineSnapshotErrorAnchor snapshot_anchor{};
    TimelineStateSummaryErrorAnchor state_summary_anchor{};
    TimelineChainIntegrityErrorAnchor chain_integrity_anchor{};
};
}
