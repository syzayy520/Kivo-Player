#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceValidationViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_validation_view
