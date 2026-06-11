#pragma once

#include "p2_public_surface_readiness_view_kind.h"
#include "p2_public_surface_readiness_view_scope.h"

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewClassification {
    P2PublicSurfaceReadinessViewKind kind{P2PublicSurfaceReadinessViewKind::Unknown};
    P2PublicSurfaceReadinessViewScope scope{P2PublicSurfaceReadinessViewScope::Unknown};

    bool operator==(const P2PublicSurfaceReadinessViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_view
