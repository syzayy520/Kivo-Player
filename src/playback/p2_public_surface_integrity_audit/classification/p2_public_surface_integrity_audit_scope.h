#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_audit {

enum class P2PublicSurfaceIntegrityAuditScope : std::uint8_t {
    PublicSurface,
    IntegrityBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
