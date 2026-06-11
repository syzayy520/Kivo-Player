#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfacePreservationViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfacePreservationViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_preservation_view
