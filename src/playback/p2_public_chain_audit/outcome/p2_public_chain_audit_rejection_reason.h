#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_chain_audit {

enum class P2PublicChainAuditRejectionReason : std::uint8_t {
    CompletionAnchorMissing,
    ClassificationInvalid,
    AuditIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_chain_audit
