#pragma once

#include "p2_public_surface_integrity_view_envelope.h"
#include "playback_p2_public_surface_integrity_view.h"

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceIntegrityViewRecord {
    P2PublicSurfaceIntegrityViewEnvelope envelope{};
    PlaybackP2PublicSurfaceIntegrityView view{};
};

} // namespace kivo::playback::p2_public_surface_integrity_view
