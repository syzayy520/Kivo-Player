#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceIntegrityViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceIntegrityViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_view
