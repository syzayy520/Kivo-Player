#pragma once

#include "p2_public_surface_preservation_view_kind.h"
#include "p2_public_surface_preservation_view_scope.h"

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfacePreservationViewClassification {
    P2PublicSurfacePreservationViewKind kind{P2PublicSurfacePreservationViewKind::Unknown};
    P2PublicSurfacePreservationViewScope scope{P2PublicSurfacePreservationViewScope::Unknown};

    bool operator==(const P2PublicSurfacePreservationViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_preservation_view
