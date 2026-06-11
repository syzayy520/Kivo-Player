#pragma once

#include "playback_session_public_kind.h"
#include "playback_session_public_scope.h"

namespace kivo::playback::session_public {

struct PlaybackSessionPublicClassification {
    PlaybackSessionPublicKind kind{PlaybackSessionPublicKind::Unknown};
    PlaybackSessionPublicScope scope{PlaybackSessionPublicScope::Unknown};

    bool operator==(const PlaybackSessionPublicClassification& other) const = default;
};

} // namespace kivo::playback::session_public
