#pragma once

#include "p2_public_surface_delta_envelope.h"
#include "playback_p2_public_surface_delta.h"

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceDeltaRecord {
    P2PublicSurfaceDeltaEnvelope envelope{};
    PlaybackP2PublicSurfaceDelta delta{};
};

} // namespace kivo::playback::p2_public_surface_delta
