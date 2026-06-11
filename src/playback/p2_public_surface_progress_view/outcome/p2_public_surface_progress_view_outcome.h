#pragma once

#include "../identity/p2_public_surface_progress_view_identity.h"
#include "p2_public_surface_progress_view_status.h"

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceProgressViewOutcome {
    P2PublicSurfaceProgressViewIdentity identity{};
    P2PublicSurfaceProgressViewStatus status{P2PublicSurfaceProgressViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceProgressViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_progress_view
