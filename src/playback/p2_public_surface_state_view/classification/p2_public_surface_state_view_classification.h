#pragma once

#include "p2_public_surface_state_view_kind.h"
#include "p2_public_surface_state_view_scope.h"

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceStateViewClassification {
    P2PublicSurfaceStateViewKind kind{P2PublicSurfaceStateViewKind::Unknown};
    P2PublicSurfaceStateViewScope scope{P2PublicSurfaceStateViewScope::Unknown};

    bool operator==(const P2PublicSurfaceStateViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_state_view
