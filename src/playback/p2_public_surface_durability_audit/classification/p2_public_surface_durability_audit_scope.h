#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_audit {

enum class P2PublicSurfaceDurabilityAuditScope : std::uint8_t {
    PublicSurface,
    DurabilityBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_audit
