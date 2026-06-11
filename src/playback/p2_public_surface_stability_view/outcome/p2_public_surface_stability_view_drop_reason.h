#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_view {

enum class P2PublicSurfaceStabilityViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_view
