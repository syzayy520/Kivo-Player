#pragma once
#include "timeline_state_summary_id.h"
#include "timeline_state_summary_sequence_id.h"
#include "timeline_state_summary_generation.h"
namespace kivo::playback::timeline_state_summary {
struct TimelineStateSummaryIdentity {
    TimelineStateSummaryId summary_id{};
    TimelineStateSummarySequenceId sequence_id{};
    TimelineStateSummaryGeneration generation{};
};
}
