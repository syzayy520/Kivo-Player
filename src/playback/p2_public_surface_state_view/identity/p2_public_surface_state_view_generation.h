#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceStateViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceStateViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_state_view
