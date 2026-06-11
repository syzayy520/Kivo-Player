#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_view {

enum class P2PublicSurfaceActivationViewRejectionReason : std::uint8_t {
    EligibilityAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_activation_view
