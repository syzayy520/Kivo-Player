#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_view {

enum class P2PublicSurfaceConfirmationViewRejectionReason : std::uint8_t {
    CommitmentAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
