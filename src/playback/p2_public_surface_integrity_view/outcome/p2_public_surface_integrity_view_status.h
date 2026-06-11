#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_view {

enum class P2PublicSurfaceIntegrityViewStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_view
