#pragma once
#include "../identity/timeline_state_summary_identity.h"
#include "timeline_state_summary_status.h"
namespace kivo::playback::timeline_state_summary {
struct TimelineStateSummaryOutcome { TimelineStateSummaryIdentity identity{}; TimelineStateSummaryStatus status{TimelineStateSummaryStatus::Unknown}; };
}
