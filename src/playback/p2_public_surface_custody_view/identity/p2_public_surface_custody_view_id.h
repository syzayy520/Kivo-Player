#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_custody_view {

struct P2PublicSurfaceCustodyViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceCustodyViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_custody_view
