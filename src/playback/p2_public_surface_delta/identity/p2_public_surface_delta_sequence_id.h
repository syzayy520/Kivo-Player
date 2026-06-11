#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceDeltaSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceDeltaSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_delta
