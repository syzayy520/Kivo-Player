#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_view {

enum class P2PublicSurfaceRetentionViewRejectionReason : std::uint8_t {
    PersistenceAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_view
