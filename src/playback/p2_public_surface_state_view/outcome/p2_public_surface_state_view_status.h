#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_state_view {

enum class P2PublicSurfaceStateViewStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_state_view
