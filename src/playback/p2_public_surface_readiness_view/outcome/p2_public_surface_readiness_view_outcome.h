#pragma once

#include "../identity/p2_public_surface_readiness_view_identity.h"
#include "p2_public_surface_readiness_view_status.h"

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewOutcome {
    P2PublicSurfaceReadinessViewIdentity identity{};
    P2PublicSurfaceReadinessViewStatus status{P2PublicSurfaceReadinessViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceReadinessViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_view
