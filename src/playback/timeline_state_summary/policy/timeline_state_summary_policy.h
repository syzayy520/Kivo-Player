#pragma once
#include "timeline_state_summary_kind.h"
#include "timeline_state_completeness_policy.h"
#include "timeline_state_priority.h"
namespace kivo::playback::timeline_state_summary {
struct TimelineStateSummaryPolicy {
    TimelineStateSummaryKind summary_kind{TimelineStateSummaryKind::Unknown};
    TimelineStateCompletenessPolicy completeness_policy{TimelineStateCompletenessPolicy::Unknown};
    TimelineStatePriority priority{TimelineStatePriority::Unknown};
};
}
