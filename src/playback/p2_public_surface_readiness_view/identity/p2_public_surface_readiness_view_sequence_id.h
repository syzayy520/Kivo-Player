#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceReadinessViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_view
