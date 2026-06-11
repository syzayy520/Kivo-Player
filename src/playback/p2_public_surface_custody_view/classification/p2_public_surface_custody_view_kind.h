#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_custody_view {

enum class P2PublicSurfaceCustodyViewKind : std::uint8_t {
    RetentionHeld,
    SurfaceHeld,
    ProofHeld,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_custody_view
