#pragma once

#include "p2_public_surface_progress_view_envelope.h"
#include "playback_p2_public_surface_progress_view.h"

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceProgressViewRecord {
    P2PublicSurfaceProgressViewEnvelope envelope{};
    PlaybackP2PublicSurfaceProgressView view{};
};

} // namespace kivo::playback::p2_public_surface_progress_view
