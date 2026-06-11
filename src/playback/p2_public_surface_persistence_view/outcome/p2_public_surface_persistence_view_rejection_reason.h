#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_persistence_view {

enum class P2PublicSurfacePersistenceViewRejectionReason : std::uint8_t {
    DurabilityAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_persistence_view
