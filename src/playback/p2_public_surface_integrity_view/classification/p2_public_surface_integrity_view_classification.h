#pragma once

#include "p2_public_surface_integrity_view_kind.h"
#include "p2_public_surface_integrity_view_scope.h"

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceIntegrityViewClassification {
    P2PublicSurfaceIntegrityViewKind kind{P2PublicSurfaceIntegrityViewKind::Unknown};
    P2PublicSurfaceIntegrityViewScope scope{P2PublicSurfaceIntegrityViewScope::Unknown};

    bool operator==(const P2PublicSurfaceIntegrityViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_view
