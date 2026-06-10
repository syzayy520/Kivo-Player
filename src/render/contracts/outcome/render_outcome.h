#pragma once
#include "../submission/render_submission_id.h"
#include "../frame/render_frame_id.h"
#include "render_outcome_status.h"
namespace kivo::playback::render {
struct RenderOutcome {
    RenderSubmissionId submission_id{};
    RenderFrameId frame_id{};
    RenderOutcomeStatus status{RenderOutcomeStatus::Unknown};
};
}
