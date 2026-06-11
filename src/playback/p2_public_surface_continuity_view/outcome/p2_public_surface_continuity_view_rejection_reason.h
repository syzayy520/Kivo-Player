#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_continuity_view {

enum class P2PublicSurfaceContinuityViewRejectionReason : std::uint8_t {
    StabilityAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_continuity_view
