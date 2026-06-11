#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_coherence_view {

enum class P2PublicSurfaceCoherenceViewScope : std::uint8_t {
    PublicSurface,
    IntegrityBoundary,
    CoherenceBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_coherence_view
