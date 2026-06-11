#pragma once
#include "timeline_request_status_anchor.h"
#include "timeline_decision_status_anchor.h"
#include "timeline_result_status_anchor.h"
#include "timeline_snapshot_status_anchor.h"
#include "timeline_state_summary_status_anchor.h"
#include "timeline_chain_integrity_status_anchor.h"
#include "timeline_error_surface_status_anchor.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineUserStatusAnchorSet {
    TimelineRequestStatusAnchor request_anchor{};
    TimelineDecisionStatusAnchor decision_anchor{};
    TimelineResultStatusAnchor result_anchor{};
    TimelineSnapshotStatusAnchor snapshot_anchor{};
    TimelineStateSummaryStatusAnchor state_summary_anchor{};
    TimelineChainIntegrityStatusAnchor chain_integrity_anchor{};
    TimelineErrorSurfaceStatusAnchor error_surface_anchor{};
};
}
