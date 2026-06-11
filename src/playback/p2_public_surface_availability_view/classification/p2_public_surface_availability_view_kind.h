#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_availability_view {

enum class P2PublicSurfaceAvailabilityViewKind : std::uint8_t {
    ConsistencyAvailable,
    SurfaceAvailable,
    ProofAvailable,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_availability_view
