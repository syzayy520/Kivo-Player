#pragma once

#include "p2_public_surface_snapshot_kind.h"
#include "p2_public_surface_snapshot_scope.h"

namespace kivo::playback::p2_public_surface_snapshot {

struct P2PublicSurfaceSnapshotClassification {
    P2PublicSurfaceSnapshotKind kind{P2PublicSurfaceSnapshotKind::Unknown};
    P2PublicSurfaceSnapshotScope scope{P2PublicSurfaceSnapshotScope::Unknown};

    bool operator==(const P2PublicSurfaceSnapshotClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_snapshot
