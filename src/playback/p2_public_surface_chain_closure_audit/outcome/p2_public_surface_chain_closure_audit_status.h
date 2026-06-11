#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_chain_closure_audit {

enum class P2PublicSurfaceChainClosureAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
