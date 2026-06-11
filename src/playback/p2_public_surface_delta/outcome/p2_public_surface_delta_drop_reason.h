#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_delta {

enum class P2PublicSurfaceDeltaDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_delta
