#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_audit {

enum class P2PublicSurfaceStabilityAuditRejectionReason : std::uint8_t {
    StabilityAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_audit
