#pragma once

#include "p2_public_surface_confirmation_view_envelope.h"
#include "playback_p2_public_surface_confirmation_view.h"

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewRecord {
    P2PublicSurfaceConfirmationViewEnvelope envelope{};
    PlaybackP2PublicSurfaceConfirmationView view{};
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
