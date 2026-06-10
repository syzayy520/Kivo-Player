#pragma once
#include "render_submission_id.h"
#include "../outcome/render_outcome_status.h"
namespace kivo::playback::render {
struct RenderSubmissionResult {
    RenderSubmissionId submission_id{};
    RenderOutcomeStatus status{RenderOutcomeStatus::Pending};
};
}
