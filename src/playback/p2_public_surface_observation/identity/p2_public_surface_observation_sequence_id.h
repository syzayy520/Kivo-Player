#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_observation {

struct P2PublicSurfaceObservationSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceObservationSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_observation
