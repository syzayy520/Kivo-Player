#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_audit {

enum class P2PublicSurfaceConfirmationAuditScope : std::uint8_t {
    PublicSurface,
    ConfirmationBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
