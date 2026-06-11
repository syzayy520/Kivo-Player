#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_observation {

enum class P2PublicSurfaceObservationScope : std::uint8_t {
    PublicSurface,
    ChainBoundary,
    ObservationBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_observation
