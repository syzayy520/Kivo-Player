#pragma once

#include "p2_public_surface_stability_view_kind.h"
#include "p2_public_surface_stability_view_scope.h"

namespace kivo::playback::p2_public_surface_stability_view {

struct P2PublicSurfaceStabilityViewClassification {
    P2PublicSurfaceStabilityViewKind kind{P2PublicSurfaceStabilityViewKind::Unknown};
    P2PublicSurfaceStabilityViewScope scope{P2PublicSurfaceStabilityViewScope::Unknown};

    bool operator==(const P2PublicSurfaceStabilityViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_view
