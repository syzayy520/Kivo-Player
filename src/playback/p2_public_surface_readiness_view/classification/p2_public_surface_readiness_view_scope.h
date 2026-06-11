#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

enum class P2PublicSurfaceReadinessViewScope : std::uint8_t {
    PublicSurface,
    AvailabilityBoundary,
    ReadinessBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_view
