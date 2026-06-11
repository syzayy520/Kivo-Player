#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceChainClosureAuditGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceChainClosureAuditGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
