#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_availability_view {

enum class P2PublicSurfaceAvailabilityViewRejectionReason : std::uint8_t {
    ConsistencyAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_availability_view
