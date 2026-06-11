#pragma once

#include "../identity/p2_public_surface_persistence_view_identity.h"
#include "../anchor/p2_public_surface_persistence_view_anchor_set.h"
#include "../classification/p2_public_surface_persistence_view_classification.h"

namespace kivo::playback::p2_public_surface_persistence_view {

struct PlaybackP2PublicSurfacePersistenceView {
    P2PublicSurfacePersistenceViewIdentity identity{};
    P2PublicSurfacePersistenceViewAnchorSet anchors{};
    P2PublicSurfacePersistenceViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_persistence_view
