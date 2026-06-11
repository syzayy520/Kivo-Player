#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_audit {

enum class P2PublicSurfaceActivationAuditKind : std::uint8_t {
    ActivationClosed,
    SurfaceActive,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_activation_audit
