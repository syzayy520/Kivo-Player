#pragma once

#include "p2_public_readback_envelope.h"
#include "playback_p2_public_readback.h"

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackRecord {
    P2PublicReadbackEnvelope envelope{};
    PlaybackP2PublicReadback readback{};
};

} // namespace kivo::playback::p2_public_readback
