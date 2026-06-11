#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_audit {

enum class P2PublicSurfaceReadinessAuditRejectionReason : std::uint8_t {
    ReadinessAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
