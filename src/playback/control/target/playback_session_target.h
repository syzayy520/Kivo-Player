#pragma once
#include "../identity/control_request_id.h"
#include "playback/orchestration/session/playback_session_id.h"
namespace kivo::playback::control {
struct PlaybackSessionTarget {
    ControlRequestId request_id{};
    kivo::playback::orchestration::PlaybackSessionId session_id{};
};
}
