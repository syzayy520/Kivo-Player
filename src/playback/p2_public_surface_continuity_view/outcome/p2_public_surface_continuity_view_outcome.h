#pragma once

#include "../identity/p2_public_surface_continuity_view_identity.h"
#include "p2_public_surface_continuity_view_status.h"

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceContinuityViewOutcome {
    P2PublicSurfaceContinuityViewIdentity identity{};
    P2PublicSurfaceContinuityViewStatus status{P2PublicSurfaceContinuityViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceContinuityViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_continuity_view
