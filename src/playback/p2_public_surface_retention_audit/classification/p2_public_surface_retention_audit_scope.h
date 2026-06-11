#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_audit {

enum class P2PublicSurfaceRetentionAuditScope : std::uint8_t {
    PublicSurface,
    RetentionBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_audit
