#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundarySequenceId {
    std::uint64_t value{0};

    bool operator==(const TimelinePublicSurfaceBoundarySequenceId& other) const = default;
};

} // namespace kivo::playback::timeline_public_surface_boundary
