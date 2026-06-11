#pragma once

#include "../identity/p2_public_surface_delta_identity.h"
#include "p2_public_surface_delta_status.h"

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceDeltaOutcome {
    P2PublicSurfaceDeltaIdentity identity{};
    P2PublicSurfaceDeltaStatus status{P2PublicSurfaceDeltaStatus::Unknown};

    bool operator==(const P2PublicSurfaceDeltaOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_delta
