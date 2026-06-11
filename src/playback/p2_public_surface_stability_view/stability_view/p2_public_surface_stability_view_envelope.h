#pragma once

#include "../identity/p2_public_surface_stability_view_identity.h"
#include "../anchor/p2_public_surface_stability_view_anchor_set.h"
#include "../classification/p2_public_surface_stability_view_classification.h"

namespace kivo::playback::p2_public_surface_stability_view {

struct P2PublicSurfaceStabilityViewEnvelope {
    P2PublicSurfaceStabilityViewIdentity identity{};
    P2PublicSurfaceStabilityViewAnchorSet anchors{};
    P2PublicSurfaceStabilityViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_stability_view
