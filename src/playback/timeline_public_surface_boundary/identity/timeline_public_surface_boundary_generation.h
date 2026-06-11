#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundaryGeneration {
    std::uint64_t value{0};

    bool operator==(const TimelinePublicSurfaceBoundaryGeneration& other) const = default;
};

} // namespace kivo::playback::timeline_public_surface_boundary
