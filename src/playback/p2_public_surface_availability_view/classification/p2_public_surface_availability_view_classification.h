#pragma once

#include "p2_public_surface_availability_view_kind.h"
#include "p2_public_surface_availability_view_scope.h"

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceAvailabilityViewClassification {
    P2PublicSurfaceAvailabilityViewKind kind{P2PublicSurfaceAvailabilityViewKind::Unknown};
    P2PublicSurfaceAvailabilityViewScope scope{P2PublicSurfaceAvailabilityViewScope::Unknown};

    bool operator==(const P2PublicSurfaceAvailabilityViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_availability_view
