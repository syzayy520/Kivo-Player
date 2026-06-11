#pragma once

#include "../identity/p2_public_surface_availability_view_identity.h"
#include "p2_public_surface_availability_view_status.h"

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceAvailabilityViewOutcome {
    P2PublicSurfaceAvailabilityViewIdentity identity{};
    P2PublicSurfaceAvailabilityViewStatus status{P2PublicSurfaceAvailabilityViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceAvailabilityViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_availability_view
