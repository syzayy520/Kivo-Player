#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_audit {

enum class P2PublicSurfaceReadinessAuditKind : std::uint8_t {
    ReadinessClosed,
    SurfaceReady,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
