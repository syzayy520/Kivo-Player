#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_chain_closure_audit {

enum class P2PublicSurfaceChainClosureAuditScope : std::uint8_t {
    PublicSurface,
    DeltaBoundary,
    P2SurfaceChain,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
