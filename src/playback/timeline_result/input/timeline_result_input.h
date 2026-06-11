#pragma once
#include "timeline_result_input_kind.h"
#include "timeline_decision_route_record_input.h"
#include "playback_timeline_result_input.h"
namespace kivo::playback::timeline_result {
struct TimelineResultInput {
    TimelineResultInputKind kind{TimelineResultInputKind::Unknown};
    TimelineDecisionRouteRecordInput route_record{};
    PlaybackTimelineResultInput timeline_result{};
};
}
