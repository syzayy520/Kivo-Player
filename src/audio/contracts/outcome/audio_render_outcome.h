#pragma once
#include "../submission/audio_render_submission_id.h"
#include "audio_render_outcome_status.h"
namespace kivo::playback::audio {
struct AudioRenderOutcome {
    AudioRenderSubmissionId submission_id{};
    AudioRenderOutcomeStatus status{AudioRenderOutcomeStatus::Unknown};
};
}
