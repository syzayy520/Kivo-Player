#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_view {

struct P2PublicSurfaceDurabilityViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceDurabilityViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_view
