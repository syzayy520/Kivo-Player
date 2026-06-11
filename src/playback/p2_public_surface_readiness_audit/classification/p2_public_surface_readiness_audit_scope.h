#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_audit {

enum class P2PublicSurfaceReadinessAuditScope : std::uint8_t {
    PublicSurface,
    ReadinessBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
