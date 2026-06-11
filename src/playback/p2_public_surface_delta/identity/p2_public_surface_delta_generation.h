#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceDeltaGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceDeltaGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_delta
