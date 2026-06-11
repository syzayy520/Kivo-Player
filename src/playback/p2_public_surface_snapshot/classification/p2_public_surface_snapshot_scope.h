#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_snapshot {

enum class P2PublicSurfaceSnapshotScope : std::uint8_t {
    PublicSurface,
    ObservationBoundary,
    SnapshotBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_snapshot
