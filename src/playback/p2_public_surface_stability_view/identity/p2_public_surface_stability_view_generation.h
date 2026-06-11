#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_view {

struct P2PublicSurfaceStabilityViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceStabilityViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_view
