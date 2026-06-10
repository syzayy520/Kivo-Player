#pragma once
#include "playback_intent_id.h"
#include "playback_intent_kind.h"
#include "../session/playback_session_id.h"
namespace kivo::playback::orchestration {
struct PlaybackIntent {
    PlaybackIntentId intent_id{};
    PlaybackIntentKind kind{PlaybackIntentKind::Unknown};
    PlaybackSessionId session_id{};
};
}
