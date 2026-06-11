#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicChainAuditSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_chain_audit
