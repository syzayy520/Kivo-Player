#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

enum class P2PublicSurfaceReadinessViewRejectionReason : std::uint8_t {
    AvailabilityAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_view
