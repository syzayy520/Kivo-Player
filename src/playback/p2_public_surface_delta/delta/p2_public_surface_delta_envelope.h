#pragma once

#include "../identity/p2_public_surface_delta_identity.h"
#include "../anchor/p2_public_surface_delta_anchor_set.h"
#include "../classification/p2_public_surface_delta_classification.h"

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceDeltaEnvelope {
    P2PublicSurfaceDeltaIdentity identity{};
    P2PublicSurfaceDeltaAnchorSet anchors{};
    P2PublicSurfaceDeltaClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_delta
