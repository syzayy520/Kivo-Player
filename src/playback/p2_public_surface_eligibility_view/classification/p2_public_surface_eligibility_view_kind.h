#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_eligibility_view {

enum class P2PublicSurfaceEligibilityViewKind : std::uint8_t {
    ReadinessEligible,
    SurfaceEligible,
    ProofEligible,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
