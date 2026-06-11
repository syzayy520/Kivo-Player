#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_state_view {

enum class P2PublicSurfaceStateViewKind : std::uint8_t {
    ClosureState,
    SurfaceState,
    ProofState,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_state_view
