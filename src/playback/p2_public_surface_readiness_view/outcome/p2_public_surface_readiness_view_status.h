#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

enum class P2PublicSurfaceReadinessViewStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_view
