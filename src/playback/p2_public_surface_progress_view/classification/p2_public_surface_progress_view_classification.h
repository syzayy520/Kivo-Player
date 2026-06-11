#pragma once

#include "p2_public_surface_progress_view_kind.h"
#include "p2_public_surface_progress_view_scope.h"

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceProgressViewClassification {
    P2PublicSurfaceProgressViewKind kind{P2PublicSurfaceProgressViewKind::Unknown};
    P2PublicSurfaceProgressViewScope scope{P2PublicSurfaceProgressViewScope::Unknown};

    bool operator==(const P2PublicSurfaceProgressViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_progress_view
