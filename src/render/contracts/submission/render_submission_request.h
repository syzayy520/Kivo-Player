#pragma once
#include "render_submission_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
namespace kivo::playback::render {
struct RenderSubmissionRequest {
    RenderSubmissionId submission_id{};
    kivo::playback::timeline::MediaTimestamp target_time{};
};
}
