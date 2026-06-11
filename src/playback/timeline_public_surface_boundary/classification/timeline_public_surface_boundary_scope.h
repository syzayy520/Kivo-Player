#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

enum class TimelinePublicSurfaceBoundaryScope : std::uint8_t {
    PublicSafe,
    BoundaryOnly,
    TimelineOnly,
    Unknown
};

} // namespace kivo::playback::timeline_public_surface_boundary
