#pragma once

#include "../identity/p2_public_surface_retention_view_identity.h"
#include "../anchor/p2_public_surface_retention_view_anchor_set.h"
#include "../classification/p2_public_surface_retention_view_classification.h"

namespace kivo::playback::p2_public_surface_retention_view {

struct PlaybackP2PublicSurfaceRetentionView {
    P2PublicSurfaceRetentionViewIdentity identity{};
    P2PublicSurfaceRetentionViewAnchorSet anchors{};
    P2PublicSurfaceRetentionViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_retention_view
