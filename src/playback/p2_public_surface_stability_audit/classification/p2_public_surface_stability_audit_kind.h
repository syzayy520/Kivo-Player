#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_audit {

enum class P2PublicSurfaceStabilityAuditKind : std::uint8_t {
    StabilityClosed,
    SurfaceStable,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_audit
