#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfacePreservationViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfacePreservationViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_preservation_view
