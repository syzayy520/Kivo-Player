#pragma once

#include "p2_public_surface_validation_view_envelope.h"
#include "playback_p2_public_surface_validation_view.h"

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewRecord {
    P2PublicSurfaceValidationViewEnvelope envelope{};
    PlaybackP2PublicSurfaceValidationView view{};
};

} // namespace kivo::playback::p2_public_surface_validation_view
