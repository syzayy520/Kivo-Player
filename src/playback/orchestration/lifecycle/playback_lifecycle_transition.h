#pragma once
#include "playback_lifecycle_state.h"
#include "playback_lifecycle_request.h"
#include "../session/playback_session_id.h"
namespace kivo::playback::orchestration {
struct PlaybackLifecycleTransition {
    PlaybackSessionId session_id{};
    PlaybackLifecycleState previous{PlaybackLifecycleState::Unknown};
    PlaybackLifecycleRequestKind request{PlaybackLifecycleRequestKind::Unknown};
    PlaybackLifecycleState next{PlaybackLifecycleState::Unknown};
};
}
