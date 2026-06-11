#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceStateViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceStateViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_state_view
