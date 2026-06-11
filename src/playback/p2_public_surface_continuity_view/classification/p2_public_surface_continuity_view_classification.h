#pragma once

#include "p2_public_surface_continuity_view_kind.h"
#include "p2_public_surface_continuity_view_scope.h"

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceContinuityViewClassification {
    P2PublicSurfaceContinuityViewKind kind{P2PublicSurfaceContinuityViewKind::Unknown};
    P2PublicSurfaceContinuityViewScope scope{P2PublicSurfaceContinuityViewScope::Unknown};

    bool operator==(const P2PublicSurfaceContinuityViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_continuity_view
