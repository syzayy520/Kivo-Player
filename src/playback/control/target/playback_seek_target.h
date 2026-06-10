#pragma once
#include "../identity/control_request_id.h"
#include "playback/orchestration/session/playback_session_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
namespace kivo::playback::control {
struct PlaybackSeekTarget {
    ControlRequestId request_id{};
    kivo::playback::orchestration::PlaybackSessionId session_id{};
    kivo::playback::timeline::MediaTimestamp target_position{};
};
}
