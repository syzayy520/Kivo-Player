#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_snapshot {

enum class P2PublicSurfaceSnapshotKind : std::uint8_t {
    ObservationSnapshot,
    SurfaceSnapshot,
    ProofSnapshot,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_snapshot
