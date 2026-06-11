#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_final_audit {

enum class P2PublicSurfaceFinalAuditRejectionReason : std::uint8_t {
    SourceAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_final_audit
