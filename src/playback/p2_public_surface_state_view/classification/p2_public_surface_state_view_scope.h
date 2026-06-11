#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_state_view {

enum class P2PublicSurfaceStateViewScope : std::uint8_t {
    PublicSurface,
    ClosureBoundary,
    StateViewBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_state_view
