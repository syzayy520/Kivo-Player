#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_view {

enum class P2PublicSurfaceConfirmationViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
