#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_eligibility_view {

enum class P2PublicSurfaceEligibilityViewRejectionReason : std::uint8_t {
    ReadinessAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
