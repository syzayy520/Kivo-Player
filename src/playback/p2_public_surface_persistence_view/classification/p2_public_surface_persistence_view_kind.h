#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_persistence_view {

enum class P2PublicSurfacePersistenceViewKind : std::uint8_t {
    DurabilityPersistent,
    SurfacePersistent,
    ProofPersistent,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_persistence_view
