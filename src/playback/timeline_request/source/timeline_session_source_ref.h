#pragma once
#include "playback/orchestration/session/playback_session_id.h"
namespace kivo::playback::timeline_request {
struct TimelineSessionSourceRef {
    kivo::playback::orchestration::PlaybackSessionId session_id{};
};
}
