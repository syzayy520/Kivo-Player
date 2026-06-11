#pragma once

#include "../identity/p2_public_surface_snapshot_identity.h"
#include "p2_public_surface_snapshot_status.h"

namespace kivo::playback::p2_public_surface_snapshot {

struct P2PublicSurfaceSnapshotOutcome {
    P2PublicSurfaceSnapshotIdentity identity{};
    P2PublicSurfaceSnapshotStatus status{P2PublicSurfaceSnapshotStatus::Unknown};

    bool operator==(const P2PublicSurfaceSnapshotOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_snapshot
