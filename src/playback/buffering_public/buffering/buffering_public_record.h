#pragma once

#include "buffering_public_envelope.h"
#include "playback_buffering_public.h"

namespace kivo::playback::buffering_public {

struct BufferingPublicRecord {
    BufferingPublicEnvelope envelope{};
    PlaybackBufferingPublic buffering{};
};

} // namespace kivo::playback::buffering_public
