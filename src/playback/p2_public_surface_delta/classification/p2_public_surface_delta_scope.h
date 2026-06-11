#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_delta {

enum class P2PublicSurfaceDeltaScope : std::uint8_t {
    PublicSurface,
    SnapshotBoundary,
    DeltaBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_delta
