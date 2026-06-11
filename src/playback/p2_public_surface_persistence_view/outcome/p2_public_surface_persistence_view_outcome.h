#pragma once

#include "../identity/p2_public_surface_persistence_view_identity.h"
#include "p2_public_surface_persistence_view_status.h"

namespace kivo::playback::p2_public_surface_persistence_view {

struct P2PublicSurfacePersistenceViewOutcome {
    P2PublicSurfacePersistenceViewIdentity identity{};
    P2PublicSurfacePersistenceViewStatus status{P2PublicSurfacePersistenceViewStatus::Unknown};

    bool operator==(const P2PublicSurfacePersistenceViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_persistence_view
