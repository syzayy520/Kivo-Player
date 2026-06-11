#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_continuity_view {

enum class P2PublicSurfaceContinuityViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_continuity_view
