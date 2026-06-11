#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_continuity_view {

enum class P2PublicSurfaceContinuityViewKind : std::uint8_t {
    StabilityContinuous,
    SurfaceContinuous,
    ProofContinuous,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_continuity_view
