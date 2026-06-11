#pragma once

#include "../identity/p2_public_surface_activation_view_identity.h"
#include "p2_public_surface_activation_view_status.h"

namespace kivo::playback::p2_public_surface_activation_view {

struct P2PublicSurfaceActivationViewOutcome {
    P2PublicSurfaceActivationViewIdentity identity{};
    P2PublicSurfaceActivationViewStatus status{P2PublicSurfaceActivationViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceActivationViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_view
