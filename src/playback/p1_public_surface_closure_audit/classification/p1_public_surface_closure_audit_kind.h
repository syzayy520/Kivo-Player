#pragma once

#include <cstdint>

namespace kivo::playback::p1_public_surface_closure_audit {

enum class P1PublicSurfaceClosureAuditKind : std::uint8_t {
    ChainClosed,
    SurfaceClosed,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p1_public_surface_closure_audit
