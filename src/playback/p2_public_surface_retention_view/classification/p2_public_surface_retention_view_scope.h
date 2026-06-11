#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_view {

enum class P2PublicSurfaceRetentionViewScope : std::uint8_t {
    PublicSurface,
    PersistenceBoundary,
    RetentionBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_view
