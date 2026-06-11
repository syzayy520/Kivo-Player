#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_view {

enum class P2PublicSurfaceStabilityViewRejectionReason : std::uint8_t {
    CoherenceAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_view
