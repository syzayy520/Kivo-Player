#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_audit {

enum class P2PublicSurfaceRetentionAuditRejectionReason : std::uint8_t {
    RetentionAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_audit
