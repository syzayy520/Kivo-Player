#pragma once

#include "media_open_public_envelope.h"
#include "playback_media_open_public.h"

namespace kivo::playback::media_open_public {

struct MediaOpenPublicRecord {
    MediaOpenPublicEnvelope envelope{};
    PlaybackMediaOpenPublic open{};
};

} // namespace kivo::playback::media_open_public
