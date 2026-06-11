#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_preservation_view {

enum class P2PublicSurfacePreservationViewKind : std::uint8_t {
    CustodyPreserved,
    SurfacePreserved,
    ProofPreserved,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_preservation_view
