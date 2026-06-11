#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_consistency_audit {

enum class P2PublicSurfaceConsistencyAuditRejectionReason : std::uint8_t {
    ProgressViewAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
