#pragma once

#include "p2_public_surface_confirmation_view_kind.h"
#include "p2_public_surface_confirmation_view_scope.h"

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewClassification {
    P2PublicSurfaceConfirmationViewKind kind{P2PublicSurfaceConfirmationViewKind::Unknown};
    P2PublicSurfaceConfirmationViewScope scope{P2PublicSurfaceConfirmationViewScope::Unknown};

    bool operator==(const P2PublicSurfaceConfirmationViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
