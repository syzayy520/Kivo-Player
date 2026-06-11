#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_view {

enum class P2PublicSurfaceDurabilityViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_view
