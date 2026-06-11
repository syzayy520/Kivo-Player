#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

enum class P2PublicSurfaceValidationViewStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_validation_view
