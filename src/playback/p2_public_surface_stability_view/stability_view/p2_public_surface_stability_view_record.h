#pragma once

#include "p2_public_surface_stability_view_envelope.h"
#include "playback_p2_public_surface_stability_view.h"

namespace kivo::playback::p2_public_surface_stability_view {

struct P2PublicSurfaceStabilityViewRecord {
    P2PublicSurfaceStabilityViewEnvelope envelope{};
    PlaybackP2PublicSurfaceStabilityView view{};
};

} // namespace kivo::playback::p2_public_surface_stability_view
