#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_audit {

enum class P2PublicSurfaceIntegrityAuditRejectionReason : std::uint8_t {
    IntegrityAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
