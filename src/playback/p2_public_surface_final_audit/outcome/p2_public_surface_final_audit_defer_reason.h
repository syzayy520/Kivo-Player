#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_final_audit {

enum class P2PublicSurfaceFinalAuditDeferReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_final_audit
