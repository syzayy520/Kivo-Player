#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_audit {

enum class P2PublicSurfaceActivationAuditRejectionReason : std::uint8_t {
    ActivationAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_activation_audit
