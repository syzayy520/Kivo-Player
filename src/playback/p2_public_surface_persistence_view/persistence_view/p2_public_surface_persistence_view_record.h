#pragma once

#include "p2_public_surface_persistence_view_envelope.h"
#include "playback_p2_public_surface_persistence_view.h"

namespace kivo::playback::p2_public_surface_persistence_view {

struct P2PublicSurfacePersistenceViewRecord {
    P2PublicSurfacePersistenceViewEnvelope envelope{};
    PlaybackP2PublicSurfacePersistenceView view{};
};

} // namespace kivo::playback::p2_public_surface_persistence_view
