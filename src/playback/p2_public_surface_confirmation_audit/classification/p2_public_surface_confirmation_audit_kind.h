#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_audit {

enum class P2PublicSurfaceConfirmationAuditKind : std::uint8_t {
    ConfirmationClosed,
    SurfaceConfirmed,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
