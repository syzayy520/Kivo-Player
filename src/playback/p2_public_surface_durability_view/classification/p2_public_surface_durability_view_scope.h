#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_view {

enum class P2PublicSurfaceDurabilityViewScope : std::uint8_t {
    PublicSurface,
    ContinuityBoundary,
    DurabilityBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_view
