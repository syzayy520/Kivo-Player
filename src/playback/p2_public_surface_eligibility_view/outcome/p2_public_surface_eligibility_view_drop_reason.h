#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_eligibility_view {

enum class P2PublicSurfaceEligibilityViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
