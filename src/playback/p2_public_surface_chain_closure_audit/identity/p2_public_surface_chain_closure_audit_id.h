#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceChainClosureAuditId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceChainClosureAuditId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
