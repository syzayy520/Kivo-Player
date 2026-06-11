#pragma once
#include "../identity/timeline_state_summary_identity.h"
#include "../source/timeline_state_source.h"
#include "../input/timeline_state_input.h"
#include "../policy/timeline_state_summary_policy.h"
namespace kivo::playback::timeline_state_summary {
struct TimelineStateSummaryEnvelope { TimelineStateSummaryIdentity identity{}; TimelineStateSource source{}; TimelineStateInput input{}; TimelineStateSummaryPolicy policy{}; };
}
