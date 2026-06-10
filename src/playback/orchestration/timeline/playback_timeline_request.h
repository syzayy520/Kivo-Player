#pragma once
#include "../session/playback_session_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
#include "core/presentation/timing/presentation_deadline.h"
namespace kivo::playback::orchestration {
struct PlaybackTimelineRequest {
    PlaybackSessionId session_id{};
    kivo::playback::timeline::MediaTimestamp target_position{};
    kivo::playback::presentation::PresentationDeadline deadline{};
};
}
