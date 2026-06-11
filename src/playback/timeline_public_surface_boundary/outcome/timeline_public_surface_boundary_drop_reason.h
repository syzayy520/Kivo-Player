#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

enum class TimelinePublicSurfaceBoundaryDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::timeline_public_surface_boundary
