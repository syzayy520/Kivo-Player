#pragma once

#include "../identity/p2_public_surface_preservation_view_identity.h"
#include "../anchor/p2_public_surface_preservation_view_anchor_set.h"
#include "../classification/p2_public_surface_preservation_view_classification.h"

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfacePreservationViewCandidate {
    P2PublicSurfacePreservationViewIdentity identity{};
    P2PublicSurfacePreservationViewAnchorSet anchors{};
    P2PublicSurfacePreservationViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_preservation_view
