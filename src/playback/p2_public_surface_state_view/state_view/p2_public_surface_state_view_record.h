#pragma once

#include "p2_public_surface_state_view_envelope.h"
#include "playback_p2_public_surface_state_view.h"

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceStateViewRecord {
    P2PublicSurfaceStateViewEnvelope envelope{};
    PlaybackP2PublicSurfaceStateView view{};
};

} // namespace kivo::playback::p2_public_surface_state_view
