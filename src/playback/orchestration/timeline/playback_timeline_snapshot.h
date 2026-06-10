#pragma once
#include "../session/playback_session_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
namespace kivo::playback::orchestration {
struct PlaybackTimelineSnapshot {
    PlaybackSessionId session_id{};
    kivo::playback::timeline::MediaTimestamp position{};
};
}
