#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_view {

enum class P2PublicSurfaceIntegrityViewScope : std::uint8_t {
    PublicSurface,
    ValidationBoundary,
    IntegrityBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_view
