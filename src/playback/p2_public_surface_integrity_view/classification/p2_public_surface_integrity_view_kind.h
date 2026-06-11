#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_view {

enum class P2PublicSurfaceIntegrityViewKind : std::uint8_t {
    ValidationIntact,
    SurfaceIntact,
    ProofIntact,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_view
