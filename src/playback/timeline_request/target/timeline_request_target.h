#pragma once
#include "timeline_target_kind.h"
#include "timeline_position_target.h"
#include "timeline_control_target_ref.h"
namespace kivo::playback::timeline_request {
struct TimelineRequestTarget {
    TimelineTargetKind kind{TimelineTargetKind::Unknown};
    TimelinePositionTarget position_target{};
    TimelineControlTargetRef control_target_ref{};
};
}
