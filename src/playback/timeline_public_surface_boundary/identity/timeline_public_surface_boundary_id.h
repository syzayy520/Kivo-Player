#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundaryId {
    std::uint64_t value{0};

    bool operator==(const TimelinePublicSurfaceBoundaryId& other) const = default;
};

} // namespace kivo::playback::timeline_public_surface_boundary
