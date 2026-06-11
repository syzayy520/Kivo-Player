#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_audit {

enum class P2PublicSurfaceConfirmationAuditRejectionReason : std::uint8_t {
    ConfirmationAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
