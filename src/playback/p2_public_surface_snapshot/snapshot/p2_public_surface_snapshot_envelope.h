#pragma once

#include "../identity/p2_public_surface_snapshot_identity.h"
#include "../anchor/p2_public_surface_snapshot_anchor_set.h"
#include "../classification/p2_public_surface_snapshot_classification.h"

namespace kivo::playback::p2_public_surface_snapshot {

struct P2PublicSurfaceSnapshotEnvelope {
    P2PublicSurfaceSnapshotIdentity identity{};
    P2PublicSurfaceSnapshotAnchorSet anchors{};
    P2PublicSurfaceSnapshotClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_snapshot
