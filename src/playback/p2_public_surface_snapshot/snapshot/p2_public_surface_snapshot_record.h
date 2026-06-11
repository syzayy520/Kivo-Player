#pragma once

#include "p2_public_surface_snapshot_envelope.h"
#include "playback_p2_public_surface_snapshot.h"

namespace kivo::playback::p2_public_surface_snapshot {

struct P2PublicSurfaceSnapshotRecord {
    P2PublicSurfaceSnapshotEnvelope envelope{};
    PlaybackP2PublicSurfaceSnapshot snapshot{};
};

} // namespace kivo::playback::p2_public_surface_snapshot
