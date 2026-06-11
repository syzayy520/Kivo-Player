#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceValidationViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_validation_view
