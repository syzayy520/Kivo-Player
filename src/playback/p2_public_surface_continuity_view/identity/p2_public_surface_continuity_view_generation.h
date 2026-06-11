#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceContinuityViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceContinuityViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_continuity_view
