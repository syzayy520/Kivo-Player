#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_commitment_view {

enum class P2PublicSurfaceCommitmentViewRejectionReason : std::uint8_t {
    ActivationAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_commitment_view
