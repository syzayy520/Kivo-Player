#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_chain_audit {

enum class P2PublicChainAuditKind : std::uint8_t {
    CompletionClosed,
    ChainClosed,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_chain_audit
