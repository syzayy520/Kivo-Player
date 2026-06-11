#pragma once

#include "../identity/p2_public_surface_eligibility_view_identity.h"
#include "../anchor/p2_public_surface_eligibility_view_anchor_set.h"
#include "../classification/p2_public_surface_eligibility_view_classification.h"

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceEligibilityViewEnvelope {
    P2PublicSurfaceEligibilityViewIdentity identity{};
    P2PublicSurfaceEligibilityViewAnchorSet anchors{};
    P2PublicSurfaceEligibilityViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
