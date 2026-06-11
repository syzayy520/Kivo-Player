#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_audit {

enum class P2PublicSurfaceDurabilityAuditRejectionReason : std::uint8_t {
    DurabilityAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_audit
