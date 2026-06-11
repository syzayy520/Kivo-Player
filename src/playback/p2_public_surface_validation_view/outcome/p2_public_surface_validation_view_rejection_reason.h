#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

enum class P2PublicSurfaceValidationViewRejectionReason : std::uint8_t {
    ConfirmationAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_validation_view
