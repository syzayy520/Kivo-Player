#pragma once

#include "playback/p2_public_surface_observation/identity/p2_public_surface_observation_identity.h"

namespace kivo::playback::p2_public_surface_snapshot {

struct P2PublicSurfaceObservationSnapshotAnchor {
    kivo::playback::p2_public_surface_observation::P2PublicSurfaceObservationIdentity observation_identity{};
};

} // namespace kivo::playback::p2_public_surface_snapshot
