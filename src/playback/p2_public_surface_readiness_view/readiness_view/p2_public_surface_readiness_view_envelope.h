#pragma once

#include "../identity/p2_public_surface_readiness_view_identity.h"
#include "../anchor/p2_public_surface_readiness_view_anchor_set.h"
#include "../classification/p2_public_surface_readiness_view_classification.h"

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewEnvelope {
    P2PublicSurfaceReadinessViewIdentity identity{};
    P2PublicSurfaceReadinessViewAnchorSet anchors{};
    P2PublicSurfaceReadinessViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_readiness_view
