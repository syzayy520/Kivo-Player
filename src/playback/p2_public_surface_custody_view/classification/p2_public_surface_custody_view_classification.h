#pragma once

#include "p2_public_surface_custody_view_kind.h"
#include "p2_public_surface_custody_view_scope.h"

namespace kivo::playback::p2_public_surface_custody_view {

struct P2PublicSurfaceCustodyViewClassification {
    P2PublicSurfaceCustodyViewKind kind{P2PublicSurfaceCustodyViewKind::Unknown};
    P2PublicSurfaceCustodyViewScope scope{P2PublicSurfaceCustodyViewScope::Unknown};

    bool operator==(const P2PublicSurfaceCustodyViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_custody_view
