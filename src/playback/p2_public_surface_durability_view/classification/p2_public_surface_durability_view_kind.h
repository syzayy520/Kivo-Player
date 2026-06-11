#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_view {

enum class P2PublicSurfaceDurabilityViewKind : std::uint8_t {
    ContinuityDurable,
    SurfaceDurable,
    ProofDurable,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_view
