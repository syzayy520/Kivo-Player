#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_chain_closure_audit {

enum class P2PublicSurfaceChainClosureAuditKind : std::uint8_t {
    DeltaClosed,
    SurfaceChainClosed,
    ProofOnly,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
