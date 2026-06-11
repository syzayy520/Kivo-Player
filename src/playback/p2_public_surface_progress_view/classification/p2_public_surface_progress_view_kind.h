#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_progress_view {

enum class P2PublicSurfaceProgressViewKind : std::uint8_t {
    StateProgress,
    SurfaceProgress,
    ProofProgress,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_progress_view
