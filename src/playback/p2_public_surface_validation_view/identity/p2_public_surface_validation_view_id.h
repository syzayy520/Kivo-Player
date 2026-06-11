#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceValidationViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_validation_view
