#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_view {

enum class P2PublicSurfaceActivationViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_activation_view
