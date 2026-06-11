#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_custody_view {

enum class P2PublicSurfaceCustodyViewDeferReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_custody_view
