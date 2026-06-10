#pragma once
#include <cstdint>
#include "render_submission_id.h"
#include "render_submission_status.h"
namespace kivo::playback::render {
struct RenderSubmissionResult {
    RenderSubmissionId submission_id{};
    RenderSubmissionStatus status{RenderSubmissionStatus::Unknown};
    uint64_t frames_accepted{0};
    uint64_t frames_dropped{0};
};
}
