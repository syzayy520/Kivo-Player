#pragma once

#include "../identity/playback_session_public_identity.h"
#include "playback_session_public_status.h"

namespace kivo::playback::session_public {

struct PlaybackSessionPublicOutcome {
    PlaybackSessionPublicIdentity identity{};
    PlaybackSessionPublicStatus status{PlaybackSessionPublicStatus::Unknown};

    bool operator==(const PlaybackSessionPublicOutcome& other) const = default;
};

} // namespace kivo::playback::session_public
