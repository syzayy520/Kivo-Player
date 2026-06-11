#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_view {

enum class P2PublicSurfaceIntegrityViewRejectionReason : std::uint8_t {
    ValidationAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_view
