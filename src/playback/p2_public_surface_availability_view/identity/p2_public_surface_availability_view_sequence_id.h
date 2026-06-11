#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceAvailabilityViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceAvailabilityViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_availability_view
