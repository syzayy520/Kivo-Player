#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_preservation_view {

enum class P2PublicSurfacePreservationViewRejectionReason : std::uint8_t {
    CustodyAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_preservation_view
