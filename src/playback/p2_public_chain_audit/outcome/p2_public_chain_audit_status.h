#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_chain_audit {

enum class P2PublicChainAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_chain_audit
