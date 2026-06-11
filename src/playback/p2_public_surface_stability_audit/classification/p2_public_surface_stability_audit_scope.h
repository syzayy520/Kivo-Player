#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_audit {

enum class P2PublicSurfaceStabilityAuditScope : std::uint8_t {
    PublicSurface,
    StabilityBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_audit
