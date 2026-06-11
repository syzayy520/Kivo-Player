#pragma once

#include "../identity/p2_public_surface_preservation_view_identity.h"
#include "p2_public_surface_preservation_view_status.h"

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfacePreservationViewOutcome {
    P2PublicSurfacePreservationViewIdentity identity{};
    P2PublicSurfacePreservationViewStatus status{P2PublicSurfacePreservationViewStatus::Unknown};

    bool operator==(const P2PublicSurfacePreservationViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_preservation_view
