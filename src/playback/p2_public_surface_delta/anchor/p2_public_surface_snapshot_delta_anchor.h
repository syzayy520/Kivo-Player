#pragma once

#include "playback/p2_public_surface_snapshot/identity/p2_public_surface_snapshot_identity.h"

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceSnapshotDeltaAnchor {
    kivo::playback::p2_public_surface_snapshot::P2PublicSurfaceSnapshotIdentity snapshot_identity{};
};

} // namespace kivo::playback::p2_public_surface_delta
