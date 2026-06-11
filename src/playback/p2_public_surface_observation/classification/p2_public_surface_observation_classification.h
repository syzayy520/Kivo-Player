#pragma once

#include "p2_public_surface_observation_kind.h"
#include "p2_public_surface_observation_scope.h"

namespace kivo::playback::p2_public_surface_observation {

struct P2PublicSurfaceObservationClassification {
    P2PublicSurfaceObservationKind kind{P2PublicSurfaceObservationKind::Unknown};
    P2PublicSurfaceObservationScope scope{P2PublicSurfaceObservationScope::Unknown};

    bool operator==(const P2PublicSurfaceObservationClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_observation
