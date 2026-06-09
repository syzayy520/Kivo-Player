// src/core/session/playback_session.h - Synthetic media session placeholder.
// Depends on: core/id, standard library.
#pragma once
#include "../id/playback_id.h"
#include <string>

namespace kivo::playback {

struct PlaybackSession {
    SessionId id{};
    GenerationId generation{};
    bool active{false};
    std::string source{};

    PlaybackSession() = default;
};

} // namespace kivo::playback
