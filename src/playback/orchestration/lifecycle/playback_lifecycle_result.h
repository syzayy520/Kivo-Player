#pragma once
#include "playback_lifecycle_state.h"
#include "../session/playback_session_id.h"
namespace kivo::playback::orchestration {
struct PlaybackLifecycleResult {
    PlaybackSessionId session_id{};
    PlaybackLifecycleState resulting_state{PlaybackLifecycleState::Unknown};
};
}
