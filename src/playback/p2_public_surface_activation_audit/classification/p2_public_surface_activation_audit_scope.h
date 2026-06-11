#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_audit {

enum class P2PublicSurfaceActivationAuditScope : std::uint8_t {
    PublicSurface,
    ActivationBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_activation_audit
