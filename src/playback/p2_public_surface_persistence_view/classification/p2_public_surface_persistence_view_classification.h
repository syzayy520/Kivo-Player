#pragma once

#include "p2_public_surface_persistence_view_kind.h"
#include "p2_public_surface_persistence_view_scope.h"

namespace kivo::playback::p2_public_surface_persistence_view {

struct P2PublicSurfacePersistenceViewClassification {
    P2PublicSurfacePersistenceViewKind kind{P2PublicSurfacePersistenceViewKind::Unknown};
    P2PublicSurfacePersistenceViewScope scope{P2PublicSurfacePersistenceViewScope::Unknown};

    bool operator==(const P2PublicSurfacePersistenceViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_persistence_view
