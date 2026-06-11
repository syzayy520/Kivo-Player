#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_view {

enum class P2PublicSurfaceConfirmationViewScope : std::uint8_t {
    PublicSurface,
    CommitmentBoundary,
    ConfirmationBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
