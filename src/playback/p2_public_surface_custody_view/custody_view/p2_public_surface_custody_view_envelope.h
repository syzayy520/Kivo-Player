#pragma once

#include "../identity/p2_public_surface_custody_view_identity.h"
#include "../anchor/p2_public_surface_custody_view_anchor_set.h"
#include "../classification/p2_public_surface_custody_view_classification.h"

namespace kivo::playback::p2_public_surface_custody_view {

struct P2PublicSurfaceCustodyViewEnvelope {
    P2PublicSurfaceCustodyViewIdentity identity{};
    P2PublicSurfaceCustodyViewAnchorSet anchors{};
    P2PublicSurfaceCustodyViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_custody_view
