#pragma once

#include "p2_public_surface_continuity_view_envelope.h"
#include "playback_p2_public_surface_continuity_view.h"

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceContinuityViewRecord {
    P2PublicSurfaceContinuityViewEnvelope envelope{};
    PlaybackP2PublicSurfaceContinuityView view{};
};

} // namespace kivo::playback::p2_public_surface_continuity_view
