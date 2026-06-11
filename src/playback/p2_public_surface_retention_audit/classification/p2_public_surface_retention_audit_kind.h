#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_audit {

enum class P2PublicSurfaceRetentionAuditKind : std::uint8_t {
    RetentionClosed,
    SurfaceRetained,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_audit
