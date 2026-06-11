#pragma once

#include "p2_public_surface_durability_view_kind.h"
#include "p2_public_surface_durability_view_scope.h"

namespace kivo::playback::p2_public_surface_durability_view {

struct P2PublicSurfaceDurabilityViewClassification {
    P2PublicSurfaceDurabilityViewKind kind{P2PublicSurfaceDurabilityViewKind::Unknown};
    P2PublicSurfaceDurabilityViewScope scope{P2PublicSurfaceDurabilityViewScope::Unknown};

    bool operator==(const P2PublicSurfaceDurabilityViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_view
