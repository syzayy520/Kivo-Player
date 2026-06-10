#pragma once
#include "render_outcome_status.h"
#include "render_failure_reason.h"
#include "render_drop_reason.h"
namespace kivo::playback::render {
struct RenderOutcome {
    uint64_t submission_id{0};
    uint64_t frame_id{0};
    RenderOutcomeStatus status{RenderOutcomeStatus::Pending};
    RenderFailureReason failure_reason{RenderFailureReason::InternalError};
    RenderDropReason drop_reason{RenderDropReason::LateFrame};
    int64_t present_time_us{0};
};
}
