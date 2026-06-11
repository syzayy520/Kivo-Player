#pragma once

#include "../identity/p2_public_surface_custody_view_identity.h"
#include "p2_public_surface_custody_view_status.h"

namespace kivo::playback::p2_public_surface_custody_view {

struct P2PublicSurfaceCustodyViewOutcome {
    P2PublicSurfaceCustodyViewIdentity identity{};
    P2PublicSurfaceCustodyViewStatus status{P2PublicSurfaceCustodyViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceCustodyViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_custody_view
