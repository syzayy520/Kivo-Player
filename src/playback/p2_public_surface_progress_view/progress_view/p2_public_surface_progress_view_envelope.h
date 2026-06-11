#pragma once

#include "../identity/p2_public_surface_progress_view_identity.h"
#include "../anchor/p2_public_surface_progress_view_anchor_set.h"
#include "../classification/p2_public_surface_progress_view_classification.h"

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceProgressViewEnvelope {
    P2PublicSurfaceProgressViewIdentity identity{};
    P2PublicSurfaceProgressViewAnchorSet anchors{};
    P2PublicSurfaceProgressViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_progress_view
