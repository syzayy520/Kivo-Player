#pragma once

#include "../identity/p2_public_surface_eligibility_view_identity.h"
#include "p2_public_surface_eligibility_view_status.h"

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceEligibilityViewOutcome {
    P2PublicSurfaceEligibilityViewIdentity identity{};
    P2PublicSurfaceEligibilityViewStatus status{P2PublicSurfaceEligibilityViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceEligibilityViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
