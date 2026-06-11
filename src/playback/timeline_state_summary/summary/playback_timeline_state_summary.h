#pragma once
#include "../identity/timeline_state_summary_identity.h"
#include "../source/timeline_state_source.h"
#include "../input/timeline_state_input.h"
namespace kivo::playback::timeline_state_summary {
struct PlaybackTimelineStateSummary { TimelineStateSummaryIdentity identity{}; TimelineStateSource source{}; TimelineStateInput input{}; };
}
