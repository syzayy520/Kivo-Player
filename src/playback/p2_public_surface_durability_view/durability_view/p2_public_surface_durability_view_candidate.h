#pragma once

#include "../identity/p2_public_surface_durability_view_identity.h"
#include "../anchor/p2_public_surface_durability_view_anchor_set.h"
#include "../classification/p2_public_surface_durability_view_classification.h"

namespace kivo::playback::p2_public_surface_durability_view {

struct P2PublicSurfaceDurabilityViewCandidate {
    P2PublicSurfaceDurabilityViewIdentity identity{};
    P2PublicSurfaceDurabilityViewAnchorSet anchors{};
    P2PublicSurfaceDurabilityViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_durability_view
