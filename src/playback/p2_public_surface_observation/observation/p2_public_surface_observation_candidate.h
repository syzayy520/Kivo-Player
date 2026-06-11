#pragma once

#include "../identity/p2_public_surface_observation_identity.h"
#include "../anchor/p2_public_surface_observation_anchor_set.h"
#include "../classification/p2_public_surface_observation_classification.h"

namespace kivo::playback::p2_public_surface_observation {

struct P2PublicSurfaceObservationCandidate {
    P2PublicSurfaceObservationIdentity identity{};
    P2PublicSurfaceObservationAnchorSet anchors{};
    P2PublicSurfaceObservationClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_observation
