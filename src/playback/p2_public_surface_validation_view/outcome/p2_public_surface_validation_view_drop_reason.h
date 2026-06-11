#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

enum class P2PublicSurfaceValidationViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_validation_view
