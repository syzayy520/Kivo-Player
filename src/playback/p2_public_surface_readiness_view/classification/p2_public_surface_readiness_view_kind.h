#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

enum class P2PublicSurfaceReadinessViewKind : std::uint8_t {
    AvailabilityReady,
    SurfaceReady,
    ProofReady,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_view
