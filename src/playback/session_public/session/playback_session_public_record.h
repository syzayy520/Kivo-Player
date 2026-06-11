#pragma once

#include "playback_session_public_envelope.h"
#include "playback_session_public.h"

namespace kivo::playback::session_public {

struct PlaybackSessionPublicRecord {
    PlaybackSessionPublicEnvelope envelope{};
    PlaybackSessionPublic session{};
};

} // namespace kivo::playback::session_public
