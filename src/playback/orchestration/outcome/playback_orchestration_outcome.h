#pragma once
#include "../session/playback_session_id.h"
#include "playback_orchestration_status.h"
namespace kivo::playback::orchestration {
struct PlaybackOrchestrationOutcome {
    PlaybackSessionId session_id{};
    PlaybackOrchestrationStatus status{PlaybackOrchestrationStatus::Unknown};
};
}
