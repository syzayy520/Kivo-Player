#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_view {

enum class P2PublicSurfaceDurabilityViewRejectionReason : std::uint8_t {
    ContinuityAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_view
