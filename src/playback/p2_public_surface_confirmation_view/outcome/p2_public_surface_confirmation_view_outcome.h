#pragma once

#include "../identity/p2_public_surface_confirmation_view_identity.h"
#include "p2_public_surface_confirmation_view_status.h"

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewOutcome {
    P2PublicSurfaceConfirmationViewIdentity identity{};
    P2PublicSurfaceConfirmationViewStatus status{P2PublicSurfaceConfirmationViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceConfirmationViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
