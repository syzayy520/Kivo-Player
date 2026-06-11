#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_custody_view {

enum class P2PublicSurfaceCustodyViewRejectionReason : std::uint8_t {
    RetentionAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_custody_view
