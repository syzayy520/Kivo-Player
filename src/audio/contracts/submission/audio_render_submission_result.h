#pragma once
#include <cstdint>
#include "audio_render_submission_id.h"
#include "audio_render_submission_status.h"
namespace kivo::playback::audio {
struct AudioRenderSubmissionResult {
    AudioRenderSubmissionId submission_id{};
    AudioRenderSubmissionStatus status{AudioRenderSubmissionStatus::Unknown};
    uint64_t frames_accepted{0};
    uint64_t frames_dropped{0};
};
}
