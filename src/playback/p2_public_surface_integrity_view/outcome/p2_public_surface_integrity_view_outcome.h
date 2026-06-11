#pragma once

#include "../identity/p2_public_surface_integrity_view_identity.h"
#include "p2_public_surface_integrity_view_status.h"

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceIntegrityViewOutcome {
    P2PublicSurfaceIntegrityViewIdentity identity{};
    P2PublicSurfaceIntegrityViewStatus status{P2PublicSurfaceIntegrityViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceIntegrityViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_view
