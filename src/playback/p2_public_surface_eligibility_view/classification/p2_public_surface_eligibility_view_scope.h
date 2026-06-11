#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_eligibility_view {

enum class P2PublicSurfaceEligibilityViewScope : std::uint8_t {
    PublicSurface,
    ReadinessBoundary,
    EligibilityBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
