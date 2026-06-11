#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_consistency_audit {

enum class P2PublicSurfaceConsistencyAuditKind : std::uint8_t {
    ProgressConsistent,
    SurfaceConsistent,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
