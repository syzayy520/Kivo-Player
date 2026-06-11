#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceReadinessViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_view
