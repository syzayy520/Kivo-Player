#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_continuity_view {

enum class P2PublicSurfaceContinuityViewScope : std::uint8_t {
    PublicSurface,
    StabilityBoundary,
    ContinuityBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_continuity_view
