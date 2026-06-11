#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_view {

enum class P2PublicSurfaceRetentionViewKind : std::uint8_t {
    PersistenceRetained,
    SurfaceRetained,
    ProofRetained,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_view
