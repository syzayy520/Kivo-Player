#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

enum class P2PublicSurfaceReadinessViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_view
