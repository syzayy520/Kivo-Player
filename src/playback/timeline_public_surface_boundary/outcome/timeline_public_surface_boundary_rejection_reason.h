#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

enum class TimelinePublicSurfaceBoundaryRejectionReason : std::uint8_t {
    ResponseAnchorMissing,
    ClassificationInvalid,
    BoundaryIdentityMissing,
    Unknown
};

} // namespace kivo::playback::timeline_public_surface_boundary
