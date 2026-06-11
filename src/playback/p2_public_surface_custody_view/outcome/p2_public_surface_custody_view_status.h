#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_custody_view {

enum class P2PublicSurfaceCustodyViewStatus : std::uint8_t {
    Recorded,
    Rejected,
    Deferred,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_custody_view
