#pragma once

#include "../identity/p2_public_surface_validation_view_identity.h"
#include "p2_public_surface_validation_view_status.h"

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewOutcome {
    P2PublicSurfaceValidationViewIdentity identity{};
    P2PublicSurfaceValidationViewStatus status{P2PublicSurfaceValidationViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceValidationViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_validation_view
