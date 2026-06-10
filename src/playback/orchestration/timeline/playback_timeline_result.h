#pragma once
#include "../session/playback_session_id.h"
#include "playback_timeline_decision.h"
namespace kivo::playback::orchestration {
struct PlaybackTimelineResult {
    PlaybackSessionId session_id{};
    PlaybackTimelineDecision decision{};
};
}
