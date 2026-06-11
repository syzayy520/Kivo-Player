#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_surface_boundary {

enum class TimelinePublicSurfaceBoundaryKind : std::uint8_t {
    Query,
    Response,
    Surface,
    Unknown
};

} // namespace kivo::playback::timeline_public_surface_boundary
