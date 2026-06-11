#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_coherence_view {

enum class P2PublicSurfaceCoherenceViewKind : std::uint8_t {
    IntegrityCoherent,
    SurfaceCoherent,
    ProofCoherent,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_coherence_view
