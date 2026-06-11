#pragma once

#include "playback/p2_public_surface_persistence_view/identity/p2_public_surface_persistence_view_identity.h"

namespace kivo::playback::p2_public_surface_retention_view {

struct P2PublicSurfacePersistenceRetentionViewAnchor {
    kivo::playback::p2_public_surface_persistence_view::P2PublicSurfacePersistenceViewIdentity persistence_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_retention_view
