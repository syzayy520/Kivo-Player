#pragma once
#include "timeline_request_read_anchor.h"
#include "timeline_decision_read_anchor.h"
#include "timeline_result_read_anchor.h"
#include "timeline_snapshot_read_anchor.h"
#include "timeline_state_summary_read_anchor.h"
#include "timeline_chain_integrity_read_anchor.h"
#include "timeline_error_surface_read_anchor.h"
#include "timeline_user_status_surface_read_anchor.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelinePublicReadAnchorSet {
    TimelineRequestReadAnchor request_anchor{};
    TimelineDecisionReadAnchor decision_anchor{};
    TimelineResultReadAnchor result_anchor{};
    TimelineSnapshotReadAnchor snapshot_anchor{};
    TimelineStateSummaryReadAnchor state_summary_anchor{};
    TimelineChainIntegrityReadAnchor chain_integrity_anchor{};
    TimelineErrorSurfaceReadAnchor error_surface_anchor{};
    TimelineUserStatusSurfaceReadAnchor user_status_surface_anchor{};
};
}
