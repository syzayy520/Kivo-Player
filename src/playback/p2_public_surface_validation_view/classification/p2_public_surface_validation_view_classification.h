#pragma once

#include "p2_public_surface_validation_view_kind.h"
#include "p2_public_surface_validation_view_scope.h"

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewClassification {
    P2PublicSurfaceValidationViewKind kind{P2PublicSurfaceValidationViewKind::Unknown};
    P2PublicSurfaceValidationViewScope scope{P2PublicSurfaceValidationViewScope::Unknown};

    bool operator==(const P2PublicSurfaceValidationViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_validation_view
