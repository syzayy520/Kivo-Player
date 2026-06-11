#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_chain_closure_audit {

enum class P2PublicSurfaceChainClosureAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
