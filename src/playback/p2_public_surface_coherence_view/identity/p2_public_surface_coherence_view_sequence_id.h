#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_coherence_view {

struct P2PublicSurfaceCoherenceViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceCoherenceViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_coherence_view
