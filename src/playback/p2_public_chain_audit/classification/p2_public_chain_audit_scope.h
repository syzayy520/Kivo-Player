#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_chain_audit {

enum class P2PublicChainAuditScope : std::uint8_t {
    PublicSurface,
    CompletionBoundary,
    P2Chain,
    Unknown
};

} // namespace kivo::playback::p2_public_chain_audit
