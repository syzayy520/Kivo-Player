#pragma once

#include "../identity/p2_public_surface_integrity_view_identity.h"
#include "../anchor/p2_public_surface_integrity_view_anchor_set.h"
#include "../classification/p2_public_surface_integrity_view_classification.h"

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceIntegrityViewEnvelope {
    P2PublicSurfaceIntegrityViewIdentity identity{};
    P2PublicSurfaceIntegrityViewAnchorSet anchors{};
    P2PublicSurfaceIntegrityViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_integrity_view
