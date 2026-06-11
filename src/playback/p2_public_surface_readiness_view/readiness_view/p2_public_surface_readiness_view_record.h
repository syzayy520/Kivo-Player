#pragma once

#include "p2_public_surface_readiness_view_envelope.h"
#include "playback_p2_public_surface_readiness_view.h"

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewRecord {
    P2PublicSurfaceReadinessViewEnvelope envelope{};
    PlaybackP2PublicSurfaceReadinessView view{};
};

} // namespace kivo::playback::p2_public_surface_readiness_view
