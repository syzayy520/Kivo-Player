#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_preservation_view {

enum class P2PublicSurfacePreservationViewDeferReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_preservation_view
