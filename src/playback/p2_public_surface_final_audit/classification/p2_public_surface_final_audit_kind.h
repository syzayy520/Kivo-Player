#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_final_audit {

enum class P2PublicSurfaceFinalAuditKind : std::uint8_t {
    FinalClosed,
    SurfaceFinalized,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_final_audit
