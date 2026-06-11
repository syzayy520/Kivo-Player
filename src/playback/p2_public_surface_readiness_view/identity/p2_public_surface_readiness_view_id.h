#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceReadinessViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_view
