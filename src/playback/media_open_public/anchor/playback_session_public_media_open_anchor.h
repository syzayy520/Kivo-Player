#pragma once

#include "playback/session_public/identity/playback_session_public_identity.h"

namespace kivo::playback::media_open_public {

struct PlaybackSessionPublicMediaOpenAnchor {
    kivo::playback::session_public::PlaybackSessionPublicIdentity session_identity{};
};

} // namespace kivo::playback::media_open_public
