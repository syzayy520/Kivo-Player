#pragma once

#include "../identity/p2_public_surface_validation_view_identity.h"
#include "../anchor/p2_public_surface_validation_view_anchor_set.h"
#include "../classification/p2_public_surface_validation_view_classification.h"

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewCandidate {
    P2PublicSurfaceValidationViewIdentity identity{};
    P2PublicSurfaceValidationViewAnchorSet anchors{};
    P2PublicSurfaceValidationViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_validation_view
