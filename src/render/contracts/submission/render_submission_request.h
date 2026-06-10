#pragma once
#include <vector>
#include "render_submission_id.h"
#include "../frame/render_frame_id.h"
#include "../target/render_target_id.h"
namespace kivo::playback::render {
struct RenderSubmissionRequest {
    RenderSubmissionId submission_id{};
    std::vector<RenderFrameId> frame_ids{};
    RenderTargetId target_id{};
};
}
