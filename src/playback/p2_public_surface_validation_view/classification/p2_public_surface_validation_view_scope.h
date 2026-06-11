#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

enum class P2PublicSurfaceValidationViewScope : std::uint8_t {
    PublicSurface,
    ConfirmationBoundary,
    ValidationBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_validation_view
