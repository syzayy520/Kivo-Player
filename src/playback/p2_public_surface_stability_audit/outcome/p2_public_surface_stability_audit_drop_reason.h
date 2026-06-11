#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_audit {

enum class P2PublicSurfaceStabilityAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_stability_audit
