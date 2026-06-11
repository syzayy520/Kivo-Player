#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_availability_view {

enum class P2PublicSurfaceAvailabilityViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_availability_view
