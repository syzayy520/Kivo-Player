#pragma once

#include "../identity/p2_public_surface_stability_view_identity.h"
#include "p2_public_surface_stability_view_status.h"

namespace kivo::playback::p2_public_surface_stability_view {

struct P2PublicSurfaceStabilityViewOutcome {
    P2PublicSurfaceStabilityViewIdentity identity{};
    P2PublicSurfaceStabilityViewStatus status{P2PublicSurfaceStabilityViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceStabilityViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_view
