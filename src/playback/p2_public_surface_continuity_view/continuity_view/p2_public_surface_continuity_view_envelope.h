#pragma once

#include "../identity/p2_public_surface_continuity_view_identity.h"
#include "../anchor/p2_public_surface_continuity_view_anchor_set.h"
#include "../classification/p2_public_surface_continuity_view_classification.h"

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceContinuityViewEnvelope {
    P2PublicSurfaceContinuityViewIdentity identity{};
    P2PublicSurfaceContinuityViewAnchorSet anchors{};
    P2PublicSurfaceContinuityViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_continuity_view
