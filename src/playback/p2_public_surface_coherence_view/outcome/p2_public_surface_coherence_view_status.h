#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_coherence_view {

enum class P2PublicSurfaceCoherenceViewStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_coherence_view
