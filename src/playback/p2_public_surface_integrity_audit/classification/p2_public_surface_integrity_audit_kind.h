#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_audit {

enum class P2PublicSurfaceIntegrityAuditKind : std::uint8_t {
    IntegrityClosed,
    SurfaceIntact,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
