#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_preservation_view {

enum class P2PublicSurfacePreservationViewScope : std::uint8_t {
    PublicSurface,
    CustodyBoundary,
    PreservationBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_preservation_view
