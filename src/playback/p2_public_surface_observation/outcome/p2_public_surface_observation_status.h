#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_observation {

enum class P2PublicSurfaceObservationStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_observation
