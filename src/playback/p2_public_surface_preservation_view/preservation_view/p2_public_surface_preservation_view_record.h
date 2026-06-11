#pragma once

#include "p2_public_surface_preservation_view_envelope.h"
#include "playback_p2_public_surface_preservation_view.h"

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfacePreservationViewRecord {
    P2PublicSurfacePreservationViewEnvelope envelope{};
    PlaybackP2PublicSurfacePreservationView view{};
};

} // namespace kivo::playback::p2_public_surface_preservation_view
