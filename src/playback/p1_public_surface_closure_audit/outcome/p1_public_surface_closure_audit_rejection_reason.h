#pragma once

#include <cstdint>

namespace kivo::playback::p1_public_surface_closure_audit {

enum class P1PublicSurfaceClosureAuditRejectionReason : std::uint8_t {
    RecoveryAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p1_public_surface_closure_audit
