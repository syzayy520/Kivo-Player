#pragma once

#include "p2_public_surface_custody_view_envelope.h"
#include "playback_p2_public_surface_custody_view.h"

namespace kivo::playback::p2_public_surface_custody_view {

struct P2PublicSurfaceCustodyViewRecord {
    P2PublicSurfaceCustodyViewEnvelope envelope{};
    PlaybackP2PublicSurfaceCustodyView view{};
};

} // namespace kivo::playback::p2_public_surface_custody_view
