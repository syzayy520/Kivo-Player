#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_chain_closure_audit {

enum class P2PublicSurfaceChainClosureAuditRejectionReason : std::uint8_t {
    DeltaAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
