#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceProgressViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceProgressViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_progress_view
