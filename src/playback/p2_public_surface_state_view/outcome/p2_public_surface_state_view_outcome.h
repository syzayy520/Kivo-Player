#pragma once

#include "../identity/p2_public_surface_state_view_identity.h"
#include "p2_public_surface_state_view_status.h"

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceStateViewOutcome {
    P2PublicSurfaceStateViewIdentity identity{};
    P2PublicSurfaceStateViewStatus status{P2PublicSurfaceStateViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceStateViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_state_view
