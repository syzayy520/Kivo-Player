#pragma once

#include "../identity/p2_public_surface_state_view_identity.h"
#include "../anchor/p2_public_surface_state_view_anchor_set.h"
#include "../classification/p2_public_surface_state_view_classification.h"

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceStateViewEnvelope {
    P2PublicSurfaceStateViewIdentity identity{};
    P2PublicSurfaceStateViewAnchorSet anchors{};
    P2PublicSurfaceStateViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_state_view
