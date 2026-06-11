#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_view {

enum class P2PublicSurfaceStabilityViewStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_view
