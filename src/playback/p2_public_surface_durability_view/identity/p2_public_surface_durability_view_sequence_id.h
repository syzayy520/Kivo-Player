#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_view {

struct P2PublicSurfaceDurabilityViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceDurabilityViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_view
