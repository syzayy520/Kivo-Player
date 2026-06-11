#pragma once
#include "timeline_state_summary_envelope.h"
#include "playback_timeline_state_summary.h"
namespace kivo::playback::timeline_state_summary {
struct TimelineStateSummaryRecord { TimelineStateSummaryEnvelope envelope{}; PlaybackTimelineStateSummary summary{}; };
}
