#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

enum class TimelinePublicSurfaceBoundaryStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::timeline_public_surface_boundary
