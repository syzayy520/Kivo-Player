#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_delta {

enum class P2PublicSurfaceDeltaStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_delta
