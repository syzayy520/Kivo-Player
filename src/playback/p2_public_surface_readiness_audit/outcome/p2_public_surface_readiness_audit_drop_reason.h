#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_audit {

enum class P2PublicSurfaceReadinessAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
