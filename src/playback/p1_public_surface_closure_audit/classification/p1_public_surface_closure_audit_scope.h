#pragma once

#include <cstdint>

namespace kivo::playback::p1_public_surface_closure_audit {

enum class P1PublicSurfaceClosureAuditScope : std::uint8_t {
    PublicSurface,
    P1Chain,
    Proof,
    Unknown
};

} // namespace kivo::playback::p1_public_surface_closure_audit
