#pragma once

#include "../identity/p2_public_surface_observation_identity.h"
#include "p2_public_surface_observation_status.h"

namespace kivo::playback::p2_public_surface_observation {

struct P2PublicSurfaceObservationOutcome {
    P2PublicSurfaceObservationIdentity identity{};
    P2PublicSurfaceObservationStatus status{P2PublicSurfaceObservationStatus::Unknown};

    bool operator==(const P2PublicSurfaceObservationOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_observation
