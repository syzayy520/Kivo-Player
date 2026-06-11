#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_view {

struct P2PublicSurfaceDurabilityViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceDurabilityViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_view
