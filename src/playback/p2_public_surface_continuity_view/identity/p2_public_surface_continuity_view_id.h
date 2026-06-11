#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceContinuityViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceContinuityViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_continuity_view
