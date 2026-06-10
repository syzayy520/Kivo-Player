#pragma once
#include "../identity/control_request_id.h"
#include "playback/orchestration/intent/playback_intent.h"
namespace kivo::playback::control {
struct NormalizedPlaybackIntent {
    ControlRequestId request_id{};
    kivo::playback::orchestration::PlaybackIntent intent{};
};
}
