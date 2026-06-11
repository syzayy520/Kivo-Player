#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_audit {

enum class P2PublicSurfaceDurabilityAuditKind : std::uint8_t {
    DurabilityClosed,
    SurfaceDurable,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_audit
