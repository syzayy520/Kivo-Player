#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_view {

enum class P2PublicSurfaceStabilityViewKind : std::uint8_t {
    CoherenceStable,
    SurfaceStable,
    ProofStable,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_view
