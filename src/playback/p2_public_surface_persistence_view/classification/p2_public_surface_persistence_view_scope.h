#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_persistence_view {

enum class P2PublicSurfacePersistenceViewScope : std::uint8_t {
    PublicSurface,
    DurabilityBoundary,
    PersistenceBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_persistence_view
