#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicChainAuditGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_chain_audit
