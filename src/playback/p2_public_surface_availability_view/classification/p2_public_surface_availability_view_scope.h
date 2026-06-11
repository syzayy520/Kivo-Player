#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_availability_view {

enum class P2PublicSurfaceAvailabilityViewScope : std::uint8_t {
    PublicSurface,
    ConsistencyBoundary,
    AvailabilityBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_availability_view
