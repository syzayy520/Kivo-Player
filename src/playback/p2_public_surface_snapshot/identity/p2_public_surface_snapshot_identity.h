#pragma once

#include "p2_public_surface_snapshot_id.h"
#include "p2_public_surface_snapshot_sequence_id.h"
#include "p2_public_surface_snapshot_generation.h"

namespace kivo::playback::p2_public_surface_snapshot {

struct P2PublicSurfaceSnapshotIdentity {
    P2PublicSurfaceSnapshotId snapshot_id{};
    P2PublicSurfaceSnapshotSequenceId sequence_id{};
    P2PublicSurfaceSnapshotGeneration generation{};

    bool operator==(const P2PublicSurfaceSnapshotIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_snapshot
