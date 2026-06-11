#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_chain_audit {

enum class P2PublicChainAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_chain_audit
