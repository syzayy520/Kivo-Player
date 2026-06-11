#pragma once

#include "p2_public_surface_activation_view_kind.h"
#include "p2_public_surface_activation_view_scope.h"

namespace kivo::playback::p2_public_surface_activation_view {

struct P2PublicSurfaceActivationViewClassification {
    P2PublicSurfaceActivationViewKind kind{P2PublicSurfaceActivationViewKind::Unknown};
    P2PublicSurfaceActivationViewScope scope{P2PublicSurfaceActivationViewScope::Unknown};

    bool operator==(const P2PublicSurfaceActivationViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_view
