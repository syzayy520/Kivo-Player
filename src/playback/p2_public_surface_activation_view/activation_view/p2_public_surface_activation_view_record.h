#pragma once

#include "p2_public_surface_activation_view_envelope.h"
#include "playback_p2_public_surface_activation_view.h"

namespace kivo::playback::p2_public_surface_activation_view {

struct P2PublicSurfaceActivationViewRecord {
    P2PublicSurfaceActivationViewEnvelope envelope{};
    PlaybackP2PublicSurfaceActivationView view{};
};

} // namespace kivo::playback::p2_public_surface_activation_view
